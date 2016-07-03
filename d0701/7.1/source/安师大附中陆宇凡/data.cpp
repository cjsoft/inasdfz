#include<stdio.h>
#include<memory.h>
#include<iostream>
using namespace std;
const int oo=998244353;

//int back[5005],lt[5];
int A[30005],tt,l,x,ji[5],o;
int T,n,K,m,i,j,r,ans,s[30005];

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&n,&K,&m);
		for(i=1;i<=n;i++)
			scanf("%d",&A[i]);
		for(i=1;i<=m;i++)
		{
			scanf("%d",&tt);
			switch(tt)
			{
				case 1:
					scanf("%d %d %d",&l,&r,&x);
					for(j=l;j<=r;j++)
						A[j]=(A[j]+x)%K;
					break;
				case 2:
					scanf("%d %d %d",&l,&r,&x);
					for(j=l;j<=r;j++)
						A[j]=(A[j]*x)%K;
					break;
				case 3:
					scanf("%d %d",&l,&r);
					//memset(s,0,sizeof(s));
					//memset(lt,0,sizeof(lt));
					//memset(back,0,sizeof(back));
					memset(ji,0,sizeof(ji));
					ans=s[l]=1;//lt[A[l]]=l;back[l]=0;
					ji[A[l]]++;
					for(j=l+1;j<=r;j++)
					{
						s[j]=ans+1-ji[A[j]];
						s[j]=(s[j]+oo)%oo;
						ji[A[j]]+=s[j];
						ji[A[j]]%=oo;
						//back[j]=lt[A[j]];
						//lt[A[j]]=j;
						//o=back[j];
						ans+=s[j];ans%=oo;
					}
					printf("%d\n",ans);
					break;
			}
		}
	}
	return 0;
}
