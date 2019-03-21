#include<bits/stdc++.h>
using namespace std;
#define MAXN 1010

int n, m, x, y, xf, yf;
int tab[MAXN][MAXN], vx[4] = {0,1,0,-1}, vy[4]={1,0,-1,0};
int dist[MAXN][MAXN];

void dfs(int i, int j){
	for(int mov=0;k<4;k++){
		int novo_i = i+vx[k];
		int novo_j = j+vx[k];

		// check for boundaries
		// && check if already visited
		if(tab[novo_i][novo_j]>0 && dist[novo_i][novo_j]<0){
			dist[novo_i][novo_j] = dist[i][j] + 1;

			dfs(novo_i, novo_j);
		}
	}
}

int main(){

	memset(dist, -1, sizeof dist); // dist[i][j]=-1 (inicial)

	scanf("%d %d", &n, &m);

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d", &tab[i][j]);

			if(tab[i][j]==2){
				x = i;
				y = j;
			}

			if(tab[i][j]==3){
				xf = i;
				yf = j;
			}
		}
	}

	dist[x][y] = 1;
	dfs(x, y);

	printf("%d\n", dist[xf][yf]);
	return 0;
}
