# Ordenação Topológica

Uma ordenação topológica de um dado grafo _direcionado acíclico_ G é uma ordenação de seus vértices de tal forma que: para cada aresta u -> v, o vértice u aparece antes de v na ordenação. De forma mais abrangente, se existe um caminho partindo de um vértice A e terminando em um vértice B, então o vértice A aparece antes de B na ordenação topológica do grafo.

É interessante reparar que **todo** grafo _acíclico_ possuí uma ordenação topológica, ao passo que, se o grafo possui um cíclo, não existe uma ordenação topológica tal grafo.

Existem dois algoritmos mais utilizados para encontrar ordenações topológicas, um deles conhecido como Algoritmo de Kahn com funcionamento similar ao algoritmo de BFS, e um algoritmo baseadom em DFS, cuja implementação é mais simples.

## Algoritmo de Kahn

A ideia do algoritmo pode ser entendida facilmente através de pseudocódigo:

```
L ← Lista vazia que irá conter a resposta
S ← Conjunto de todos os vértices sem arestas de entrada (grau = 0)

enquanto S é não-vazio faça:
    remova um vértice n de S
    insira n em L
    para cada vértice m com uma aresta n -> m faça:
        remova a aresta (n -> m) do grafo
        se m não tem mais arestas de entrada então:
            insira m em S

se o grafo tem arestas sobrando então:
    impossível (grafo possui ciclos)
senão:
    ordenação topológica está em L
```

Em C++, um código que implementa tal algoritmo fica:

```c++
for (int i = 1; i <= n; i++) {
  if(grau[i] == 0)
    lista.push_back(i);
}

int ini = 0;
while (ini < (int) lista.size()){
	int atual = lista[ini];
	ini++;

	for(int i = 0; i < (int) grafo[atual].size(); i++) {
		int v = grafo[atual][i];
		grau[v]--;
    // se o grau se tornar zero, acrescento à lista
		if(grau[v] == 0) lista.push_back(v);
	}
}

// agora, se na lista não houver N vértices,
// sabemos que é impossível realizar o procedimento

if ((int)lista.size() < n) cout << "impossivel\n";
else {
	for(int i = 0;i < (int)lista.size();i++) cout << lista[i] << " ";
	cout << endl;
}
```

## Algoritmo alternativo

Outro jeito de se encontrar uma ordenação topológica de um grafo é com uma variação do algoritmo de DFS. Basicamente, executamos uma DFS no vértice atual se este vértice não foi processado ainda. Sempre vamos manter 3 possíveis estados:

1. Não processado
2. Sendo processado
3. Já processado

Todos os vértices começam como não processados. Quando chegamos em um vértice pela primeira vez, seu estado é "Sendo processado", e depois que todos os seus vizinhos foi processado e acabamos a sua busca, ele passa a ser "Já processado". Dessa maneira, conseguimos encontrar uma possível ordenação topológica ou detectar um cíclo.

## Exercícios

- https://olimpiada.ic.unicamp.br/pratique/p2/2011/f2/escalona/
