#include <iostream>
#include <cstdio>
#include <Cstring>
#include <algorithm>
#define MXN 1007
#define INFID 2001
using namespace std;
char lastop[INFID];
char whe[INFID];
int lastoid[INFID];
char op[3];
int cnt[2][2][MXN]; // [L, E][unidentified, identified][prefix]
int sum[4];
void init();
inline int getint();
int main() {
    freopen("probe.in", "r", stdin);
    freopen("probe.out", "w", stdout);
    for (int T = getint(); T > 0; --T) {
        init();
        int n = getint();
        int tsum = 0;
        bool tag = false;
        for (int i = 2; i <= n + 1; ++i) {
            int id, o;
            scanf("%s %d", op, &id);
            o = op[0] == 'E' ? 1 : 0;
            if (id) {
                cnt[o ^ 1][0][i] = cnt[o ^ 1][0][i - 1];
                if (lastop[id] == o) --cnt[o ^ 1][0][i];
                if (lastop[id] == o) whe[id] = o, --sum[2 + (o ^ 1)];
                if (lastop[id] == o && -sum[2 + (o ^ 1)] > sum[o ^ 1]) sum[2 + (o ^ 1)] = -sum[o ^ 1]; 
                cnt[o][0][i] = cnt[o][0][i - 1];
                cnt[o ^ 1][1][i] = cnt[o ^ 1][1][i - 1];
                cnt[o][1][i] = cnt[o][1][i - 1];
                if (lastop[id] == o && cnt[o ^ 1][0][i - 1] - cnt[o ^ 1][0][lastoid[id]] < 1) {
                    puts("OTHER");
                    goto ED;
                }
                lastoid[id] = i;
                lastop[id] = o;
            } else {
                cnt[o][0][i] = cnt[o][0][i - 1] + 1;
                cnt[o ^ 1][0][i] = cnt[o ^ 1][0][i - 1];
                cnt[o][1][i] = cnt[o][1][i - 1];
                cnt[o ^ 1][1][i] = cnt[o ^ 1][1][i - 1];
                ++sum[o];
                if (!o && !tag) --sum[2 + o];
            }
            if (o) tag = true;
            whe[id] = o;
        }
        for (int i = 1; i <= 2000; ++i) if (whe[i]) ++tsum;
        tsum += sum[1] + sum[3] - sum[0] - sum[2];
        printf("%d\n", max(tsum, 0));
ED:;
    }

    return 0;
}
void init() {
    memset(lastop, 0, sizeof(lastop));
    memset(cnt, 0, sizeof(cnt));
    memset(lastoid, 0, sizeof(lastoid));
    memset(whe, 0, sizeof(whe));
    memset(sum, 0, sizeof(sum));
    cnt[1][0][1] = INFID;
    cnt[0][0][1] = INFID;
    
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