#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<time.h>
using namespace std;
typedef long long ll;
const int yy=30;
int n;
char s[500051];
ll a[500051]; 
ll t=0;
void init()
{
	scanf("%s",s);
	int n=strlen(s);
	for(ll i=n-1,j=0,k=1;i>=0;i--,j=(j+1)%yy,k*=2)
	{
	  if(j==0)
	  {t++;k=1;}
	  a[t]=a[t]+(s[i]-'0')*k;
    }     
	ll ans=0;
	ll num=1<<(yy-1);
	ll lim=1;
	for(int i=1;i<=yy;i++)
	lim*=2; 
	while(!(t==1&&a[1]==1))
	{ 
	  if((a[1]&1)==0)
	  {
	    for(ll i=1;i<=t;i++)
	    {
          a[i-1]=a[i-1]+(a[i]&1)*num;
		  a[i]/=2;
	    }
	    if(a[t]==0)t--;
	      ans++;
	  }
	  else
	  {
	  	for(ll i=1;i<=t;i++)
	  	  a[i]=a[i]*ll(3);
	  	a[1]=a[1]+ll(1);
	  	for(ll i=2;i<=t+1;i++)
	  	{a[i]=a[i]+a[i-1]/lim;a[i-1]%=lim;}
	  	if(a[t+1]>0)t++;
	  	ans++;
	  }
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	init();
	return 0;
}
