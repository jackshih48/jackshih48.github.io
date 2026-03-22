---
layout: math
title: 線性代數核心筆記：EVD 與 SVD
---

# 線性代數核心筆記：EVD 與 SVD

這份筆記整理特徵值分解（EVD）與奇異值分解（SVD）的定義、幾何意義與代數推導。

---

## 一、特徵值分解（Eigenvalue Decomposition, EVD）

### 1. 定義與矩陣形式

對於一個 $n \times n$ 的方陣 $A$，若存在非零向量 $\boldsymbol{v}$ 與純量 $\lambda$ 滿足：

$$
A\boldsymbol{v} = \lambda\boldsymbol{v}
$$

則稱 $\lambda$ 為特徵值，$\boldsymbol{v}$ 為對應的特徵向量。

若 $A$ 擁有 $n$ 個線性獨立的特徵向量 $\boldsymbol{v}_1, \boldsymbol{v}_2, \dots, \boldsymbol{v}_n$，對應的特徵值為 $\lambda_1, \lambda_2, \dots, \lambda_n$，則可寫成：

$$
A
\begin{bmatrix}
| & & | \\
\boldsymbol{v}_1 & \dots & \boldsymbol{v}_n \\
| & & |
\end{bmatrix}
=
\begin{bmatrix}
| & & | \\
\lambda_1 \boldsymbol{v}_1 & \dots & \lambda_n \boldsymbol{v}_n \\
| & & |
\end{bmatrix}
$$

令 $V$ 為特徵向量組成的矩陣，$\Lambda$ 為特徵值組成的對角矩陣，則原式可改寫為：

$$
AV = V\Lambda
$$

若 $V$ 可逆，便得到 **EVD 的一般形式**：

$$
A = V \Lambda V^{-1}
$$

---

### 2. 實對稱矩陣的正交對角化

若 $A$ 為實對稱矩陣，即 $A = A^T$，則根據譜定理，其特徵值皆為實數，且特徵向量可選成彼此正交的單位向量。

此時 $V$ 為正交矩陣，習慣記為 $Q$。由於正交矩陣滿足：

$$
Q^{-1} = Q^T
$$

因此分解式可簡化為：

$$
A = Q \Lambda Q^T
$$

---

### 3. 譜分解（Spectral Decomposition）

將實對稱矩陣的分解式 $A = Q \Lambda Q^T$ 展開：

$$
A =
\begin{bmatrix}
| & & | \\
\boldsymbol{q}_1 & \dots & \boldsymbol{q}_n \\
| & & |
\end{bmatrix}
\begin{bmatrix}
\lambda_1 & & \\
& \ddots & \\
& & \lambda_n
\end{bmatrix}
\begin{bmatrix}
- \boldsymbol{q}_1^T - \\
\vdots \\
- \boldsymbol{q}_n^T -
\end{bmatrix}
$$

先將特徵值乘入對應特徵向量：

$$
A =
\begin{bmatrix}
| & & | \\
\lambda_1 \boldsymbol{q}_1 & \dots & \lambda_n \boldsymbol{q}_n \\
| & & |
\end{bmatrix}
\begin{bmatrix}
- \boldsymbol{q}_1^T - \\
\vdots \\
- \boldsymbol{q}_n^T -
\end{bmatrix}
$$

進一步可得：

$$
A
=
\lambda_1 \boldsymbol{q}_1 \boldsymbol{q}_1^T
+
\lambda_2 \boldsymbol{q}_2 \boldsymbol{q}_2^T
+
\dots
+
\lambda_n \boldsymbol{q}_n \boldsymbol{q}_n^T
=
\sum_{i=1}^n \lambda_i \boldsymbol{q}_i \boldsymbol{q}_i^T
$$

這表示矩陣 $A$ 可以拆成一系列秩為 1 的外積矩陣線性組合。

---

### 4. 外積的幾何意義

對任意向量 $\boldsymbol{x}$，

$$
(\boldsymbol{q}_i \boldsymbol{q}_i^T)\boldsymbol{x}
=
\boldsymbol{q}_i (\boldsymbol{q}_i^T \boldsymbol{x})
$$

其中 $\boldsymbol{q}_i^T \boldsymbol{x}$ 是 $\boldsymbol{x}$ 在 $\boldsymbol{q}_i$ 方向上的投影長度，因此：

- $\boldsymbol{q}_i \boldsymbol{q}_i^T$ 是一個投影算子
- $\lambda_i$ 控制該方向上的縮放大小

所以譜分解可以理解為：  
矩陣 $A$ 會沿著各個特徵向量方向進行投影與縮放。

---

### 5. 二次型與幾何解釋

給定二次型：

$$
q(\boldsymbol{x}) = \boldsymbol{x}^T A \boldsymbol{x}
$$

若代入 EVD：

$$
\boldsymbol{x}^T A \boldsymbol{x}
=
\boldsymbol{x}^T (Q \Lambda Q^T)\boldsymbol{x}
=
(Q^T\boldsymbol{x})^T \Lambda (Q^T\boldsymbol{x})
$$

