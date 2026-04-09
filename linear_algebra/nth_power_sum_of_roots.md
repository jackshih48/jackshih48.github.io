---
layout: math
title: 任意多項式根的n次方和
---

# 任意多項式根的n次方和

<br>

## 公式

根據代數基本定理，任意k次多項式皆可表達成以下形式:

$$
f(x) = a(x-\alpha_1)(x-\alpha_2) \dots (x-\alpha_k)
$$

若想求根的n次方和 $S_n$ ，也就是

$$
S_n = \alpha_1^n + \alpha_2^n + \dots + \alpha_k^n
$$

可利用下述公式求得:

$$
\boxed{
\frac{f'(x)}{f(x)} = \frac{S_0}{x} + \frac{S_1}{x^2} + \frac{S_2}{x^3} + \dots
} 
$$

<br>

## 證明

首先微分關係式 $(\ln x)' = \frac{1}{x}$ 可如下證明:

$$
1 = (x)' = (e^{\ln x})' = (e^{\ln x})(\ln x)' = x (\ln x)'.
$$

接著對原多項式取 $\ln$ 並微分:

$$
\begin{algined}
(\ln f(x))' = (\ln a + \ln(x-\alpha_1) + \ln(x-\alpha_2) + \dots + \ln(x-\alpha_k))' \\
\frac{f'(x)}{f(x)} = \frac{1}{x-\alpha_1} + \frac{1}{x-\alpha_2} + \dots \frac{1}{x-\alpha_k} \\
\frac{f'(x)}{f(x)} = \frac{1}{x} (\frac{1}{1-\alpha_1 / x} + \frac{1}{1-\alpha_2 / x} + \dots \frac{1}{x-\alpha_k  / x}) \\
\frac{f'(x)}{f(x)} = \frac{1}{x} ((1 + \frac{\alpha_1 / x} + \frac{\alpha_1^2 / x^2} + \dots) + (\dots) + \dots) \\
\frac{f'(x)}{f(x)} = \frac{S_0}{x} + \frac{S_1}{x^2} + \frac{S_2}{x^3} + \dots
\end{algined}
$$

