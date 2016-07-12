#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
map<int,int> hash;
const int maxn = 1000;
pair<int,int> e[maxn*maxn];
int n,p,q,a[maxn],a1[maxn],b1[maxn],p1[maxn],tot,cnt;
bool cmp(pair<int,int> x,pair<int,int> y)
{
	for(int i = 0; i <= n; i++) a1[i]=0;
	for(int i = 0; i <= n; i++) b1[i]=0;
	for(int i = x.first; i <= x.second; i++) a1[hash[a[i]]]++;
	for(int i = y.first; i <= y.second; i++) b1[hash[a[i]]]++;
	for(int i = 0; i <= n; i++)
		if(a1[i]!=b1[i])return a1[i]>b1[i];
	return (x.first)<(y.first);
}
bool cmp1(int x,int y)
{
	return a[x]<a[y];
}
int main(void)
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d%d%d",&n,&p,&q);
	for(int i = 1; i <= n; i++)
		scanf("%d",&a[i]),p1[i]=i;
	sort(p1+1,p1+1+n,cmp1);
	for(int i = 1; i <= n; i++) if(!hash[a[p1[i]]])hash[a[p1[i]]]=++cnt;
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
			e[++tot]=make_pair(i,j);
	sort(e+1,e+tot+1,cmp);
	for(int i = p; i <= q;i++)
		printf("%d %d\n",e[i].first,e[i].second);
	return 0;
}
