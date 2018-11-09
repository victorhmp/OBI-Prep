# Árvore de Indexação Binária (BIT) ou Árvore de Fenwick

Vamos estudar uma estrutura de dados bem específica que pode ser cobrada em provas de competição competiva, as `BIT`s. Para entender a motivação por trás de seu uso e sua idealização por Peter M. Fenwick para ser utilizada em aplicações de compressão de dados, vamos considerar o seguinte problema:

```
Temos N caixas que podem ser submetidas às seguintes operações:

- Adicionar item à caixa i
- Retornar a soma de itens nas caixas de k,...,l.

Como podemos implementar essas operações?
```

## Abordagens "ingênuas"

### Implementação direta

Logo de cara, podemos implementar facilmente funções `add(i, x)`, que adiciona x itens à caixa i, e `sum_interval(k, l)`, que calcula a soma dos elementos contidos nas caixas k,...,l.

Vamos representar as N caixas como sendo índices de um vetor C de tamanho N, onde `C[i] = número de itens dentro da caixa i`. Assim, uma função `add(i, x)` consome tempo `O(1)`, já que basta atualizar um valor em um vetor. Já a função `sum_interval(k, l)` teria consumo de tempo `O(n)`.

Num primeiro momento, esse consumo de tempo parece razoável, mas o problema é quando precisamos realizar `m` operações sobre o vetor. Num cenário de pior caso, gastaríamos tempo `O(N * m)`, o que já pode deixar de ser ideal dependendo da ordem de grandeza de `m` em relação à N. Imagine fazer 10.000 operações alternadas em um vetor de 100.000 elementos...

### Vetor de soma acumulada

## Solução com BITs

Agora vamos aprender como resolver esse problema obtendo um consumo de tempo de pior caso `O(m * lg N)`, utilizando BITs.

Para esta implementação, vamos utilizar um segundo vetor que irá representar nossa árvore, logo se chamará `tree[1...N]`. Agora, sendo `p(k) = maior potência de 2 que divide k`, vamos armazenar na árvore:

```
tree[k] = soma de todas as caixas indo da posição (k - p(k)) até k
```

Isso quer dizer que cada posição `k` do vetor `tree` contem a soma de um intervalo de tamanho `p(k)` que termina na posição `k`. Por exemplo:

```
C = [1, 3, 4, 8, 6, 1, 4, 2]

tree = [1, 4, 4, 16, 6, 7, 4, 29]

```

Vemos que, por exemplo, `sum(1, 7) = tree[7] + tree[6] + tree[4]`, escrevendo os índices usando base 2, fica bem claro as operações que estamos fazendo: `sum(111) = sum(111) + (110) + sum(100)`. Nota-se que estamos sempre "apagando" o último bit 1 do número em sua forma binária. É com essa observação que podemos implementar a operação `sum_interval(k)`:

```c++
int sum_interval(int k) {
  int sum = 0;
  while(k > 0) {
    sum += tree[k];
    k -= (k & -k); // remover o bit menos significante
  }

  return sum;
}
```

Essa implementação nos garante consumo de tempo `O(lg N)`.

Para implementar a operação `add(x, i)`, pensamos de maneira análoga: Se atulizamos o valor de uma caixa, precisamos atualizar todas as outras caixas que são utilizadas na construção de uma consulta de soma que terminan nela. Logo, a implementação faz o processo inverso:

```c++
void add(int x, int i) {
  while(i <= N) {
    tree[i] += x;
    i += (x & -x);
  }
}
```

Novamente podemos garantir consumo de tempo no pior caso de `O(lg N)`.

