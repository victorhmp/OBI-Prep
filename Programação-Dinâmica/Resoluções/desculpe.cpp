#include<bits/stdc++.h>
using namespace std;

int c, f, test = 1;
int comp[212], desc[212];
int memo[212][212];

int dp(int idx, int res){
	if(idx == c || res==0) return 0;
	if(memo[idx][res]>=0) return memo[idx][res];

	int nope = dp(idx+1, res);

	if(comp[idx]<=res){
		int yep = desc[idx] + dp(idx+1, res-comp[idx]);
		return memo[idx][res] = max(nope, yep);
	}

	return memo[idx][res] = nope;
}

int main(){
	while(scanf("%d%d", &c, &f) && c!=0 && f!=0){
		memset(memo, -1, sizeof memo);
		
		for(int i=1;i<=f;i++) scanf("%d%d", &comp[i], &desc[i]);
		
		int resp = dp(1, c);

		printf("Teste %d\n", test);
		printf("%d\n\n", resp);

		test++;
	}

	return 0;
}
