#include <iostream>
#include <cstdio>
using namespace std;
long long f[50],w,ans;
int l,n,num,g[50],cnt;
bool check(long long y) {
	int i,j,p[50]; long long k=549755813888ll;
	for (i=1;i<=40;i++) {
		p[i]=y/k;
		y%=k; k/=2;
	}
	bool flag=false;
	for (i=1;i+l-1<=40;i++) {
		for (j=0;j<l;j++)
			if (p[i+j]!=g[j+1]) break;
		if (j==l) {flag=true; break;}
	}
	if (flag) ans++;
}

void work1(int x,long long y) {
	if (x>n) {check (y); return;}
	work1 (x+1,y^f[x]);
	work1 (x+1,y);
}

void work() {
	char str[50][50];
	scanf ("%d\n",&n);
	for (int i=1;i<=n;i++)
		scanf ("%s\n",str[i]+1);
	for (int j=1;j<=n;j++) {
		f[j]=0;
		for (int k=1;k<=40;k++)
			(f[j]*=2)+=str[j][k]-'0';
	}
	scanf ("%d\n",&l);
	scanf ("%s",str[n+1]+1);
	for (int i=1;i<=l;i++)
		g[i]=str[n+1][i]-'0';
	work1 (1,0);
}

int main() {
	freopen ("elf.in","r",stdin);
	freopen ("elf.out","w",stdout);
	work (); printf ("%lld",ans);
	return 0;
}
	
