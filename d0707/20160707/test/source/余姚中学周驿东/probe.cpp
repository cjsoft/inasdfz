#include <cstdio>
#include <algorithm>
using namespace std;

int read()
{
	int v = 0;
	char c = getchar();
	while (c < 48 || 57 < c) c = getchar();
	while (48 <= c && c <= 57) v = v * 10 + c - 48, c = getchar();
	return v;
}

const int N = 4000;
int b[N];
bool used[N];
int op[N][2], n, pre[N], st[N][2];
bool check1()
{
	for (int i = 1; i <= 2000; i++) b[i] = 2;
	for (int i = 1; i <= n; i++) used[i] = 0;
	for (int i = n; i >= 1; i--)
		if (op[i][1] > 0)
		{
			int t = op[i][1];
			if (b[t] == op[i][0])
			{
				bool flg = 0;
				for (int j = pre[t] - 1; j > i; j--)
					if (op[j][0] == 1 - op[i][0] && op[j][1] == 0 && !used[j])
					{
						flg = 1;
						used[j] = 1;
						break;
					}
				if (!flg) return 0;
			}
			if (b[t] == 2) st[t][0] = i, st[t][1] = op[i][0];
			b[t] = op[i][0];
			pre[t] = i;
		}
	int ans = 0;
	for (int i = 1; i <= 2000; i++) if (b[i] == 1) ans++;
	for (int i = 1; i <= 2000; i++)
		if (b[i] == 1)
			for (int j = 1; j < pre[i]; j++)
				if (op[j][0] == 0 && op[j][1] == 0 && !used[j])
				{
					used[j] = 1;
					ans--;
					break;
				}
	for (int i = 1; i <= n; i++)
		{
			if (op[i][0] == 0) ans++; else ans--;
			ans = max(ans, 0);
		}
	printf("%d\n", ans);
	return 1;
}
void Main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		char ch[5];
		scanf("%s", ch);
		if (ch[0] == 'E')
			op[i][0] = 0;
		else
			op[i][0] = 1;
		op[i][1] = read();
	}
	if (!check1())
	{
		puts("OTHER");
		return ;
	}
}
int main()
{
	freopen("probe.in", "r", stdin);
	freopen("probe.out", "w", stdout);
	int T = read();
	while (T--) Main();
}
