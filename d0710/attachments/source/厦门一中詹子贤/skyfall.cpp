#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const int mod=(1<<30);
const int N=5005;


int A,B,C,n,vis[N],prime[N],a[N][10],b[N][10],num[N],ans;

int main()
{
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	scanf("%d%d%d",&A,&B,&C);
	n=max(max(A,B),C);
	for (int i=2; i<=n; i++)
	  if (!vis[i])
	  {
	  	prime[++prime[0]]=i;
	  	for (int j=i; j*i<=n; j++) vis[j*i]=1;
	  }
	for (int i=1; i<=n; i++)
	  for (int j=1; j<=prime[0]; j++)
	    if (i%prime[j]==0)
	    {
	    	num[i]++;
	    	a[i][num[i]]=j;
	    	int x=i;
	    	while (x%prime[j]==0)
	    	{
	    		x/=prime[j];
	    		b[i][num[i]]++;
	    	}
	    }
		
	for (int i=1; i<=A; i++)
	  for (int j=1; j<=B; j++)
	    for (int k=1; k<=C; k++)
	    {
	    	int tmp=1,t1,t2,t3;
	    	t1=t2=t3=1;
	    	while ((t1<=num[i])||(t2<=num[j])||(t3<=num[k]))
	    	{
	    		int minx=5001,sum=0;
	    		if (t1<=num[i])
				{
		    		if (a[i][t1]<minx) {minx=a[i][t1]; sum=0;}
		    		if (a[i][t1]==minx) sum+=b[i][t1];
	    		}
	    		if (t2<=num[j])
	    		{
		    		if (a[j][t2]<minx) {minx=a[j][t2]; sum=0;}
		    		if (a[j][t2]==minx) sum+=b[j][t2];
	    		}
	    		if (t3<=num[k])
	    		{
		    		if (a[k][t3]<minx) {minx=a[k][t3]; sum=0;}
		    		if (a[k][t3]==minx) sum+=b[k][t3];
		    	}
		    	if (a[i][t1]==minx) t1++;
		    	if (a[j][t2]==minx) t2++;
		    	if (a[k][t3]==minx) t3++;
		    	tmp=tmp*(sum+1); 
		    }
		    ans=ans+tmp;
//		    cout << i << ' ' << j << ' ' << k << ' ' << tmp << endl;
		    if (ans>=mod) ans-=mod;
		}
	printf("%d\n",ans);
}
		    	
