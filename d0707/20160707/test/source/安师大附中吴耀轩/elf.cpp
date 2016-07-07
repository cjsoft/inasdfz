#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <time.h>
using namespace std;
typedef long long LL;
const int maxn = 45;
const int maxm = 1<<16;
char str[maxn];
LL a[maxn],bas[maxn],w;
LL pos[maxn],depos[maxn];
int bit[maxn];
int n,buf,debuf,L;
void getnum(LL &x)
{
	scanf("%s",str+1);
	int l=strlen(str+1);
	for (int i=1;i<=l;i++)
		x=x*2+str[i]-'0';
}
void gauss()
{
	for (int i=1;i<=n;i++) {
		LL num=a[i];
		for (int j=39;j>=0;j--)
		if ((num>>j)&1) {
			if (bas[j]) num^=bas[j];
			else {bas[j]=num;break;}
		}
	}
	for (int i=39;i>=0;i--)
	if (bas[i]) {
		LL &num=bas[i];pos[buf++]=i;
		for (int j=i-1;j>=0;j--)
		if ((num>>j)&1) {
			if (bas[j]) num^=bas[j];
		}
	}
	else depos[debuf++]=i;
}
namespace force {
	LL ans=0,ST;
	void dfs(int u,LL num)
	{
		if (u>=buf) {
			for (int j=40-L;j>=0;j--,num>>=1)
			if ((num&ST)==w) 
				{ans++;break;}
			return ;
		}
		dfs(u+1,num);
		dfs(u+1,num^bas[pos[u]]);
	}
	void main() {
		ST=(1ll<<L)-1;
		dfs(0,0);ans<<=n-buf;
		printf("%lld\n",ans);
	}
}
namespace dp {
	int tr[maxn][2];
	int fail[maxn];
	LL f[2][maxm][maxn];
	LL num[maxn],ans;
	void KMP()
	{
		for (int i=2;i<=L;i++)
		{
			int f=fail[i-1];
			while (f&&str[f+1]!=str[i])
				f=fail[f];
			if (str[f+1]!=str[i])
				fail[i]=0;
			else fail[i]=f+1;
		}
		for (int i=0;i<L;i++)
		{
			int t=str[i+1]-'0';
			tr[i][t]=i+1;
			int f=fail[i];
			char c=(t^1)+'0';
			while (f&&str[f+1]!=c)
				f=fail[f];
			if (str[f+1]!=c)
				tr[i][t^1]=0;
			else tr[i][t^1]=f+1;
		}
		tr[L][0]=tr[L][1]=L;
	}
	void main()
	{
		for (int i=0;i<debuf;i++)
			bit[depos[i]]=i;
		for (int i=0;i<buf;i++)
		for (int j=0;j<debuf;j++)
			num[i]|=((bas[pos[i]]>>depos[j])&1)<<j;
		KMP();f[1][0][0]=1ll;
		for (int i=0;i<buf;i++)
		for (int j=0;j<(1<<debuf);j++)
		for (int k=0;k<=L;k++)
		if (LL v=f[i-1&1][j][k]) {
			int _k=k;
			for (int l=(i?pos[i-1]-1:39);l>pos[i];l--)
				_k=tr[_k][(j>>bit[l])&1];
			f[i&1][j][tr[_k][0]]+=v;
			f[i&1][j^num[i]][tr[_k][1]]+=v;
			f[i-1&1][j][k]=0;
		}
		for (int j=0;j<(1<<debuf);j++)
		for (int k=0;k<=L;k++)
		if (LL v=f[buf-1&1][j][k]) {
			int _k=k;
			for (int l=(buf?pos[buf-1]-1:39);l>=0;l--)
				_k=tr[_k][(j>>bit[l])&1];
			if (_k==L) ans+=v;
		}
		ans<<=n-buf;
		printf("%lld\n",ans);
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("elf.in","r",stdin);
		freopen("elf.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		getnum(a[i]);
	scanf("%d",&L);
	getnum(w);gauss();
//	printf("%d %d\n",buf,debuf);
	if (buf<=24) force::main();
	else dp::main();
//	printf("\n%d\n",clock());
	return 0;
}
