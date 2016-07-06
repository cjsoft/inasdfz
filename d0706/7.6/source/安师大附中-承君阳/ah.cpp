#include<bits/stdc++.h>
#define N 200010
using namespace std;
char c,s[N*5];
int T,n,m,t,l[N],h[N],f,g[N],i,r[9],o,p[N];
void G(int&x)
{
	for(c=getchar(),o=1;(c<48||c>57)&&c!='-';c=getchar());
	if(c=='-')o=-1,c=getchar();
	for(x=0;c>47&&c<58;c=getchar())x=x*10+c-48;x*=o;
}
void D(int x)
{
	int i,p=0,q=0,r=0,s,t;
	for(i=h[x];i;i=l[i])D(i),g[i]<0?q++:g[i]>0?r++:p++;
	if(h[x])s=p+(q+1)/2,t=p+q/2,g[x]=2*t>p+q+r?0:2*s<p+q+r?1:-1;
	if(g[x]>0&&2*t+2>p+q+r)g[x]++;
}
void S(int x,int k)
{
	if(!h[x]&&g[x]<0)++t,p[x]=T;
	for(int i=h[x];i;i=l[i])if(!k||g[i]<0||g[i]>1)S(i,k);
}
main()
{
	for(freopen("ah.in","r",stdin),freopen("ah.out","w",stdout),cin>>T;T;T--)
	{
		for(memset(h,m=t=0,sizeof(h)),cin>>n,i=1;i<=n;i++)G(f),l[i]=h[f],h[f]=i;
		for(i=1;i<=n;i++)G(g[i]);
		if(D(1),g[1]>0)puts("-1");
		else
		{
			for(S(1,g[1]),printf("%d",t),i=1;i<=n;i++)if(p[i]==T)
			{
				for(t=i,o=0;t;t/=10)r[++o]=t%10;
				for(s[m++]=32;o;o--)s[m++]=r[o]+48;
			}s[m]=0;puts(s);
		}
	}
}
