#include<cstdio>
#define FOR(l,r) for(int i=l;i<=r;i++)
#define N 30001
using namespace std;
int T,n,m,k,ty,l,r,x,a[N],f[N],g[5];
int p=998244353;
int read(){
	int x=0; char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x;
}
void change1(int l,int r,int x){
	FOR(l,r){a[i]+=x; if(a[i]>=k)a[i]-=k;}
}
void change2(int l,int r,int x){
	FOR(l,r){a[i]*=x; if(a[i]>=k)a[i]%=k;}
}
int work(int l,int r){
	f[l-1]=0; FOR(0,k-1)g[i]=0;
	FOR(l,r){
		int ne=g[a[i]]; g[a[i]]=i;
		f[i]=(f[i-1]<<1)|1;
		if(ne)f[i]-=1+f[ne-1]; 
		if(f[i]>=p)f[i]-=p;
		if(f[i]<0)f[i]+=p;
	}
	return f[r];
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	T=read();
	while(T--){
		n=read(); k=read(); m=read();
		FOR(1,n)a[i]=read();
		FOR(1,m){
			ty=read();
			if(ty==1){l=read(); r=read(); x=read(); change1(l,r,x);}else
			if(ty==2){l=read(); r=read(); x=read(); change2(l,r,x);}else 
			{l=read(); r=read(); printf("%d\n",work(l,r));}
		} 
	}
	return 0;
}
