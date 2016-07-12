#include <bits/stdc++.h>

using namespace std;
const int N = 2001000;

struct Node{
	int l,r;
	Node(){}
	Node(int l,int r):l(l),r(r){}
}nod[N];
int b[2010][2010];
int a[N],n,p,q,len;
bool operator < (const Node &x,const Node &y){
	for (int i = 1;i <= n;i++){
		int u = b[i][x.r]-b[i][x.l-1],v = b[i][y.r]-b[i][y.l-1];
		if (u < v) return 0;
		if (u > v) return 1;
	}
	if (x.l < y.l) return 1;
	return 0;
}
int main(){
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d%d%d",&n,&p,&q);
	for (int i = 1;i <= n;i++){ 
		scanf("%d",&a[i]);
		b[a[i]][i]++;
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			b[j][i] += b[j][i-1];
	for (int i = 1;i <= n;i++)
		for (int j = i;j <= n;j++)
			nod[++len] = Node(i,j);
	sort(nod+1,nod+1+len);
	for (int i = p;i <= q;i++)
		printf("%d %d\n",nod[i].l,nod[i].r);
	return 0;
}
