# Árvore Geradora Mínima (MST)

## Algoritmo de Kruskal

O (m\*lg(n))

```c++
struct edge {
    int weight;
    int x, y;
};

bool comp(edge a, edge b){ return a.weight < b.weight; }

// número de vértices e edges
int n, m;
edge edges[MAXM];

edge mst[MAXM];

// Union Find

int pai[MAXN];
int set_weight[MAXN];

int find(int x){
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}
void join(int a, int b){

    a = find(a);
    b = find(b);

    if(set_weight[a] < set_weight[b]) pai[a] = b;
    else if(set_weight[b] < set_weight[a]) pai[b] = a;
    else{
        pai[a] = b;
        set_weight[b]++;
    }
}

// Kruskal

void kruskal(edge[] edges) {
    // inicializar os pais para o union-find
    for(int i = 1;i <= n;i++) pai[i] = i;

    sort(edge+1, edge+m+1, comp);

    int size = 0;
    for(int i = 1;i <= m;i++){

        if( find(edge[i].x) != find(edge[i].y) ){
            join(edge[i].x, edge[i].y);

            mst[++size] = edge[i];
        }

    }
}
```

## Algoritmo de Prim

O (m\*lg(n))

```c++
int n, m;                      // número de vértices e arestas
int distancia[MAXN];           // o array de distâncias à fonte
int processado[MAXN];          // o array que guarda se um vértice foi processado
vector<pii> vizinhos[MAXN];    // nossas listas de adjacência. O primeiro elemento do par representa a distância e o segundo representa o vértice

int Prim(){

	for(int i = 2;i <= n;i++) distancia[i] = INFINITO;
	distancia[1] = 0;

	priority_queue< pii, vector<pii>, greater<pii> > fila; // Criamos uma fila de prioridade onde o menor fica no topo.
	fila.push( pii(distancia[1], 1) );                     // Como se pode ver, colocamos o primeiro elemento como seja a distância do
	                                                       // vértice a Árvore Geradora Mínima e o segundo como sendo o próprio vértice

	while(true){

		int davez = -1;

		// selecionamos o vértice mais próximo
		while(!fila.empty()){

			int atual = fila.top().second;
			fila.pop();

			if(!processado[atual]){ // podemos usar esse vértice porque ele ainda não foi processado
				davez = atual;
				break;
			}

			// se não, continuamos procurando
		}

		if(davez == -1) break; // se não achou ninguém, é o fim do algoritmo

		processado[davez] = true; // marcamos para não voltar para este vértice

		// agora, tentamos atualizar as distâncias
		for(int i = 0;i < (int)vizinhos[davez].size();i++){

			int dist  = vizinhos[davez][i].first;
			int atual = vizinhos[davez][i].second;

			// A nova possível distância é dist.
			// Comparamos isso com distancia[atual].
			// Porém, é importante checar se o vértice atual não foi processado ainda

			if( distancia[atual] > dist && !processado[atual]){  // vemos que vale a pena usar o vértice davez
				distancia[atual] = dist;                         // atualizamos a distância
				fila.push( pii(distancia[atual], atual) );       // inserimos na fila de prioridade
			}
		}
	}

	int custo_arvore = 0;
	for(int i = 1;i <= n;i++) custo_arvore += distancia[i];

	return custo_arvore;
}

int main(){

	cin >> n >> m;

	for(int i = 1;i <= m;i++){

		int x, y, tempo;
		cin >> x >> y >> tempo;

		vizinhos[x].push_back( pii(tempo, y) );
		vizinhos[y].push_back( pii(tempo, x) );
	}

	cout << Prim() << endl; // imprimimos a resposta

	return 0;
}
```

## Exercícios

- https://olimpiada.ic.unicamp.br/pratique/p2/2011/f2/rmapa/
- https://olimpiada.ic.unicamp.br/pratique/p2/2014/f1/copa/
- https://olimpiada.ic.unicamp.br/pratique/p2/2008/f2/frete/
