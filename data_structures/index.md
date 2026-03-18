---
layout: page
title: Data Structure
---

# Data Structure

<style>
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

  .file-link {
    color: #0969da;
    text-decoration: none;
  }

  .file-link:hover {
    text-decoration: underline;
  }
</style>

<p>點檔名後會直接跳到該檔案頁面。</p>

<div id="file-tree">載入中...</div>

<script>
const OWNER = "jackshih48";
const REPO = "jackshih48.github.io";
const BRANCH = "main";
const TARGET_DIR = "data_structures";

const ALLOW_EXT = [".c", ".h", ".cpp", ".hpp", ".py", ".java", ".txt", ".md"];

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
      const a = document.createElement("a");
      a.textContent = key;
      a.className = "file-link";
      a.href = "/" + node[key].path;
      li.appendChild(a);
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