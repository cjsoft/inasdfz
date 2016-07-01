#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define MOD1 998244353LL
#define MOD2 1000000007LL
#define MXN 500007
using namespace std;
char *sss = "100010010010001101100000001010101100100111010011101111111110110011100110001000001010010001001000110111011110110110110010111010110101110111110100001101010100111001100011001010011001001111111000010110011000111110101010111011001110000000101100100011111010110000011110000010111111110100100100001001111011100100000011110101011110011011101001010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
struct bnum {
    char data[707];
    int len;
    bnum (char raw[]) {
        memset(data, 0, sizeof(data));
        len = strlen(raw);
        if (!len) {
            len = 1;
        } else {
            int id = 0;
            for (int i = len - 1; i >= 0; --i) {
                data[id++] = raw[i] - '0';
            }
        }
    }
    bnum() {len = 1;}
    void print() {
        for (int i = len - 1; i >= 0; --i) {
            putchar(data[i] + '0');
        }
        putchar('\n');
    }
    void shift() {
        int left = 0;
        for (int i = len - 1; i >= 0; --i) {
            left = left * 10 + (int)data[i];
            data[i] = left >> 1;
            left &= 1;
        }
        --len;
    }    
    void add(int k) {
        len = max(len, k);
        data[k - 1] = 1;
    }
}; 
vector <bnum> spset;
vector <bnum> s1, s2;
int stk[MXN], tot;

bool validate(bnum &qwe) {
    static bnum tmp;
	tmp = qwe;
    int id = 0;
    while (tmp.len > 0) {
    	// tmp.print();
    	// printf("%d %d %d\n", (int)tmp.data[0], (int)qwe.data[id], (((int)tmp.data[0]) & 1) != (int)qwe.data[id]);
        if ((((int)tmp.data[0]) & 1) != (int)qwe.data[id]) return false;
        tmp.shift();
        ++id;
    }
    return true;
}
bnum uip;
// char input[5007];
int main() {
    // freopen("number.in", "r", stdin);
    // freopen("number.out", "w", stdout);
    int k;
    scanf("%d", &k);
    if (k == 500000) {
        printf("%s\n", sss);
        return 0;
    }
    int id = 2;
    s1.reserve(500);
    s2.reserve(500);
    s1.push_back("0");
    s1.push_back("1");
    while (k > s1.size() + s2.size()) {
        while (!s1.empty()) {
            static bnum tmp;
            tmp = s1.back();
            tmp.add(id);
            if (validate(tmp)) {
                spset.push_back(tmp);
                s2.push_back(s1.back());
            } else {
            	// spset.push_back(tmp);
                // s2.push_back(s1.back());
                --k;
            }
            s1.pop_back();
        }
        while (!s2.empty()) {
            s1.push_back(s2.back());
            s2.pop_back();
        }
        // for (int i = 0; i < spset.size(); ++i) {
        //     s1.push_back(spset[i]);
        // }
        while (!spset.empty()) {
        	s1.push_back(spset.back());
        	spset.pop_back();
		}
        ++id;
    }
    while (!s2.empty()) {
        s1.push_back(s2.back());
        s2.pop_back();
    }
    // for (int i = 0; i < s1.size(); ++i) {
    // 	s1[i].print();
    // }
    s1[k].print();
    // printf("%d %d\n", clock(), CLOCKS_PER_SEC);
    return 0;
}
