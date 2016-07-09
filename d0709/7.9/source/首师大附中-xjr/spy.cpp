#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int read() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)){ if(x == '-') f = -1; c = getchar(); }
	while(isdigit(c)){ x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

void printbit(int x) {
	int num[20], cnt = 0;
	while(x) {
		num[++cnt] = x & 1;
		x >>= 1;
	}
	for(int i = cnt; i < 4; i++) putchar('0');
	for(int i = cnt; i; i--) printf("%d", num[i]);
	return ;
}
int bitcount(int x) {
	int cnt = 0;
	while(x) {
		cnt += (x & 1);
		x >>= 1;
	}
	return cnt;
}

#define maxn 2510
int A[maxn][maxn], B[maxn], ans[maxn];
int main() {
	freopen("spy.in", "r", stdin);
	freopen("spy.out", "w", stdout);
	int n = read();
	for(int i = 0; i < n; i++) B[i] = read();
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) if((bitcount((i | j) ^ i) + 1) & 1)
			A[i][j] = 1;
		else A[i][j] = 0;
	
	/*for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) printf("%d", A[i][j], A[i][j]);
		putchar('\n');
	}*/
	for(int i = 1; i < n; i++) {
		bool ok = 1;
		for(int j = 0; j < n; j++) if(A[i][j]) {
			if(i > j) {
				if(A[i][j] + A[j][j] == 0) {
					for(int k = 0; k < n; k++) A[i][k] += A[j][k];
					B[i] += B[j];
				}
				else {
					for(int k = 0; k < n; k++) A[i][k] -= A[j][k];
					B[i] -= B[j];
				}
				ok = 0;
			}
			break;
		}
		if(!ok) i--;
	}
	/*for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) printf("%2d", A[i][j]);
		printf(" %d\n", B[i]);
	}*/
	for(int i = n - 1; i >= 0; i--) {
		int tmp = B[i];
		for(int j = n - 1; j > i; j--) B[i] -= A[i][j] * ans[j];
		ans[i] = B[i] / A[i][i];
	}
	
	for(int i = 0; i < n; i++) printf("%d ", ans[i]);
	
	return 0;
}
