---
layout: math
title: 二次曲線的切線方程式
---

# 二次曲線的切線方程式

## 公式

二次曲線圖形包括拋物線、橢圓、雙曲線，以及它們的旋轉。  
代數式皆可表示成如下的形式：

$$
ax^2 + bxy + cy^2 + dx + ey + f = 0
$$

若我們想求這個二次曲線圖形過點 $P(x_0, y_0)$ 的切線方程式，透過「兩個變數，一個不變，一個代點」的代換口訣可以快速得到。具體代換規則如下：

$$
\begin{aligned}
x^2 &\rightarrow x_0x \\
y^2 &\rightarrow y_0y \\
xy  &\rightarrow \frac{x_0y + xy_0}{2} \\
x   &\rightarrow \frac{x + x_0}{2} \\
y   &\rightarrow \frac{y + y_0}{2}
\end{aligned}
$$

因此，任意二次函數在點 $P(x_0, y_0)$ 的切線方程式為

$$
axx_0 + b\frac{x_0y + xy_0}{2} + cyy_0 + d\frac{x + x_0}{2} + e\frac{y + y_0}{2} + f = 0
$$

## 證明

若想求 $f(x, y)$ 的切線方程式，我們需先對函數微分，求此函數的斜率方程式：

$$
\begin{aligned}
(ax^2 + bxy + cy^2 + dx + ey + f)' &= (0)' \\
2ax + by + bxy' + 2cyy' + d + ey' &= 0 \\
y'(bx + 2cy + e) &= -2ax - by - d \\
y' &= -\frac{2ax + by + d}{bx + 2cy + e}
\end{aligned}
$$

因此，在點 $P(x_0, y_0)$ 的斜率為：

$$
y' = -\frac{2ax_0 + by_0 + d}{bx_0 + 2cy_0 + e}
$$

所以切線方程式為

$$
y - y_0 = y'(x - x_0)
$$

化簡：

$$
\begin{aligned}
(y - y_0)(bx_0 + 2cy_0 + e) &= -(2ax_0 + by_0 + d)(x - x_0) \\
y(bx_0 + 2cy_0 + e) + x(2ax_0 + by_0 + d) &= y_0(bx_0 + 2cy_0 + e) + x_0(2ax_0 + by_0 + d) \\
y(bx_0 + 2cy_0 + e) + x(2ax_0 + by_0 + d) &= 2ax_0^2 + 2bx_0y_0 + 2cy_0^2 + dx_0 + ey_0
\end{aligned}
$$

由於點 $P(x_0, y_0)$ 在曲線上，我們有條件式：

$$
ax_0^2 + bx_0y_0 + cy_0^2 + dx_0 + ey_0 + f = 0
$$

所以切線方程式可以改寫成：

$$
\begin{aligned}
y(bx_0 + 2cy_0 + e) + x(2ax_0 + by_0 + d) + dx_0 + ey_0 + 2f &= 0 \\
2axx_0 + b(xy_0 + x_0y) + 2cyy_0 + d(x + x_0) + e(y + y_0) + 2f &= 0 \\
axx_0 + b\frac{x_0y + xy_0}{2} + cyy_0 + d\frac{x + x_0}{2} + e\frac{y + y_0}{2} + f &= 0
\end{aligned}
$$

得證。

## 例子

一個開口向右的拋物線 $x = ay^2$ 的切線方程式為（若 $P(x_0, y_0)$ 在拋物線上）：

$$
\frac{x + x_0}{2} = ayy_0
$$

圓 $x^2 + y^2 = r^2$ 的切線方程式為（若 $P(x_0, y_0)$ 在圓上）：

$$
xx_0 + yy_0 = r^2
$$

## 延伸討論

- 若點 $P(x_0, y_0)$ 是平面上的任意點，用此公式必定可求得一直線，稱作極線，P點則是極點。
- 當極點在曲線上，極線就是切線。
- 當極點在曲線外，極線就是切點弦(過極點與二次曲線相交的兩切線交點的連線)。
- 當極點在曲線內，所有過極點的直線與二次曲線有兩交點，這兩點上的切線可求得另一交點，
這些交點會在一直線上，稱作極線。