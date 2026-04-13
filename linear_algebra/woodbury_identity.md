---
layout: math
title: Woodbury Identity
---

# Woodbury Identity

<br>

## 公式

對於任意的可逆方陣 $A,C$ ，若 $A+UCV$ 可逆，則有以下恆等式:

$$
(A+UCV)^{-1} = A^{-1} - A^{-1}U(C^{-1} + VA^{-1}U)^{-1}VA^{-1}.
$$

<br>

## 證明

Lemma(Push-through identity, 穿透律):

將下述等式

$$
V(I + UV) = V + VUV = (I + VU)V
$$

左右同乘反矩陣可得穿透律( $V$ 穿過後，$UV$ 變 $VU$ ):

$$
V(I + UV)^{-1} = (I + VU)^{-1}V
$$

接下來，我們利用此引理來展開 Woodbury 恆等式的證明：

$$
\begin{aligned}
A^{-1} &= (A+UCV)^{-1} (A+UCV) A^{-1} \\
&= (A+UCV)^{-1} (I + UCVA^{-1}) \\
&= (A+UCV)^{-1} + (A+UCV)^{-1}UCVA^{-1}\\
&= (A+UCV)^{-1} + \big[ A(I + A^{-1}UCV) \big]^{-1} UCVA^{-1} \\
&= (A+UCV)^{-1} + (I + A^{-1}UCV)^{-1} A^{-1} UCVA^{-1} \\
&= (A+UCV)^{-1} + A^{-1}U (I + CVA^{-1}U)^{-1} CVA^{-1} \qquad \text{(使用穿透律} \\
&= (A+UCV)^{-1} + A^{-1}U \big[ C^{-1}(I + CVA^{-1}U) \big]^{-1} VA^{-1} \\
&= (A+UCV)^{-1} + A^{-1}U(C^{-1} + VA^{-1}U)^{-1}VA^{-1}
\end{aligned}
$$

因此

$$
(A+UCV)^{-1} = A^{-1} - A^{-1}U(C^{-1} + VA^{-1}U)^{-1}VA^{-1}.
$$