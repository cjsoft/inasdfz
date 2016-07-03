#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 100000
#define MAXB 1000
typedef bitset<MAXB> bs;
bs INF;
bs pw10[200];

bs operator+(bs b1,bs b2){
	bs tmp=0;
	for(int i=0,x=0;i!=MAXB;++i){
		int tx=(b1[i]+b2[i]+x)>>1;
		tmp[i]=(b1[i]+b2[i]+x)&1;
		x=tx;
	}
	return tmp;
}
bs operator-(bs b1,bs b2){
	bs tmp=b1;
	for(int i=0,x=0;i!=MAXB;++i){
		int nw=tmp[i];
		nw-=x; nw-=b2[i];
		x=0;
		if(nw<0)x=1,nw+=2;
		tmp[i]=nw;
	}
	return tmp;
}
bs operator>>(bs b1,int x){
	bs tmp=b1;
}
int getp(bs b1,int p){
	for(int j=0;j!=p;++j)
		if(b1[j])return 0;
	return 1;
}

int b[MAXN],tot;
bs value[MAXN];
bs res[MAXN];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i!=MAXB;++i)INF[i]=1;
	pw10[0]=1;
	for(int i=1;i<100;++i)
		for(int j=0;j!=10;++j)
			pw10[i]=pw10[i-1]+pw10[i];
	bs ans=0;
	int K;scanf("%d",&K);
	if(K==1){
		printf("1\n");
		return 0;
	}
	--K;
	b[++tot]=1; value[tot]=0; res[tot]=1;
	for(int i=1,cnt=K;;++i){
		bs dt=pw10[i]; dt[i]=0;
		int ntot=tot;
		for(int j=1;j<=ntot;++j){
			if(!getp(value[j],i+1))b[j]=0;
			if(b[j]){
				b[++tot]=1;
				bs tmp=0; tmp=pw10[i-1]; tmp[i-1]=0;
				value[tot]=value[j]+dt;
				value[j]=value[j]-tmp;
				value[j]=value[j]+dt;
				res[tot]=res[j];
				res[j][i-1]=0;
				res[j][i]=1; res[tot][i]=1;
			}
		}
		for(int j=1;j<=tot;++j){
			cnt-=b[j];
			if(!cnt){
				for(int k=i;k>=0;--k)
					if(res[j][k])printf("1");
					else printf("0");
				return 0;
			}
		}
	}
	return 0;
}
