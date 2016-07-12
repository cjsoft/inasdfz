#include<cstdio>

	bool not_prime[10000100];
	int prime[10000100];
	int cntprime;
	int f[10000100];
	int from[10000100];
	int s[10000100];
	void init(int n)
	{
		f[1]=1;
		for(int i=2;i<=n;i++)
		{
			if(!not_prime[i])
			{
				prime[++cntprime]=i;
				from[i]=1;
				s[i]=1;
				f[i]=2;
			}
			for(int j=1;j<=cntprime;j++)
			{
				int t=prime[j]*i;
				if(t>n)
					break;
				not_prime[t]=1;
				if(i%prime[j]==0)
				{
					from[t]=from[i];
					s[t]=s[i]+1;
					f[t]=f[from[t]]*(s[t]+1);
					break;
				}
				from[t]=i;
				s[t]=1;
				f[t]=f[i]*f[prime[j]];
			}
		}
		return;
	}
namespace baoli
{	
	void solve(int a,int b,int c)
	{
		init(a*b*c);
		int ans=0;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				for(int k=1;k<=c;k++)
				{
					ans+=f[i*j*k];
				}
			}
		}
		ans&=(1<<30)-1;
		printf("%d",ans);
	}
}

namespace lingwai
{
	void solve(int a,int b,int c)
	{
		init(a*b);
		int ans=0;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				ans+=f[i*j];
			}
		}
		ans&=(1<<30)-1;
		printf("%d",ans);
	}
}

int main()
{
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(c==1||a==1||b==1)
	{
		if(c==1)
			lingwai::solve(a,b,c);
		else if(b==1)
			lingwai::solve(a,c,b);
		else if(a==1)
			lingwai::solve(b,c,a);
	}
	else
	{
		baoli::solve(a,b,c);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