令

$$
\boldsymbol{y} = Q^T \boldsymbol{x}
$$

則可化為：

$$
\boldsymbol{y}^T \Lambda \boldsymbol{y}
=
\sum_{i=1}^n \lambda_i y_i^2
= c
$$

這表示透過正交變換後，二次型中的交叉項被消除，得到標準形式。

**幾何上：**

- 正交矩陣 $Q$ 描述主軸方向
- 特徵值 $\lambda_i$ 描述沿主軸方向的曲率或尺度
- 例如橢球半徑可視為 $r_i \propto 1/\sqrt{\lambda_i}$

---

## 二、奇異值分解（Singular Value Decomposition, SVD）

### 1. SVD 幾何存在性定理

對於任意線性變換

$$
M : \mathbb{R}^n \to \mathbb{R}^m
$$

必定存在一組定義於輸入空間的正交基底 $\boldsymbol{v}_1, \dots, \boldsymbol{v}_n$，使得它們經過 $M$ 映射後，在輸出空間中產生的向量

$$
M\boldsymbol{v}_1, \dots, M\boldsymbol{v}_n
$$

彼此仍然正交。

將這些映射後的正交向量正規化，可得到輸出空間的正交基底 $\boldsymbol{u}_i$，並有：

$$
M \boldsymbol{v}_i = \sigma_i \boldsymbol{u}_i
$$

其中 $\sigma_i \ge 0$ 稱為奇異值，表示沿該方向的拉伸或壓縮比例。

---

### 2. 定義與矩陣形式

任何一個 $m \times n$ 的實矩陣 $M$ 都可以分解為：

$$
M = U \Sigma V^T
$$

其中：

- $U \in \mathbb{R}^{m \times m}$：左奇異向量矩陣
- $V \in \mathbb{R}^{n \times n}$：右奇異向量矩陣
- $\Sigma \in \mathbb{R}^{m \times n}$：奇異值矩陣

且 $\Sigma$ 的對角元素為：

$$
\sigma_1 \ge \sigma_2 \ge \dots \ge 0
$$

---

### 3. SVD 與 $M^T M$、$M M^T$ 的關係

由

$$
M = U \Sigma V^T
$$

可得：

$$
M^T M = (U \Sigma V^T)^T (U \Sigma V^T)
$$

利用轉置公式 $(AB)^T = B^T A^T$：

$$
M^T M = V \Sigma^T U^T U \Sigma V^T
$$

由於 $U$ 為正交矩陣，滿足 $U^T U = I$，所以：

$$
M^T M = V \Sigma^T \Sigma V^T
$$

而 $\Sigma^T \Sigma$ 為對角矩陣，可記作 $\Sigma^2$，因此：

$$
M^T M = V \Sigma^2 V^T
$$

同理可得：

$$
M M^T = U \Sigma^2 U^T
$$

這說明：

1. $V$ 的 columns 是 $M^T M$ 的特徵向量
2. $U$ 的 columns 是 $M M^T$ 的特徵向量
3. 奇異值平方 $\sigma_i^2$ 是 $M^T M$ 與 $M M^T$ 的非零特徵值

亦即：

$$
\sigma_i = \sqrt{\lambda_i(M^T M)} = \sqrt{\lambda_i(M M^T)}
$$

---

### 4. Rank 定理

矩陣 $M$ 的秩 $r$，恰好等於其大於零的非零奇異值個數。

也就是說：

$$
\mathrm{rank}(M) = \#\{\sigma_i > 0\}
$$

這是 SVD 在資料壓縮、降維與低秩近似中非常重要的基礎。

---

### 5. 幾何意義

SVD 可將線性變換拆成三個步驟：

1. $V^T$：先把輸入座標系旋轉到右奇異向量基底
2. $\Sigma$：沿各正交方向獨立縮放
3. $U$：再把結果旋轉到輸出空間的方向

所以 SVD 的本質是：

> 任意線性變換都可以拆成「旋轉／反射 + 軸向縮放 + 旋轉／反射」。

---

## 三、EVD 與 SVD 的比較

| 項目 | EVD | SVD |
|---|---|---|
| 適用矩陣 | 方陣，常討論可對角化矩陣 | 任意 $m \times n$ 矩陣 |
| 分解形式 | $A = V \Lambda V^{-1}$ | $M = U \Sigma V^T$ |
| 對稱情況 | $A = Q \Lambda Q^T$ | 無須對稱也可做 |
| 幾何意義 | 沿特徵方向縮放 | 旋轉 + 縮放 + 旋轉 |
| 特殊量 | 特徵值 $\lambda_i$ | 奇異值 $\sigma_i$ |

---

## 四、總結

- EVD 適合分析方陣本身的固有方向與縮放特性
- 對實對稱矩陣而言，EVD 具有最清楚的幾何意義
- SVD 更一般，任何矩陣都能分解
- 奇異值反映了矩陣在不同方向上的伸縮能力
- 在資料分析、訊號處理、機器學習中，SVD 是非常核心的工具
