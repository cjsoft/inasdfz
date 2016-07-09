#include <cstdio>
typedef long long int64;
static const int MAXN = 1500008;

int n;
int64 b[MAXN], a[MAXN];

void solve(int l, int sz)
{
    if (sz == 1) { a[l] = b[l]; return; }
    int64 lhalf_sum = b[l + sz / 2 - 1];
    int64 rhalf_sum = b[l + sz - 1] - b[l + sz / 2 - 1];

    for (int i = l; i < l + sz / 2; ++i)
        b[i] = (b[i] + b[i + sz / 2] - rhalf_sum) / 2;
    solve(l, sz / 2);
    for (int i = l; i < l + sz / 2; ++i)
        b[i] = (b[i] * 2 - b[i + sz / 2] + rhalf_sum);

    for (int i = l + sz / 2; i < l + sz; ++i)
        b[i] = (b[i] - b[i - sz / 2] + rhalf_sum) / 2;
    solve(l + sz / 2, sz / 2);
    for (int i = l + sz / 2; i < l + sz; ++i)
        b[i] = (b[i] * 2 + b[i - sz / 2] - rhalf_sum);
}

int main()
{
    freopen("spy.in", "r", stdin);
    freopen("spy.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lld", &b[i]);
    solve(0, n);
    for (int i = 0; i < n; ++i)
        printf("%lld%c", a[i], i == n - 1 ? '\n' : ' ');

    fclose(stdin); fclose(stdout);
    return 0;
}

