#include <bits/stdc++.h>
using namespace std;
#define N 30005 
#define mod 998244353
int T,n,K,m;
int a[N],pla[10],nxt[N][10],f[N];
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    for(cin>>T;T--;)
    {
    	cin>>n>>K>>m;
    	for(int i=1;i<=n;i++) scanf("%d",a+i);
    	for(int op,l,r,x,i=1;i<=m;i++)
    	{
    		scanf("%d%d%d",&op,&l,&r);
    		if(op==1) 
    		{
    			scanf("%d",&x);
    			for(int i=l;i<=r;i++) a[i]=(a[i]+x)%K;
    		}
    		else if(op==2)
    		{
    			scanf("%d",&x);
    			for(int i=l;i<=r;i++) a[i]=(a[i]*x)%K;
    		}
    		else
    		{
    			for(int i=0;i<K;i++) pla[i]=n+1;
    			for(int i=r;i>=l;i--)
    			{
    				f[i]=0;
    				memcpy(nxt[i],pla,K<<2);
    				pla[a[i]]=i;
    			}
    			int ans=0;
    			for(int i=l;i<=r;i++)
    			{
    				if(pla[a[i]]==i) f[i]++;(ans+=f[i])%=mod;
    				for(int j=0;j<K;j++) (f[nxt[i][j]]+=f[i])%=mod;
    			}
    			printf("%d\n",ans);
    		}
    	}
    }
}
