# Subsequência comum máxima - LCS (Longest Common Subsequence)

Um problema clássico de programação dinâmica é o de encontrar subsequências comuns máximas. Vamos primeiro entender o que é uma subsequência:

```
⟨z1,...,zk⟩ é subsequência de ⟨x1,...,xm⟩ se existem índices i1 < ··· < ik tais que
z1 = xi1 . . . zk = xik
```

Por exemplo: <5, 9, 2, 7> é uma subsequência de <9, 5, 6, 9, 6, 2, 7, 3> e <A, A, D, A, A> é subsequência de <A, B, R, A, C, A, D, A, B, R, A>.

## Subsequência simples

Com essa definição, vamos abordar um primeiro problema envolvendo essas subsequências:

```
Como decidir se Z[1...m] é uma subsequência de X[1...n]?
```

### Solução

```C++
boolean is_subsequence(string Z, int m, string X, int n) {
    int i = m;
    int j = n;

    while(i >= 1 && j >= 1) {
        if (Z[i] == X[j]) i--;
        j--;
    }

    (i >= 1) ? return false : return true;
}
```

## Subsequência Comum Máxima

Podemos definir Z como uma subsequência _comum_ de X e Y se _Z é subsequência de X e de Y_. A subsequência comum **máxima** de X e Y é uma subsequência Z de comprimento máximo entre as que podemos formar. Por exemplo:

- X = A B C B D A B
- Y = B D C A B A

Temos ao menos duas subsequências Z que são máximas: `B C A B` e `B D A B`.

Vamos tentar encontrar uma `subestrutura ótima` para o problema para entender como podemos resolver o problema como um todo à partir de soluções de subproblemas.

Suponhamos que Z[1...k] é um `subsequência comum máxima` de X[1...m] e Y[1...n]. Podemos notar que:

- Se `X[m] = Y[n]`, então Z[k] = X[m] = Y[n] e Z[1...k-1] é subsequência comum máxima de X[1...m-1] e Y[1...n-1];
- Se `X[m] != Y[n]`, então Z[k] != X[m] implica que Z[1...k] é subsequência comum máxima de X[1...m-1] e Y[1...n];
- Se `X[m] != Y[n]`, então Z[k] != Y[n] implica que Z[1...k] é subsequência máxima de X[1...m] e Y[1...n-1].

Pronto, encontramos a subestrutura ótima do problema! Vamos analizando sequências comuns cada vez menores até chegar em uma base, que seria a primeira letra em comum entre X e Y. Logo, podemos definir uma recorrência para resolver o problema.

Vamos primeiro simplificar o problema para:

```
Dadas duas sequências X[1...m] e Y[1...n], encontre o COMPRIMENTO
de uma subsequência comum máxima.
```

### Solução

Seja `c[i, j] = comprimento de uma LCS de X[1...i] e Y[1...j]`. Vale a seguinte recorrência:

- `c[0, j] = c[i, 0] = 0`;
- `c[i, j] = c[i-1, j-1] + 1`, se X[i] = Y[j];
- `c[i, j] = max{ c[i, j-1], c[i-1, j] }`, se X[i] != Y[j].

Agora podemos facilmente implementar essa recursão usando C++:

```C++
int lcs (string X, int i, string Y, int j) {
    if (i == 0 || j == 0) return 0;

    if (X[i] == Y[j]) return lcs(X, i-1, Y, j-1) + 1;

    else
        return max( lcs(X, i-1, Y, j), lcs(X, i, Y, j-1) );
}
```

Fazendo uma análise mais detalhada, chegamos que o consumo de tempo desse algoritmo é O(2^min{m, n}).

## Programação Dinâmica

Agora que já conhecemos todas as características relevantes do problema e já encontramos uma recorrência que resolve o que queremos, basta otimizar esse algoritmo, já que um algoritmo que consome tempo exponencial não é muito útil.

Vamos pensar em como resolver cada subproblema de encontrar uma subsequência comum máxima de X[1...i] e Y[1...j] apenas _uma_ vez.
Como sempre, a maior dúvida é: "Qual a melhor ordem para se calcular as soluções?".

### Solução

Quais subproblemas precisamos para saber a resposta de `c[4, 6]`, por exemplo? Bom, lembrando da recursão que encontramos, vamos precisar saber os valores de `c[4, 5]`, `c[3, 6]` e `c[3, 5]`. Se pensarmos em preecher uma tabela, podemos ver que precisamos calcular todos os `c[i, j]` com `i = 1` e `j = 0, 1, 2, ..., n`, depois todos os `i = 2` e `j = 0, 1, 2, ..., n`, depois todos com `i = 3` e `j = 0, 1, ..., n`, e por aí vai...

Agora que já sabemos como preencher a tabela e sabemos a recursão que resolve o problema, basta escrever o código:

```C++
int lcs(string X, int m, string Y, int n) {
    for (int i = 0; i <= m; i++) c[i][0] = 0;
    for (int j = 0; j <= n; j++) c[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i] == Y[j]) c[i][j] = c[i-1, j-1] + 1;
            else c[i][j] = max( c[i-1, j], c[i, j-1] );
        }
    }

    return c[m, n];
}
```

Quanto ao consumo de tempo do algoritmo usando programação dinâmica, fica fácil chegar em O(m \* n);
