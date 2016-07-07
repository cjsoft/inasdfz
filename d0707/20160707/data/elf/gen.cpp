#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAX_VALUE = int(1e6);

void print01(int n) {
	for (int i = 0; i < n; ++i) {
		putchar('0' + rand() % 2);
	}
	puts("");
}

void gen_random(int n, int L) {
	cout << n << endl;
	for (int i = 0; i < n; ++i) {
		print01(40);
	}
	cout << L << endl;
	print01(L);
}

void gen_constructed(int n, int L) {
	//n<=40
	vector<int> space(n);
	int rem = 40 - n;
	for (int i = 0; i < rem; ++i) {
		space[rand() % n]++;
	}
	vector<int> keep;
	vector<int> my;
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		my.push_back(cur++);
		for (int j = 0; j < space[i]; ++j) {
			keep.push_back(cur++);
		}
	}

	cout << n << endl;
	for (int i = 0; i < n; ++i) {
		bool bit[40] = { };
		bit[my[i]] = 1;
		for (int j = 0; j < keep.size(); ++j) {
			if (keep[j] > my[i])
				bit[keep[j]] = rand() % 2;
		}
		for (int j = 0; j < 40; ++j) {
			cout << bit[j];
		}
		cout << endl;
	}
	cout << L << endl;
	print01(L);
}

int main(int argv, char*argc[]) {
	int n = atoi(argc[1]);
	int L = atoi(argc[2]);
	string type = argc[3];
	int idx = atoi(argc[4]);
	srand(idx + 199581);
	if (type == "random")
		gen_random(n, L);
	else
		gen_constructed(n, L);
}
