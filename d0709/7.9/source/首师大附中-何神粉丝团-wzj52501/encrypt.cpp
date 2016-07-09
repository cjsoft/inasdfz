#include<cstdio>
#include<cctype>
#include<cstring>
#include<ctime>
#include<algorithm>
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
using namespace std;
const int S=10000;
char pf[S],*o1=pf,*o2=pf+S;
#define ot(x) (o1==o2?fwrite(pf,1,S,stdout),*(o1=pf)++=x:*o1++=x)
void print(int x) {char s[10],*b;b=s;if(!x) *b++=48;for(;x;*b++=x%10+48,x/=10);for(;b--!=s;ot(*b));}
const int maxn=1000010;
const int inf=1e9;
int to[maxn][26],fa[maxn],num[maxn],f[maxn],l[maxn],cnt=1,last=1;
void extend(int c,int pos) {
	int p,np,q,nq;p=last;l[last=np=++cnt]=l[p]+1;
	f[np]=pos;num[pos]=np;
	for(;!to[p][c];p=fa[p]) to[p][c]=np;
	if(!p) fa[np]=1;
	else {
		q=to[p][c];
		if(l[p]+1==l[q]) fa[np]=q;
		else {
			l[nq=++cnt]=l[p]+1;
			memcpy(to[nq],to[q],sizeof(to[q]));
			fa[nq]=fa[q];fa[q]=fa[np]=nq;
			for(;to[p][c]==q;p=fa[p]) to[p][c]=nq;
		}
	}
}
int anc[maxn][20];
int n,c[maxn],od[maxn];
char s[maxn];
void init() {
	rep(i,0,n*2) f[i]=inf;
	dwn(i,n,1) extend(s[i]-'a',i);
	rep(i,1,cnt) c[l[i]]++;
	rep(i,1,n) c[i]+=c[i-1];
	dwn(i,cnt,1) od[c[l[i]]--]=i;
	dwn(i,cnt,1) {
		int x=od[i];
		f[fa[x]]=min(f[fa[x]],f[x]);
	}
	rep(i,1,cnt) {
		int x=od[i];
		anc[x][0]=fa[x];
		rep(j,1,19) anc[x][j]=anc[anc[x][j-1]][j-1];
	}
}
int main() {
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",s+1);n=strlen(s+1);init();
	int x=1;
	while(x<=n) {
		int p=num[x];
		dwn(i,19,0) {
			int k=anc[p][i];
			if(f[k]>=x) p=k;
		}
		if(f[p]>=x) p=fa[p];
		if(l[p]&&f[p]<x) {
			int len=l[p];
			print(len);ot(' ');print(f[p]-1);
			x+=len;
		}
		else ot('-'),ot('1'),ot(' '),print(s[x]),x++;
		ot(' ');
	}
	fwrite(pf,1,o1-pf,stdout);
	return 0;
}
