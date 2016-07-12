#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
static const int MAXN = 2008;
static const int LOGN = 18;

int psgt_hash[MAXN];

struct psgt_node {
    int l, r, lch, rch;
    int ct;
} t[MAXN * (2 + LOGN)];
int psgt_sz = 0;
int psgt_build(int l, int r)
{
    int idx = psgt_sz++;
    t[idx].l = l; t[idx].r = r; t[idx].ct = 0;
    if (l == r) {
        t[idx].lch = t[idx].rch = -1;
    } else {
        int m = (l + r) >> 1;
        t[idx].lch = psgt_build(l, m);
        t[idx].rch = psgt_build(m + 1, r);
    }
    return idx;
}
inline int psgt_newnode(int model, int ct)
{
    int idx = psgt_sz++;
    t[idx].l = t[model].l; t[idx].r = t[model].r;
    t[idx].lch = t[model].lch; t[idx].rch = t[model].rch;
    t[idx].ct = ct;
    return idx;
}
int psgt_modify(int idx, int pos)
{
    int cur = psgt_newnode(idx, t[idx].ct + psgt_hash[pos]);
    if (t[idx].l == t[idx].r) return cur;
    int &ch = (pos <= t[t[idx].lch].r) ? t[cur].lch : t[cur].rch;
    ch = psgt_modify(ch, pos);
    return cur;
}
int psgt_op_pos, psgt_op_result;
inline int psgt_pfxsum(int idx)
{
    int ans = 0;
    do {
        if (idx == -1) return ans;
        if (t[idx].r <= psgt_op_pos) { ans += t[idx].ct; return ans; }
        if (t[t[idx].lch].r <= psgt_op_pos) {
            ans += t[t[idx].lch].ct;
            idx = t[idx].rch;
        } else {
            idx = t[idx].lch;
        }
    } while (true);
}
inline int psgt_ptval(int idx)
{
    while (t[idx].l != t[idx].r) {
        idx = (t[t[idx].lch].r >= psgt_op_pos ? t[idx].lch : t[idx].rch);
    }
    return t[idx].ct;
}

int n, p, q;
int a[MAXN];
int rt[MAXN];

typedef std::pair<int, int> rg_multiset;
inline bool rg_multiset_comparator(const rg_multiset &lhs, const rg_multiset &rhs) {
    static int r1, r2, r3, r4, lo, hi, mid, a, b;
    r1 = rt[lhs.second]; r2 = rt[lhs.first];
    r3 = rt[rhs.second]; r4 = rt[rhs.first];
    lo = -1, hi = n;
    while (lo < hi - 1) {
        psgt_op_pos = mid = (lo + hi) >> 1;
        if (psgt_pfxsum(r1) - psgt_pfxsum(r2) != psgt_pfxsum(r3) - psgt_pfxsum(r4))
            hi = mid;
        else lo = mid;
    }
    psgt_op_pos = hi;
    a = psgt_ptval(r1) - psgt_ptval(r2);
    b = psgt_ptval(r3) - psgt_ptval(r4);
    return (a == b) ? (lhs.first < rhs.first) : (a > b);
}
rg_multiset m[MAXN * MAXN];
int m_ct = 0;

int main()
{
    freopen("lian.in", "r", stdin);
    freopen("lian.out", "w", stdout);

    scanf("%d%d%d", &n, &p, &q);
    if (n > 1000) {
        puts("> <");
        fclose(stdin); fclose(stdout);
        return 0;
    }
    for (int i = 0; i < n; ++i) { scanf("%d", &a[i]); --a[i]; }
    for (int i = 0; i < n; ++i) psgt_hash[i] = rand();

    rt[0] = psgt_build(0, n);
    for (int i = 0; i < n; ++i) rt[i + 1] = psgt_modify(rt[i], a[i]);

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            m[m_ct++] = rg_multiset(i, j);
    std::sort(m, m + m_ct, rg_multiset_comparator);
    for (int i = p - 1; i < q; ++i) printf("%d %d\n", m[i].first + 1, m[i].second);

    fclose(stdin); fclose(stdout);
    return 0;
}

