---
title: 'Resumo: Recorrências lineares'
date: 2024-05-24 23:37:02
tags:
---

## Polinômio característico

Uma recorrência linear na forma:

$f(n) = a_1 \cdot f(n-1) + a_2 \cdot f(n-2) + \cdots + a_k \cdot f(n - k)$

tem o seguinte polinômio característico:

$X^k = a_1 \cdot X^{k-1} + a_2 \cdot X^{k-2} + \cdots + a_{k-1} \cdot X^1 + a_k \cdot X^0$

## Fórmula fechada

Dado uma recorrência linear com polinômio característico igual a:

$(X - r_1)(X - r_1)(X - r_2)(X - r_3) = 0$

tem fórmula fechada na forma:

$f(n) = c_1 \cdot r_1^n + c_2 \cdot n \cdot r_1^n + c_3 \cdot r_2^n + c_4 \cdot r_3^n $

## Truque da soma acumulada de Fibonacci

Seja  $$f(n) = \begin{cases}  n, & \text{se  $n \le 1$}\\\\  f(n-1) + f(n-2), & \text{caso contrário} \end{cases}$$

A partir do fato que $f(n-2) = f(n) - f(n-1)$ é o mesmo que $f(n) = f(n + 2) - f(n+1)$

Podemos calcular $s(n) = f(0) + f(1) + \dots + f(n)$, através da seguinte soma telescópica:

$f(0) = f(2) - f(1)$

$f(1) = f(3) - f(2)$

$f(2) = f(4) - f(3)$​

​              $\cdots$

$f(n-1) = f(n+1) - f(n)$

$f(n) = f(n+2) - f(n+1)$

Somando essas igualdades temos:

$f(0) + f(1) + \cdots + f(n-1) + f(n) = \Big(f(2) - f(1)\Big) + \Big(f(3) - f(2)\Big)  + \cdots + \Big( f(n+1) - f(n) \Big) + \Big( f(n+2) - f(n+1)\Big)$

$s(n) = -f(1) + f(n+2)$

$s(n) = f(n + 2) - f(1)$

## Problemas para praticar

