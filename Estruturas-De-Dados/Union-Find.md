# Union-Find

Union-Find é um nome comum para estruturas de dados que são capazes de representar um conjunto de dados divididos em _conjuntos disjuntos_.

Vamos considerar o seguinte problema para visualizar o uso da estrutura e quais suas propriedades.

```
Em uma sala estão N pessoas.
Vamos definir duas pessoas como sendo amigos se estão conectados diretamente ou indiretamente.
Se A é amigo de B, e B é amigo de C, então A também é amigo de C.
Um grupo de amigos é um grupo de pessoas tal que quaisquer dois integrantes são amigos.
Dada a lista de amigos diretos, encontre o número de grupos de amigos e o número de pessoas em cada grupo.
```

Esse problema poderia ser resolvido usando _BFS_, porém vamos resolvê-lo com Union-Find.
Primeiramente, uma estrutura de conjuntos disjuntos é uma estrutura que mantem uma coleção `S1`, `S2`, ..., `Sn` de conjuntos disjuntos dinâmicos. Além disso, cada um desses conjuntos possui um _representante_, que é um dos seus elementos.

Vamos representar os _grupos de amigos_ como os _conjuntos_, e o representante de cada grupo é a pessoa de maior índice. No começo, cada pessoa representa um grupo, o seu próprio, de tamanho 1. Depois, vamos _conectando_ os grupos de acordo com as amizades diretas que recebemos na entrada.

Definindo as seguintes operações:

- create_set(x) = cria um novo conjunto { x }.
- merge_sets(x, y) = junta os conjuntos que contém os elementos `x` e `y` em um único novo conjunto.
- find_set(x) = retorna o elemento que representa o conjunto no qual `x` está contido.

Com apenas essas três operações, poderíamos resolver o problema:

```
for (each person in x from 1 to N)
  create_set(x);
for (each pair of friends (x, y))
  if (find_set(x) != find_set(y))
    merge_sets(x, y)
```

Agora vem a principal pergunta: `Como representar essa estrutura e implementar essas 3 operações de forma eficiente?`.

Vamos pensar em uma representação em _floresta_, ou seja, um conjunto de árvores. A ideia é simples, vamos representar cada _conjunto_ (ou grupo de amigos) como uma árvore, sendo o elemento da raíz o representante do conjunto, com todos os seus "filhos" apontando para seus descendentes diretos.

Com isso em mente, escrevemos as funções em C++ da maneira mais otimizada:

```c++
int pai[MAXN];

int find(int x) {
    if(pai[x]==x) return x;
    return find(pai[x]);
}

void union(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) {
        return;
    }

    if(peso[x] < peso[y]) {
        pai[x] = y;
    }
    if(peso[x] > peso[y]){
        pai[y] = x;
    }

    if(peso[x] == peso[y]){
        pai[x] = y;
        peso[y]++;
    }
}
```

Com essa implementação, conseguimos manipular nossa estrutura de dados com consumo de tempo `O(1)` em ambas as funções!
