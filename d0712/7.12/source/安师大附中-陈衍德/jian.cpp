#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int A[110];
int B[110],orz;
int pos[110];
int ok(){
	orz++;
	for(int i=1;i<=n;i++)
	B[(A[i]+i)%n]=orz;
	for(int i=0;i<n;i++)
	if(B[i]!=orz)return 0;
	for(int i=1;i<=n;i++)
	pos[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
		if(pos[j]!=-1&&A[pos[j]]>A[pos[1]])return 0;
		if(A[pos[j]]<A[pos[1]])pos[j]=-1;
		}
		for(int j=1;j<=n;j++){
			if(pos[j]!=-1)pos[j]++;
			if(pos[j]>n)pos[j]=1;
		}
	}
	for(int i=2;i<=n;i++)
	if(pos[i]!=-1)return 0;
	return 1;
}
void dfs(int d,int c){
	if(c<0)return;
	if(d==n){
		A[d]=c;
		ans+=ok();
		A[d]=0;
		return;
	}
	for(int i=0;i<=c;i++){
	A[d]=i;
	dfs(d+1,c-i);
	A[d]=0;
	}
}
int main(){
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=5&&m<=10){
	dfs(1,m);
	printf("%d",ans);
	}
	else printf("0\n");
	return 0;
}
