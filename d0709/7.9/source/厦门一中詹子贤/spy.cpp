#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const int N=1500005;

int n;
long long ans[N],a[N],b[N],sum;

long long read()
{
    long long x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main()
{
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	n=read();
	for (int i=0; i<n; i++) 
	{
		b[i]=read();
		sum+=b[i];
	}
	sum-=b[n-1];
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n-1; j++)
		{
			int x=((j|i)^j),tmp=1;
			for (; x; x>>=1)
			  if (x&1) tmp^=1;
			if (tmp) 
			{
				a[i]+=b[j];
//				cout << i << ' ' << j << endl;
			}
		}
	}
//	cout << 'a' << endl;
	ans[0]=(sum-b[n-1]*(n/2-1))/(n-n/2);
	printf("%d",ans[0]);
//	cout << ans[0] << ' ';
	for (int i=1; i<n; i++) printf(" %d",(a[i]-b[n-1]*(n/4-1))/(n/4)-ans[0]); printf("\n");
	return 0;
}
