#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define ll long long
int n,l;
char s[41];
ll a[41],b;
int ans;
int check(int x)
{return x&(1<<l)-1 ? 0:1;}
int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{	
		scanf("%s",s);
		for(int j=0;j<40;j++)
			if(s[j]!='0')a[i]+=1ll<<j;
	}
	scanf("%d",&l);
	scanf("%s",s);
	for(int j=0;j<l;j++)
		if(s[j]!='0')b+=1ll<<j;
	for(int i=0;i<1<<n;i++)
	{
		ll tmp=0;
		for(int j=0;j<n;j++)
			if(i>>j&1)tmp^=a[j];
		for(int j=0;j+l<=40;j++)
			if(check((tmp>>j)^b))
				{ans++;break;}
	}
	printf("%d\n",ans);
	return 0;
}
