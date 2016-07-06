#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MXN 100007
#define iterate(x, i) for (edge *i = head[x]; i; i = i->prev)
using namespace std;
typedef long long ll;
struct edge {
    int to;
    edge *prev;
} buf[MXN], *head[MXN], *cur;
int n;
int ans[MXN], tot;
int sum[MXN];
int raw[MXN];
inline int getint();
void addedge(int, int);
void init();
int dfs(int);
int getans(int);
int main() {
    freopen("ah.in", "r", stdin);
    freopen("ah.out", "w", stdout);
    int T = getint();
    while (T--) {
        static int loc[] = {0, 1, -1};
        n = getint();
        init();
        for (int i = 1; i <= n; ++i) addedge(getint(), i);
        for (int i = 1; i <= n; ++i) sum[i] = raw[i] = loc[getint() + 1];
        dfs(1);
        if (sum[1] < 0) puts("-1");
        else if (sum[1] != 0) {
            for (int i = 1; i <= n; ++i) if (!head[i] && !sum[i]) ans[tot++] = i;
            printf("%d", tot);
            for (int i = 0; i < tot; ++i) printf(" %d", ans[i]);
            putchar('\n');
        } else {
            getans(1);
            sort(ans, ans + tot);
            printf("%d", tot);
            for (int i = 0; i < tot; ++i) printf(" %d", ans[i]);
            putchar('\n');
        }
    }
    return 0;
}
int dfs(int root) {
    iterate(root, i) sum[root] += dfs(i->to);
    raw[root] = sum[root];
    if (sum[root] > 1) return sum[root] = 1;
    else if (sum[root] < -1) return sum[root] = -1;
}
int getans(int root) {
    if (!head[root] && !raw[root]) ans[tot++] = root;
    iterate(root, i) if (raw[i->to] == 0 || raw[i->to] == -1) getans(i->to);
}
void init() {
    memset(buf, 0, sizeof(buf));
    memset(head, 0, sizeof(head));
    memset(sum, 0, sizeof(sum));
    memset(raw, 0, sizeof(raw));
    memset(ans, 0, sizeof(ans));
    tot = 0;
    cur = buf;
}
void addedge(int a, int b) {
    cur->to = b;
    cur->prev = head[a];
    head[a] = cur++;
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