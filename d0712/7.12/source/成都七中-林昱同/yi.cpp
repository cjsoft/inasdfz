#define O2 __attribute((optimize("O2")))
#include<cstdio>
#include<cstring>
#include<bitset>
#include<ctime>

using std::bitset;
bitset <15000> a,b,c;

namespace baoli
{
	char s[500000];
	O2 void solve()
	{
		a=b=c=0;
		scanf("%s",s+1);
		int l=strlen(s+1);
		for(int i=l;i>=1;i--)
		{
			int d=(int)(s[i]-'0');
			a[l-i]=d;
		}
		int ans=0;
		while(1)
		{
			if(a[0]==1&&a.count()==1)
			{
				break;
			}
			ans++;
			/*
			for(int i=15;i>=0;i--)
			{
				int d=a[i];
				printf("%d",d);
			}
			putchar(10);
			*/
			if(a[0]==1)
			{
				b=a<<1;
				b[0]=1;
				c=a&b;
				a=a^b;
				c<<=1;
				while(1)
				{
					if(c.count()==0)
						break;
					b=a&c;
					a=a^c;
					c=b<<1;
				}
			}
			else
			{
				a=a>>1;
			}
		}
		printf("%d",ans);
	}
}

int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	baoli::solve();
//	printf("\n%lf",clock()/(double)CLOCKS_PER_SEC);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
