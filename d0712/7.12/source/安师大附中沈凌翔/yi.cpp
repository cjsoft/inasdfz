#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int K=30;
const unsigned int M=1<<K;
unsigned int f[20000],g[20000];
int length,ans; char z[300101];

int main() {
	freopen ("yi.in","r",stdin);
	freopen ("yi.out","w",stdout);
	scanf ("%s",z+1); length=strlen (z+1);
	register int a,b;
	for (a=length,b=(K-length%K)%K;a;a--)
		z[a+b]=z[a];
	for (a=1,length+=b;a<=b;a++) z[a]='0';
	for (a=(length/=K),b=1;a;b++) {
		(f[a]<<=1)+=z[b]-'0';
		if (b%K==0) a--;
	}
	while (length>1||f[1]>1) {
		if (f[1]&1) {
			for (a=1;a<=length;a++)
				g[a]=f[a]<<1;
			g[length+1]=0;
			for (a=1;a<=length;a++)
				if (g[a]>=M) {
					g[a]-=M; g[a+1]++;
				}
			if (g[length+1]>0) length++;
			for (a=1;a<=length;a++) {
				f[a]+=g[a];
				if (f[a]>=M) {
					f[a]-=M; f[a+1]++;
				}
			}
			for (a=1,f[1]++;f[a]>=M;a++) {
				f[a]-=M; f[a+1]++;
			}
			if (f[length+1]>0) length++;
		} else {
			for (a=1;a<=length;a++) {
				if (f[a+1]&1) {
					f[a+1]--; f[a]+=M;
				}
				f[a]>>=1;
			}
			if (f[length]==0) length--;
		}
		ans++;
	}
	printf ("%d",ans);
	return 0;
}
