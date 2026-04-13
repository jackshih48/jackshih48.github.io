---
layout: math
title: Woodbury Identity
---

# Woodbury Identity

<br>

## 公式

對於任意的可逆方陣 $A,C$ ，若 $A+UCV$ 可逆，則有以下恆等式:

$$
f(x)=a(x-\alpha_1)(x-\alpha_2)\cdots(x-\alpha_k).
$$

<br>

## 證明

$$
\begin{aligned}
A^{-1} &= (A+UCV)^{-1} (A+UCV) A^{-1} \\
&= (A+UCV)^{-1} (I + UCVA^{-1}) \\
&= (A+UCV)^{-1} + (A+UCV)^{-1}UCVA^{-1}\\
&= (A+UCV)^{-1} + \big[ A(I + A^{-1}UCV) \big]^{-1} UCVA^{-1}} \\
&= (A+UCV)^{-1} + (I + A^{-1}UCV)^{-1} A^{-1} UCVA^{-1}} \\
&= (A+UCV)^{-1} + A^{-1}U (I + CVA^{-1}U)^{-1} CVA^{-1} \qquad \text{(使用穿透律：將 } A^{-1}U \text{ 穿透至左側)} \\
&= (A+UCV)^{-1} + A^{-1}U \big[ C^{-1}(I + CVA^{-1}U) \big]^{-1} VA^{-1}} \\
&= (A+UCV)^{-1} + A^{-1}U(C^{-1} + VA^{-1}U)^{-1}VA^{-1}.}
\end{aligned}
$$