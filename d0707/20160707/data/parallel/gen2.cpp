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
  for (int i=0;i<k;++i) s+='0';
  for (int i=0;i<l-k;++i) 
    if (rand()%10>4) s+='0';
    else s+='1';
  reverse(s.begin(),s.end());
  return s;
}

string gen1() {
  string s;
  int cnt=0;
  int p=rand()%k+1;
  for (int i=0;i<p-1;++i) s+='0';
  s+='1';
  for (int i=0;i<l-p;++i) 
    if (rand()%10>4) s+='0';
    else s+='1';
  reverse(s.begin(),s.end());
  return s;
}

string B;

int main() {
  freopen("parallel.in","w",stdout);
  
  srand((int)time(0));
  n=rand()%70+31;
  m=rand()%15+6;
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
      string s=gen1();
        cout << s;
  }
  cout << endl;
}