- [BEE 3413 - Baita Desafio Complexo - Beecrowd](https://judge.beecrowd.com/pt/problems/view/3413)

### **Solução:** 

Em resumo, nesse problema a parte principal de sua solução é aplicar os truques (1) e (2) ao contrário, ou seja, a partir de uma fórmula fechada encontrar a recorrência linear correspondente, uma vez que temos essa recorrência linear podemos computá-la em um ponto específico rapidamente usando exponenciação de matrizes (usando exponenciação binária) e para computar sua soma acumulada arrematamos o problema usando o truque (3). A seguir uma descrição mais detalhada.

A partir do truque (2) podemos notar que $f(n)$ do problema tem o formato de uma recorrência linear igual a:

$$f(n) = c_1 \cdot {\Big(\dfrac{1 + R}{2}\Big)}^n +  c_2 \cdot {\Big(\dfrac{1 - R}{2}\Big)}^n$$

que por sua vez tem polinômio característico igual:

$\Big(X - \Big(\dfrac{1 + R}{2}\Big)\Big)\Big(X - \Big(\dfrac{1 - R}{2}\Big)\Big) = 0$

expandindo essa equação temos:

$$ \Big(X - \Big(\dfrac{1 + R}{2}\Big)\Big)\Big(X - \Big(\dfrac{1 - R}{2}\Big)\Big) = X^2 - X \Big(\dfrac{1 - R}{2}\Big) - \Big(\dfrac{1 + R}{2}\Big) X  + \Big(\dfrac{1 + R}{2}\Big) \Big(\dfrac{1 - R}{2}\Big) = $$

$= X^2 - X\Big(\dfrac{1 - R + 1 + R}{2}\Big) + \dfrac{1 - R^2}{4} = X^2 - X + \dfrac{1 - (i\cdot\sqrt{4T - 1})^2}{4} = X^2 - X  + \dfrac{1 -(-1 \cdot (4T - 1))}{4} = $

$= X^2 - X + T = 0$

que colocando no formato $X^2 = X^1 - T \cdot X^0$ evidencia que podemos aplicar o truque (1) para descobrir que $f(n)$ tem a forma:

$f(n) = f(n - 1) - T \cdot f(n - 2)$

Para nossa instância podemos verificar que $f(0) = 0$ e $f(1) = 1$, desse modo temos que $f(n)$ como descrito no enunciado é o mesmo que:

$$f(n) = \begin{cases} n , & \text{se } n \le 1\\\\ f(n - 1) - T \cdot f(n - 2), & \text{caso contrário}\end{cases}$$

que pode ser computada através da seguinte transformação linear em $O(\log{n})$ usando exponenciação binária:

$$ \begin{bmatrix}
f(n) \\\\
f(n-1)
\end{bmatrix} = \begin{bmatrix}
1 & -T \\\\
1 & 0
\end{bmatrix} \begin{bmatrix}
f(n-1)  \\\\
f(n-2)
\end{bmatrix}$$

$$ \begin{bmatrix}
f(n) \\\\
f(n-1)
\end{bmatrix} = \begin{bmatrix}
1 & -T \\\\
1 & 0
\end{bmatrix}^{n-1} \begin{bmatrix}
f(1)  \\\\
f(0)
\end{bmatrix}, \text{onde } n \ge 2$$

Por fim, para computar $s(n) = f(0) + f(1) + \dots + f(n)$ podemos aplicar o truque (3) da seguinte maneira:

A partir do fato que $-T \cdot f(n-2) = f(n) - f(n-1)$ é o mesmo que $-T \cdot f(n) = f(n + 2) - f(n+1)$

Podemos encontrar $s(n)$ através da seguinte soma telescópica:

$-T \cdot f(0) = f(2) - f(1)$

$-T \cdot f(1) = f(3) - f(2)$

$-T \cdot f(2) = f(4) - f(3)$

​              $\cdots$

$-T \cdot f(n-1) = f(n+1) - f(n)$

$-T \cdot f(n) = f(n+2) - f(n+1)$

Somando essas igualdades temos:

$-T \cdot \Big(f(0) + f(1) + \cdots + f(n-1) + f(n) \Big) = \Big(f(2) - f(1)\Big) + \Big(f(3) - f(2)\Big)  + \cdots + \Big( f(n+1) - f(n) \Big) + \Big( f(n+2) - f(n+1)\Big)$

$-T \cdot s(n) = -f(1) + f(n+2)$

$s(n) = \dfrac{f(n + 2) - f(1)}{-T}$

$\blacksquare$

#### Código

A seguir o código do problema, omitindo o código da [exponenciação de matrizes](https://github.com/pedrov3/competitive-programming-notebook/blob/main/expmatrix.cpp), [exponenciação binária](https://github.com/pedrov3/competitive-programming-notebook/blob/main/expbin.cpp) e o restante do [template](https://github.com/pedrov3/competitive-programming-notebook/blob/main/templates/cpp.cpp).

```c++
signed main(){
    cin.tie(0)->sync_with_stdio(0);

    int t, m;
    cin >> t >> m;

    auto f = [&](int n){
        if (n <= 1) return n;
        Matrix base({{1, -t}, {1, 0}});
        auto retval = expbin(base, n - 1);
        return retval[0][0];
    };

    auto s = [&](int n){
        // inverso modular através do 'Fermat's little theorem';
        return (f(n + 2) - f(1)) * expbin(-t, P - 2) 
    };

    vi a(m);
    cin >> a;
    int l = *max_element(all(a));
    int ans = s(l);
    for (auto &x: a){
        ans -= f(x);
        ans %= P;
        ans += P;
        ans %= P;
    }
    cout << ans << "\n";
}
```

## Referências

- [Notas de aula de recorrências lineares do Profº Leandro Zatesko](https://pessoal.dainf.ct.utfpr.edu.br/zatesko/icsd21.html#:~:text=AULA%206%3A%20Recorr%C3%AAncias%20lineares)
- [Oficina {28set,9nov}22: Upsolving da 1ª Fase Zero da Maratona de Programação da SBC - A partir de 2 hr 59 min 47 seg](https://youtu.be/C1uwYwjYqdE?si=5NTejm-K9_rcsE3L&t=10787)
