#include <cstdio>
static const int MAXN = 7006;
static const int LOGN = 14;
static const int MAXM = MAXN * 2;
struct edge {
    int dest, w, next_id;
    edge() : dest(-1), w(1), next_id(-1) { }
    edge(int dest, int _u_, int next_id) : dest(dest), w(_u_), next_id(next_id) { }
};

template <typename T> T gcd(const T a, const T b) { return b == 0 ? a : gcd(b, a % b); }
template <typename T> inline void swap(T &a, T &b) { static T t; t = a; a = b; b = t; }

int n, q;
edge e[MAXM];
int e_head[MAXN];
int sts[MAXN][MAXN];

int dfs_rt;
int dangerous_ct = 0;

void acute(int u, int p = -1, int val = 0)
{
    sts[dfs_rt][u] = 1;
    //printf("%d %d %d\n", dfs_rt + 1, u + 1, val);
    if (val == 1) ++dangerous_ct;
    for (int i = e_head[u]; i != -1; i = e[i].next_id) if (e[i].dest != p) {
        acute(e[i].dest, u, gcd(val, e[i].w));
        sts[dfs_rt][u] += sts[dfs_rt][e[i].dest];
    }
}
void react(int u, int p = -1, int val = 0)
{
    if (val == 1) { dangerous_ct += sts[dfs_rt][u]; return; }
    for (int i = e_head[u]; i != -1; i = e[i].next_id) if (e[i].dest != p) {
        react(e[i].dest, u, gcd(val, e[i].w));
    }
}

int main()
{
    freopen("network.in", "r", stdin);
    freopen("network.out", "w", stdout);

    int u, v, w;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) e_head[i] = -1;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d%d", &u, &v, &w); --u, --v;
        e[i + i] = edge(v, w, e_head[u]); e_head[u] = i + i;
        e[i + i + 1] = edge(u, w, e_head[v]); e_head[v] = i + i + 1;
    }

    for (int i = 0; i < n; ++i) { dfs_rt = i; acute(i); }
    printf("%lld\n", dangerous_ct / 2);
    scanf("%d", &q);
    do {
        scanf("%d%d", &u, &w); e[u + u - 2].w = e[u + u - 1].w = w;
        dangerous_ct = 0;
        for (int i = 0; i < n; ++i) { dfs_rt = i; react(i); }
        printf("%lld\n", dangerous_ct / 2);
    } while (--q);

    fclose(stdout);
    return 0;
}

