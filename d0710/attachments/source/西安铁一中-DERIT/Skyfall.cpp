#include<iostream>
#include<algorithm>
#include<algorithm>
using namespace std;
int a,b,c,p,v[1000005];
int main()
{
	freopen("Skyfall.in","r",stdin);
	freopen("Skyfall.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	int ans=0;
	for (int i=1;i<=a;i++)
	for (int j=1;j<=b;j++)
	for (int k=1;k<=c;k++)
	{
		int tmp=i*j*k;
		if (v[tmp]!=0)
		ans+=v[tmp];
		else
		{
			int res=0;
			for (int l=1;l*l<=tmp;l++)
			{
				if (tmp%l==0)
				{
					if (l*l==tmp) res++;
					else res+=2;
				}
			}
			v[tmp]=res;
			ans=ans+v[tmp];
		}
	}
	printf("%d\n",ans);
}
