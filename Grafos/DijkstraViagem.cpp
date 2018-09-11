#include<queue>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
typedef pair<int, int> pii;

#define MAXN 10100
#define INFINITY INT_MAX

int n, m;
int origem, destino;
int dist[MAXN], visit[MAXN];

// < dist.da origem, vértice  >
vector<pii> vizinhos[MAXN];

void Dijkstra(int source){
	// iniciar distâncias como infinito, menos a do vértice de origem
	for(int i=1;i <= n;i++) dist[i] = INFINITY;
	dist[source] = 0;

	// min-priority_queue
	priority_queue< pii, vector<pii>, greater<pii>  > fila;
	fila.push( pii(dist[source], source)  );

	while(true){ // executado até o final do algoritmo
		int v1 = -1;
		int menor = INFINITY;

		while(!fila.empty()){ // enquanto a fila ainda tem elementos
			// selecionamos o mais próximo, que está no topo
			int v2 = fila.top().second;
			fila.pop();

			if(!visit[v2]){
				// se ele ainda não foi visitado, vamos usá-lo
				v1 = v2;
				break;
			}

			// se não, continuamos procurando
		}

		if(v1 == -1) break; // se não encontrou ninguém, o algoritmo acabou

		visit[v1] = true; // marcamos o vértice como visitado

		// agora vamos atualizar as distâncias
		for(int i=0; i < (int)vizinhos[v1].size(); i++){
			
			int distancia = vizinhos[v1][i].first;
			int atual = vizinhos[v1][i].second;

			// a possível nova distância é dist[v1] + distancia
			// comparamos isso com a dist[atual]

			if( dist[atual] > dist[v1] + distancia  ){
				dist[atual] = dist[v1] + distancia; // atualizamos a dist
				fila.push( pii(dist[atual], atual)  )  // inserimos na fila
			}
		}

	}
}

int main(){
	scanf("%d %d", &n, &m);
	scanf(" %d %d", &origem, &destino);

	for(int i = 1; i <= m; i++){
		int x, y, tempo;
		scanf(" %d %d %d", &x, &y, &tempo);
		
		// grafo bidirecional (o algoritmo funciona para uni tbm)
		vizinhos[x].push_back(pii(tempo, y));
		vizinhos[y].push_back(pii(tempo, x));

	}

	Dijkstra(origem);
	prinf("%d\n", dist[destino]);
}




