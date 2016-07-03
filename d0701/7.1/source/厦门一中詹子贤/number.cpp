#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int a[100000000],n,ans,k;
long long ansx;

void dfs(int y)
{
	if (y>n)
	{
		long long x=0,tmp;
		for (int i=1; i<=n; i++) x=x*10+a[i];
		int j=n,flag=1; tmp=x;
		if (x==0) return;
		int z=1;
		while (!a[z]) z++;
		while ((j>=z)&&(x))
		{
//			if (tmp==10) cout << j << ' ' << x << ' ' << x%2 << ' ' << a[j] << endl;
			if (x%2!=a[j]) {flag=0; break;}
			j--;
			x>>=1;
		}
		if ((flag))
		{
			ans++;
			if (ans==k) {ansx=tmp; return;} return;
			long long g=0,h=1;
			for (int i=1; i<=z; i++) cout << " ";
			cout << tmp << ' ';
//			x=tmp;
			while (tmp)
			{
//				g<<=1;
				if (tmp%10) g+=h;
				tmp/=10;;
				h<<=1;
			}
			cout << g/2 << ' ' << ans << ' ' << n-z << endl;
		//	cout << tmp << ' ' << ans << ' ' << n-z << endl;
			 /*
			j=1;
			while (!a[j]) j++;
			for (; j<=n; j++) cout << a[j]; cout << endl;*/
		}
		return;
	}
	a[y]=0;
	dfs(y+1);
	if (ans==k) return;
	a[y]=1;
	dfs(y+1);
}

int main()
{
//	freopen("number.txt","w",stdout);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	n=21;
	scanf("%d",&k);
	dfs(1);
//	cout << 'a' << endl;
	printf("%lld\n",ansx);
}
