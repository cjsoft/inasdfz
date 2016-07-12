#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int N=2001,M=2001005,INF=2100000000;

int n,p,q,a[N],b[N],cnt,mn[N][N];

void Read(int &x){
register char ch;
while((ch=getchar())<'0' || ch>'9');
x=ch-'0';
while((ch=getchar())>='0' && ch<='9')x=x*10+ch-'0';
}

struct Node{
int l,r;
friend inline bool operator<(register Node A,register Node B){
if(A.l<B.l && B.r<A.r)return 1;
if(B.l<A.l && A.r<B.r)return 0;
if(mn[A.l][A.r]<mn[B.l][B.r])return 1;
if(mn[B.l][B.r]<mn[A.l][A.r])return 0;
memset(b,0,sizeof(b));
for(int i=A.l;i<=A.r;i++)b[a[i]]++;
for(int i=B.l;i<=B.r;i++)b[a[i]]--;
for(int i=1;i<=n;i++)if(b[i])return b[i]>0;
return A.l<B.l;
}
}node[M];
//#include<ctime>
int main(){
freopen("lian.in","r",stdin);
freopen("lian.out","w",stdout);
Read(n);Read(p);Read(q);
for(register int i=1;i<=n;i++)Read(a[i]);
for(register int i=1;i<=n;i++){
	for(register int j=i;j<=n;j++){
		if(i==j)mn[i][j]=a[i];
		else mn[i][j]=min(mn[i][j-1],a[j]);
		node[++cnt].l=i;
		node[cnt].r=j;
	}
}
if(n>=500){
	nth_element(node+1,node+cnt+1,node+p);
	nth_element(node+p+1,node+cnt+1,node+q);
	sort(node+p,node+q+1);
}
else sort(node+1,node+cnt+1);
for(register int i=p;i<=q;i++)printf("%d %d\n",node[i].l,node[i].r);
//printf("%.3lf\n",(double)clock()/CLOCKS_PER_SEC);
return 0;
}

