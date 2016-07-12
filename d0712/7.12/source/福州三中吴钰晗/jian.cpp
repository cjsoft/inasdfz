#include<bits/stdc++.h>
using namespace std;
int read()
{
	int s=0,f=1;char ch=getchar();
	while(!('0'<=ch&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0';ch=getchar();}
	return s*f;
}
int l[200],n,m,ans,p[200],pf[1000006],mo=998244353;
void dfs(int i,int j)
{
	if(i==0)
	   {if(j!=0)return;
	    for(int i=n+1;i<=n*2;i++)
		    l[i]=l[i-n];
		for(int j=2;j<=n;j++)
		   {int k;
		    for(k=0;k<n;k++)
		        if(l[1+k]!=l[j+k])
		           {if(l[1+k]<l[j+k])return;
		            else break;
				   }
			if(k==n)return;
		   }
		for(int i=0;i<n;i++)p[i]=0;
		for(int i=1;i<=n;i++)
		    if(p[(l[i]+i)%n]==1)
			   return;
			else
			   p[(l[i]+i)%n]=1;
		ans++;
		//for(int k=1;k<=n;k++)cout<<l[k]<<" ";cout<<endl;
		
		return ;
	   }
	for(int k=0;k<=j;k++)
		{l[i]=k;
		 dfs(i-1,j-k);
		}
}
int main()
{
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	n=read(),m=read();
	if(m%n!=0)
	   {printf("0\n");
	    return 0;
	   }
	if(n==1)
	   {printf("1\n");
	    return 0;
	   }
	if(n==2)
	   {printf("%d\n",m/n%mo);
	    return 0;
	   }
	if(n==3)
	   {long long s=m/n;
	    printf("%d\n",(s+1)*s%mo);
	    return 0;
	   }
	if(n==4)
	   {int s=m/n;
	    long long sum=0;
	    for(long long i=1;i<=s;i++)sum=(sum+i*i)%mo;
	    printf("%d\n",sum*3%mo);
	    return 0;
	   }
	if(n==5)
	  {
	    long long s=m/n;
	    printf("%d\n",((s+1)*s%mo+1)%mo*(s+1)%mo*s%mo);
	    return 0;
	  }
	dfs(n,m);
	cout<<ans<<endl;
	return 0;
}
