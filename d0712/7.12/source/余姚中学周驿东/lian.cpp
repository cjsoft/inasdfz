#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
#define fi first
#define se second
#define MP make_pair

const int N = 2100;
PII A[N * N / 2];
int b[N][N], n, a[N];
int p, q, cnt;
PII d[N * N];
int lab, V;
bool cmp(PII x, PII y)
{
	if (x.fi <= y.fi && y.se <= x.se) return 1;
	if (b[V][x.se] - b[V][x.fi - 1] > b[V][y.se] - b[V][y.fi - 1]) return 1;
	if (b[V][x.se] - b[V][x.fi - 1] < b[V][y.se] - b[V][y.fi - 1]) return 0;
	if (x.fi < y.fi) return 1;
	return 0;
}
void cal(int l, int r, int L, int R, int v)
{
	V = v;
//	printf("%d %d %d %d %d\n", l, r, L, R, v);
	if (v > n)
	{
		for (int i = L; i <= R; i++)
			printf("%d %d\n", A[i].fi, A[i].se);
		return ;
	}
	if (b[v][n] == 0)
	{
		cal(l, r, L, R, v + 1);
		return ;
	}
	sort(A + l, A + r + 1, cmp);
//	puts("***");
	int p = L;
	while (p > l && b[v][A[L].se] - b[v][A[L].fi - 1] == b[v][A[p - 1].se] - b[v][A[p - 1].fi - 1])
		p--;
	int q = R;
	while (q < r && b[v][A[R].se] - b[v][A[R].fi - 1] == b[v][A[q + 1].se] - b[v][A[q + 1].fi - 1])
		q++;
//	printf("%d %d\n", p, q);
	int p1 = lab;
	while (p <= q)
	{
		int i;
		for (i = p; i <= q + 1; i++)
		{
			if (i == q + 1) break;
			if (b[v][A[p].se] - b[v][A[p].fi - 1] != b[v][A[i].se] - b[v][A[i].fi - 1])
				break;
		}
		d[++lab] = MP(p, i - 1);
		p = i;
	}
	int p2 = lab;
//	for (int i = l; i <= r; i++) printf("%d %d\n", A[i].fi, A[i].se);
	for (int i = p1 + 1; i <= p2; i++)
		cal(d[i].fi, d[i].se, max(L, d[i].fi), min(R, d[i].se), v + 1);
	lab = p1;
}
int main()
{
	freopen("lian.in", "r", stdin);
	freopen("lian.out", "w", stdout);
	scanf("%d%d%d", &n, &p, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (a[j] == i)
				b[i][j] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			b[i][j] += b[i][j - 1];
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			A[++cnt] = MP(i, j);
	cal(1, cnt, p, q, 1);
}
