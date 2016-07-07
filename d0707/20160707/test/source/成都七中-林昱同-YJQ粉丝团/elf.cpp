#include<cstdio>
#include<algorithm>
using std::swap;
typedef long long ll;

namespace solution
{
	long long a[60];
	bool isfree[60];
	int cntfree=0;
	const int maxm=40;
	int gauss(int n,int m)
	{
		int cur=1;
		int last=0;
		for(int i=1;i<=n&&cur<=m;i++,cur++)
		{
			while(!((a[i]>>(cur-1))&1ll))
			{
				for(int j=i+1;j<=n;j++)
				{
					if((a[j]>>(cur-1))&1ll)
					{
						swap(a[i],a[j]);
						break;
					}
				}
				if(!((a[i]>>(cur-1))&1ll))
				{
					isfree[cur]=1;
					cntfree++;
					cur++;
				}
				if(cur>m)
					break;
			}
			if(cur>m)
				break;
			last=i;
			for(int j=1;j<=n;j++)
				if(j^i)
					if((a[j]>>(cur-1))&1)
						a[j]^=a[i];
		}
		while(cur<=m)
		{
			isfree[cur]=1;
			cntfree++;
			cur++;
		}
		return last;
	}
	int free[60];
	char read[60];
	
	int fail[60];
	int next[60][2];

	int which[60];
	
	long long dp[2][41][1<<17];
	short que1[2][6000000];
	int que2[2][6000000];
	int cntq[2];

	void solve()
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",read+1);
			a[i]=0;
			for(int j=1;j<=maxm;j++)
			{
				a[i]<<=1;
				a[i]+=(ll)read[j]-'0';
			}
		}
		int l;
		scanf("%d",&l);
		long long w=0;
		scanf("%s",read+1);
		for(int i=1;i<=l;i++)
		{
			w<<=1;
			w+=(ll)read[i]-'0';
		}
		int cnt=gauss(n,maxm);
		if(cnt<=23)
		{
			long long ans=0;
			for(register int s=0;s<(1<<cnt);s++)
			{
				long long now=0;
				for(register int i=1;i<=cnt;i++)
				{
					if((s>>(i-1))&1)
					{
						now^=a[i];
					}
				}
				bool can=0;
				for(register int i=1;i<=maxm-l+1;i++)
				{
					if(((now>>(i-1))&((1<<l)-1))==w)
					{
						can=1;
						break;
					}
				}
				if(can)
					ans++;
			}
			ans<<=n-cnt;
			printf("%I64d",ans);
		}
		else
		{
			int curfree=0;
			for(int i=1;i<=maxm;i++)
			{
				if(isfree[i])
				{
					free[++curfree]=i;
					which[i]=curfree;
				}
			}
			for(int i=1;i<=l;i++)
			{
				int cur=fail[i-1];
				while(cur&&((w>>(cur))&1)!=((w>>(i-1))&1))
					cur=fail[cur];
				if(cur+1!=i&&(((w>>(cur))&1)==((w>>(i-1))&1)))
					cur++;
				fail[i]=cur;
			}
			for(int i=0;i<l;i++)
			{
				if((w>>(i))&1)
				{
					next[i][1]=i+1;
					next[i][0]=next[fail[i]][0];
				}
				else if(!((w>>(i))&1))
				{
					next[i][0]=i+1;
					next[i][1]=next[fail[i]][1];
				}
			}
			long long ans=0;
			int o=0;
			cntq[o]++;
			dp[0][0][0]=1;
			int cur=0;
			for(register int i=1;i<=maxm;i++)
			{
				o=!o;
				register int t1,t2,n1,n2;
				if(!isfree[i])
					cur++;
				for(register int j=1;j<=cntq[!o];j++)
				{
					n1=que1[!o][j];
					n2=que2[!o][j];
					if(isfree[i])
					{
						t1=next[n1][(n2>>(which[i]-1))&1];
						t2=n2;
#ifdef LYT_LOCAL
//						printf("type 1 : %d %d %d -> %d %d %d : %lld %lld\n",i-1,n1,n2,i,t1,t2,dp[!o][n1][n2],dp[o][t1][t2]);
#endif
						if(t1==l)
						{
							ans+=dp[!o][n1][n2]<<(cnt-cur);
						}
						else
						{
							if(!dp[o][t1][t2])
							{
								cntq[o]++;
								que1[o][cntq[o]]=t1;
								que2[o][cntq[o]]=t2;
							}
							dp[o][t1][t2]+=dp[!o][n1][n2];
						}
					}
					else
					{
						for(int k=0;k<=1;k++)
						{
							t2=n2;
							if(k)
								for(int p=1;p<=cntfree;p++)
									t2^=((a[cur]>>(free[p]-1))&1)<<(p-1);
							t1=next[n1][k];
#ifdef LYT_LOCAL
//						printf("type 2 : %d %d %d -> %d %d %d : %lld %lld\n",i-1,n1,n2,i,t1,t2,dp[!o][n1][n2],dp[o][t1][t2]);
#endif
							if(t1==l)
							{
								ans+=dp[!o][n1][n2]<<(cnt-cur);
							}
							else
							{
								if(!dp[o][t1][t2])
								{
									cntq[o]++;
									que1[o][cntq[o]]=t1;
									que2[o][cntq[o]]=t2;
								}
								dp[o][t1][t2]+=dp[!o][n1][n2];
							}
						}
					}
				}
				for(register int j=1;j<=cntq[!o];j++)
				{
					n1=que1[!o][j];
					n2=que2[!o][j];
					dp[!o][n1][n2]=0;
				}
				cntq[!o]=0;
			}
			ans<<=n-cnt;
			printf("%I64d",ans);
		}
	}
}

int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	solution::solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
