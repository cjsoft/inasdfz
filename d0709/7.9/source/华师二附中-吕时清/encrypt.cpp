#include <cstdio>
//#include <cstdlib>
//#include <ctime>
#include <algorithm>
static const int MAXN = 500004;
static const int LOGN = 20;

int n;
char s[MAXN];

int sa_buildlen;
int sa[MAXN], rk[MAXN], lcp[MAXN];
inline bool sa_rk_cmp(const int a, const int b) {
    return rk[a] != rk[b] ? rk[a] < rk[b] :
        (a + sa_buildlen > n ? -1 : rk[a + sa_buildlen]) <
        (b + sa_buildlen > n ? -1 : rk[b + sa_buildlen]);
}
void sfx_arr_build()
{
    s[n] = -1;
    for (int i = 0; i <= n; ++i) {
        rk[i] = s[i]; sa[i] = i;
    }
    static int t[MAXN];
    for (sa_buildlen = 1; sa_buildlen <= n; sa_buildlen <<= 1) {
        std::sort(sa, sa + n + 1, sa_rk_cmp);
        t[sa[0]] = 0;
        for (int i = 1; i <= n; ++i) t[sa[i]] = t[sa[i - 1]] + sa_rk_cmp(sa[i - 1], sa[i]);
        for (int i = 0; i <= n; ++i) rk[i] = t[i];
    }
    lcp[0] = -1; int h = 0;
    for (int i = 0; i < n; ++i) {
        int j = sa[rk[i] - 1];
        if (h > 0) --h;
        for (; i + h < n && j + h < n; ++h)
            if (s[i + h] != s[j + h]) break;
        lcp[rk[i]] = h;
    }
    //s[n] = '\0';
    //for (int i = 0; i <= n; ++i) printf("[%d]\t%d\t%d\t%s\n", i, sa[i], lcp[i], &s[sa[i]]);
}

struct min_rmq {
    int rmq_f[MAXN][LOGN];
    inline int log2(const int x) {
        return 8 * sizeof(int) - __builtin_clz(x - 1) - 1;
    }
    void init(int *arr)
    {
        for (int i = 0; i <= n; ++i) rmq_f[i][0] = arr[i];
        for (int j = 1; j < LOGN; ++j)
            for (int i = 0; i <= n + 1 - (1 << j); ++i)
                rmq_f[i][j] = std::min(rmq_f[i][j - 1], rmq_f[i + (1 << (j - 1))][j - 1]);
    }
    inline int query(const int l, const int r)
    {
        int sz = log2(r - l + 1);
        return std::min(rmq_f[l][sz], rmq_f[r - (1 << sz) + 1][sz]);
    }
} q_sa, q_lcp;

int fwk[MAXN] = { 0 };
inline void fwk_add(int p, const int inc = +1) {
    for (; p < MAXN; p += (p & -p)) fwk[p] += inc;
}
inline int fwk_sum(int r) {
    int ans = 0;
    for (; r; r -= (r & -r)) ans += fwk[r];
    return ans;
}

int main()
{
    freopen("encrypt.in", "r", stdin);
    freopen("encrypt.out", "w", stdout);

    n = 0;
    while ((s[n] = getchar()) >= 'a' && s[n] <= 'z') ++n;
    //while (n < 100000) s[n++] = rand() % 26 + 'a';
    //fprintf(stderr, "%lu\n", sizeof(q_sa) + sizeof(q_lcp) + sizeof(s) + sizeof(sa) * 4);

    sfx_arr_build();
    q_sa.init(sa);
    q_lcp.init(lcp);
    //fprintf(stderr, "%lf\n", (double)clock() / CLOCKS_PER_SEC);

    printf("-1 %d", s[0]);
    fwk_add(rk[0]);
    for (int i = 1; i < n; ) {
        int max_len = 0, max_id = 0x7fffffff, cur_len;
        #define CHECK_AND_UPDATE(_val) do { \
            if ((_val) > rk[i]) cur_len = q_lcp.query(rk[i] + 1, (_val)); \
            else cur_len = q_lcp.query((_val) + 1, rk[i]); \
            if (max_len < cur_len) max_len = cur_len; \
        } while (0)
        int target = fwk_sum(rk[i]), lo, hi, mid;
        lo = 0, hi = n + 1;
        while (lo < hi - 1) {
            mid = (lo + hi) >> 1;
            if (fwk_sum(mid) <= target) lo = mid; else hi = mid;
        }
        CHECK_AND_UPDATE(lo + 1);
        lo = -1, hi = n;
        while (lo < hi - 1) {
            mid = (lo + hi) >> 1;
            if (fwk_sum(mid) < target) lo = mid; else hi = mid;
        }
        CHECK_AND_UPDATE(hi);
        if (max_len == 0) { printf(" -1 %d", s[i]); max_len = 1; }
        else {
            lo = rk[i], hi = 0;
            while (lo > hi + 1) {
                mid = (lo + hi) >> 1;
                if (q_lcp.query(mid + 1, rk[i]) >= max_len) lo = mid; else hi = mid;
            }
            max_id = std::min(max_id, q_sa.query(lo, rk[i]));
            lo = rk[i], hi = n + 1;
            while (lo < hi - 1) {
                mid = (lo + hi) >> 1;
                if (q_lcp.query(rk[i] + 1, mid) >= max_len) lo = mid; else hi = mid;
            }
            max_id = std::min(max_id, q_sa.query(rk[i], lo));
            printf(" %d %d", max_len, max_id);
        }
        for (int j = i; j < i + max_len; ++j) fwk_add(rk[j]);
        i += max_len;
    }

    //fprintf(stderr, "%lf\n", (double)clock() / CLOCKS_PER_SEC);
    fclose(stdin); fclose(stdout);
    return 0;
}

