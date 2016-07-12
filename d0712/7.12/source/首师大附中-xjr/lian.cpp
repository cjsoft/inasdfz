#include <iostream>
#include <cmath>
using namespace std;

int read() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)){ if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)){ x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

#define maxn 110
#define oo (1ll << 60)
#define ULL unsigned long long
int n, A[maxn], C[maxn][maxn][maxn];
bool has[maxn][maxn];
ULL H[maxn][maxn][maxn], x = 233;

int main() {
	freopen("lian.in", "r", stdin);
	freopen("lian.out", "w", stdout);
	n = read(); int ql = read(), qr = read();
	for(int i = 1; i <= n; i++) A[i] = read();
	
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++) {
			for(int k = i; k <= j; k++) C[i][j][A[k]]++;
			H[i][j][0] = 0;
			for(int k = 1; k <= n; k++) H[i][j][k] = H[i][j][k-1] * x + C[i][j][k];
		}
	if(ql == 1) printf("%d %d\n", 1, n);
	int nl = 1, nr = n; has[1][n] = 1;
	for(int ord = 2; ord <= qr; ord++) {
		int mx = 0, nnl = -1, nnr = -1;
		// puts("here");
		for(int i = 1; i <= n; i++)
			for(int j = n; j >= i; j--) if(!has[i][j]) {
				int l = 1, r = n;
				while(l < r) {
					int mid = (l + r & 1) ? (l + r >> 1) + 1 : l + r >> 1;
					// printf("%d,%d,%d ", l, r, mid);
					if(H[nl][nr][mid] != H[i][j][mid]) r = mid - 1; else l = mid;
				}
				// if(H[nl][nr][l] != H[i][j][l]) l--;
				// puts("");
				if(l < mx) continue;
				if(l > mx) {
					mx = l; nnl = i; nnr = j;
					continue;
				}
				if(nnl >= 0 && nnr >= 0) for(int k = l + 1; k <= n; k++) if(C[i][j][k] != C[nnl][nnr][k]) {
					if(C[i][j][k] < C[nnl][nnr][k]) nnl = i, nnr = j;
					break;
				}
				else nnl = i, nnr = j;
				/*if(l == mx && tmp < mn) {
					mn = tmp; nnl = i; nnr = j;
				}*/
			}
		nl = nnl; nr = nnr;
		has[nl][nr] = 1;
		if(ql <= ord) printf("%d %d\n", nl, nr);
	}
	
	return 0;
}
