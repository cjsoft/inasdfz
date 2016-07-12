#include <cstdio>
#include <cstring>
#include <algorithm>
static const int MAXN = 50005;
static const unsigned long long MAX_ULL = 0xffffffffffffffffULL;
static const unsigned long long MAX_DG = MAX_ULL / 4;

struct bb {
    unsigned long long _dg[MAXN];
    unsigned long long *dg, len;
    bb() : len(MAXN - 1) { this->dg = this->_dg; memset(this->_dg, 0, sizeof this->_dg); }
};

inline bool bb_ne_one(const bb &x) {
    for (register int i = x.len; i > 0; --i) if (x.dg[i]) return true;
    return x.dg[0] != 1;
}
inline void bb_mul3(const bb &x) {
    for (register int i = x.len; i > 0; --i) x.dg[i] += x.dg[i - 1];
}
inline void bb_rsh1(bb &x) {
    x.dg[1] += (x.dg[0] >> 1);
    ++x.dg; --x.len;
}
inline void bb_rebuild(const bb &x) {
    for (register int i = 0; i < x.len - 1; ++i) if (x.dg[i] > 1) {
        x.dg[i + 1] += (x.dg[i] >> 1);
        x.dg[i] &= 1;
    }
}

int n;
bb x;

int main()
{
    freopen("yi.in", "r", stdin);
    freopen("yi.out", "w", stdout);

    n = 0; char c;
    while ((c = getchar()) == '0' || c == '1') x.dg[n++] = c - '0';
    if (n > 10000) {
        puts("> <");
        fclose(stdin); fclose(stdout); return 0;
    }

    std::reverse(x.dg, x.dg + n);
    int ans = 0;
    while (bb_ne_one(x)) {
        ++ans;
        if (x.dg[0] & 1) {
            bb_mul3(x);
            ++x.dg[0];
        } else {
            bb_rsh1(x);
        }
        if ((ans & 127) == 0) bb_rebuild(x);
    }
    printf("%d\n", ans);

    fclose(stdin); fclose(stdout);
    return 0;
}

