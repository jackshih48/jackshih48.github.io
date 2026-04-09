---
layout: math
title: 任意多項式根的 n 次方和
---

# 任意多項式根的 n 次方和

<br>

## 公式

根據代數基本定理，任意 \(k\) 次多項式都可寫成

$$
f(x)=a(x-\alpha_1)(x-\alpha_2)\cdots(x-\alpha_k).
$$

若定義根的 \(n\) 次方和為

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

由

$$
f(x)=a(x-\alpha_1)(x-\alpha_2)\cdots(x-\alpha_k)
$$

兩邊取對數，可得

$$
\ln f(x)
=
\ln a+\ln(x-\alpha_1)+\ln(x-\alpha_2)+\cdots+\ln(x-\alpha_k).
$$

對上式兩邊微分，利用

$$
(\ln g(x))'=\frac{g'(x)}{g(x)}
$$

可得

$$
\frac{f'(x)}{f(x)}
=
\frac{1}{x-\alpha_1}
+
\frac{1}{x-\alpha_2}
+\cdots+
\frac{1}{x-\alpha_k}.
$$

接著將每一項改寫成關於 \(\frac{1}{x}\) 的形式：

$$
\frac{1}{x-\alpha_i}
=
\frac{1}{x\left(1-\frac{\alpha_i}{x}\right)}
=
\frac{1}{x}\cdot\frac{1}{1-\frac{\alpha_i}{x}}.
$$

因此

$$
\frac{f'(x)}{f(x)}
=
\frac{1}{x}
\left(
\frac{1}{1-\frac{\alpha_1}{x}}
+
\frac{1}{1-\frac{\alpha_2}{x}}
+\cdots+
\frac{1}{1-\frac{\alpha_k}{x}}
\right).
$$

再利用等比級數展開

$$
\frac{1}{1-t}=1+t+t^2+t^3+\cdots
\qquad (|t|<1),
$$

令 \(t=\frac{\alpha_i}{x}\)，則

$$
\frac{1}{1-\frac{\alpha_i}{x}}
=
1+\frac{\alpha_i}{x}+\frac{\alpha_i^2}{x^2}+\frac{\alpha_i^3}{x^3}+\cdots.
$$

代回上式：

$$
\begin{aligned}
\frac{f'(x)}{f(x)}
&=
\frac{1}{x}
\sum_{i=1}^k
\left(
1+\frac{\alpha_i}{x}+\frac{\alpha_i^2}{x^2}+\frac{\alpha_i^3}{x^3}+\cdots
\right) \\
&=
\frac{1}{x}
\left[
\sum_{i=1}^k 1
+
\frac{1}{x}\sum_{i=1}^k \alpha_i
+
\frac{1}{x^2}\sum_{i=1}^k \alpha_i^2
+
\frac{1}{x^3}\sum_{i=1}^k \alpha_i^3
+\cdots
\right].
\end{aligned}
$$

依照 \(S_n\) 的定義，

$$
S_0=\sum_{i=1}^k 1,\qquad
S_1=\sum_{i=1}^k \alpha_i,\qquad
S_2=\sum_{i=1}^k \alpha_i^2,\qquad
\ldots
$$

所以最後得到

$$
\frac{f'(x)}{f(x)}
=
\frac{S_0}{x}
+
\frac{S_1}{x^2}
+
\frac{S_2}{x^3}
+\cdots.
$$

證畢。