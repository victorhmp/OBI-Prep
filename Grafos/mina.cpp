#include<bits/stdc++.h>
using namespace std;

#define MAXN 110
#define INF 12234

#define F first
#define S second

typedef pair<int, int> vertice;
typedef pair<int, vertice> iii;

int n, mine[MAXN][MAXN], dist[MAXN][MAXN];

int dijkstra(){
	memset(dist, INF, sizeof(dist));

	dist[1][1] = 0;

	priority_queue< iii, vector<iii>, greater<iii> > heap;
	heap.push(iii(0, vertice(1, 1)));

	while(!heap.empty()){
		int distance = heap.top().F;
		int i = heap.top().S.F;
		int j = heap.top().S.S;

		heap.pop();

		if(distance > dist[i][j]) continue;
		
		// first neighbour
		int i_nei = i+1, j_nei = j;

		if(i_nei >= 1 && i <= n && j >= 1 && j<=n &&
		dist[i][j]+mine[i_nei][j_nei]<dist[i_nei][j_nei]){
			dist[i_nei][j_nei] = dist[i][j] + mine[i_nei][j_nei];
			heap.push(iii(dist[i_nei][j_nei], vertice(i_nei, j_nei)));
		}

		// second neighbour
		i_nei = i-1, j_nei = j;

		if(i_nei >= 1 && i <= n && j >= 1 && j<=n &&
		dist[i][j]+mine[i_nei][j_nei]<dist[i_nei][j_nei]){
			dist[i_nei][j_nei] = dist[i][j] + mine[i_nei][j_nei];
			heap.push(iii(dist[i_nei][j_nei], vertice(i_nei, j_nei)));
		}

		// third neighbour
		i_nei = i, j_nei = j+1;

		if(i_nei >= 1 && i <= n && j >= 1 && j <= n &&
		dist[i][j]+mine[i_nei][j_nei]<dist[i_nei][j_nei]){
			dist[i_nei][j_nei] = dist[i][j] + mine[i_nei][j_nei];
			heap.push(iii(dist[i_nei][j_nei], vertice(i_nei, j_nei)));
		}

		// last neighbour
		i_nei = i, j_nei = j-1;

		if(i_nei >= 1 && i <= n && j >= 1 && j<=n &&
		dist[i][j]+mine[i_nei][j_nei]<dist[i_nei][j_nei]){
			dist[i_nei][j_nei] = dist[i][j] + mine[i_nei][j_nei];
			heap.push(iii(dist[i_nei][j_nei], vertice(i_nei, j_nei)));
		}

	}
	return dist[n][n];
}

int main(){
	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		for(int j=1; j <= n; j++)
			scanf(" %d", &mine[i][j]);
	}

	printf("%d\n", dijkstra());
	return 0;
}
