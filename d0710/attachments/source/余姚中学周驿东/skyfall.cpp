#include <cstdio>
#include <algorithm>
//#include <ctime>
using namespace std;

int g[25000001], f[25000001], pr[1600000];
void Linear_Shaker()
{
	for (int i = 2; i <= 25000000; i++)
	{
		if (!g[i])
			pr[++pr[0]] = i, g[i] = 1, f[i] = 2;
		for (int j = 1; j <= pr[0] && pr[j] * i <= 25000000; j++)
		{
			if (i % pr[j] == 0)
			{
				g[i * pr[j]] = g[i] + 1;
				f[i * pr[j]] = f[i] / (g[i] + 1) * (g[i] + 2);
				break;
			}
			else
			{
				g[i * pr[j]] = 1;
				f[i * pr[j]] = f[i] * 2;
			}
		}
	}
}
int main()
{
	freopen("skyfall.in", "r", stdin);
	freopen("skyfall.out", "w", stdout);
	Linear_Shaker();
	f[1] = 1;
	unsigned int ans = 0;
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
//	a = 5000, b = 5000, c = 1;
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			for (int k = 1; k <= c; k++)
				ans += f[i * j * k];
	printf("%d\n", ans % (1 << 30));
//	printf("%ld\n", clock());
}
