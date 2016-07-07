#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 41 
#define C 16

ll getbint(int k){
	ll x=0; char ch=getchar();
	while(ch!='0'&&ch!='1')ch=getchar();
	while(k-->0)x=(x<<1)+(ch=='1'),ch=getchar();
	return x;
}

int N,L;
ll w,mask;
ll s[MAXN];
int rp[MAXN],bl[MAXN];
ll rest[MAXN];
int G(){
	for(int i=0;i!=MAXN;++i)
		rp[i]=bl[i]=-1;
	int cnt=0;
	for(int i=1;i<=N;++i){
		if(!s[i])continue;
		++cnt; rp[i]=0;
		while(!((s[i]>>rp[i])&1))++rp[i];
		bl[rp[i]]=i;
		for(int j=i+1;j<=N;++j)
			if((s[j]>>rp[i])&1)s[j]^=s[i];
	}
	for(int i=1,j=1;i<=cnt;++i,++j){
		while(!s[j])++j;
		bl[rp[j]]=i,rp[i]=rp[j],s[i]=s[j];
	}
	for(int i=cnt;i>=1;--i)
		for(int j=i-1;j>=1;--j)
			if((s[j]>>rp[i])&1)s[j]^=s[i];
	for(int i=cnt;i>=1;--i)
		for(int j=0;j!=MAXN;++j)
			if(!bl[j])rest[i]=(rest[i]<<1)+((s[i]>>j)&1);
	return N=cnt;
}


ll ans=0;
void dfs(int x,ll tmp){
	if(x>N){
		int flag=0;
		for(int i=0;i<=40-L;++i)
			if(((tmp>>i)&mask)==w)flag=1;
		ans+=flag;
	}else
		dfs(x+1,tmp),dfs(x+1,tmp^s[x]);
}



int main(){
	
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	
	scanf("%d",&N);
	int pN=N;
	for(int i=1;i<=N;++i)
		s[i]=getbint(40);
	scanf("%d",&L);
	mask=(1LL<<L)-1;
	w=getbint(L);
	
	G();
	
	dfs(1,0);
	ans=ans*(1LL<<(pN-N));
	cout<<ans<<endl;
	
	return 0;
	
}
