#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define maxn 2010

using namespace std;

int su[maxn][maxn]={0};
int n,p,q,ai[maxn]={0};
void getsu(){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			su[i][j]=su[i-1][j];
		su[i][ai[i]]++;
	}
}
struct Node{int l,r;};
bool operator < (const Node &a,const Node &b){
	int i,cnta,cntb;
	for(i=1;i<=n;i++){
		cnta=su[a.r][i]-su[a.l-1][i];
		cntb=su[b.r][i]-su[b.l-1][i];
		if(cnta<cntb)return false;
		if(cnta>cntb)return true;
	}
	return a.l<b.l;
}
Node ni[maxn*maxn];

int main(){
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	int i,j,len=0;
	scanf("%d%d%d",&n,&p,&q);
	for(i=1;i<=n;i++)
		scanf("%d",&ai[i]);
	getsu();
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			ni[++len]=(Node){i,j};
	sort(ni+1,ni+1+len);
	for(i=p;i<=q;i++)
		printf("%d %d\n",ni[i].l,ni[i].r);

	return 0;
}
