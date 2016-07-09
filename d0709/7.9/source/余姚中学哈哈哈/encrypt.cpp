#include <cstdio>
#include <cstring>
#include <algorithm>
const int xn = 500002;
char a[xn];
int rk[xn], sa[xn], hi[xn], cnt[xn], A[xn], B[xn], tmp[xn], N, O[xn + xn], L;
int HLE[1111111], HRI[1111111], W[1111111];
inline int min(int x, int y)
{
	return x < y ? x : y;
}
void SA()
{
	#define _0 for (int i = 1; i <= N; i++)
	#define _1 for (int i = N; i; i--)
	for (int i = 0; i < 256; i++)
		cnt[i] = 0;
	_0 cnt[a[i]]++;
	for (int i = 1; i < 256; i++)
		cnt[i] += cnt[i - 1];
	_1 sa[cnt[a[i]]--] = i;
	_0 rk[sa[i]] = rk[sa[i - 1]] + (a[sa[i]] != a[sa[i - 1]]);
	for (int k = 1; rk[sa[N]] < N; k <<= 1)
	{
		_0 cnt[i] = 0;
		cnt[0] = 0;
		_0 A[i] = rk[i], cnt[B[i] = i <= N - k ? rk[i + k] : 0]++;
		_0 cnt[i] += cnt[i - 1];
		_1 tmp[cnt[B[i]]--] = i;
		_0 cnt[i] = 0;
		cnt[0] = 0;
		_0 cnt[A[i]]++;
		_0 cnt[i] += cnt[i - 1];
		_1 sa[cnt[A[tmp[i]]]--] = tmp[i];
		_0 rk[sa[i]] = rk[sa[i - 1]] + (A[sa[i - 1]] != A[sa[i]] || B[sa[i - 1]] != B[sa[i]]);
	}
	int v = 0;
	_0
	{
		while (a[i + v] == a[sa[rk[i] + 1] + v])
			v++;
		hi[rk[i]] = v ? v-- : 0;
	}
}
void but(int p, int l, int r)
{
	if (l == r)
		HLE[p] = hi[l], HRI[p] = hi[l - 1], W[p] = sa[l];
	else
	{
		int m = l + r >> 1;
		but(p << 1, l, m), but(p << 1 | 1, m + 1, r);
		HLE[p] = min(HLE[p << 1], HLE[p << 1 | 1]);
		HRI[p] = min(HRI[p << 1], HRI[p << 1 | 1]);
		W[p] = min(W[p << 1], W[p << 1 | 1]);
	}
}
int GL(int p, int l, int r, int x)
{
	if (x == 1 || W[p] >= sa[x])
		return -1;
	if (r < x)
	{
		while (l < r)
		{
			int m = l + r >> 1;
			if (W[p << 1 | 1] < sa[x])
				p = p << 1 | 1, l = m + 1;
			else
				p <<= 1, r = m;
		}
		return l;
	}
	else
	{
		int m = l + r >> 1, res = x > m + 1 ? GL(p << 1 | 1, m + 1, r, x) : -1;
		return (~res) ? res : GL(p << 1, l, m, x);
	}
}
int GR(int p, int l, int r, int x)
{
	if (x == N || W[p] >= sa[x])
		return -1;
	if (l > x)
	{
		while (l < r)
		{
			int m = l + r >> 1;
			if (W[p << 1] < sa[x])
				p <<= 1, r = m;
			else
				p = p << 1 | 1, l = m + 1;
		}
		return l;
	}
	else
	{
		int m = l + r >> 1, res = x < m ? GR(p << 1, l, m, x) : -1;
		return (~res) ? res : GR(p << 1 | 1, m + 1, r, x);
	}
}
int GHLE(int p, int l, int r, int L, int R)
{
	if (L <= l && r <= R)
		return HLE[p];
	else
	{
		int m = l + r >> 1;
		if (R <= m)
			return GHLE(p << 1, l, m, L, R);
		if (L > m)
			return GHLE(p << 1 | 1, m + 1, r, L, R);
		return min(GHLE(p << 1, l, m, L, R), GHLE(p << 1 | 1, m + 1, r, L, R));
	}
}
int lcp(int x, int y)
{
	if (x == y)
		return N - x + 1;
	x = rk[x], y = rk[y];
	if (x > y)
		std::swap(x, y);
	return GHLE(1, 1, N, x, y - 1);
}
int EXTL(int p, int l, int r, int x, int lim)
{
	if (x == 1 || HLE[p] >= lim)
		return -1;
	if (r < x)
	{
		while (l < r)
		{
			int m = l + r >> 1;
			if (HLE[p << 1 | 1] < lim)
				p = p << 1 | 1, l = m + 1;
			else
				p <<= 1, r = m;
		}
		return l;
	}
	else
	{
		int m = l + r >> 1, res = m + 1 < x ? EXTL(p << 1 | 1, m + 1, r, x, lim) : -1;
		return (~res) ? res : EXTL(p << 1, l, m, x, lim);
	}
}
int EXTR(int p, int l, int r, int x, int lim)
{
	if (x == N || HRI[p] >= lim)
		return -1;
	if (l > x)
	{
		while (l < r)
		{
			int m = l + r >> 1;
			if (HRI[p << 1] < lim)
				p <<= 1, r = m;
			else
				p = p << 1 | 1, l = m + 1;
		}
		return l;
	}
	else
	{
		int m = l + r >> 1, res = x < m ? EXTR(p << 1, l, m, x, lim) : -1;
		return (~res) ? res : EXTR(p << 1 | 1, m + 1, r, x, lim);
	}
}
int GW(int p, int l, int r, int L, int R)
{
	if (L <= l && r <= R)
		return W[p];
	else
	{
		int m = l + r >> 1;
		if (R <= m)
			return GW(p << 1, l, m, L, R);
		if (L > m)
			return GW(p << 1 | 1, m + 1, r, L, R);
		return min(GW(p << 1, l, m, L, R), GW(p << 1 | 1, m + 1, r, L, R));
	}
}
void U(int &x)
{
	int Lnear = GL(1, 1, N, rk[x]), Rnear = GR(1, 1, N, rk[x]), Llcp = (~Lnear) ? lcp(sa[Lnear], x) : 0, Rlcp = (~Rnear) ? lcp(sa[Rnear], x) : 0;
	if (Llcp + Rlcp == 0)
	{
		O[++L] = -1, O[++L] = a[x], x++;
		return;
	}
	if (Llcp > Rlcp)
	{
		int Lfar = EXTL(1, 1, N, rk[x], Llcp);
		Lfar = (~Lfar) ? Lfar + 1 : 1;
		O[++L] = Llcp, O[++L] = GW(1, 1, N, Lfar, Lnear) - 1;
		x += Llcp;
		return;
	}
	if (Llcp < Rlcp)
	{
		int Rfar = EXTR(1, 1, N, rk[x], Rlcp);
		Rfar = (~Rfar) ? Rfar - 1 : N;
		O[++L] = Rlcp, O[++L] = GW(1, 1, N, Rnear, Rfar) - 1;
		x += Rlcp;
		return;
	}
	int Lfar = EXTL(1, 1, N, rk[x], Llcp);
	int Rfar = EXTR(1, 1, N, rk[x], Rlcp);
	Lfar = (~Lfar) ? Lfar + 1 : 1;
	Rfar = (~Rfar) ? Rfar - 1 : N;
	O[++L] = Llcp, O[++L] = min(GW(1, 1, N, Lfar, Lnear), GW(1, 1, N, Rnear, Rfar)) - 1;
	x += Llcp;
}
int main()
{
	freopen("encrypt.in", "r", stdin);
	freopen("encrypt.out", "w", stdout);
	scanf("%s", a + 1);
	N = strlen(a + 1);
	SA();
	but(1, 1, N);
	for (int i = 1; i <= N; )
		U(i);
	for (int i = 1; i < L; i++)
		printf("%d ", O[i]);
	printf("%d\n", O[L]);
	return 0;
}
