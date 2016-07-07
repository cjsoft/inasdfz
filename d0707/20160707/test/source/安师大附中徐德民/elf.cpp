#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,L;long long A[45],B,J2[45],Ans;
void check(long long x){
	for(int i=1;i<=41-L;i++){
		if(((x^B)&(J2[L]-1))==0){Ans++;return;}
		x/=2;
	    }
}
void dfs(int x,long long s){
	if(x>N){check(s);return;}
	dfs(x+1,s^A[x]);dfs(x+1,s);
}
int main(){
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&N);int i,j,k;char c;J2[0]=1;
	for(i=1;i<=40;i++)J2[i]=J2[i-1]*2;
	for(i=1;i<=N;i++){
		for(j=1;j<=40;j++){
			c=getchar();
			while(c!='0'&&c!='1')c=getchar();
			A[i]=A[i]*2+(c-'0');
		    }
	    }
	scanf("%d",&L);
	if(L>40){printf("0\n");return 0;}
	for(i=1;i<=L;i++){
		c=getchar();
		while(c!='0'&&c!='1')c=getchar();
		B=B*2+(c-'0');
	    }
	dfs(1,0);printf("%lld\n",Ans);
	return 0;
}

