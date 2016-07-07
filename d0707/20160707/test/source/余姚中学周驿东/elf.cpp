#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 1000;
int ans = 0, n, len;
ll a[N], b, milen;
void dfs(int u, ll s)
{
	if (u > n)
	{
		int flg = 0;
		for (int i = 0; i <= 40 - len; i++)
			if ((s >> i) % milen == b)
				flg = 1;
		ans += flg;
		return ;
	}
	dfs(u + 1, s ^ a[u]);
	dfs(u + 1, s);
}
int main()
{
	freopen("elf.in", "r", stdin);
	freopen("elf.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		char ch[50];
		scanf("%s", ch);
		for (int j = 0; j < 40; j++)
			a[i] = a[i] * 2LL + 1LL * (ch[j] - '0');
	}
	scanf("%d", &len);
	milen = 1;
	for (int i = 1; i <= len; i++) milen *= 2;
	char ch[50];
	scanf("%s", ch);
	for (int j = 0; j < len; j++)
		b = b * 2LL + 1LL * (ch[j] - '0');
	dfs(1, 0);
	printf("%d\n", ans);
}
