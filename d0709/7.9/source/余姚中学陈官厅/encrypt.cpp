#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <ctime>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1100000;
int lg[1500000], mi[50], f[510000][20], g[510000][20], n, a[N], ans[N];
char ch[N];
bool vis[200];
#define REP for (int i = 0; i < n; i++)
#define PER for (int i = n - 1; i >= 0; i--)
#define REP2 for (int i = 0; i < m; i++)
#define REP3 for (int i = 1; i < m; i++)
#define REP4 for (int i = 1; i < n; i++)
int wa[N], wb[N], wc[N], wd[N], sa[N], rank[N], height[N];
inline int cmp(int *r, int a, int b, int l) {
 return r[a] == r[b] && r[a + l] == r[b + l];
}
inline void da(int *r, int *sa, int n, int m) {
 int *x = wa, *y = wb;
 REP2 wd[i] = 0;
 REP wd[x[i] = r[i]]++;
 REP3 wd[i] += wd[i - 1];
 PER sa[--wd[x[i]]] = i;
 for (int j = 1, p = 1; p < n; j *= 2, m = p) {
  p = 0;
  for (int i = n - j; i < n; i++) y[p++] = i;
  REP if (sa[i] >= j) y[p++] = sa[i] - j;
  REP wc[i] = x[y[i]];
  REP2 wd[i] = 0;
  REP wd[wc[i]]++;
  REP3 wd[i] += wd[i - 1];
  PER sa[--wd[wc[i]]] = y[i];
  swap(x, y);
  p = 1;
  x[sa[0]] = 0;
  REP4 x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
 }
}
inline void calheight(int *r, int *sa, int n) {
 int j, k = 0;
 for (int i = 1; i <= n; i++) rank[sa[i]] = i;
 for (int i = 0; i < n; height[rank[i++]] = k)
  for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
}
inline int queryf(int l, int r)
{
 int t = lg[r - l + 1];
 return min(f[l][t], f[r - mi[t] + 1][t]);
}
inline int queryg(int l, int r)
{
 l++;
 int t = lg[r - l + 1];
 return min(g[l][t], g[r - mi[t] + 1][t]);
}
int main() {
 freopen("encrypt.in", "r", stdin);
 freopen("encrypt.out", "w", stdout);
 scanf("%s", ch);
 n = strlen(ch);
 for (int i = 0; i < n; i++) a[i] = ch[i];
 da(a, sa, n + 1, 200);
 calheight(a, sa, n);
 for (int i = 1; i <= n; i++) sa[i]++;
 for (int i = 1; i <= n; i++) rank[sa[i]] = i;
 for (int i = n; i >= 1; i--) a[i] = a[i - 1];
 for (int i = 1; i <= n; i++) f[i][0] = sa[i];
 mi[0] = 1; for (int i = 1; i <= 19; i++) mi[i] = mi[i - 1] * 2;
 for (int i = 0; i < 19; i++)
  for (int j = mi[i]; j < mi[i + 1]; j++)
   lg[j] = i;
 for (int i = 1; i <= 19; i++)
  for (int j = 1; j <= n - mi[i] + 1; j++)
   f[j][i] = min(f[j][i - 1], f[j + mi[i - 1]][i - 1]);
 for (int i = 2; i <= n; i++) g[i][0] = height[i];
 for (int i = 1; i <= 19; i++)
  for (int j = 1; j <= n - mi[i] + 1; j++)
   g[j][i] = min(g[j][i - 1], g[j + mi[i - 1]][i - 1]);
 int now = 1;
 while (now < n)
 {
  if (!vis[a[now]])
  {
   ans[++ans[0]] = -1;
   ans[++ans[0]] = a[now];
   vis[a[now]] = 1;
   now++;
   continue;
  }
  int t = rank[now];
  int t1 = 0;
  int p1, p2;
  if (queryf(1, t) >= now)
   p1 = t;
  else
  {
   int l = 1, r = t;
   while (l < r)
   {
    int mid = l + r + 1 >> 1;
    if (queryf(mid, t) < now)
     l = mid;
    else
     r = mid - 1;
   }
   p1 = l;
  }
  if (queryf(t, n) >= now)
   p2 = t;
  else
  {
   int l = t, r = n;
   while (l < r)
   {
    int mid = l + r >> 1;
    if (queryf(t, mid) < now)
     r = mid;
    else
     l = mid + 1;
   }
   p2 = l;
  }
  if (p1 < t) t1 = max(t1, queryg(p1, t));
  if (t < p2) t1 = max(t1, queryg(t, p2));
//  printf("%d %d %d\n", p1, p2, t1);
  int t2, t3;
  if (p1 < t)
  {
   if (t1 == queryg(p1, t))
   {
    int l = 1, r = t;
    if (queryg(1, t) == t1)
     t2 = 1;
    else
    {
     while (l < r)
     {
      int mid = l + r >> 1;
      if (queryg(mid, t) == t1)
       r = mid;
      else
       l = mid + 1;
     }
     t2 = l;
    }
   } else t2 = t;
  } else t2 = t;
  if (t < p2)
  {
   if (t1 == queryg(t, p2))
   {
    int l = t, r = n;
    if (queryg(t, n) == t1)
     t3 = n;
    else
    {
     while (l < r)
     {
      int mid = l + r + 1 >> 1;
      if (queryg(t, mid) == t1)
       l = mid;
      else
       r = mid - 1;
     }
     t3 = l;
    }
   } else t3 = t;
  } else t3 = t;
  int t4 = queryf(t2, t3);
//  printf("%d %d %d\n", t2, t3, t4);
  ans[++ans[0]] = t1;
  ans[++ans[0]] = t4 - 1;
  now += t1;
 }
 for (int i = 1; i < ans[0]; i++)
  printf("%d ", ans[i]);
 printf("%d\n", ans[ans[0]]);
}

