---
layout: page
title: Data Structure
---

# Data Structure

<style>
  .ds-layout {
    display: grid;
    grid-template-columns: 320px 1fr;
    gap: 24px;
    align-items: start;
  }

  .ds-panel h2 {
    margin-top: 0;
  }

  #file-tree ul {
    list-style: none;
    padding-left: 18px;
    margin: 6px 0;
  }

  #file-tree li {
    margin: 6px 0;
  }

  #file-tree summary {
    cursor: pointer;
    font-weight: 600;
  }

  .file-btn {
    border: none;
    background: none;
    padding: 0;
    cursor: pointer;
    color: #0969da;
    text-align: left;
    font: inherit;
  }

  #code-title {
    word-break: break-all;
  }

  #code-viewer {
    background: #f6f8fa;
    padding: 16px;
    border-radius: 8px;
    overflow: auto;
    white-space: pre-wrap;
    line-height: 1.5;
    min-height: 400px;
  }

  #code-viewer code {
    background: transparent !important;
    padding: 0 !important;
    border: 0 !important;
    color: inherit;
  }

  @media (max-width: 900px) {
    .ds-layout {
      grid-template-columns: 1fr;
    }
  }
</style>

<p>左邊是檔案列表，點一下就能看 code。</p>

<div class="ds-layout">
  <div class="ds-panel">
    <h2>檔案列表</h2>
    <div id="file-tree">載入中...</div>
  </div>

  <div class="ds-panel">
    <h2 id="code-title">Code Preview</h2>
    <pre id="code-viewer"><code>請先點左邊檔案</code></pre>
  </div>
</div>

<script>
const OWNER = "jackshih48";
const REPO = "jackshih48.github.io";
const BRANCH = "main";
const TARGET_DIR = "data_structures";

const ALLOW_EXT = [".c", ".h", ".cpp", ".hpp", ".py", ".java", ".txt", ".md"];

function escapeHtml(str) {
  return str
    .replaceAll("&", "&amp;")
    .replaceAll("<", "&lt;")
    .replaceAll(">", "&gt;");
}

function isAllowedFile(path) {
  return ALLOW_EXT.some(ext => path.toLowerCase().endsWith(ext));
}

function insertPath(tree, parts, fullPath) {
  let node = tree;
  for (let i = 0; i < parts.length; i++) {
    const part = parts[i];
    const isFile = i === parts.length - 1;

    if (!node[part]) {
      node[part] = isFile ? { __file: true, path: fullPath } : {};
    }
    node = node[part];
  }
}

function buildTree(paths) {
  const tree = {};
  for (const path of paths) {
    const relative = path.replace(/^data_structures\//, "");
    const parts = relative.split("/");
    insertPath(tree, parts, path);
  }
  return tree;
}

function renderTree(node, container) {
  const ul = document.createElement("ul");

  const keys = Object.keys(node).sort((a, b) => {
    const aIsFile = !!node[a].__file;
    const bIsFile = !!node[b].__file;
    if (aIsFile !== bIsFile) return aIsFile ? 1 : -1;
    return a.localeCompare(b, "zh-Hant");
  });

  for (const key of keys) {
    const li = document.createElement("li");

    if (node[key].__file) {
      const btn = document.createElement("button");
      btn.textContent = key;
      btn.className = "file-btn";
      btn.onclick = () => loadCode(node[key].path);
      li.appendChild(btn);
    } else {
      const details = document.createElement("details");
      details.open = true;

      const summary = document.createElement("summary");
      summary.textContent = key;
      details.appendChild(summary);

      renderTree(node[key], details);
      li.appendChild(details);
    }

    ul.appendChild(li);
  }

  container.appendChild(ul);
}

async function loadCode(path) {
  const codeTitle = document.getElementById("code-title");
  const codeViewer = document.getElementById("code-viewer");

  codeTitle.textContent = path;
  codeViewer.innerHTML = "<code>載入中...</code>";

  const rawUrl = `https://raw.githubusercontent.com/${OWNER}/${REPO}/${BRANCH}/${path}`;

  try {
    const res = await fetch(rawUrl);
    if (!res.ok) throw new Error("讀取失敗");
    const text = await res.text();
    codeViewer.innerHTML = `<code>${escapeHtml(text)}</code>`;
  } catch (err) {
    codeViewer.innerHTML = `<code>載入失敗：${escapeHtml(String(err))}</code>`;
  }
}

async function loadFileTree() {
  const container = document.getElementById("file-tree");
  container.textContent = "載入中...";

  const apiUrl = `https://api.github.com/repos/${OWNER}/${REPO}/git/trees/${BRANCH}?recursive=1`;

  try {
    const res = await fetch(apiUrl);
    if (!res.ok) throw new Error("無法讀取 GitHub API");
    const data = await res.json();

    const files = (data.tree || [])
      .filter(item => item.type === "blob")
      .map(item => item.path)
      .filter(path => path.startsWith(TARGET_DIR + "/"))
      .filter(path => !path.endsWith("/index.md"))
      .filter(isAllowedFile);

    if (files.length === 0) {
      container.textContent = "目前沒有可顯示的檔案。";
      return;
    }

    const tree = buildTree(files);
    container.innerHTML = "";
    renderTree(tree, container);
  } catch (err) {
    container.textContent = "載入檔案列表失敗：" + err;
  }
}

loadFileTree();
</script>