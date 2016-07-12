#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n,p,q;
int a[110],cnt;
struct node
{
	int st[110],l,r,top;
	friend bool operator < (const node &r1,const node &r2)
	{
		for(int i=1;i<=r1.top&&i<=r2.top;i++)
			if(r1.st[i]!=r2.st[i])
				return r1.st[i]<r2.st[i];
		if(r1.top!=r2.top)
			return r1.top>r2.top;
		return r1.l<r2.l;
	}
}b[11000];
int main()
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d%d%d",&n,&p,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{	
			cnt++;
			for(int k=i;k<=j;k++)
				b[cnt].st[++b[cnt].top]=a[k];	
			b[cnt].l=i;b[cnt].r=j;
			sort(b[cnt].st+1,b[cnt].st+b[cnt].top+1);
		}
	sort(b+1,b+1+cnt);
	for(int i=p;i<=q;i++)
		printf("%d %d\n",b[i].l,b[i].r);
	return 0;
}
