#include<bits/stdc++.h>
using namespace std;

#define MAXN 1010

int land[MAXN][MAXN];
int m, n, le, ri, up, down, ans;
char in;

int main(){
	scanf("%d %d", &m, &n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf(" %c", &in);
			if(in == '.') land[i][j] = 0;
			else if(in == '#') land[i][j] = 1;
		}
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(land[i][j]==1){
				if(i > 0){
					up = land[i-1][j];
				}
				else up = 0;
				if(i < m-1){
					down = land[i+1][j];
				}
				else down = 0;

				if(j > 0){
					le = land[i][j-1];
				}
				else le = 0;
				if(j < n-1){
					ri = land[i][j+1];
				}
				else ri = 0;

				if(!ri || !le || !up || !down) ans++;
			}
		}
	}
	
	printf("%d\n", ans);
}
