#include <cstdio>
#include <algorithm>
static const int MAXN = 12;
typedef double mat[MAXN][MAXN];

int n, m;
mat lst = {
    { 1,   2,   3,   4,   5,   6,   7,   8,   9,  10 }, 
    { 2,   6,  12,  20,  30,  42,  56,  72,  90, 110 },
    { 3,  15,  42,  90, 165, 273, 420, 612, 855,1155 },
    { 6,  42, 156, 420, 930,1806,3192,5256,8190,12210 },
    { 9, 107, 554,1910,5155,11809,24052,44844,78045,128535 },
    { 18, 294,2028,8820,28830,77658,181944,383688,745290,1355310 }, 
    { 30, 780,7350,40590,161040,510510,1376340,3283380,7118730,14294280 },
    { 56,2128,26936,187880,902720,3363976,10429328,28133616,68064360 },
};
mat eq;
double *coef[MAXN];

double *gaussian_elimination(int n, mat a)
{
    for (int i = 0; i < n; ++i) {
        if (a[i][i] == 0) {
            for (int j = i + 1; j < n; ++j) if (a[j][i] != 0) {
                for (int k = 0; k <= n; ++k) std::swap(a[i][k], a[j][k]);
                break;
            }
        }
        for (int j = i + 1; j < n; ++j) {
            for (int k = i + 1; k <= n; ++k)
                a[j][k] -= a[i][k] * a[j][i] / a[i][i];
            a[j][i] = 0;
        }
    }
    double *x = new double[n];
    for (int i = n - 1; i >= 0; --i) {
        x[i] = a[i][n] / a[i][i];
        for (int j = 0; j < i; ++j) a[j][n] -= a[j][i] * x[i];
    }
    return x;
}

double polynomial_eval(int n, double *coef, double x)
{
    double ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans = ans * x + coef[i];
    }
    return ans;    
}    

int calc()
{
    if (m % n != 0) return 0;
    return (long long)(polynomial_eval(n, coef[n - 1], m / n) + 0.5) % 998244353;
}

int main()
{
    freopen("jian.in", "r", stdin);
    freopen("jian.out", "w", stdout);

    for (int i = 0; i <= 10; ++i) {
        for (int j = 0; j <= i; ++j) {
            eq[j][0] = 1;
            for (int k = 1; k <= i; ++k) eq[j][k] = eq[j][k - 1] * (j + 1);
            eq[j][i + 1] = lst[i - 1][j];
        }
        coef[i] = gaussian_elimination(i + 1, eq);
    }
    coef[0][0] = 1;
    scanf("%d%d", &n, &m);
    printf("%d\n", calc());

    fclose(stdin); fclose(stdout);
    return 0;
}

