# Filas de Prioridade e Heaps

Uma _fila de prioridade_ é muito similar à uma fila, ou pilha comum, porém à cada um de seus elementos é associada uma _prioridade_ associada, que em geral é definida pela seu usuário. Essa prioridade permite que elementos sejam processados em ordem crescente (ou decrescente) de prioridade.

Em C++, `std::priority_queue` faz parte do _header_ `<queue>`, e é implementada como uma **Heap**.

## Heaps binários

_Heap binário_ é uma árvore binária balanceada que satisfaz uma _propriedade_ de ordenação que pode ser de dois tipos:

- `min_heap`, é um _heap_ em que o valor de cada nó é **maior ou igual** ao valor de seu pai, com o **menor** elemento da heap na raíz;
- `max_heap`, é um _heap_ em que o valor de cada nó é **menor ou igual** ao valor de seu pai, com o **maior** elemento da heap na raíz.

_Heaps_ são particularmente úteis quando precisamos remover rapidamente o elemento de **maior** (ou **menor**) prioridade. Sendo naturalmente utilizada na implementação de filas de prioridade.

Operações básicas, como _inserir_ um elemento e _remover_ o elemento de _maior_ (ou _menor_) prioridade, podem ser executadas com consumo de tempo `O(lg n)`. Além disso, podemos também rodar um `HeapSort` em tempo `O(n*(lg n))`.

## Exemplo de uso

Como já vimos, filas de prioridade são utilizadas na implementação de alguns algoritmos clássicos, como `Dijkstra`, para encontrar caminhos mínimos em grafos direcionados; também aparecem em alguns algoritmos de busca com heurísticas, como o algoritmo `A*`, utilizado em modelos de IA; implementação do `algoritmo de Prim`, para encontrar árvores geradoras mínimas.

## Em C++

Em C++, filas de prioridades podem ser utilizadas através do header `<queue>`, sendo que por padrão elas seguem a propriedade `max_heap`, ou seja, o elemento na raíz é o **maior**. O consumo de tempo da operação de inserção é `O(lg n)`, porque a Heap tem que ser "mantida".