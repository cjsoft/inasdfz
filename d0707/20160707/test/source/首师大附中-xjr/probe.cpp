#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int read() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)){ if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)){ x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

#define maxn 1010
#define maxid 2010
int T, n, num[maxid], l0[maxid];
bool has[maxid];
struct Query { int tp, id; } qs[maxn];

int main() {
	freopen("probe.in", "r", stdin);
	freopen("probe.out", "w", stdout);
	T = read();
	while(T--) {
		int n = read(), e0 = 0, L0 = 0, mxid = 0;
		for(int i = 1; i <= n; i++) {
			char c = getchar();
			while(!isalpha(c)) c = getchar();
			int id = read(), tp = c == 'E' ? 1 : 0;
			qs[i] = (Query){ tp, id };
			mxid = max(mxid, id);
		}
		memset(num, 0, sizeof(num));
		memset(l0, 0, sizeof(l0));
		bool finish = 0;
		for(int i = 1; i <= n; i++) {
			int tp = qs[i].tp, id = qs[i].id;
			if(tp && !id) e0++;
			if(!tp && !id){ for(int j = 1; j <= mxid; j++) if(num[j]) l0[j]++; L0++; }
			if(tp && id) {
				num[id]++;
				if(!has[id]){ has[id] = 1; continue; }
				has[id] = 1;
				if(num[id] > 1 && l0[id] && L0) L0--, l0[id]--, num[id]--;
				if(num[id] > 1 && (!l0[id] || !L0)){ finish = 1; puts("OTHER"); break; }
			}
			if(!tp && id) {
				num[id]--;
				has[id] = 1;
				if(num[id] < 0 && e0) e0--, num[id]++;
				if(num[id] < 0 && !e0){ finish = 1; puts("OTHER"); break; }
			}
		}
		int ans = e0 - L0;
		for(int i = 1; i <= mxid; i++) ans += num[i];
		if(ans < 0) ans = 0;
		if(!finish) printf("%d\n", ans);
	}
	
	return 0;
}
