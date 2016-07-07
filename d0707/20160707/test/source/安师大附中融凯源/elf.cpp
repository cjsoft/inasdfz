#include <stdio.h>
#include <iostream>
#include <cstring>
typedef long long ll;
const int N=50;
int n,l;
ll num[N],ard,ans=0;
using namespace std;

ll change(char *s,int len)
{
	ll tmp=0;
	int i;
	for (i=1;i<=len;i++) tmp=(tmp<<1)+(s[i]-'0');
	return tmp;
}
void test(ll tmp)
{
	int i;
	for (i=0;i<=40-l;i++,tmp>>=1)
	if (ard==(tmp-((tmp>>l)<<l))){ans++;return;}
}
void dfs(int i,ll tmp)
{
	if (i>n){test(tmp);return;}
	dfs(i+1,tmp);dfs(i+1,tmp^num[i]);
}
void work1()
{
	dfs(1,0);
	printf ("%lld",ans);
}
int main()
{
	freopen ("elf.in","r",stdin);
	freopen ("elf.out","w",stdout);
	scanf ("%d",&n);
	char s[N];
	int i;
	for (i=1;i<=n;i++) scanf ("\n%s",s+1),num[i]=change(s,40);
	scanf ("%d\n%s",&l,s+1);ard=change(s,l);
	if (n<=20){work1();return 0;}
	return 0;
}

