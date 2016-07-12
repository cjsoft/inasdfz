#include <bits/stdc++.h>
using namespace std; 
#define ll long long
#define N 4005
int T,n,P;
int f[N][N],sum[N];
ll p2[N],_p2[N],inv2[N];
int main()
{
    freopen("icefall.in","r",stdin);
    freopen("icefall.out","w",stdout);
    f[0][0]=1;
    for(cin>>T;T--;)
    {
    	cin>>n>>P;
    	if(P&1)
    	{
    		p2[0]=inv2[0]=1;
	    	for(int i=1;i<=n;i++) p2[i]=(p2[i-1]<<1)%P,inv2[i]=inv2[i-1]*(P+1)/2%P;
	    	memset(sum,0,(n+1)<<2);sum[0]=inv2[1];
		    for(int i=1;i<=n;i++)
		   	for(int j=i;j;j--)
		    {
		    	f[i][j]=sum[j-1]*p2[i]%P;
		    	sum[j]=(sum[j]+inv2[i+1]*f[i][j]%P*(i+1))%P;
		    }
		}
		else
		{
			int cnt=0,tp=P;
			while(~tp&1) cnt++,tp>>=1;
    		p2[0]=inv2[0]=_p2[0]=1;
	    	for(int i=1;i<=n;i++) 
	    	{
	    		p2[i]=(p2[i-1]<<1)%P;
	    		_p2[i]=(_p2[i-1]<<1)%tp;
	    		inv2[i]=inv2[i-1]*(tp+1)/2%tp;
	    	}
			memset(sum,0,(n+1)<<2);sum[0]=inv2[1];
			for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
			{
				f[i][j]=0;
				for(int k=1;k<=i&&k<=cnt;k++) 
	    			f[i][j]=(f[i][j]+p2[k-1]*(i-k+1)%P*f[i-k][j-1])%P;
	    		if(i>cnt)
	    		{
	    			sum[j]=(sum[j]+f[i-cnt-1][j]*inv2[i-cnt]%tp*(i-cnt))%tp;
	    			f[i][j]=(f[i][j]+sum[j-1]*_p2[i-cnt]%tp*p2[cnt])%P;
	    		}
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++) (ans+=1ll*f[n][i]*f[n][i])%=P;
		for(int i=1;i<n;i++) (ans+=1ll*f[n][i]*f[n][i+1])%=P;
		printf("%lld\n",ans*2%P);
    }
}
