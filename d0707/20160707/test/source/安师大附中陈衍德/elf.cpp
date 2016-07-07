#include<bits/stdc++.h>
using namespace std;
int N,L,pppp;
long long A[44],B;
map<long long,int> M;
char s[44];
long long ans;
void dfs1(int d,long long b,int r){
	if(d>pppp){
		M[b>>(r-L)]++;
		//if(r==5)printf("%lld\n",b);
		return;
	}
	dfs1(d+1,b^(A[d]&((1<<r)-1)),r);
	dfs1(d+1,b,r);
}
void dfs2(int d,long long b){
	if(d<1){
		for(int i=0;i<=40-L;i++)
		if(((b>>i)&((1<<L)-1))==B){
			ans++;return;
		}
		//if(l==3)printf("%lld %d\n",b^B,M[b^B]);
		return;
	}
	if(d==pppp){
		int cnt=0;
		for(int i=0;i<=40-L;i++)
		cnt+=M[((b>>i)&((1<<L)-1))^B];
		if(cnt==0)return;
	}
	dfs2(d-1,b^A[d]);
	dfs2(d-1,b);
}
int main(){
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&N);
	pppp=N/2;
	for(int i=1;i<=N;i++){
		scanf("%s",s);
		int len=strlen(s);
		for(int j=0;j<len;j++)
		A[i]=A[i]*2+s[j]-'0';
	}
	scanf("%d",&L);
	scanf("%s",s);
	int len=strlen(s);
	for(int j=0;j<len;j++)
	B=B*2+s[j]-'0';
	for(int i=1;i<=41-L;i++){
		//M.clear();
		dfs1(1,0,i+L-1);
	}
	dfs2(N,0);
	cout<<ans;
	return 0;
}
