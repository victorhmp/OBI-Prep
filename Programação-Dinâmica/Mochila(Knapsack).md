# Problema da Mochila (Knapsack Problem)

Vamos estudar um problema clássico de programação dinâmica, o problema da mochila (Knapsack Problem), que representa uma classe inteira de problemas que podem ser resolvidos usando a ideia que vamos aprender.

Uma versão simplificada do enunciado do problema é a seguinte:

```
Dada uma mochila de capacidade máxima limitada W e um conjunto de N itens, cada um
com seu valor e peso associado, preencha a mochila de maneira que o conteúdo dentro
dela tenha o maior valor total possível.
```

Vamos primeiro encontrar uma subestrutura ótima para o problema. Para cada possível solução do problema, temos definida uma _mochila booleana_, ou seja, um vetor x[1...n] tal que x[i] = 0 ou x[i] = 1, para todo `1 ≤ i ≤ n`. Cada posição desse vetor representa "colocar" ou "não colocar" um elemento na mochila. O valor de cada item é dado por um vetor v[1...n] e o peso é dado por um vetor w[1...n]. Com isso, podemos definir o **valor** de uma mochila como o _produto escalar_ `x . v = x[1]v[1] + x[2]v[2] + ... + x[n]v[n]` e o peso total como `x . w = x[1]w[1] + ... + x[n]w[n] ≤ W`, ou seja, o peso total dos elementos que forem colocados na mochila não supera a sua capacidade.

Suponha que o problema seja completamente definido pelos valores (w[], v[], N, W). Se x[1...n] é uma _mochila booleana ótima_ para o problema com os parâmetros `(w[], v[], N, W)`, então:

- Se `x[n] = 1` => então x[1...n-1] é uma _mochila booleana ótima_ para `(w[], v[], N-1, W - w[n])`;
- Senão => x[1...n-1] é uma _mochila booleana ótima_ para `(w[], v[], N-1, W)`.

Podemos generalizar essas afirmações para um índice qualquer `i`.

Seja `t[i, Y] = valor de uma mochila booleana ótima para (w,v,i,Y)`, com Y = 0, 1, 2, ..., W. Podemos definir os valores de `t[]` de maneira recursiva:

- Casos base: `t[0, Y] = 0`, para todo `Y`. `t[i, 0] = 0`, para todo `i`;
- `t[i, Y] = t[i−1, Y]` se `w[i] > Y`;
- `t[i, Y] = max { t[i−1, Y], t [i−1, Y−w[i]] + v[i] }` se `w[i] ≤ Y`.

Essa recursividade encontrada resolve o problema! Note que para cada elemento que temos disponível, fazemos uma **escolha** entre coloca-lo ou não na mochila. Podemos facilmente escrever essa recursão em C++:

```C++
int knapsack(int cap, int n) {
  if (n == 0 || cap <= 0) return 0;

  if (weight[n - 1] > cap)
    return knapsack(cap, n - 1);

  else {
    int including = val[n - 1] + knapsack(cap - weight[n - 1], n - 1);
    int not_including = knapsack(cap, n - 1);

    return max(including, not_including);
  }
}
```

Analisando esse algoritmo, chegamos em um consumo de tempo O(2^n).

## Usando Programação Dinâmica

Na solução recursiva, estamos calculando o mesmo subproblema várias vezes. Vamos usar a técnica de Programação Dinâmica para resolve-los apenas **uma** vez. O problema principal é `Em que ordem calcular?`.

Pensando na recorrência:

- `t[i, Y] = t[i−1, Y]` se `w[i] > Y`;
- `t[i, Y] = max { t[i−1, Y], t [i−1, Y−w[i]] + v[i] }` se `w[i] ≤ Y`.

Vemos que uma boa ideia é preencher a tabela `t[][]` em `linhas horizontais, de cima para baixo`.

Com isso, temos tudo o que precisamos para implementar o algoritmo de programação dinâmica em C++ que resolve o problema:

```C++
int knapsack(int w[], int v[], int n, int W) {
  for (int y = 0; y <= W; y++) {
    t[0][y] = 0;

    for (int i = 0; i <= n; i++) {
      int a = t[i -1][y];
      int b = 0;

      if (w[i] > y)
        b = 0;
      else
        b = t[i − 1][y − w [i]] + v [i];

      t[i][y] = max (a, b);
    }
  }

  return t[n][W];
}
```

Com essa implementação a análise é muito mais simples, sendo fácil chegar em um consumo de tempo O(n\*W).
