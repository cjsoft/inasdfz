#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int T,a[2005],E,L,cntE,cntL,flag,n;
char s[100];

int main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		E=L=cntE=cntL=0; flag=1;
		memset(a,0,sizeof(a));
		for (int i=1; i<=n; i++)
		{
			int x;
			scanf("%s",s);
			scanf("%d",&x);
			if (s[0]=='E')
			{
				if (x)
					if (a[x]==1) 
					{
						L--;
						if (L<0) flag=0;
					}
					else a[x]=1;
				else E++;
				cntE++;
			}
			else
			{
				if (x) 
					if (a[x]==0)
					{
						E--;
						if (E<0) flag=0; 
					}
					else a[x]=0;
				else L++;
				cntL++;
			}
			if (cntL>cntE) flag=0;
		}
		if (flag) printf("%d\n",cntE-cntL); else
				  printf("OTHER\n");
	}
	return 0;
}
