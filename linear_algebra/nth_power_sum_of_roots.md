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

則有展開式

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