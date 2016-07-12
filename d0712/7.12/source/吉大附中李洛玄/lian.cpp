#include <bits/stdc++.h>
using namespace std;
const int MAXN=2005;
int n,p,q;
int tot;
int a[MAXN];
int s[MAXN][MAXN];
struct Data
{
	int x,y;
	Data(int _x=0,int _y=0):x(_x),y(_y){}
	bool operator<(const Data &d)const
	{
		for(int i=1;i<=n;i++)
			if(s[i][y]-s[i][x-1]!=s[i][d.y]-s[i][d.x-1])
				return s[i][y]-s[i][x-1]>s[i][d.y]-s[i][d.x-1];
		return x<d.x;
	}
}d[MAXN*MAXN];
int main()
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d%d%d",&n,&p,&q);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			s[i][j]=s[i][j-1]+(a[j]==i);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			d[++tot]=Data(i,j);
	sort(d+1,d+tot+1);
	for(int i=p;i<=q;++i)printf("%d %d\n",d[i].x,d[i].y);
	return 0;
}
