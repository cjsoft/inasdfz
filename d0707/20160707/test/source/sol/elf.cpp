#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

typedef long long int64;

int n;
const int MAX_N = 100 + 10;
const int BIT = 40, THRESHOLD = 24;
int64 S[MAX_N];
int64 want;
int L, freev, major;

int who[BIT];

bool check(int64 S, int64 pat, int L) {
	for (int i = 0; i <= BIT - L; ++i) {
		int64 v = (S >> i) & ((1LL << L) - 1);
		if (pat == v)
			return true;
	}
	return false;
}

void bf() {
	major = 0;
	for (int i = 0; i < n; ++i) {
		if (S[i] != 0)
			S[major++] = S[i];
	}

//	cout << major << " " << freev << endl;
	n = major;
	static int64 sum[1 << THRESHOLD];
	sum[0] = 0;
	for (int i = 1; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			if (i >> j & 1) {
				sum[i] = sum[i - (1 << j)] ^ S[j];
				break;
			}
		}
	}
	int64 ans = 0;
	for (int i = 0; i < (1 << n); ++i) {
		ans += check(sum[i], want, L);
	}
	ans <<= freev;
	cout << ans << endl;
}

void dp() {
	static int next[BIT + 2];
	static int next_state[BIT + 2][2];
	//calculate kmp
	next[0] = -1;
	for (int i = 1; i <= L; ++i) {
		int j = next[i - 1];
		while (j >= 0 && (want >> j & 1) != (want >> (i - 1) & 1))
			j = next[j];
		next[i] = j + 1;
	}

	for (int i = 0; i < L; ++i) {
		for (int v = 0; v < 2; ++v) {
			int j = i;
			while (j >= 0 && (want >> j & 1) != v)
				j = next[j];
			next_state[i][v] = j + 1;
		}
	}

	next_state[L][0] = next_state[L][1] = L;

	//major>=24
	int pos[BIT];
	int val[BIT];
	int tot = 0;
	for (int i = 0; i < BIT; ++i) {
		if (who[i] == -1) {
			pos[i] = tot++;
		}
	}

	for (int i = 0; i < BIT; ++i) {
		if (who[i] != -1) {
			int v = who[i]; //S[v]
			val[i] = 0;

			for (int j = 0; j < BIT; ++j) {
				if (who[j] == -1) {
					val[i] ^= (S[v] >> j & 1) << pos[j];
				}
			}
		}
	}

	const int MAX_BIT = BIT - THRESHOLD;
//cur,next,mask
	static int64 dp[2][BIT + 1][1 << MAX_BIT];
	int cur = 0, nxt = 1;
	memset(dp, 0, sizeof dp);
	dp[cur][0][0] = 1;
	for (int i = 0; i < BIT; ++i) {

		memset(dp[nxt], 0, sizeof dp[nxt]);

		for (int j = 0; j <= L; ++j) {
			for (int k = 0; k < (1 << tot); ++k) {
				int64 c = dp[cur][j][k];
				if (who[i] == -1) {
					int me = k >> pos[i] & 1;
					dp[nxt][next_state[j][me]][k] += c;
				} else {
					int v = val[i];
					for (int me = 0; me < 2; ++me) {
						dp[nxt][next_state[j][me]][k ^ (me * v)] += c;
					}
				}
			}
		}

		swap(cur, nxt);
	}

	int64 ans = 0;
	for (int i = 0; i < (1 << tot); ++i) {
		ans += dp[cur][L][i];
	}

	ans <<= freev;
	cout << ans << endl;
}

int main() {
    freopen("elf.in","r",stdin);
    freopen("elf.out","w",stdout);
    
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char buf[100];
		scanf("%s", buf);
		for (int j = 0; j < BIT; ++j) {
			S[i] |= (1LL << j) * (buf[j] - '0');
		}
	}
	cin >> L;
	char buf[100];
	scanf("%s", buf);
	for (int j = 0; j < L; ++j) {
		want |= (1LL << j) * (buf[j] - '0');
	}

	static bool used[MAX_N] = { };
	memset(who, -1, sizeof who);
	major = 0;

	for (int i = 0; i < BIT; ++i) {
		int u = -1;
		for (int j = 0; j < n; ++j)
			if (!used[j]) {
				if (S[j] >> i & 1) {
					u = j;
					break;
				}
			}
		who[i] = u;
		if (u == -1)
			continue;
		++major;
		used[u] = true;

		for (int j = 0; j < n; ++j) {
			if (j != u && (S[j] >> i & 1))
				S[j] ^= S[u];
		}
	}

//	for (int i = 0; i < BIT; ++i) {
//		if (who[i] != -1) {
//			int u = who[i];
//			for (int j = 0; j < BIT; ++j) {
//				cout << (S[u] >> j & 1);
//			}
//			cout << endl;
//		}
//	}

	freev = n - major;
//	cout << major << endl;
	if (major <= THRESHOLD) {
		bf();
	} else {
		dp();
	}
	return 0;
}
