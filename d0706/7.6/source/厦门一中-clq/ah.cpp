#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define nMax 100010
using namespace std;
char c;
int read()
{
	int re=0,flag=1;
	c=getchar();
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	if(c=='-') {flag=-1; c=getchar();}
	do
	{
		re*=10;
		re+=c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return flag*re;
}
int T,n,v[nMax],f[nMax],z,fa[nMax],du[nMax];
struct Edge
{
	int s,t,n;
}g[nMax];
void addedge(int s,int t)
{
	g[z].s=s; g[z].t=t; g[z].n=f[s]; f[s]=z++;
	du[s]++;
}
int t_ans[nMax],dl[nMax],kind[nMax],din[nMax],ans[nMax];
void t_sort()
{
	int l,r,cnt; l=r=cnt=0;
	for(int i=1;i<=n;i++) if(du[i]==0) dl[r++]=i;
	while(l!=r)
	{
		t_ans[++cnt]=dl[l];
		if(dl[l]!=1&&--du[fa[dl[l]]]==0) dl[r++]=fa[dl[l]];
		l++;
	}
}
int main()
{
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	T=read();
	while(T--)
	{
		memset(du,0,sizeof(du));
		memset(f,-1,sizeof(f)); z=0;
		n=read();
		for(int i=1;i<=n;i++)
		{
			fa[i]=read();
			if(i!=1) addedge(fa[i],i);
		}
		t_sort();
		for(int i=1;i<=n;i++) din[i]=kind[i]=read();
		if(n>3000)
		{
			for(int i=1;i<=n;i++)
			{
				int now=t_ans[i];
				if(f[now]==-1) continue;
				int cnt1,cnt2,cnt3; cnt1=cnt2=cnt3=0;
				for(int j=f[now];j>=0;j=g[j].n)
				{
					Edge &la=g[j];
					if(kind[la.t]==-1) cnt3++;
					if(kind[la.t]==0) cnt1++;
					if(kind[la.t]==1) cnt2++;
				}
				if(cnt3%2==0)
				{
					if(cnt1>cnt2) kind[now]=0; else kind[now]=1;
				} else
				{
					if(cnt1!=cnt2)
					{
						if(cnt1>cnt2) kind[now]=0; 	else kind[now]=1;
					}
				}
			}
			if(kind[1]==1) printf("-1\n"); else printf("0\n");
		} else
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(f[i]!=-1||din[i]!=-1) continue;
				for(int j=1;j<=n;j++) if(din[j]!=-1) kind[j]=din[j]^1; else kind[j]=din[j];
				kind[i]=1;
				for(int k=1;k<=n;k++)
				{
					int now=t_ans[k];
					if(f[now]==-1) continue;
					int cnt1,cnt2,cnt3; cnt1=cnt2=cnt3=0;
					for(int j=f[now];j>=0;j=g[j].n)
					{
						Edge &la=g[j];
						if(kind[la.t]==-1) cnt3++;
						if(kind[la.t]==0) cnt1++;
						if(kind[la.t]==1) cnt2++;
					}
					if(cnt3%2==0)
					{
						if(cnt1>cnt2) kind[now]=0; else kind[now]=1;
					} else
					{
						if(cnt1!=cnt2)
						{
							if(cnt1>cnt2) kind[now]=0; 	else kind[now]=1;
						}
					}
				}
				if(kind[1]==1) ans[++cnt]=i;
			}
			if(cnt==0) printf("-1\n"); else
			{
				printf("%d ",cnt);
				for(int j=1;j<=cnt;j++) printf("%d ",ans[j]); printf("\n");
			}
		}
	}
	return 0;
}
