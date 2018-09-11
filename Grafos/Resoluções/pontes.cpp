#include<bits/stdc++.h>
using namespace std;

#define MAXN 1123
#define MAXM 11234
#define INF 999999

typedef pair<int, int> pii;

int n, m, s, t, b;
int dist[MAXN], visit[MAXN];

vector<pii> vizinhos[MAXN];

void dj(int s){
	memset(dist, INF, sizeof(dist));
	dist[s] = 0;

	priority_queue< pii, vector<pii>, greater<pii> > heap;
	heap.push( pii(dist[s], s) );

	while(true){
		int v = -1;
		int mini = INF;

		while(!heap.empty()){
			int u = heap.top().second;
			heap.pop();

			if(!visit[u]){
				v = u;
				break;
			}
		}

		if(v == -1) break;

		visit[v] = true;

		for(int i=0;i<(int)vizinhos[v].size();i++){
			int distance = vizinhos[v][i].first;
			int vert = vizinhos[v][i].second;

			if(dist[vert] > dist[v] + distance){
				dist[vert] = dist[v] + distance;
				heap.push( pii(dist[vert], vert) );
			}
		}

	}

}

int main(){

	scanf("%d %d", &n, &m);
	while(m--){
		scanf(" %d %d %d", &s, &t, &b);

		vizinhos[s].push_back( pii(b, t) );
		vizinhos[t].push_back( pii(b, s) );
	}

	dj(0);

	printf("%d\n", dist[n+1]);

	return 0;
}
