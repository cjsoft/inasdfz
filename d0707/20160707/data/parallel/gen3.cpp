#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int n,m,l;
int k;

string gen() {
  string s;
  int cnt=0;
  for (int i=0;i<l;++i) 
    if (rand()%10>4) s+='0';
    else s+='1';
  return s;
}

string B;

int main() {
  freopen("parallel.in","w",stdout);
  
  srand((int)time(0));
  n=rand()%70+31;
  m=1;//rand()%15+6;
  l=rand()%10+41;
  k=5;
  printf("%d %d %d\n",n,m,l);
  for (int i=0;i<n;++i) {
    if (i>0) printf(" ");
      string s=gen();
        cout << s;
  }
  cout << endl;
  for (int i=0;i<m;++i) {
    if (i>0) printf(" ");
      string s=gen();
        cout << s;
  }
  cout << endl;
}