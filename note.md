---
layout: page
title: My Note
---

這就為你準備好可以直接放到 GitHub 上的 Markdown 原始碼！

先跟你分享一個好消息：**GitHub 其實在 2022 年 5 月就已經全面原生支援 LaTeX 數學公式渲染了！** 你不需要裝任何外掛，只要在普通的 `.md` 檔案（例如 `README.md`）裡，使用標準的 `$`（單行內嵌）和 `$$`（獨立區塊）將公式包起來，GitHub 就會自動用 MathJax 幫你把它渲染成漂亮的數學式。

以下是為你排版好的完整 Markdown 內容，我已經確保所有公式都緊貼著 `$` 和 `$$` 符號（這是 GitHub 成功渲染的關鍵，符號和公式之間不能有空格）。你可以直接全選複製貼上：

***

# 線性代數核心筆記：特徵值分解 (EVD) 與奇異值分解 (SVD)

## 一、 特徵值分解 (Eigenvalue Decomposition, EVD)

### 1. 定義與矩陣形式
對於一個$n \times n$的方陣$A$，若存在非零向量$\boldsymbol{v}$與純量$\lambda$滿足：
$$A\boldsymbol{v} = \lambda\boldsymbol{v}$$
則稱$\lambda$為特徵值，$\boldsymbol{v}$為對應的特徵向量。

若$A$擁有$n$個線性獨立的特徵向量$\boldsymbol{v}_1, \boldsymbol{v}_2, \dots, \boldsymbol{v}_n$，對應的特徵值為$\lambda_1, \lambda_2, \dots, \lambda_n$。將這$n$條方程式合併為矩陣相乘的形式：
$$A \begin{bmatrix} | & & | \\ \boldsymbol{v}_1 & \dots & \boldsymbol{v}_n \\ | & & | \end{bmatrix} = \begin{bmatrix} | & & | \\ \lambda_1\boldsymbol{v}_1 & \dots & \lambda_n\boldsymbol{v}_n \\ | & & | \end{bmatrix}$$

令$V$為特徵向量組成的矩陣，$\Lambda$為特徵值組成的對角矩陣，原式可改寫為$AV = V\Lambda$。由於$V$的行向量線性獨立，$V^{-1}$必然存在，同乘$V^{-1}$即得到 **EVD 的一般定義**：
$$A = V \Lambda V^{-1}$$

**實對稱矩陣的正交對角化：**
若$A$為實對稱矩陣($A = A^T$)，根據譜定理 (Spectral Theorem)，其特徵值皆為實數，且特徵向量必可選為彼此正交的單位向量。此時$V$為正交矩陣 (Orthogonal Matrix)，習慣記為$Q$。因正交矩陣滿足$Q^{-1} = Q^T$，分解式可簡化為：
$$A = Q \Lambda Q^T$$

### 2. 譜分解 (Spectral Decomposition) 的推導
將實對稱矩陣的分解式$A = Q \Lambda Q^T$透過分塊矩陣乘法展開：
$$A = \begin{bmatrix} | & & | \\ \boldsymbol{q}_1 & \dots & \boldsymbol{q}_n \\ | & & | \end{bmatrix} \begin{bmatrix} \lambda_1 & & \\ & \ddots & \\ & & \lambda_n \end{bmatrix} \begin{bmatrix} — \boldsymbol{q}_1^T — \\ \vdots \\ — \boldsymbol{q}_n^T — \end{bmatrix}$$

先計算前兩個矩陣的乘積，將$\lambda_i$乘入對應的特徵向量：
$$A = \begin{bmatrix} | & & | \\ \lambda_1\boldsymbol{q}_1 & \dots & \lambda_n\boldsymbol{q}_n \\ | & & | \end{bmatrix} \begin{bmatrix} — \boldsymbol{q}_1^T — \\ \vdots \\ — \boldsymbol{q}_n^T — \end{bmatrix}$$

