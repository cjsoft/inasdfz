#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <bitset>
#include <fstream>
#include <cstring>

using namespace std;

string s1,s2;
string g[120];
int l,l1,l2;
bitset<120> st[201][201][2];
int cnt[201][201];
int n,m;
int t1,t2,t3;
ifstream in,pout,qout;
ofstream rout;

bool CheckValid(string s1,string s2) {
  if (l1+l2>200) return false;
  if (l1==0 || l2==0) return false;
  for (int i=0;i<l1;++i)
    if (s1[i]!='0' && s1[i]!='1' && s1[i]!='?') return false;
  for (int i=0;i<l2;++i)
    if (s2[i]!='0' && s2[i]!='1' && s2[i]!='?') return false;
  int cnt=0;
  for (int i=0;i<l1;++i)
    if (s1[i]=='?') cnt++;
  for (int i=0;i<l2;++i)
    if (s2[i]=='?') cnt++;
  if (cnt!=l) return false;
  return true;
}

bitset<120> change(const bitset<120> &a,int l,int c) {
  bitset<120> res=a;
  for (int i=0;i<n+m;++i)
    if (res.test(i))
      if (g[i][l]!='0'+c) res.set(i,0);
  return res;
}

int main(int argc,char **argv) {
  in.open(argv[1]);
  pout.open(argv[2]);
  qout.open(argv[3]);
  rout.open(argv[5]);
  rout << 0 << endl;
  rout.close();
  
  in >> n >> m >> l;
  for (int i=0;i<n;++i) {
    in >> g[i];
  }
  for (int i=0;i<m;++i) {
    in >> g[i+n];
  }
  
  pout >> s1; pout >> s2;
  l1=s1.size(); l2=s2.size();
  if (!CheckValid(s1,s2)) return 0;
  
  qout >> t1 >> t2 >> t3;
  for (int i=0;i<=l1;++i)
    for (int j=0;j<=l2;++j)
      for (int k=0;k<2;++k)
        st[i][j][k].reset();
  for (int i=0;i<n+m;++i)
    st[0][0][0].set(i);
  memset(cnt,0,sizeof(cnt));
  for (int i=0;i<=l1;++i)
    for (int j=0;j<=l2;++j)
        if (i>0) cnt[i][j]=cnt[i-1][j]+(s1[i-1]=='?');
        else cnt[i][j]=cnt[i][j-1]+(s2[j-1]=='?');
  
  for (int i=0;i<=l1;++i)
    for (int j=0;j<=l2;++j)
      for (int k=0;k<2;++k)
        if (st[i][j][k].any()) {
          if (i<l1) {
            if (s1[i]=='0') st[i+1][j][0]|=st[i][j][k];
            if (s1[i]=='1') st[i+1][j][1]|=st[i][j][k];
            if (s1[i]=='?') st[i+1][j][k]|=change(st[i][j][k],cnt[i][j],k);
          }
          if (j<l2) {
            if (s2[j]=='0') st[i][j+1][0]|=st[i][j][k];
            if (s2[j]=='1') st[i][j+1][1]|=st[i][j][k];
            if (s2[j]=='?') st[i][j+1][k]|=change(st[i][j][k],cnt[i][j],k);
          }
        }
  bitset<120> res=st[l1][l2][0]|st[l1][l2][1];
  rout.open(argv[5]);
    int p=0,q=1;
  for (int i=0;i<n;++i)
    if (res.test(i)) p++;
  for (int i=0;i<m;++i)
    if (res.test(i+n)) q++;
  p/=q;
  if (p<t1) rout << 1 << endl;
  if (p>=t1 && p<t2) rout << 2 << endl;
  if (p>=t2 && p<t3) rout << 3 << endl;
  if (p==t3) rout << 5 << endl;
  if (p>t3) rout << 6 << endl;
}
