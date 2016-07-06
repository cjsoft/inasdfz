#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
const int BUF_SIZE = (int) 1<<15;
struct fastIO {
	char buf[BUF_SIZE];
	int cur;
	FILE *in;
	fastIO () {
		cur = BUF_SIZE;
		in = stdin;
	}
	inline char nextChar () {
		if (cur == BUF_SIZE) {
			fread (buf, BUF_SIZE, 1, in);
			cur = 0;
		}
		return buf[cur++];
	}
	inline int nextInt () {
		int x = 0;
		char c = nextChar ();
		while (!('0' <= c && c <= '9')) c = nextChar ();
		while ('0' <= c && c <= '9') {
			x = x * 10 + c - '0';
			c = nextChar ();
		}
		return x;
	}
} IO;
const int N=100005;
int a[N][2];
bool p[N];
int main(){
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	int i,n,m,l,r,x;long long ans=0;
	n=IO.nextInt();
	for(i=1;i<=n;i++) a[i][0]=IO.nextInt();
	for(i=1;i<=n;i++) a[i][1]=IO.nextInt();
	m=IO.nextInt();
	for(i=1;i<=m;i++){
		l=IO.nextInt();r=IO.nextInt();x=IO.nextInt();
		for(register int j=l;j<=r;j++)
			if(a[j][p[j]]<=x) p[j]^=1;
	}
	for(i=1;i<=n;i++) ans+=a[i][p[i]];
	printf("%lld",ans);
	return 0;
}
