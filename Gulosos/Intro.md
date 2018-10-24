# Algorítmos Gulosos (Greedy Algorithms)

A técnica chamada de _gulosa_ é de certa forma muito parecida com a ideia de programação dinâmica, e também é muito comum em problemas de _otimização_.

Um excelente quote sobre algoritmos gulosos, por `I. Parberry, Problems on Algorithms, Prentice Hall, 1995`:

```
A greedy algorithm starts with a solution to a very small subproblem and augments it successively to a solution for the big problem. 
The augmentation is done in a “greedy” fashion, that is, paying atention to short-term or local gain, without regard to whether it will lead to a good long-term or global solution. 
As in real life, greedy algorithms sometimes lead to the best solution, sometimes lead to pretty good solutions, and sometimes lead to lousy solutions.
The trick is to determine when to be greedy.
```

Basicamente, podemos resumir a ideia de um algoritmo guloso em, quando temos que fazer uma escolha, fazemos a **melhor** escolha dentre as que estamos diante _no momento_. Tomamos decisões ótimas _locais_ com a esperança de obter no final uma solução ótima **global**. 

Nem sempre algoritmos gulosos nos fornecem soluções ótimas, mas às vezes fornecem! Em geral são algoritmos fáceis de serem implementados, porém difícies de serem provados.

## Escalonamento de atividades

Vamos estudar um problema clássico em que um algoritmo guloso nos dá uma solução ótima mais eficientemento do que programação dinâmica.

```
Dadas n atividades que requerem uso exclusivo de um mesmo recurso comum, 
como n aulas que só podem ser dadas em uma sala de aula.
A i-ésima atividade está marcada para utilizar tal recurso durante o período [s[i], f[i]), onde
s[i] = tempo de início
f[i] = tempo de término

Seu trabalho é selecionar o maior conjunto de atividades não comporrentes possível. Também pode
ser visto como maior conjunto de intervalos disjuntos dois-a-dois.
```

### Solução

Primeiro, vamos definir quando duas atividades são compatíveis dois-a-dois: queremos uma coleção disjunta máxima de atividades _compatíveis_, ou seja, `i` e `j` são compatíveis => `f[i]` <= `s[j]`.

Com base nisso podemos escrever um primeiro pseudocódigo que poderia resolver o problema:

```
A = conjunto vazio
R = {1, ..., n} // conjunto de todos os intervalos

enquanto R != vazio faça:
  escolha por um critério guloso um intervalo i de R
  A = A + {i}
  R = R - {j pertence a R : j intersecta i}
devolva A
```

É claro que esse algoritmo faz com que A seja uma coleção de intervalos compatíveis, porém, fica a pargunta de _qual_ critério guloso usar para escolher um intervalo de R?

Temos algumas opções que parecem razoáveis:

- escolher o intervalo `i` em `R` com _menor_ `s[i]`
- escolher o intervalo `i` em `R` com _menor_ `f[i] - s[i]`
- escolher o intervalo `i` tal que
        | {j pertence a R : j intersecta i}
é o menor possível
- escolher o intervalo `i` em `R` com _menor_ `f[i]`

Qual será a escolha que resolve o problema?

Suponha que A é a _coleção máxima_ de intervalos disjuntos de S.

Se `i pertence a A` é tal que `f[i]` é _mínimo_, então A - {i} é _coleção máxima_ de intervalos disjuntos de `{k : s[k] >= f[i]}` (todos os intervalos "à direita" de `i`).
Senão, A é _coleção máxima_ de intervalos disjuntos de `S \ {i}`.

Essa é a substrutura ótima do problema!

Podemos escrever um algoritmo de programação dinâmica que resolve o problema, considerando a subestrutura ótima:

```
Suponha `s[1] <= s[2] <= ... <= s[n]`.

t[i] = tamanho de uma subcoleção disjunta máxima de `{i, ..., n}`

t[n] = 1;
t[i] = max{ t[i + 1], 1 + t[k] } para i = 1, ..., n-1,

onde k é o menor índice tal que s[k] => f[i].
```

O consumo de tempo de uma implementação que usa P.D. com essa substrutura consome tempo `O(n^2)`.

#### Escolha gulosa

Vamos utilizar a escolha gulosa de sempre escolher o intervalo com _menor_ `f[i]` em `S`. E isso funciona!

```c++
struct task {
  int s, f;
};

bool compare(task a, task b){
  return a.f < b.f;
}

int solve(task S[], n) {
  sort(S+1, S+n+1, compare);
  int ans = 1;
  int i = 1;

  for (int j = 2; j <= n; j++) {
    if (S[j].s >= S[i].f) {
      ans++;
      i = j;
    }
  }

  return ans;
}
```

O consumo de tempo desse algoritmo é `O(n*lg(n))`, melhor do que a P.D!