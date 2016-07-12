#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=107;

int V[maxn],N;

int cnta[maxn],cntb[maxn];
struct NODE{
	int l,r;
	bool operator <(const NODE &o)const{
		memset(cnta,0,sizeof(cnta));
		memset(cntb,0,sizeof(cntb));
		for(int i=l;i<=r;++i) cnta[V[i]]++;
		for(int i=o.l;i<=o.r;++i) cntb[V[i]]++;
		for(int i=1;i<=N;++i) if(cnta[i]!=cntb[i]) return cnta[i]>cntb[i];
		return l<o.l;
	}
}nodes[maxn*maxn];
int cn=0;

int P,Q;
int main(){
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d%d%d",&N,&P,&Q);
	for(int i=1;i<=N;++i) scanf("%d",V+i);
	for(int i=1;i<=N;++i) for(int j=i;j<=N;++j) nodes[cn++]=(NODE){i,j};
	sort(nodes,nodes+cn);
	for(int i=P-1;i<=Q-1;++i) printf("%d %d\n",nodes[i].l,nodes[i].r);
}
