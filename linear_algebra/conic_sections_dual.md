---
layout: math
title: 二次曲線的對偶結構
---

# 二次曲線的對偶結構

對於二次曲線

$$
F(\mathbf{x})=\mathbf{x}^T A\mathbf{x}+\mathbf{b}^T\mathbf{x}+f=0
$$

其中

$$
\mathbf{x}=\begin{bmatrix}x\\y\end{bmatrix}, \quad A=A^T
$$

若取平面上一點 $P(\mathbf{x}_0)$，則透過"換一半"公式(即極線公式)可對應到一直線：

$$
\mathbf{x}_0^T A\mathbf{x}+\mathbf{b}^T\frac{\mathbf{x}+\mathbf{x}_0}{2}+f=0
$$

稱為極點$P$所對應的極線。

<br>

## 對偶結構

"換一半"公式，建立了點與線之間的對應關係:

$$
\mathbf{x}_0^T A\mathbf{x}+\mathbf{b}^T\frac{\mathbf{x}+\mathbf{x}_0}{2}+f=0
$$

可改寫為:

$$
\begin{aligned}
(\mathbf{x}_0^T A+\mathbf{b}^T)\mathbf{x} + \frac{1}{2} \mathbf{b}^T\mathbf{x}_0 +f=0 \\
(A \mathbf{x}_0 +\mathbf{b})^T \mathbf{x} + \frac{1}{2} \mathbf{b}^T\mathbf{x}_0 +f=0
\end{aligned}
$$ 

若A可逆，對於平面上每一點，上述公式都給出一條對應直線，反之亦然：

$$
\boxed{
\text{點 } P \longleftrightarrow \text{直線 } \ell_P
}
$$

這正是二次曲線中的對偶結構。

<br>

## La Hire Theorem

設平面上兩點分別為 $P_1(\mathbf{x}_1)$、$P_2(\mathbf{x}_2)$。  
若點 $P_2$ 在點 $P_1$ 的極線上，則將 $\mathbf{x}_2$ 代入 $P_1$ 的極線方程式可得：

$$
\mathbf{x}_1^T A\mathbf{x}_2+\mathbf{b}^T\frac{\mathbf{x}_1+\mathbf{x}_2}{2}+f=0
$$

由於矩陣 $A$ 為對稱矩陣，故有

$$
\mathbf{x}_1^T A\mathbf{x}_2
=
(\mathbf{x}_1^T A\mathbf{x}_2)^T
=
\mathbf{x}_2^T A^T\mathbf{x}_1
=
\mathbf{x}_2^T A\mathbf{x}_1
$$

因此上式等價於

$$
\mathbf{x}_2^T A\mathbf{x}_1+\mathbf{b}^T\frac{\mathbf{x}_2+\mathbf{x}_1}{2}+f=0
$$

這表示點 $P_1$ 也在點 $P_2$ 的極線上。

所以我們得到：

$$
\boxed{
P_2 \text{ 在 } P_1 \text{ 的極線上}
\iff
P_1 \text{ 在 } P_2 \text{ 的極線上}
}
$$

這個性質描述極點與極線的對稱性，也稱為 La Hire Theorem。

<br>

由 La Hire Theorem，還可得到下列對應。

若兩點 $A,B$ 都在某點 $P$ 的極線上，則點 $P$ 也必在 $A,B$ 各自的極線上。  
也就是說，若一個點在另外兩點的極線上，則那兩點的極線交於此點。

換句話說，原本「兩點決定一直線」的結構，經過"換一半"公式對應後，會轉成「兩線交於一點」的結構。

在二次曲線所誘導的幾何中，常見的對偶關係如下：

- 點 $\longleftrightarrow$ 線
- 共線 $\longleftrightarrow$ 共點
- 兩點連線 $\longleftrightarrow$ 兩線交點

<br>

## 射影平面

到目前為止，我們的討論都在仿射平面 $\mathbb{R}^2$ 中進行。  
這樣已足以處理許多問題，但若想把點線對偶寫成沒有例外的理論，仍會遇到一些困難。

### 1. 平行線沒有交點

在對偶的語言裡，「兩線交於一點」與「兩點連成一直線」應當彼此對應。  
但在仿射平面中，平行線沒有交點，因此某些對應會出現缺口。

### 2. 反求極點時可能失敗

由極線方程式可知，點 $\mathbf{x}_0$ 對應到極線的法向量為

$$
2A\mathbf{x}_0+\mathbf{b}
$$

若反過來給定一直線，想求其極點 $\mathbf{x}_0$，便需要反解矩陣 $A$。  
若 $A$ 不可逆，例如拋物線的情形；退化二次曲線中也常會出現類似問題，則此反推過程會失效。

<br>

因此，為了補足這些缺口，並保留點線對偶的完整結構，我們需要引入**齊次座標**，將仿射平面擴充為射影平面。

在射影平面中：

- 平行線交於無窮遠點；
- 點與線的角色更對稱；
- 二次曲線可統一表示為單一的齊次二次型。

<br>

## 射影二次曲線

在仿射平面中，二次曲線為:

$$
F(\mathbf{x})=\mathbf{x}^T A\mathbf{x}+\mathbf{b}^T\mathbf{x}+f=0
$$

若引入齊次座標

$$
\mathbf{X}=
\begin{bmatrix}
x\\y\\1
\end{bmatrix}
$$

則原式可改寫為

$$
\boxed{
\mathbf{X}^T Q \mathbf{X}=0
}
$$

其中

$$
Q=
\begin{bmatrix}
a & \frac{b}{2} & \frac{d}{2} \\
\frac{b}{2} & c & \frac{e}{2} \\
\frac{d}{2} & \frac{e}{2} & f
\end{bmatrix}
$$
是對稱矩陣。

如此一來，原本仿射形式中的二次項、一次項與常數項，便可統一寫成一個齊次二次型。  
在這個表示法中，點與線的對應、切線方程式、極點極線的關係，都會變得更簡潔而對稱。