#include <bits/stdc++.h>
using namespace std;
const int MAXN=1500005;
int n;
long long a[MAXN];
void Solve(int l,int r)
{
	if(l==r) return;int mid=l+r>>1;
	for(int i=l,j=mid+1;i<=mid;i++,j++)a[i]-=a[r]-a[j];
	for(int i=mid+1,j=l;i<=r;i++,j++)a[i]-=(a[j]=a[j]+a[mid]>>1);
	Solve(l,mid);Solve(mid+1,r);
}
int main()
{
	freopen("spy.in","r",stdin);freopen("spy.out","w",stdout);
	scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%lld",a+i);
	Solve(1,n);for(int i=1;i<=n;i++) printf("%lld ",a[i]);
	return !printf("\n");
}
