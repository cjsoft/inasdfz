#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int a = 0;
    for (int i = 1; i <= 1024; ++i) {
        for (int j = 1; j <= 1024; ++j) {
            for (int k = 1; k <= 1600; ++k) {
                for (int l = 0; l < 14; ++l)
                    a += l;
            }
        }
    }
}