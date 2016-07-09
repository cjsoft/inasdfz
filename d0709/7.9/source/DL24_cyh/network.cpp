#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define itearte(_x, _i) for (int _i = head[_x]; _i; _i = buf[_i].prev)
#define MXN 1007
using namespace std;
typedef long long ll;
struct edge {
    int id, to, weight;
    int prev;
} buf[MXN << 2 | 1];
int head[MXN];
int tot = 2;
void addedge(int a, int b, int weight) {buf[tot].to = b; buf[tot].weight = weight; buf[tot].prev = head[a]; head[a] = tot++;}
int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}
int n;
// int fa[MXN][13];
// int dep[MXN];
// int attr[MXN][13];
// int nodeattr[MXN];
int sz[MXN][MXN];
void dfs1(int root, int from, int stp) {
    sz[stp][root] = 1;
    itearte(root, i) {
        if (buf[i].to == from) continue;
        dfs1(buf[i].to, root, stp);
        sz[stp][root] += sz[stp][buf[i].to];
    }
}
int dfs(int root, int from, int resu, int stp) {
    int cnt = 0;
    if (resu == 1) {
        return sz[stp][root] - 1;
    }
    itearte(root, i) {
    // for (int i = head[root]; i; i = buf[i].prev) {
        if (buf[i].to == from) continue;
        if (gcd(buf[i].weight, resu) == 1) ++cnt;
        cnt += dfs(buf[i].to, root, gcd(buf[i].weight, resu), stp);
    }
    itearte(root, i) {
    // for (int i = head[root]; i; i = buf[i].prev) {
        if (buf[i].to == from) continue;
    }
    return cnt;
}
inline int getint();
int main() {
    freopen("network.in", "r", stdin);
    freopen("network.out", "w", stdout);
    n = getint();
    int u, v, w;
    for (int i = 1; i < n; ++i) {
        u = getint(); v = getint(); w = getint();
        addedge(u, v, w);
        addedge(v, u, w);
    }
    for (int i = 1; i <= n; ++i) dfs1(i, 0, i);
    int rtn = 0;
    for (int i = 1; i <= n; ++i) {
        rtn += dfs(i, 0, 0, i);
    }
    printf("%d\n", rtn >> 1);
    // return 0;
    for (int Q = getint(); Q; Q--) {
        u = getint(); w = getint();
        buf[u << 1].weight = w;
        buf[u << 1 | 1].weight = w;
        // edit(buf[u << 1 | 1].id, w);
        rtn = 0;
        for (int i = 1; i <= n; ++i) {
            rtn += dfs(i, 0, 0, i);
        }
        printf("%d\n", rtn >> 1);
    }
    return 0;
}


int getint() {
    static int rtn, f;
    static char ch;
    rtn = 0; f = 1;
    while ((ch = getchar()) < '0' || ch > '9') if (ch == '-') f = -f;
    rtn = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9') rtn = rtn * 10 + ch - '0';
    return rtn * f;
}