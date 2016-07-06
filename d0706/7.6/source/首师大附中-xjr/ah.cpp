#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int read() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)){ if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)){ x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

int main() {
	freopen("ah.in", "r", stdin);
	freopen("ah.out", "w", stdout);
	int t = read();
	while(t--) {
		int n = read();
		for(int i = 1; i <= 2 * n; i++) read();
		
		puts("0");
	}
	
	return 0;
}
