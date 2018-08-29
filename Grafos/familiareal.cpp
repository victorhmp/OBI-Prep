#include<bits/stdc++.h>
using namespace std;

#define MAXN 10100

int n, m, h;
int geracao[MAXN], qtd[MAXN], presenca[MAXN]

// vector que sera a lista de adjacencia
vector<int> lista[MAXN];

void dfs(int v=0, int l=0){
	geracao[v] = l; // geracao do vertice = nivel
	qtd[l]++; // +1 descendente dessa geracao

	h = max(h, l); // assim encontramos a altura da nossa arvore

	// para cada filho de v
	for(int i=0; i<lista[v].size(); i++){
		dfs(lista[v][i], l+1); // chamo a dfs um nivel abaixo
	}
}

int main(){
	scanf(" %d %d", &n, &m);

	for(int i=q;i<=n;i++){ // cada descendente
		int pai;
		scanf(" %d", &pai);
		
		// adiciona ao grafo como filho de seu pai
		lista[pai].push_back(i);
	}

	// a dfs marca a geracao de cada descendente
	// e tambem a qtd de descendentes em casa geracao

	dfs();
	// para cada convidado
	for(int i=1;i<=m;i++){
		int part;
		scanf(" %d", &part);

		presenca[ geracao[part]  ]++;
	}

	// para cada geracao imprimo o percentual de presenca
	for(int i=1; i<=h; i++){
		// com duas casas de precisao, tenho:
		printf("%.2lf ", 100.00*presenca[i]/qtd[i]);
	}

	printf("\n");
	return 0;
}
