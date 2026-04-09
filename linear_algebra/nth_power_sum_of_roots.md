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

## 例子

考慮多項式
$$
f(x)=x^3-x^2+x-5
$$
設其三根為 \(\alpha,\beta,\gamma\)，要求
$$
\alpha^4+\beta^4+\gamma^4.
$$

先求導數：
$$
f'(x)=3x^2-2x+1.
$$

因此
$$
\frac{f'(x)}{f(x)}
=
\frac{3x^2-2x+1}{x^3-x^2+x-5}.
$$

直接做長除法：
$$
\begin{array}{r|rrrrrr}
 & \frac{3}{x} & \frac{1}{x^2} & -\frac{1}{x^3} & \frac{13}{x^4} & \frac{19}{x^5} & \cdots \\ \hline
x^3-x^2+x-5 \;\big)\; 3x^2 & -2x & 1 & 0 & 0 & 0 & \cdots \\
\multicolumn{7}{r}{\underline{\phantom{xxxxx}3x^2-3x+3-\frac{15}{x}\phantom{xxxxx}}} \\
 & x & -2 & \frac{15}{x} & 0 & 0 & \cdots \\
\multicolumn{7}{r}{\underline{\phantom{xxxxxxxx}\;x-1+\frac{1}{x}-\frac{5}{x^2}\phantom{xxxxxxxx}}} \\
 & -1 & \frac{14}{x} & \frac{5}{x^2} & 0 & \cdots \\
\multicolumn{7}{r}{\underline{\phantom{xxxxxxxxxxxxxx}-1+\frac{1}{x}-\frac{1}{x^2}+\frac{5}{x^3}\phantom{xxxxxxxxxxxxxx}}} \\
 & \frac{13}{x} & \frac{6}{x^2} & -\frac{5}{x^3} & \cdots \\
\multicolumn{7}{r}{\underline{\phantom{xxxxxxxxxxxxxxxxxxxx}\frac{13}{x}-\frac{13}{x^2}+\frac{13}{x^3}-\frac{65}{x^4}\phantom{xxxxxxxxxxxxxxxxxxxx}}} \\
 & \frac{19}{x^2} & -\frac{18}{x^3} & \frac{65}{x^4} & \cdots
\end{array}
$$

所以
$$
\frac{f'(x)}{f(x)}
=
\frac{3}{x}+\frac{1}{x^2}-\frac{1}{x^3}+\frac{13}{x^4}+\frac{19}{x^5}+\cdots
$$

由
$$
\frac{f'(x)}{f(x)}
=
\frac{S_0}{x}+\frac{S_1}{x^2}+\frac{S_2}{x^3}+\frac{S_3}{x^4}+\frac{S_4}{x^5}+\cdots
$$
可得
$$
S_4=19.
$$

因此
$$
\boxed{\alpha^4+\beta^4+\gamma^4=19.}
$$