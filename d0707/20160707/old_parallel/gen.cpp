#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int n,l;

string gen() {
  string s;
  for (int i=0;i<l;++i)
    if (rand()%10<3) s+='0';
    else s+='1';
  return s;
}

string gen1() {
  string s;
  for (int i=0;i<l;++i)
    if (rand()%10>3) s+='0';
    else s+='1';
  return s;
}

int count(string s) {
  int cnt=0;
  for (int i=0;i<l;++i)
    if (s[i]=='1') cnt++;
  return cnt;
}

string B;

int main() {
  freopen("parallel.in","w",stdout);
  
  srand((int)time(0));
  n=rand()%50+51;
  l=rand()%20+31;
  B=gen1();
  printf("%d %d\n",n,l);
  for (int i=0;i<n;++i) {
    if (i>0) printf(" ");
    while (1) {
      string s=gen();
      if (count(s)>count(B)) {
        cout << s;
        break;
      }
    }
  }
  cout << endl;
  cout << B << endl;
}