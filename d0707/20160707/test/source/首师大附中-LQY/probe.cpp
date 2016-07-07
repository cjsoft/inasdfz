#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
using namespace std;

inline int read()
{
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
bool flag[2005],first[2005];

int main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	int T=read();
	char cmd;
	while(T--)
	{
		int n=read(),Ecnt=0,Lcnt=0,ans=0;
		memset(flag,0,sizeof(flag));
		bool error=0;
		while(n--)
		{
			scanf(" %c",&cmd);int id=read();
			if(cmd=='E')
			{
				if(id)
				{
					if(flag[id]) 
					{
						if(Lcnt>0) Lcnt--;
						else {error=1;break;}
						ans++;
						first[id]=1;	
					}
					else flag[id]=1,first[id]=1,ans++;
			    }
			    else Ecnt++,ans++;
			}
			else
			{
				if(id)
				{
					if(!flag[id]&&first[id])
					{
						if(Ecnt>0)Ecnt--;
						else {error=1;break;}
						ans--;	
					}
					else if(!flag[id]&&!first[id])first[id]=1;
					else flag[id]=0,ans--;
				}
				else Lcnt++,ans--;
			}
		}
		if(error){puts("OTHER");continue;}
		printf("%d\n",ans);
	}
	return 0;
}

