# Grafos - Ideia e representações

## O que é um grafo?

Para nós, um grafo será simplesmente um conjunto de pontos, chamados de _vértices_, ligados por um conjunto de linhas, chamadas de _arestas_. Grafos são normalmente representados como desenhos, para visualização.

(desenho feito na lousa)

Quando vamos resolver problemas é comum termos que representar situações reais onde estamos trabalhando com mapas, tabuleiros e até mesmo árvores genealógicas. E de maneira geral, buscamos descobrir se existem caminhos entre um ponto e outro e até mesmo qual seria o _menor_ desses caminhos.

Nesses tipos de situações, grafos são muito úteis porque através deles podemos representar **ligações** entre pontos.

## Propriedades

O estudo matemático das propriedades dos grafos é uma área complexa e muito relevante no estudo de computação, logo não vamos nos aprofundar. Para nós, basta o conhecimento de algumas dessas propriedades.

### Grafos direcionados e bidirecionados

As arestas de um grafo qualquer podem ser direcionadas ou não, ou seja, podem possuir um único sentido no qual podem ser percorridas ou serem percorridas em qualquer sentido.

Em um grafo bidirecional, suas arestas são de "mão-dupla", ou seja, uma aresta (A, B) equivale a aresta (B, A). Podemos percorrer os vértices A e B em qualquer sentido, de A para B ou de B para A.

Já em um grafo direcionado, suas arestas só podem ser percorridas em um sentido. De uma forma mais visual, a representação das arestas pode ser feita com _setas_ no lugar de simples linhas.

### Grau de um vértice

O _grau_ de um vértice de um grafo é o número de arestas conectam ele a outros vértices.

Para grafos direcionados, podemos ainda atribuir aos vértices graus de _saída_ e de _entrada_.

### Conexidade

Um grafo (bidirecional) é chamado de **conexo** se, para todo par (u, v) de vértices no grafo, existe conjunto de arestas que ao ser percorrido forma um caminho entre u e v. De forma mais simples, saíndo de qualquer vértice do grafo, consigo chegar a qualquer um outro vértice.

## Representando um grafo

Quando queremos usar grafos para resolver problemas a primeira escolha que temos que fazer é como representar essa ideia na memória do computador. Basicamente precisamos saber como representar cada _elemento_ do grafo, ou seja, como represento os vértices e como represento as arestas.

De forma geral, representar os vértices não é problema, usamos simplesmente inteiros. Num grafo composto por N vértices, podemos usar inteiros de _0 a N-1_ ou de _1 a N_.

Agora, para representar as arestas do grafo, existem algumas opções. Cada opção possui suas vantagens e desvantagens. Vamos considerar as três mais comuns: Matriz de adjacência, lista de adjacência e implícita.

### Matriz de adjacência

Nessa representação, consideramos uma matriz _NxN_, onde _N_ representa o número de vértices no grafo. Cada célula (i, j) da matriz representa uma aresta entre os vértices i e j do grafo.

Para grafos onde as arestas não tem _peso_, usamos a convensão de que `matrix[i][j] = 0` se não existe aresta ligando os vértices i e j, `matrix[i][j] = 1` se existe tal aresta.

Essa representação é talvez a mais simples das três, porém sua complexidade de espaço é a pior, sendo quadrática no número de vértices. Já quanto ao tempo de operações básicas temos inserção e remoção de uma aresta em tempo constante, e consulta dos vizinhos em tempo proporcional ao número de vértices do grafo.

#### Exemplo de implementação

```c++
#include <iostream>
#define N 6

using namespace std;

int matrix[N][N];

// Recebe as arestas do grafo e monta a matriz de adjacência
int main()
{
  int num_edges = 0;
  cin >> num_edges;
  for (int k = 0; k < num_edges; k++)
  {
    int i, j;
    cin >> i >> j;
    matrix[i][j] = matrix[j][i] = 1;
  }

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      cout << matrix[i][j];
      if (j == N)
        cout << "\n";
    }
  }
}
```

### Lista de adjacência

Essa é a maneira mais usada de se representar arestas de grafos. Um pouco mais complicada de debugar num primeiro momento, com espaço e tempo otimizados.

Para essa representação guardamos, para cada vértice do grafo, quais são seus vizinhos.

O espaço utilizado por essa implementação é proporcial ao dobro número de arestas que temos no grafo, o que já a torna mais econômica em memória do que a matriz de adjacência. Quanto às operações básicas, podemos inserir uma nova aresta em tempo constante e realizar buscas pelos vizinhos de um vértice em tempo proporcional ao seu grau.

#### Exemplo de implementação

```c++
#include <iostream>
#include <vector>
#define N 6

using namespace std;

vector<int> neighbors[N];

// Recebe as arestas do grafo e monta as listas de adjacência de cada vértice
int main()
{
  int num_edges = 0;
  cin >> num_edges;
  for (int k = 0; k < num_edges; k++)
  {
    int i, j;
    cin >> i >> j;
    neighbors[i].push_back(j);
    neighbors[j].push_back(i);
  }
}
```

### Representação implicita de arestas

Apesar do nome, nesse tipo de situação não representamos as arestas em nenhuma estrutura de dados, bastanto apenas representar os vértices do grafo.

Esse é frequêntemente o caso em problemas em que trabalhamos com tabuleiros. Nesse tipo de problema, é comum que nosso meio de percorrer o grafo seja limitado em apenas se mover de uma determinada maneira tal que, estando em um dado vértice, só podemos nos movimentar para vértices pré-determinados.
