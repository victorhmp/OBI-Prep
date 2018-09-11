#include<bits/stdc++.h>
using namespace std;

#define MAXN 1123
#define MAXM 5123

int n, m, resp, a, b;
vector<int> lista[MAXN];
int team[MAXN];

void dfs(int x){
	for(int i=0;i < (int)lista[x].size();i++){
		int v = lista[x][i];

		if(team[v] == -1){
			team[v] = team[x];
			dfs(v);
		}
	}
}

int main(){
	scanf("%d %d", &n, &m);
	
	for(int i=1;i<=m;i++){
		scanf(" %d %d", &a, &b);
		lista[a].push_back(b);
		lista[b].push_back(a);
	}

	for(int i=1;i<=n;i++) team[i] = -1;

	for(int i=1;i<=n;i++){
		if(team[i] == -1){
			resp++;
			team[i] = resp;
			dfs(i);
		}
	}

	printf("%d\n", resp);

	return 0;
}
