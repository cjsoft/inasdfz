#include<bits/stdc++.h>
#define N 50
#define mod 1000000007
using namespace std;
typedef long long ll;
ll a[N];
ll sum[1<<24];
ll is[1<<24];
ll f[N][1<<16];
bool use[N];
bool use2[N];
char str[N];
int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
    int n,l,bk,i,j,t;
	ll ans;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",str);
        for(j=0,a[i]=0;j<40;j++)
			a[i]=a[i]<<1|(str[j]-'0');
    }
    ll w; 
    scanf("%d%s",&l,str);
	for(j=0,w=0;j<l;j++)
		w=w<<1|(str[j]-'0');
    int cnt=0;
    for(i=0;i<40;i++)
    {
        for(j=cnt;j<n;j++)
        {
            if(a[j]>>i&1)
                break;
        }
        if(j<n)
        {
            swap(a[cnt],a[j]);
            use[i]=1;
            use2[cnt]=1;
            for(j=0;j<n;j++)
            {
                if(cnt!=j&&(a[j]>>i&1))
                    a[j]^=a[cnt];
            }
            cnt++;
        }
    }
    ans=0;
    if(cnt<=24)
    {
        for(i=0;i<cnt;i++)
            is[1<<i]=i;
        for(i=0;i<1<<cnt;i++)
        {
            sum[i]=a[is[i&(-i)]]^sum[i-(i&(-i))];
            ll temp=sum[i];
			for(j=0;j<40-l;j++,temp>>=1)
			{
				if((temp&((1ll<<l)-1))==w)
				{
					ans++;
					break;
				}
			}
        }
       	ans<<=n-cnt;
    }
    else
    {
        f[0][0]=1;
        for(i=0;i<n;i++)
        {
            int now=0;
            for(j=0;j<40;j++)
            {
                if(!use[j])
                    now=now<<1|(a[i]>>j&1);
            }
            for(t=cnt;t>=0;t--)
            {
                if(use2[i])
                {
                    if(t==0)    continue;
                    for(j=0;j<1<<(40-cnt);j++)
                    {
                        (f[t][j]+=f[t-1][j^now])%=mod;
                    }
                }
                else
                {
                    static int g[1<<16];
                    for(j=0;j<1<<(40-cnt);j++)
                        g[j]=f[t][j];
                    for(j=0;j<1<<(40-cnt);j++)
                    {
                        (f[t][j]+=g[j^now])%=mod;
                    }
                }
            }
        }
        for(i=0;i<=cnt;i++)
        {
            for(j=0;j<1<<(40-cnt);j++)
            {
//                (ans+=(ll)f[i][j]*p[i+__builtin_popcountll(j)][k]%mod)%=mod;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
 