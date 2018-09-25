# Programação Dinâmica

Como uma boa definição de o que é Programação Dinâmica, uma citação de I. Parberry, Problems on Algorithms, Prentice Hall, 1995:

```quote
"Dynamic programming is a fancy name for divide-and-conquer with a table. Instead of solving subproblems recursively, solve them sequentially and store their solutions in a table. The trick is to solve them in the right order so that whenever the solution to a subproblem is needed, it is already available in the table. "
```

De maneira geral, podemos tratar a tecnica de programação dinâmica como uma "melhora" na tecnica da divisão e conquista, onde utilizamos uma alternativa à maneira recursiva de resolver problemas natural da divisão e conquista, a resolução iterativa com auxílio de uma tabela para guardar soluções dos subproblemas que naturalmente podem ser úteis para resolver o problema "maior".
Se resolvermos os subproblemas de maneira "esperta", podemos melhorar muito a eficiência de nossas soluções.

## Sequência de Fibonacci

Um exemplo muito simples de como uma solução que utiliza a ideia de programação dinâmica melhora muito a eficiência do algoritmo é evidente quando consideramos o problema: `` Dado um inteiro `n`, determine o n-ésimo termo da sequência de Fibonacci. ``

A sequência de Fibonacci é definida como o seguinte:

```
Fibonacci(0) = 0;
Fibonacci(1) = 1;
Fibonacci(2) = Fibonacci(1) + Fibonacci(0)
.
.
.
Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
```

Podemos facilmente notar a natureza recursiva dessa definição, e não é difícil pensar em uma função simples que resolva o nosso problema com C++.

```c++
int fibo(int n) {
  if (n <= 1) return n;
  return fibo(n - 1) + fibo(n - 2);
}
```

Se analizarmos o consumo de tempo desse algoritmo, chegamos em O(2^n). Para cada valor da sequência, estamos recalculando todos os valores anteriores.

Resolvendo o mesmo programa utilizando a idea de Programação dinâmica, podemos representar a mesma definição resursiva de maneira iterativa:

```C++
long long int fibo_seq[110];
int n;

int fibo(int n) {
  fibo_seq[0] = 0;
  fibo_seq[1] = 1;
  for (int i = 2; i <= n; i++) {
    fibo_seq[i] = fibo_seq[i - 1] + fibo_seq[i - 2];
  }

  return fibo_seq[n];
}
```

Dessa vez é fácil verificar que o consumo de tempo é O(n), uma melhora significativa.

Nesse algoritmo, os subproblemas são os valores calculados para Fibonacci(i), sendo que apenas calculamos seu valor UMA vez e guardamos esses valores em um vetor.

## Corte de Hastes

Agora vamos analisar um problema cuja solução não é tão trivial e a recursão não é explicitamente definida:

```
Hastes de aço são vendidas em pedaços de tamanho inteiro. As usinas produzem hastes longas, e os comerciantes cortam em pedaços para vender. Suponha que o preço de uma haste de tamanho i esteja tabelado como p[i] .
Dada uma haste de tamanho n e a tabela p de preços, qual a melhor forma de cortar a haste para maximizar o preço de venda total?
```

### Solução (Trivial)

Vamos considerar `q[n] = valor máximo que pode ser obtido com uma haste de tamanho n`.

Vamos fazer um corte de tamanho `i`. O pedaço restante tem tamanho `n - i`, vamos cortá-lo da melhor maneira possível. Assim, sabemos que o valor **total** dessa configuração de cortes é de `p[i] + q[n - i]`. Podemos escrever a solução do problema como o problema de encontrar _qual o melhor valor de i_, ou seja: `q[n] = max(1 <= i <= n){p[i] + q[n - i]}, q[0] = 0`. Agora sim temos uma recursão!

Essa recursão agora é trivial de ser implementada em C++:

```c++
int solve(int p[], int n) {
  if (n = 0) return 0;

  q = -INF;

  for (int i = 1; i <= n; i++) {
    q = max(q, p[i] + solve(p, n - i));
  }

  return q;
}
```

Se analizarmos esse algoritmo que apenas implementa diretamente a recursão, vamos chegar em seu consumo de tempo O(2^n).

### Solução (Programação Dinâmica)

Agora, vamos pensar em resolver esse mesmo problema utilizando Programação Dinâmica. Vale notar que a recursão que encontramos até agora **não** está errada e **não** é descartada, ela é _fundamental_ para resolver o problema.

Vamos usar um vetor auxiliar `r[]` que irá guardar na i-ésima posição o melhor valor possível para uma haste de tamanho `i`.

Em C++, temos algo do tipo:

```C++
int p[11234], r[11234], n;

int solve(int p[], int n) {
  int q;
  r[0] = 0;
  for (int j = 1; j <= n; j++) {
    q = -INF;
    for (int i = 1; i <= j; i++) {
      q = max(q, (p[i] + r[j - i]));
    }
    r[j] = q;
  }

  return q;
}
```

Esse algoritmo usando P.D. é trivial de analisar e chegar no consumo de tempo O(n^2).
