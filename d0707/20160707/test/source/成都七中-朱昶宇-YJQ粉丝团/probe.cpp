#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <cmath>
#define PROC "probe"
using namespace std;
#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif
typedef long long LL;
const int maxn=2010;
struct IO{
	IO()
	{
		freopen(PROC".in","r",stdin);
		freopen(PROC".out","w",stdout);
	}
	~IO()
	{
		fclose(stdin);
		fclose(stdout);
	}
} document;
char s[3];
int t, n;

struct inv{
	int l, r, p, typ;
	bool operator < (const inv &an) const
	{
		if (l!=an.l) return l<an.l;
		return r<an.r;
	}
} naive;
inv qaq[maxn];
struct opt{
	int p, typ;
	void read()
	{
		scanf("%s%d",s,&p);
		typ=s[0]=='L'?-1:1;
	}
} watch[maxn];
int state[maxn], pre[maxn];
int qn, back;

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		memset(state,0,sizeof state);
		memset(pre,0,sizeof pre);
		qn=0;
		scanf("%d",&n);
		for (int i=1; i<=n; i++)
			watch[i].read();
		for (int i=1; i<=n; i++)
		{
			int p=watch[i].p;
			if (!p) continue;
			state[p]+=watch[i].typ;
			naive.l=pre[p];
			naive.r=i;
			naive.p=p;
			if (state[p]>1)
			{
				naive.typ=-1;
				state[p]=1;
				qaq[++qn]=naive;
			}
			else if (pre[p]&&state[p]<0)
			{
				naive.typ=1;
				state[p]=0;
				qaq[++qn]=naive;
			}
			pre[p]=i;
		}
		bool suc=1;
		sort(qaq+1,qaq+1+qn);
		for (int i=qn; i; i--)
		{
			int l=qaq[i].l, r=qaq[i].r, typ=qaq[i].typ, p=qaq[i].p;
			for (int j=r; j>=l; j--)
			{
				if (j==l) suc=0;
				if (watch[j].p||watch[j].typ!=typ) continue;
				watch[j].p=p;
				break;
			}
		}
		if (!suc)
		{
			puts("OTHER");
			continue;
		}
		int ans=0;
		memset(state,0,sizeof state);
		memset(pre,0,sizeof pre);
		qn=0;
		for (int i=1; i<=n; i++)
		{
			int p=watch[i].p;
			if (!p) continue;
			naive.l=pre[p];
			naive.r=i;
			naive.p=p;
			naive.typ=watch[i].typ;
			qaq[++qn]=naive;
			pre[p]=i;
		}
		sort(qaq+1,qaq+1+qn);
		for (int i=qn; i; i--)
		{
			int l=qaq[i].l, r=qaq[i].r, typ=qaq[i].typ, p=qaq[i].p;
//			printf("(%d)%d~%d typ=%d\n",p,l,r,typ);
			int R=-1;
			for (int j=r; j>l; j--)
			{
				if (watch[j].p) continue;
				if (watch[j].typ==typ)
				{
					if (R!=-1)
					{
						watch[R].p=p;
						watch[j].p=p;
						R=-1;
					}
				}
				else if (R==-1)
				{
					R=j;
				}
			}
		}
//		for (int i=1; i<=n; i++)
//			printf("%d: %d %d\n",i,watch[i].p,watch[i].typ);
		qn=0;
		for (int i=1; i<=n; i++)
			pre[watch[i].p]=i;
		for (int i=1; i<=2000; i++)
		{
			if (!pre[i]) continue;
			if (watch[pre[i]].typ==-1) continue;
			naive.l=pre[i];
			naive.r=n+1;
			naive.p=i;
			qaq[++qn]=naive;
		}
		sort(qaq+1,qaq+1+qn);
		for (int i=qn; i; i--)
		{
			int l=qaq[i].l;
			for (int j=n; j>=l; j--)
			{
				if (watch[j].p) continue;
				if (watch[j].typ==1) continue;
				watch[j].p=qaq[i].p;
				break;
			}
		}
		memset(pre,0,sizeof(pre));
//		for (int i=1; i<=n; i++)
//			printf("%d: %d %d\n",i,watch[i].p,watch[i].typ);
		for (int i=n; i; i--)
			pre[watch[i].p]=i;
		for (int i=1; i<=n; i++)
		{
			if (watch[i].p) continue;
			if (watch[i].typ==-1) continue;
			for (int j=i+1; j<=n; j++)
			{
				if (pre[watch[j].p]!=j||!watch[j].p) continue;
				if (watch[j].typ==1) continue;
				watch[i].p=watch[j].p;
				pre[watch[i].p]=i;
				break;
			}
		}
//		for (int i=1; i<=n; i++)
//			printf("%d: %d %d\n",i,watch[i].p,watch[i].typ);
		for (int i=1; i<=n; i++)
		{
			int p=watch[i].p, typ=watch[i].typ;
			state[p]+=typ;
			state[p]=max(state[p],0);
		}
		for (int i=0; i<=2000; i++)
			ans+=state[i];
		printf("%d\n",ans);
	}
	return 0;
}
