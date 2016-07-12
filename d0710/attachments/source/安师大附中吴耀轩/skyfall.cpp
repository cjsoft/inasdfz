#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <time.h>
using namespace std;
const int maxn = 25000005;
const int N = 25000000;
const int mod = (1<<30)-1;
typedef long long LL;
int prime[maxn],tot;
bool jud[maxn];
int sum[maxn];
int A,B,C;LL ans;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("skyfall.in","r",stdin);
		freopen("skyfall.out","w",stdout);
	#endif
	sum[1]=1;
	for (int i=2;i<=N;i++) {
		if (!jud[i]) {prime[++tot]=i;sum[i]=2;}
		for (register int t,j=1;j<=tot;j++) {
			t=prime[j]*i;
			if (t>N) break;
			jud[t]=1;
			if (i%prime[j]==0) {
				register int &ans=sum[t],cnt=1;
				while (t%prime[j]==0) {
					t/=prime[j];++cnt;
				}
				ans=sum[t]*cnt;
				break;
			}
			else sum[t]=sum[i]*2;
		}
		sum[i]&=mod;
	}
	
	scanf("%d %d %d",&A,&B,&C);
	if (A<B) swap(A,B);
	if (A<C) swap(A,C);
	if (B<C) swap(B,C);
	for (register int i=1;i<=A;i++)
	for (register int j=1;j<=B;j++) {
		register int x=i*j,t=i*j*C;
		for (register int c=x;c<=t;c+=x)
			(ans+=sum[c])&=mod;
	}
	printf("%lld\n",ans);
//	printf("%d\n",clock());
	return 0;
}