接著執行行向量與列向量的矩陣相乘，可將矩陣$A$展開為一系列秩為 1 的矩陣之線性組合：
$$A = \lambda_1\boldsymbol{q}_1\boldsymbol{q}_1^T + \lambda_2\boldsymbol{q}_2\boldsymbol{q}_2^T + \dots + \lambda_n\boldsymbol{q}_n\boldsymbol{q}_n^T = \sum_{i=1}^n \lambda_i\boldsymbol{q}_i\boldsymbol{q}_i^T$$


**外積的代數與物理意義：**
矩陣$\boldsymbol{q}_i\boldsymbol{q}_i^T$為一外積矩陣。當其作用於空間中任意向量$\boldsymbol{x}$時：
$$(\boldsymbol{q}_i\boldsymbol{q}_i^T)\boldsymbol{x} = \boldsymbol{q}_i(\boldsymbol{q}_i^T\boldsymbol{x})$$
由於$\boldsymbol{q}_i^T\boldsymbol{x}$為內積純量，代表$\boldsymbol{x}$在$\boldsymbol{q}_i$方向上的投影長度。因此，$\boldsymbol{q}_i\boldsymbol{q}_i^T$為一**投影運算子 (Projection Operator)**，負責將向量投影至$\boldsymbol{q}_i$方向，而$\lambda_i$則控制該投影方向的縮放尺度。

### 3. 矩陣的雙重幾何視角
給定方陣$A \in \mathbb{R}^{n \times n}$，可依據數學情境被詮釋為兩種截然不同的物件：

* **視角一：作為線性算子 (Linear Operator)**
    矩陣$A$視為映射函數$T(\boldsymbol{x}) = A\boldsymbol{x}$，代表空間變換的「動作」。EVD ($A = Q \Lambda Q^T$) 將此變換拆解為三步驟：首先透過$Q^T$將座標軸旋轉至特徵向量基底，接著透過$\Lambda$於各基底軸上獨立縮放，最後透過$Q$旋轉回原座標系。
* **視角二：作為資料紀錄與二次型 (Quadratic Form)**
    若$A = A^T$，矩陣$A$可視為空間中測量能量或距離的「度量」，用來「紀錄」某個幾何形狀的特徵。給定二次型$q(\boldsymbol{x}) = \boldsymbol{x}^T A \boldsymbol{x}$，代入 EVD：
    $$\boldsymbol{x}^T A \boldsymbol{x} = \boldsymbol{x}^T (Q \Lambda Q^T) \boldsymbol{x} = (Q^T\boldsymbol{x})^T \Lambda (Q^T\boldsymbol{x})$$
    引入正交座標變換$\boldsymbol{y} = Q^T\boldsymbol{x}$，可化簡為標準二次曲面方程式：
    $$\boldsymbol{y}^T \Lambda \boldsymbol{y} = \sum_{i=1}^n \lambda_i y_i^2 = c$$
    **幾何結論**：EVD 解耦了二次型中的交叉項，將$A$內含的幾何資料提取出來。正交矩陣$Q$的行向量紀錄了二次曲面（如橢球）的**主軸方向**；特徵值$\lambda_i$紀錄了沿主軸的**曲率或尺度**（半徑$r_i \propto 1/\sqrt{\lambda_i}$）。

---

## 二、 奇異值分解 (Singular Value Decomposition, SVD)

### 1. SVD 幾何存在性定理
對於任意線性變換$M: \mathbb{R}^n \to \mathbb{R}^m$，必定存在一組定義於輸入空間的正交基底$\boldsymbol{v}_1, \dots, \boldsymbol{v}_n$，使得它們經過$M$映射後，在輸出空間中產生的一組向量$M\boldsymbol{v}_1, \dots, M\boldsymbol{v}_n$ **依然保持正交**。

將映射後的正交向量正規化，即可得到輸出空間的正交基底$\boldsymbol{u}_i$，其映射關係為：
$$M\boldsymbol{v}_i = \sigma_i \boldsymbol{u}_i$$
其中$\sigma_i \geq 0$為純量（奇異值），代表沿該正交方向的拉伸或壓縮比例。

