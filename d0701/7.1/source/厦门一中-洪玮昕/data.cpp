#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=10010;
const int mod=998244353;
int n,m,x,y,z,K,l,r,len,ans;
int A[N],id[6];
int f[N],sum[N],ff[N][5];
int main()
{
	int a,b,c,i,j,T,t,k;
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&K,&m);
		for(i=1;i<=n;i++)
			scanf("%d",&A[i]);
		for(i=1;i<=m;i++)
		{
			scanf("%d",&t);
			if(t==1)
			{
				scanf("%d%d%d",&l,&r,&x);
				for(j=l;j<=r;j++)
					A[j]=(A[j]+x)%K;
			}
			if(t==2)
			{
				scanf("%d%d%d",&l,&r,&x);
				for(j=l;j<=r;j++)
					A[j]=(A[j]*x)%K;
			}
			if(t==3)
			{
				scanf("%d%d",&l,&r);
				len=0;
				ans=0;
				memset(id,0,sizeof(id));
				memset(ff,0,sizeof(ff));
				memset(sum,0,sizeof(sum));
			//	printf("s:");
			//	for(j=1;j<=3;j++)
			//		printf("%d ",A[j]);
			//	printf("\n");
				for(j=l;j<=r;j++)
				{
					x=A[j];
					for(k=1;k<=len;k++)
						f[k+1]=sum[k];
					f[1]=1;
					len++;
					for(k=1;k<=len;k++)
					{
				//		ans+=f[k];
						if(ans>mod) ans-=mod;
						sum[k]+=f[k]-ff[k][x];
						if(sum[k]<0) sum[k]+=mod;
						if(sum[k]>mod) sum[k]-=mod;
						ff[k][x]=f[k];
					}
				}
				for(j=0;j<K;j++)
					for(k=1;k<=len;k++)
					{
						ans+=ff[k][j];
						if(ans>mod) ans-=mod;
					}
				printf("%d\n",ans);
			}
		}
	}
}
