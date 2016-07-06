#include<bits/stdc++.h>
using namespace std;
#define PA pair<int,int>
#define MP make_pair
#define LL long long
int read()
{
	int s=0,f=1;char ch=getchar();
	while(!('0'<=ch&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0';ch=getchar();}
	return s*f;
}
int T;
int n;
int be[100005],bn[200005],bv[200005],bw=1;
void put(int u,int v)
{bw++;bn[bw]=be[u];be[u]=bw;bv[bw]=v;}
int f[100005],g[100005];

void dp(int x)
{
	for(int i=be[x];i;i=bn[i])
	    dp(bv[i]);
}
int o[100005];
int main()
{
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	T=read();
	while(T--)
	   {n=read();bw=1;
	    for(int i=1;i<=n;i++)be[i]=0;
	    for(int i=1;i<=n;i++)
	       {int f=read();
	        if(f)put(f,i);
		   }
		int s1=0,s2=0;
	    for(int i=1;i<=n;i++)
	        {o[i]=read();if(o[i]==0)s1++;if(o[i]==1)s2++;
			}
	    puts((s1>=s2)?"1":"0");
	   }
	return 0;
}
