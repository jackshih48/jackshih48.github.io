---
layout: math
title: 任意多項式根的 n 次方和
---

# 任意多項式根的 n 次方和

<br>

## 公式

根據代數基本定理，任意 $k$ 次多項式都可寫成

$$
f(x)=a(x-\alpha_1)(x-\alpha_2)\cdots(x-\alpha_k).
$$

若定義根的 $n$ 次方和為

$$
S_n=\alpha_1^n+\alpha_2^n+\cdots+\alpha_k^n,
$$

則有公式

$$
\boxed{
\frac{f'(x)}{f(x)}
=
\frac{S_0}{x}
+
\frac{S_1}{x^2}
+
\frac{S_2}{x^3}
+\cdots
}
$$

其中

$$
S_0=\alpha_1^0+\alpha_2^0+\cdots+\alpha_k^0=k.
$$

<br>

## 證明

先由
$$
1=(x)'=(e^{\ln x})'=(e^{\ln x})(\ln x)'=x(\ln x)'
$$
得
$$
(\ln x)'=\frac{1}{x}.
$$

接著對

$$
f(x)=a(x-\alpha_1)(x-\alpha_2)\cdots(x-\alpha_k)
$$

取 $\ln$ 並微分：

$$
(\ln f(x))'=(\ln a+\ln(x-\alpha_1)+\ln(x-\alpha_2)+\cdots+\ln(x-\alpha_k))'
$$

等號兩邊可改寫:

$$
\begin{aligned}
\frac{f'(x)}{f(x)}
&=\frac{1}{x-\alpha_1}+\frac{1}{x-\alpha_2}+\cdots+\frac{1}{x-\alpha_k} \\
&=\frac{1}{x}\left(\frac{1}{1-\alpha_1/x}+\frac{1}{1-\alpha_2/x}+\cdots+\frac{1}{1-\alpha_k/x}\right) \\
&=\frac{1}{x}\left(\left(1+\frac{\alpha_1}{x}+\frac{\alpha_1^2}{x^2}+\cdots\right)+\left(1+\frac{\alpha_2}{x}+\frac{\alpha_2^2}{x^2}+\cdots\right)+\cdots\right) \\
&=\frac{S_0}{x}+\frac{S_1}{x^2}+\frac{S_2}{x^3}+\cdots
\end{aligned}
$$

> ※ 此處若從收斂角度看，需有 $\|x\|>\max\\{\|\alpha_1\|,\dots,\|\alpha_k\|\\}$；但本文只是將其作為 $1/x$ 的展開與係數比較，也就是代數上的改寫，因此收斂與否不影響結論。

<br>

## 例子1

考慮多項式 $f(x)=x^2-4x+5$，設其二根為 $\alpha,\beta$，要求 $\alpha^4+\beta^4$.

先求導數：

$$
f'(x)=2x-4.
$$

做多項式除法 (想像將公式兩邊同乘 $x^{100}$ 會發現跟正常的多項式除法作法一致)：

<img src="./roots.png" alt="roots" width="500">

所以

$$
\frac{f'(x)}{f(x)}=\frac{2}{x}+\frac{4}{x^2}-\frac{6}{x^3}+\frac{4}{x^4}+\frac{-14}{x^5}+\cdots
$$

由

$$
\frac{f'(x)}{f(x)}=\frac{S_0}{x}+\frac{S_1}{x^2}+\frac{S_2}{x^3}+\frac{S_3}{x^4}+\frac{S_4}{x^5}+\cdots
$$

可得

$$
S_4=-14.
$$

<br>

## 例子2

求 $(2+i)^{4}+(2-i)^4$ 的準確值。

令 $x = 2\pm i$ ，可發現:

$$
\begin{aligned}
x-2 = \pm i \\
(x-2)^2 = (\pm i)^2 \\
(x-2)^2 = -1 \\
x^2 - 4x + 4 = -1 \\
x^2 - 4x + 5 = 0
\end{aligned}
$$ 

因此原式所求為方程式 $x^2 - 4x + 5 = 0$ 兩根的四次方和。

在例子1中，我們已經求出

$$
S_4=\alpha^4+\beta^4=-14.
$$

所以

$$
\boxed{(2+i)^{4}+(2-i)^4=-14.}
$$

<br>

## 例子3

考慮矩陣

$$
A=
\begin{pmatrix}
0 & -5\\
1 & 4
\end{pmatrix},
$$

要求

$$
\operatorname{tr}(A^4).
$$

若 $\lambda$ 是矩陣 $A$ 的特徵值，那麼 $\lambda^n$ 會是 $A^n$ 的特徵值。

且由於矩陣的跡是特徵值和，因此我們有:

$$
\operatorname{tr}(A^n)=\alpha_0^n+ \dots + \alpha_k^n.
$$

其中 $\alpha_i$ 是矩陣 $A$ 的特徵值。

矩陣 $A$ 的特徵多項式為

$$
\det(xI-A)
=
\det
\begin{pmatrix}
x & 5\\
-1 & x-4
\end{pmatrix}
=
x(x-4)+5
=
x^2-4x+5.
$$

則它的特徵值為 $\alpha,\beta$ 正是多項式

$$
f(x)=x^2-4x+5
$$

的兩個根。

在例子1中，我們已經對 $f(x)=x^2-4x+5$ 求出

$$
S_4=\alpha^4+\beta^4=-14.
$$

因此立刻得到

$$
\boxed{\operatorname{tr}(A^4)=-14.}
$$