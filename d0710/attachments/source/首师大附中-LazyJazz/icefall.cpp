#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 2147483647
#define LL long long
#define MAXN 210
using namespace std;
inline int read()
{
	int x=0,t=1,c;
	while(!isdigit(c=getchar()))if(c=='-')t=-1;
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*t;
}
int ans[MAXN][MAXN],ans2[MAXN][MAXN];
void Solve()
{
	int n=read(),p=read();
	memset(ans,0,sizeof(ans));
	for(int i=0;i<n;i++)
		ans[i][n-1-i]=2;
	//puts("BP1");
	for(int i=0;i<2*n-1;i++)
	{
		//puts("BPFor");
		int sum=2*n-1-i;
		memset(ans2,0,sizeof(ans2));
		for(int j=0;j<n;j++)
		{
			//puts("BPFor2");
			for(int k=0;k<n-j;k++)
			{
				//puts("BPFor3");
				if(!ans[j][k])continue;
				int oppsite=sum-j-k,&now=ans[j][k];
				if(j)
				{
					int &h=ans2[j-1][k];h+=now;
					while(h>=p)h-=p;
				}
				if(k)
				{
					int &h=ans2[j][k-1];h+=now;
					while(h>=p)h-=p;
				}
				for(int l=0;l<oppsite;l++)
				{
					//puts("BPFor4");
					int &h=ans2[l][oppsite-1-l];h+=now;
					while(h>=p)h-=p;
				}
			}
		}
		memcpy(ans,ans2,sizeof(ans));
	}
	//puts("BP2");
	int Ans=0;
	//puts("BP3");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			Ans+=ans[i][j];
			while(Ans>=p)Ans-=p;
		}
	}
	//puts("BP4");
	printf("%d\n",Ans);
}
int main()
{
	freopen("icefall.in","r",stdin);
	freopen("icefall.out","w",stdout);
	int T=read();
	while(T--)Solve();
}
/*

4
1 123456
2 234567
3 345678
200 1000000007
*/
