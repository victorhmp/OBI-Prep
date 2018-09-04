# Algoritmos de caminho mínimo em grafos

## Dijkstra

Complexidade de tempo: O(m \* log(n))

```c++
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

#define MAXN 10100

#define INFINITO 999999999

int n, m;                      // número de vértices e arestas
int distancia[MAXN];           // o array de distâncias à fonte
int processado[MAXN];          // o array que guarda se um vértice foi processado
vector<pii> vizinhos[MAXN];    // o primeiro elemento do par representa a distância e o segundo representa o vértice

void Dijkstra (int S) {
	// definimos todas as distâncias como infinito, exceto a de S.
	for(int i = 1;i <= n;i++) distancia[i] = INFINITO;
	distancia[S] = 0;

	// Criamos uma fila de prioridade onde o MENOR fica no topo.
	priority_queue< pii, vector<pii>, greater<pii> > fila;

	// colocamos o primeiro elemento como seja a distância do
	// vértice a S e o segundo como sendo o próprio vértice
	fila.push( pii(distancia[S], S) );

	while(true){

		int davez = -1;
		int menor = INFINITO;

		// selecionamos o vértice mais próximo
		while(!fila.empty()){

			int atual = fila.top().second;
			fila.pop();

			// vértice ainda não foi processado
			if(!processado[atual]){
				davez = atual;
				break;
			}

			// se não, continuamos procurando
		}

		// se não achou ninguém, é o fim do algoritmo
		if(davez == -1) break;

		processado[davez] = true; // marcamos para não voltar para este vértice

		// agora, tentamos atualizar as distâncias
		for(int i = 0;i < (int)vizinhos[davez].size();i++){

			int dist  = vizinhos[davez][i].first;
			int atual = vizinhos[davez][i].second;

			// A nova possível distância é distancia[davez] + dist.
			// Comparamos isso com distancia[atual]

			// vemos que vale a pena usar o vértice davez
			if( distancia[atual] > distancia[davez] + dist ){

				// atualizamos a distância
				distancia[atual] = distancia[davez] + dist;

				// inserimos na fila de prioridade
				fila.push( pii(distancia[atual], atual) );
			}
		}
	}
}
```

## Floyd-Warshall

Complexixade de tempo: O(n^3)

```c++
// First iteration
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
       if (i == j) distance[i][j] = 0;
       else if (adj[i][j]) distance[i][j] = adj[i][j];
       else distance[i][j] = INF;
		}
}

// Calculate new distances
for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
       for (int j = 1; j <= n; j++) {
           distance[i][j] = min(distance[i][j],
					 	distance[i][k]+distance[k][j]);
			 }
		}
}
```

## Exercícios

- https://br.spoj.com/problems/ENGARRAF/
- https://www.spoj.com/problems/MICEMAZE/
- https://olimpiada.ic.unicamp.br/pratique/p2/2015/f2/mina/
- https://olimpiada.ic.unicamp.br/pratique/p2/2009/f1/pontes/
- https://br.spoj.com/problems/REUNIAO2/
