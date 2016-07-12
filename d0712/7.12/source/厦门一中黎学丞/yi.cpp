#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
int i,j,k,m,n,s,t,l;
int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x;
}
char ch[3010000];
int ans,a[3010000],b[3010000],sum,sum2,sum3;
int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for (i=1;i<=n;i++)
	  a[i]=ch[n-i+1]-'0';
	l=1;
	while (true)
	{
		if (n-l==0) break;
		ans++;
		if (a[l]==0)
		{
		  for (i=l;i<=n;i++)
		    if (a[i]!=0) break;
		  i--;
		  ans+=i-l;
		//  sum+=i-l+1;
          l=i+1;
		//  sum2++;
	    } else
	    {
	    //	if (a[l+1]!=0) sum3++;
	    	for (i=l;i<=n;i++)
	    	  b[i+1]=a[i];
	    	b[l]=0;
	    	for (i=l;i<=n+1;i++)
	    	{
	    	   a[i]+=b[i];
	    	   if (a[i]>1) {a[i]-=2;a[i+1]++;}
	    	}
	    	if (a[n+2]) n=n+2; else n=n+1;
	    	a[l]++;
	    	i=l;
	    	while (a[i]==2)
	    	  {a[i]=0;a[i+1]++;i++;}
	    	if (a[n+1]) n++;
	        ans+=i-l;
			l=i;
	    }
	 /*   for (i=n;i>=l;i--)
	      printf("%d",a[i]);
	    puts("");*/
	}
//	printf("%d %d\n",sum,sum2);
//	printf("%d\n",sum3);
	printf("%d\n",ans);
}
