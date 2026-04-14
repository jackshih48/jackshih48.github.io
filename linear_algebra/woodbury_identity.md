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

當 $C=I, U=\mathbf{u}, V=\mathbf{v}^T$ 時，可簡化為 Sherman-Morrison 公式:

$$
(A+\mathbf{u}\mathbf{v}^T)^{-1} = 
A^{-1} - \frac{A^{-1}\mathbf{u}\mathbf{v}^TA^{-1}}{I + \mathbf{v}^TA^{-1}\mathbf{u}}.
$$
<br>

## 證明

Lemma (Push-through identity, 穿透律) :

$$
\begin{aligned}
V(I + UV) &= (I + VU)V \\
V(I + UV)^{-1} &= (I + VU)^{-1}V
\end{aligned}
$$

也就是 $V$ 穿過後，$UV$ 變 $VU$。
此性質由矩陣乘法分配律可證:

$$
V(I + UV) = (I + VU)V = V + VUV
$$

並且左右同乘反矩陣可得

$$
V(I + UV)^{-1} = (I + VU)^{-1}V
$$

<br>

接著利用此引理完成 Woodbury 恆等式的證明：

$$
\begin{aligned}
A^{-1} &= (A+UCV)^{-1} (A+UCV) A^{-1} \\
&= (A+UCV)^{-1} (I + UCVA^{-1}) \\
&= (A+UCV)^{-1} + (A+UCV)^{-1}UCVA^{-1}\\
&= (A+UCV)^{-1} + \big[ A(I + A^{-1}UCV) \big]^{-1} UCVA^{-1} \\
&= (A+UCV)^{-1} + (I + A^{-1}UCV)^{-1} A^{-1} UCVA^{-1} \\
&= (A+UCV)^{-1} + A^{-1}U (I + CVA^{-1}U)^{-1} CVA^{-1} \quad \text{(使用穿透律)} \\
&= (A+UCV)^{-1} + A^{-1}U \big[ C^{-1}(I + CVA^{-1}U) \big]^{-1} VA^{-1} \\
&= (A+UCV)^{-1} + A^{-1}U(C^{-1} + VA^{-1}U)^{-1}VA^{-1}
\end{aligned}
$$

因此

$$
(A+UCV)^{-1} = A^{-1} - A^{-1}U(C^{-1} + VA^{-1}U)^{-1}VA^{-1}.
$$