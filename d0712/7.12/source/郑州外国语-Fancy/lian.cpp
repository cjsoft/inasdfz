#include <algorithm>
#include <cstdio>
#include <vector>
const int N=2002;
int n,m,tot,st,ed;
int a[N][N];
std::pair<int,int> b[N*N<<1];
bool cmp(const std::pair<int,int> x,const std::pair<int,int> y)
{
	int l1=x.first-1,r1=x.second,l2=y.first-1,r2=y.second;
	for(int i=1;i<=m;i++)
	{
		int d1=a[i][r1]-a[i][l1],d2=a[i][r2]-a[i][l2];
		if(d1!=d2) return d1>d2;
	}
	return l1<l2;
}
int main()
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d%d%d",&n,&st,&ed);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i].first),b[i].second=i;
	std::sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		if(i==1||b[i].first!=b[i-1].first) m++;
		a[m][b[i].second]=1;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			a[i][j]+=a[i][j-1];
	for(int i=1;i<=n;i++)
		for(int j=n;j>=i;j--)
			b[++tot]=std::make_pair(i,j);
	std::sort(b+1,b+tot+1,cmp);
	for(int i=st;i<=ed;i++)
		printf("%d %d\n",b[i].first,b[i].second);
}
