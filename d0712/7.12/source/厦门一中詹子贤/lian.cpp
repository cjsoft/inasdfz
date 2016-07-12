#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

const int N=100005;

map<int,int> hash;
int n,num[N],m,a[N],c[N],d[N],tail[N];
long long p,q;

int main()
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d%lld%lld",&n,&p,&q);
	for (int i=1; i<=n; i++) 
	{
		scanf("%d",&a[i]);
		num[i]=a[i];
	}
	sort(num+1,num+1+n);
	m=0;
	for (int i=1; i<=n; i++) if (!hash[num[i]]) hash[num[i]]=++m;
	for (int i=1; i<=n; i++) a[i]=hash[a[i]];
	for (int i=1; i<=n; i++) tail[i]=n;
	while (q)
	{
		int minx=0;
		for (int i=1; i<=n; i++)
		  if (tail[i]>=i)
		    if (minx==0) minx=i; else
		    {
		    	for (int j=1; j<=m; j++) c[j]=d[j]=0;
		    	for (int j=i; j<=tail[i]; j++) c[a[j]]++;
		    	for (int j=minx; j<=tail[minx]; j++) d[a[j]]++;
		    	int flag=0;
		    	for (int j=1; j<=m; j++) 
		    	  if (d[j]<c[j]) 
		    	  {
		    	  	flag=1; break;
		    	  }
		    	  else
		    	  if (d[j]>c[j]) break;
//		    	if (p==10) cout << minx << ' ' << i << ' ' << flag << endl;
		    	if (flag) minx=i;
		    }
		if (p<=1) printf("%d %d\n",minx,tail[minx]);
		tail[minx]--;
		p--;
		q--;
	}
	return 0;
}
