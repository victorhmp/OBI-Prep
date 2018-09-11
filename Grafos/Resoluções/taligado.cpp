#include<bits/stdc++.h>
using namespace std;

int n, m, typ, a, b;
vector<int> bridges[100145];

int main(){
	scanf("%d %d", &n, &m);
	while(m--){
		scanf("%d %d %d", &typ, &a, &b);
		if(typ == 0){
			int ok = 0;
			for(int i : bridges[a]){
				if(i==b)
					ok = 1;
			}

			if(ok) puts("1");
			else puts("0");
		}
		else{
			bridges[a].push_back(b);
			bridges[b].push_back(a);
		}
	}
}