### 2. 定義與矩陣形式
任何一個$m \times n$的實數矩陣$M$皆可分解為：
$$M = U \Sigma V^T$$
* **$U \in \mathbb{R}^{m \times m}$ (左奇異向量矩陣)**：為正交矩陣，其行向量$\boldsymbol{u}_i$構成輸出空間的正交基底。
* **$V \in \mathbb{R}^{n \times n}$ (右奇異向量矩陣)**：為正交矩陣，其行向量$\boldsymbol{v}_i$構成輸入空間的正交基底。
* **$\Sigma \in \mathbb{R}^{m \times n}$ (奇異值矩陣)**：為對角矩陣，對角線元素為奇異值$\sigma_i$（且$\sigma_1 \geq \sigma_2 \geq \dots \geq 0$）。

### 3. SVD 與 $M^TM$、$MM^T$ 的代數證明
透過計算$M^TM$，可證明奇異值與特徵值的代數關聯：
$$M^T M = (U \Sigma V^T)^T (U \Sigma V^T)$$
利用轉置運算性質$(AB)^T = B^T A^T$展開：
$$M^T M = V \Sigma^T U^T U \Sigma V^T$$
因$U$為正交矩陣($U^T U = I_m$)，且$\Sigma$為對角矩陣($\Sigma^T \Sigma = \Sigma^2$)，代入化簡得：
$$M^T M = V \Sigma^2 V^T$$
上式符合實對稱矩陣$M^TM$的 EVD 形式 ($A = Q \Lambda Q^T$)。同理可推導$MM^T = U \Sigma^2 U^T$。

**代數結論與 Rank 定理：**
1. 矩陣$V$的行向量 (columns) 即為$M^TM$的特徵向量。
2. 矩陣$U$的行向量 (columns) 即為$MM^T$的特徵向量。
3. 奇異值的平方$\sigma_i^2$同時是$M^TM$與$MM^T$的非零特徵值，亦即$\sigma_i = \sqrt{\lambda_i(M^T M)} = \sqrt{\lambda_i(MM^T)}$。
4. **Rank 定理**：矩陣$M$的秩 (Rank) $r$，恰好等於其大於零的非零奇異值個數。

### 4. 矩陣維度與 Reduced SVD 外積和展開
SVD 的核心在於處理非方陣的維度映射。給定矩陣$M \in \mathbb{R}^{m \times n}$，設其秩 (Rank) 為$r$。根據 Rank 定理，$M$恰有$r$個大於零的奇異值$\sigma_1 \dots \sigma_r > 0$，其餘$\sigma_{r+1} \dots \sigma_{\min(m,n)}$皆為$0$。

將$M = U \Sigma V^T$以分塊矩陣展開：
$$M = \begin{bmatrix} \boldsymbol{u}_1 & \dots & \boldsymbol{u}_m \end{bmatrix} \begin{bmatrix} \sigma_1 & & \\ & \ddots & \\ & & \sigma_n \end{bmatrix} \begin{bmatrix} \boldsymbol{v}_1^T \\ \vdots \\ \boldsymbol{v}_n^T \end{bmatrix}$$

由於對角矩陣$\Sigma$中僅前$r$個對角元為非零值，與其相乘的$U$的後$m-r$個行向量，以及$V$的後$n-r$個列向量，在乘法過程中皆會被零消去（對應至矩陣的零空間 Null Space）。

因此，可捨棄所有對應為$0$的無效向量，將原分解精簡為 **Reduced SVD (截斷奇異值分解 / Rank-r Decomposition)**，並改寫為秩為 1 的外積和形式：
$$M = \sum_{i=1}^r \sigma_i \boldsymbol{u}_i \boldsymbol{v}_i^T$$
當此展開式作用於向量$\boldsymbol{x}$時：
$$M\boldsymbol{x} = \sum_{i=1}^r \sigma_i \boldsymbol{u}_i (\boldsymbol{v}_i^T \boldsymbol{x})$$
**物理意義**：此式表達了變換過程：將輸入向量投影至基底$\boldsymbol{v}_i$獲取分量（內積純量），依權重$\sigma_i$進行縮放，最後將該純量沿著輸出空間的基底$\boldsymbol{u}_i$方向映射。任何秩為$r$的矩陣，皆可解構為這$r$個一維變換的線性疊加。
