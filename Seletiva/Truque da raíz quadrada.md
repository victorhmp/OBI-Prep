# Truque de divisão em buckets de tamanho sqrt(n)

O truque de dividir um vetor em buckets de tamanho sqrt(n) é especialmente útil em problemas envolvendo queries de consultas e updates, os mesmos em que consideramos o uso de segment trees e BITs.

A ideia é bem simples, dado que temos um vetor de `n` elementos, definimos `k = sqrt(n)`. Agora se particionarmos o vetor em `k` pedaços de tamanho `k`, podemos realizar diversas operações com consumo de tempo `O(sqrt(n))`.

## Exemplo

Vamos aplicar o truque em um problema muito conhecido:

```
Dado um vetor A de n elementos, implemente uma estrutura de dados que seja capaz de realizar operações de 

- Atualização pontual
- Consulta da soma de um intervalo (lo, hi)
```

Este problema pode ser resolvido de algumas maneiras, mas vamos utilizá-lo como exemplo para ilustrar que o simples particionamento do vetor é simples de implementar e otimiza a solução trivial.

Para melhorar a solução trivial, que utiliza apenas um vetor para atulizações em tempo `O(1)` e consultas em tempo `O(hi - lo) = O(n)`, basta pensarmos em dividir o vetor dado em intervalos de tamanho `sqrt(n)` e guardar a soma de seus elementos em um segundo vetor `s`, onde `s[i] = soma dos elementos no i-ésimo intervalo`.

Com isso, conseguimos manter o consumo de tempo _constante_ de atualizar o valor de um elemento no vetor dado, pois basta mudar diretamente seu valor e atualizar o valor de `s[i]`, onde i é o indice do intervalo em que o elemento faz parte.

Para operações de consulta, os elementos que estão no último e no primeiro "pedaço" do intervalo (parcialmente contidos) necessáriamente vão ser percorridos um a um, mas para "pedaços" internos ao intervalo da consulta, basta utilizar diretamente o valor armazenado em `s`, assim reduzindo o consumo de tempo.

Por exemplo:

```
A = [1, 2, 0, 7, 4, 2, 5, 0, 1, 3, 1, 4, 5, 2, 0, 1]
    |          |           |           |           |
S = [    10    ,     11    ,    9      ,     8     ]
```

Se a operação a ser feita é: `query(2, 14)`

```
query(2, 14) = A[2] + A[3] + 
               (A[4] + A[5] + A[6] + A[7]) +
               (A[8] + A[9] + A[10] + A[11]) +
               A[12] + A[13] + A[14]
             = A[2] + A[3] +
               S[1] + S[2] +
               A[12] + A[13] + A[14]
             = 0 + 7 + 11 + 9 + 5 + 2 + 0
             = 34
```

A implementação destas funções em C++ fica a seguinte:

```c++
void update(const vector<int> &S, const vector<int> &V, int i, int k, int x) {
  S[i/k] -= (A[i] + x);
  A[i] = x;
}

int query(const vector<int> &S, const vector<int> &V, int l, int r, int k) {
  int sum = 0;
  int i = l;

  while((i + 1) % k != 0 && i <= r) {
    sum += A[i];
    i++;
  }

  while(i + k <= r) {
    sum += S[i/k];
    i += k;
  }

  while(i <= r) {
    sum += A[i];
    i++;
  }

  return sum;
}
```

Cada operação de `query` consome em média tempo `k/2 + n/k + k/2 = k + n/k`. Essa soma é minimizada quando `k = sqrt(n)`! Assim, conseguimos consultas que consomem tempo `O(sqrt(n))`.

Esse mesmo truque também pode ser usado para outras operações associativas como: `min()`, `mdc` e `produto do intervalo`.

## Por que utilizar o "truque"?

Os problemas em que podemos aplicar esse truque da divisão em buckets de tamanho sqrt(n) normalmente podem ser resolvidos de outras maneiras, às vezes mais eficientes, porém podem ser mais difíceis de implementar. Esse truque nos fornece um bom balanço de complexidade na implementação e ganho no consumo de tempo do algoritmo utilizado.