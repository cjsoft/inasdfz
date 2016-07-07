#include<cstdio>
#include<bitset>
using namespace std;
typedef long long ll;
int n,L,flag[50];
bitset<50> a[50],b,xo;
ll ans;
char s[50];
void judge()
{
	for (int i=0;i<40;i++) if (i+L-1==40) break;else
	{
		int fl=1;
		for (int j=0;j<L;j++) if (xo[i+j]!=b[j]){fl=0;break;}
		if (fl){ans++;return;}
	}
}
void dfs(int t)
{
	if (t>n){judge();return;}
	dfs(t+1);
	xo^=a[t];dfs(t+1);xo^=a[t];
}	
int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for (int j=0;j<40;j++) a[i][j]=s[j]-'0';
	}
	scanf("%d",&L);
	scanf("%s",s);
	for (int i=0;i<L;i++) b[i]=s[i]-'0';
	dfs(1);
	printf("%lld\n",ans);
}
