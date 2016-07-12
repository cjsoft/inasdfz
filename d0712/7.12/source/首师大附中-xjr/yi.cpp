#include <iostream>
using namespace std;

int read() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)){ if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)){ x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

#define blo 60
#define maxnum (1 << blo)
#define maxn 120010
#define maxm 300010
#define LL long long
LL num[maxn];
int tp[maxn], cnt, r_num[maxm], Num[maxm+10], r_cnt;

int main() {
	freopen("yi.in", "r", stdin);
	freopen("yi.out", "w", stdout);
	char c = getchar();
	while(isdigit(c)) r_num[r_cnt++] = c - '0', c = getchar();
	int r_tmp;
	for(r_tmp = 0; r_tmp < r_cnt; r_tmp += blo) ;
	for(int i = 0; i < r_cnt; i++) Num[i+r_tmp-r_cnt] = r_num[i];
	cnt = -1;
	r_tmp -= blo;
	for(int i = r_tmp; i >= 0; i -= blo) {
		num[++cnt] = 0;
		for(int k = 0; k < blo; k++) num[cnt] = num[cnt] << 1ll | (LL)Num[i+k];
	}
	
	int top = 0, ans = 0;
	// printf("%d ", num[1]);
	while(!(top == cnt && num[top] == 1ll)) {
		while(!num[top]) ans += blo - tp[top], top++;
		while(!(num[top] & 1ll)) num[top] >>= 1ll, tp[top]++, ans++;
		// printf("%d(%d) ", num[top], ans);
		if(top == cnt && num[top] == 1ll) break;
		for(int i = top; i <= cnt; i++) num[i] += (num[i] << 1);
		num[top]++;
		for(int i = top; i <= cnt; i++) {
			num[i+1] += num[i] / (1ll << (LL)blo - tp[i]);
			num[i] %= (1ll << (LL)blo - tp[i]);
		}
		for(int i = cnt + 1; num[i]; i++) num[i+1] += num[i] / (1ll << (LL)blo - tp[i]), num[i] %= (1ll << (LL)blo - tp[i]), cnt = i;
		ans++;
		// printf("%d(%d) ", num[top], ans);
	}
	// puts("");
	
	printf("%d\n", ans);
	
	return 0;
}
