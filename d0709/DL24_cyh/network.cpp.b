#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define itearte(x, i) for (int i = head[x]; i; i = buf[i].prev)
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
int fa[MXN][13];
int dep[MXN];
int attr[MXN][13];
int nodeattr[MXN];
void dfs(int root) {
    dep[root] = dep[fa[root][0]] + 1;
    itearte(root, i) {
        if (buf[i].to == fa[root][0]) continue;
        buf[i].id = buf[i].to;
        buf[i ^ 1].id = buf[i].to;
        attr[buf[i].to][0] = buf[i].weight;
        fa[buf[i].to][0] = root;
        dfs(buf[i].to);
    }
}
void init() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < 12; ++j) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
            attr[i][j] = gcd(attr[i][j - 1], attr[fa[i][j - 1]][j - 1]);
        }
    }
}
void edit(int root, int newD) {
    attr[root][0] = newD;
    init();
}
int query(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    int delta = dep[b] - dep[a], ddd = delta;
    int l = 0, s = 1;
    int resu = attr[b][0];
    for (; s <= ddd; s <<= 1, ++l, delta >>= 1) {
        if (delta & 1) {
            resu = gcd(resu, attr[b][l]);
        }
        b = fa[b][l];
    }
    for (int i = 11; i >= 0; --i) {
        if (fa[a][i] != fa[b][i]) {
            resu = gcd(resu, attr[a][i]);
            resu = gcd(resu, attr[b][i]);
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    if (a != b) resu = gcd(resu, attr[a][0]);
    if (a != b) resu = gcd(resu, attr[b][0]);
    return resu;
}
inline int getint();
int main() {
    n = getint();
    int u, v, w;
    for (int i = 1; i < n; ++i) {
        u = getint(); v = getint(); w = getint();
        addedge(u, v, w);
        addedge(v, u, w);
    }
    dfs(1);
    init();
    // cout << query(1, 5) << endl;
    int rtn = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            // printf("   %d %d %d\n", i, j, query(i, j));
            if (query(i, j) == 1) ++rtn;
        }
    }
    printf("%d\n", rtn);
    for (int Q = getint(); Q; Q--) {
        u = getint(); w = getint();
        edit(buf[u << 1 | 1].id, w);
        rtn = 0;
        for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
                // printf("   %d %d %d\n", i, j, query(i, j));
                if (query(i, j) == 1) ++rtn;
            }
        }
        printf("%d\n", rtn);
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