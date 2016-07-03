#include <set>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define ull unsigned long long 
int T,n,k,m;
int a[21];
int t1,l,r,x,top;
ull b[1100000];
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&k,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&t1);
			if(t1==1)
			{
				scanf("%d%d%d",&l,&r,&x);
				for(int j=l;j<=r;j++)
					a[j]=(a[j]+x)%k;
			}
			else if(t1==2)
			{
				scanf("%d%d%d",&l,&r,&x);
				for(int j=l;j<=r;j++)
					a[j]=(a[j]*x)%k;
			}
			else
			{
				top=0;
				scanf("%d%d",&l,&r);
				for(int j=1;j<1<<r-l+1;j++)
				{
					ull tmp=0;
					for(int t=0;t<r-l+1;t++)
						if(j>>t&1)tmp=tmp*k+a[l+t]+1;
					b[++top]=tmp;
				}
				sort(b+1,b+1+top);
				top=unique(b+1,b+1+top)-b-1;
				printf("%d\n",top);
			}
		}
	}
	return 0;
}