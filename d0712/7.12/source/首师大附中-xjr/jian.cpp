#include <iostream>
#include <cstring>
using namespace std;
#define LL long long

LL read() {
	LL x = 0ll, f = 1ll; char c = getchar();
	while(!isdigit(c)){ if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)){ x = x * 10ll + c - '0'; c = getchar(); }
	return x * f;
}

#define maxn 25
int n, ans, As[100000][maxn];
LL m;

bool check(int* A) {
	for(int i = 1; i <= ans; i++) {
		for(int j = 0; j < n; j++) {
			bool ok = 0;
			for(int k = 1; k <= n; k++) if(As[i][k] != A[(j+k)%n+1]) {
				ok = 1; break;
			}
			if(!ok) return 0;
		}
	}
	bool ok = 0;
	for(int i = 2; i <= n; i++) if(A[i] != A[1]) {
		ok = 1; break;
	}
	return ok;
}

void dfs(int cur, int sum, int* A) {
	if(cur == n) {
		A[n] = sum;
		bool has[maxn]; memset(has, 0, sizeof(has));
		for(int i = 1; i <= n; i++) has[(A[i]+i)%n] = 1;
		bool ok = 1;
		for(int i = 0; i < n; i++) if(!has[i]) {
			ok = 0; return ;
		}
		ok &= check(A);
		if(!ok) return ;
		ans++;
		for(int i = 1; i <= n; i++) As[ans][i] = A[i];
		return ;
	}
	for(int i = sum; i >= 0; i--) {
		A[cur] = i;
		dfs(cur + 1, sum - i, A);
	}
	return ;
}

int main() {
	freopen("jian.in", "r", stdin);
	freopen("jian.out", "w", stdout);
	n = (int)read(); m = read();
	if(!m || m % n){ puts("0"); return 0; }
	int A[maxn]; memset(A, 0, sizeof(A));
	
	dfs(1, m, A);
	
	printf("%d\n", ans);
	
	return 0;
}
