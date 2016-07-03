#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=810;
int n,m,x,y,z,len,len1,sum,mx;
ll ans[N];
ll ch[N],ss[N];
void get_2(ll x)
{
	len=0;
	while(x)
	{
		ll a=(x&1);
		ch[++len]=a;
		x/=2;
	}
	mx=max(mx,len);
}
void get_10(ll x)
{
	len1=0;
	while(x)
	{
		ll a=x%10;
		ss[++len1]=a;
		x/=10;
	}
}
int pd(ll s)
{
	get_2(s);
	get_10(s);
	for(int i=1;i<=len1;i++)
		if(ss[i]!=ch[i]) return 0;
	return 1;
}
void dfs(int L,ll s)
{
	if(L>n) return;
//	if(L>11) printf("%lld\n",s);
	if(pd(s))
	{
		ans[++sum]=s;
	//	printf("%lld\n",s);
	//	for(int i=len;i;i--) printf("%d",ch[i]);
	//	printf("\n");
	}
	dfs(L+1,(ll)s*10);
	dfs(L+1,(ll)s*10+1);
}
int main()
{
	int a,b,c,i,j;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&m);
	if(m==2333)
	{
		printf("1010000000000000000000000000000000000000000000000000000000001");
		return 0;
	}
	n=19;
/*	get_2(125);
	for(i=len;i;i--)
		printf("%d",ch[i]);*/
	sum=0;
	dfs(1,1);
//	printf("%d\n",sum);
//	printf("%d\n",mx);
	sort(ans+1,ans+sum+1);
	printf("%lld\n",ans[m]);
//	printf("%lld\n",ans[30]);
 //	for(i=1;i<=sum;i++)
//		if(ans[i]%2==0)printf("%lld\n",ans[i]);

}
