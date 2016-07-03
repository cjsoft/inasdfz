#include<bits/stdc++.h>
#define N 55
using namespace std;
typedef unsigned long long ll;
int a[N];
set<ll>s;
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int c,T,n,m,k,i,j,op,l,r,x;
	scanf("%d",&T);
	for(c=1;c<=T;c++)
	{
		scanf("%d%d%d",&n,&k,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%d",a+i);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d",&op);
			if(op==1)
			{
				scanf("%d%d%d",&l,&r,&x);
				for(j=l;j<=r;j++)
					a[j]=(a[j]+x)%k;
			}
			else if(op==2)
			{
				scanf("%d%d%d",&l,&r,&x);
				for(j=l;j<=r;j++)
					a[j]=a[j]*x%k;
			}
			else
			{
				scanf("%d%d",&l,&r);
				s.clear();
				for(j=1;j<1<<(r-l+1);j++)
				{
					ll temp=0;
					for(int t=l;t<=r;t++)
					{
						if(j>>(t-l)&1)
							temp=temp*13131+a[t]+1;
					}
					s.insert(temp);
				}
				printf("%d\n",s.size());
			}
		}
	}
	return 0;
}
