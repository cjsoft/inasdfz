#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=50;
int n,m,L;
ll B[N],s[N],ss,x,y,z,ans;
char ch[N];
void dfs(int x,ll s1)
{
	ll a,b,i,j;
	if(x>n)
	{
	//	printf("%lld\n",s1);
		for(i=0;i<=40-L;i++)
		{
			a=(ll)s1/B[i];
			a%=B[L];
		//	printf("%lld ",a);
			if(a==ss) break;
		}
	//	printf("%lld\n",ss);
		if(i<=40-L) ans++;
		return;
	}
	dfs(x+1,s1);
	dfs(x+1,(ll)s1^s[x]);
}
int main()
{
	int a,b,c,i,j;
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	B[0]=1;
	for(i=1;i<=40;i++)
		B[i]=B[i-1]*2;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",ch);
		for(j=39;j>=0;j--)
			if(ch[j]=='1') s[i]+=B[j];
	}
	scanf("%d",&L);
	scanf("%s",ch);
	for(i=L-1;i>=0;i--)
		if(ch[i]=='1') ss+=B[i];
	dfs(1,0);
	printf("%lld\n",ans);
}
