#include<iostream>
#include<vector>
using namespace std;

int e, l, x, y, ok=1, t=1;

bool seen[110];
vector<int> adj[110];

void dfs(int x){
	seen[x] = true;
	for(int i=0;i<adj[x].size(); i++){
		if(seen[adj[x][i]]==false){
			dfs(adj[x][i]);
		}
	}
}

int main(){	
	while(cin>>e>>l && e!=0 && l!=0){
		for(int i=0;i<110;i++) seen[i]=false;
		for(int i=0;i<l;i++){
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		dfs(1);

		for(int i=1;i<=e; i++){
			if(seen[i]==false) ok = 0;
			adj[i].clear();	
		}
		cout<<"Teste "<<t<<"\n";
		if(ok) cout<<"normal\n";
		if(!ok) cout<<"falha\n";

		cout<<"\n";
		t++;
		ok = 1;
	}

	return 0;
}
