#include <bits/stdc++.h>
using namespace std;

const int N=2005;
int n,m,p,q,a[N],b[N],c[N],d[N],sum[N][N],mn[N][N],mx[N][N];
struct code
{
    int s,t;
}x[N*N];

int cmp(const void *a,const void *b)
{
	code p=*(code*)a,q=*(code*)b;
	int s1,t1,s2,t2,s,t,k;
	register int i,x,y;
	s1=p.s,t1=p.t;
	s2=q.s;t2=q.t;
	if(s1>=s2&&t1<=t2)return 1;
	if(s1<=s2&&t1>=t2)return -1;
	
	if(s1<s2&&t1>s2){swap(t1,s2);t1--;s2++;}
	else if(s1>s2&&t2>s1){swap(t2,s1);t2--;s1++;}
	
	if(mn[s1][t1]<mn[s2][t2])return -1;
	if(mn[s1][t1]>mn[s2][t2])return 1;
	s=min(mn[s1][t1],mn[s2][t2]);
	t=max(mx[s1][t1],mx[s2][t2]);
	for(i=s;i<=t;i++)
	{
		x=sum[t1][i]-sum[s1-1][i];
		y=sum[t2][i]-sum[s2-1][i];
		if(x>y)return -1;
		if(x<y)return 1;
	}
	if(s1<=s2)return -1;
	return 1;
}

int main()
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	int i,j,k,l;
	scanf("%d%d%d",&n,&p,&q);
	for(i=1;i<=n;i++)
	{
	    scanf("%d",&a[i]);
	    b[a[i]]=1;
	}
	for(i=1;i<=n;i++)b[i]+=b[i-1];
	for(i=1;i<=n;i++)a[i]=b[a[i]];
	for(i=1;i<=n;i++)
	    for(j=1;j<=n;j++)
	        sum[i][j]=sum[i-1][j]+(j>=a[i]);
	memset(mn,127,sizeof(mn));
	memset(mx,-1,sizeof(mx));
	for(i=1;i<=n;i++)
	{
		mn[i][i]=mx[i][i]=a[i];
		for(j=i+1;j<=n;j++)
		{
		    mn[i][j]=min(mn[i][j-1],a[j]);
		    mx[i][j]=max(mx[i][j-1],a[j]);
		}
	}
	for(i=1;i<=n;i++)
	    for(j=i;j<=n;j++)
	        x[++m].s=i,x[m].t=j;
	qsort(x+1,m,sizeof(x[1]),cmp);
	for(i=p;i<=q;i++)
	    printf("%d %d\n",x[i].s,x[i].t);
	return 0;
}

