// F91 recursive

#include<cstdio>
#include<iostream>

using namespace std;

int ini, resp;

 int f91(int n){
	if(n<=100){
		return f91( f91( n+11  )  );	
	}
	else return n-10;
} 

int main(){
	
	while(scanf("%d", &ini) && ini!=0){

		//if(ini<=100) resp=91;
		//else resp = ini-10;
		printf("f91(%d) = %d\n", ini, f91(ini));
	}	

	return 0;
}
