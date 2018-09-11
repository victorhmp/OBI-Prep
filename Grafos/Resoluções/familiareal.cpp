#include<bits/stdc++.h>
using namespace std;

#define MAXN 11234

int n, m, h;
int ger[MAXN], qtd[MAXN], presenca[MAXN];

vector<int> vizinhos[MAXN];

void dfs(int v = 0, int l = 0){
	ger[v] = l;
	qtd[l]++;

	h = max(h, l);

	for(int i=0;i<(int)vizinhos[v].size(); i++)
		dfs(vizinhos[v][i], l+1);
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;i++){
		int p;
		scanf(" %d", &p);

		vizinhos[p].push_back(i);
	}

	dfs();

	for(int i=1;i<=m;i++){
		int part;
		scanf(" %d", &part);

		presenca[ger[part]]++;
	}

	for(int i=1; i<=h; i++){
		printf("%.2lf ", 100.0*presenca[i]/qtd[i]);
	}

	printf("\n");

	return 0;
}
