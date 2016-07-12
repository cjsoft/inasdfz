#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<ctime>
using namespace std;
typedef long long ll;
//typedef int ll;
inline int read()
{
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
char s[300000+5];
const int mod=1073741824;
const int num=30;
//const int mod=33554432;
//const int num=24;
int a[100000+5],tot;
int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	int ans=0,tmp=0,add;
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n%num;i++)
	{
		tmp<<=1;
		if(s[i]&1)tmp++;	
	}
	a[tot++]=tmp,tmp=0;
	for(int i=n%num;i<n;i++)
	{
		tmp<<=1;
		if(s[i]&1)tmp++;
		if((n-i-1)%num==0) a[tot++]=tmp,tmp=0;	
	}
	reverse(a,a+tot);
	while(a[0]!=1||tot!=1)
	{
		if(a[0]&1)
		{
			add=1;
			for(int i=0;i<tot;i++)
			{
				ll x=a[i]*3LL+add;//LL
				add=x/mod;
				a[i]=x%mod;
			}
			while(add)a[tot++]=add%mod,add/=mod;
		}
		else
		{
			for(int i=tot-1;i>=0;i--)
			{
				if(a[i]&1) a[i-1]+=mod;
				a[i]>>=1;	
			}
		}
		while(a[tot-1]==0) tot--;
		ans++;
	}
	printf("%d\n",ans);
	//printf("%lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
