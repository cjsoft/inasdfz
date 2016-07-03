#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
const int maxn=3E4+56;
const int mod=998244353;
int T;

char Buff[300077],*ptr=Buff;

#define isNum(c) ('0'<=(c) && (c)<='9')
inline int getint(){
	int ret=0;
	while(!isNum(*ptr)) ++ptr;
	while(isNum(*ptr)) ret=(ret<<1)+(ret<<3)+(*ptr)-'0',++ptr;
	return ret;
}

char P[10];
int cp=0;
void putint(int v){
	//printf("%d\n",v);
	if(v==0) putchar('0');
	else{
		cp=0;
		while(v){
			P[cp++]='0'+(v%10);
			v/=10;
		}
		for(int i=cp-1;i>=0;--i) putchar(P[i]);
	}
	putchar('\n');
}

int N,M,K,A[maxn],Transp[5][5],Transt[5][5],dp[5];
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	fread(Buff,sizeof(char),sizeof(Buff),stdin);
	for(T=getint();T;--T){
		//scanf("%d%d%d",&N,&K,&M);
		N=getint();
		K=getint();
		M=getint();
		for(int i=1;i<=N;++i) A[i]=getint();
		
		for(int i=0;i<K;++i) for(int j=0;j<K;++j) Transp[i][j]=(i+j)%K,Transt[i][j]=(i*j)%K;
		
		while(M--){
			int t,l,r,x;
			//scanf("%d%d%d",&t,&l,&r);
			t=getint();
			l=getint();
			r=getint();
			if(t==1){
				//scanf("%d",&x);
				x=getint();
				for(int i=l;i<=r;++i) A[i]=Transp[A[i]][x];
			}else if(t==2){
				//scanf("%d",&x);
				x=getint();
				for(int i=l;i<=r;++i) A[i]=Transt[A[i]][x];
			}else{
				dp[0]=dp[1]=dp[2]=dp[3]=dp[4]=0;
				dp[A[l]]=1;
				for(int i=l+1;i<=r;++i){
					int nv=dp[0]+dp[1];
					if(nv>=mod) nv-=mod;
					nv+=dp[2];
					if(nv>=mod) nv-=mod;
					nv+=dp[3];
					if(nv>=mod) nv-=mod;
					nv+=dp[4]+1;
					if(nv>=mod) nv-=mod;
					dp[A[i]]=nv;
				}
				//for(int i=0;i<K;++i) cerr<<"dp["<<i<<"]="<<dp[i]<<endl;
				int ans=dp[0]+dp[1];
				if(ans>=mod) ans-=mod;
				ans+=dp[2];
				if(ans>=mod) ans-=mod;
				ans+=dp[3];
				if(ans>=mod) ans-=mod;
				ans+=dp[4];
				if(ans>=mod) ans-=mod;
				//while(ans<0) ans+=mod;
				//while(ans>=mod) ans-=mod;
				putint(ans);
			}
		}
	}
}
