#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 5010
#define FOR(n) for(int i=1;i<=n;i++)
using namespace std;
char ch[M];
int Sa[M],t1[M],t2[M],C[M],Ra[M],h[M],f[M][M],n;
void get_sa(int m){
	int *x=t1,*y =t2;
	FOR(n)C[x[i]=ch[i]]++; FOR(m)C[i]+=C[i-1];
	for(int i=n;i;--i)Sa[C[x[i]]--]=i;
	for(int b=1;b<n;b<<=1){
		int t=0; for(int i=n;i>n-b;--i)y[++t]=i;
		FOR(n)if(Sa[i]>b)y[++t]=Sa[i]-b; FOR(m)C[i]=0;
		FOR(n)C[x[i]]++; FOR(m)C[i]+=C[i-1];
		for(int i=n;i;--i)Sa[C[x[y[i]]]--]=y[i]; swap(x,y),m=1;
		FOR(n)x[Sa[i]]=y[Sa[i]+b]==y[Sa[i+1]+b]&&y[Sa[i]]==y[Sa[i+1]]?m:m++;
		if(m>n)return;
	}
}
void get_h(){
	for(int i=1;i<=n;++i)Ra[Sa[i]]=i; int x=0;
	for(int i=1;i<=n;++i) if(Ra[i]!=n){
		for(x=max(x-1,0);ch[i+x]==ch[Sa[Ra[i]+1]+x];x++);
		h[Ra[i]]=x;
	}
}
void pint(int x){
	int tmp[20],*t =tmp;
	for(;x;x/=10)*t++=x%10+'0';
	if(t==tmp)putchar('0');
	else for(--t;t>=tmp;--t)putchar(*t);
	putchar(' ');
}
void work(){
	FOR(n-1){
		f[i][i]=h[i];
		for(int j=i+1;j<n;j++)f[i][j]=min(f[i][j-1],h[j]);
	}
	for(int i=1;i<=n;){
		int len=0,jj=0;
		for(int j=1;j<i;j++){
			int ll=Ra[i],rr=Ra[j];
			if(ll>rr)swap(ll,rr);
			int lenn=f[ll][rr-1];
			if(lenn>len){len=lenn; jj=j;}
		}
		if(!len){printf("-1 %d ",(int)ch[i]); i++;}
		else{pint(len); pint(jj-1); i+=len;}
	}
}
int main(){
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	gets(ch+1),n=strlen(ch+1);
	get_sa(128); get_h(); work();
	return 0;
}
