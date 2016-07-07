#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int n,m,l;
int k;

string gen() {
  string s;
  int cnt=0;
  s+=(char)(rand()%2+'0');
  for (int i=1;i<l;++i) {
    if (rand()%10>2 || cnt==k) s+=s[i-1];
    else {
      cnt++;
      s+=s[i-1]^1;
    }
  }
  return s;
}

string gen1() {
  string s;
  int cnt=0;
  while (cnt<=k+2) {
    cnt=0;
    s=(char)(rand()%2+'0');
    for (int i=1;i<l;++i) {
      if (rand()%10>4) s+=s[i-1];
      else {
        cnt++;
        s+=s[i-1]^1;
      }
    }
  }
  return s;
}

string B;

int main() {
  freopen("parallel.in","w",stdout);
  
  srand((int)time(0));
  n=rand()%70+31;
  l=rand()%10+41;
  m=rand()%15+6;
  k=12;
  printf("%d %d %d\n",n,m,l);
  for (int i=0;i<n;++i) {
    if (i>0) printf(" ");
      string s=gen();
        cout << s;
  }
  cout << endl;
  for (int i=0;i<m;++i) {
    if (i>0) printf(" ");
      string s=gen1();
        cout << s;
  }
  cout << endl;
}