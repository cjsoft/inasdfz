#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int n,l;
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

string B;

int main() {
  freopen("parallel.in","w",stdout);
  
  srand((int)time(0));
  n=rand()%70+31;
  l=rand()%10+41;
  k=16;
  printf("%d %d\n",n,l);
  for (int i=0;i<n;++i) {
    if (i>0) printf(" ");
      string s=gen();
        cout << s;
  }
  cout << endl;
}