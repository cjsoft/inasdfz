#include<cstdio>
using namespace std;
typedef long long ll;
int n,a[1500010];
ll b[1500010];
char s[15];
int read()
{
	char ch=getchar();
	while (ch>'9'||ch<'0') ch=getchar();
	int x=0;
	while (ch<='9'&&ch>='0'){x=(x<<3)+x+x+ch-'0';ch=getchar();}
	return x;
}
ll Read()
{
	char ch=getchar();
	while (ch>'9'||ch<'0') ch=getchar();
	ll x=0;
	while (ch<='9'&&ch>='0'){x=(x<<3)+x+x+ch-'0';ch=getchar();}
	return x;
}
void print(int x)
{
	int l=0;
	if (!x) s[l++]='0';
	if (x<0){putchar('-');x=-x;}
	while (x){s[l++]=x%10+'0';x/=10;}
	for (int i=l-1;i>=0;i--) putchar(s[i]);
}
void solve(int l,int r)
{
	if (l==r){a[l]=b[l];return;}
	int mid=(l+r)>>1;
	ll sum=b[r]-b[mid];
	for (int i=l;i<=mid;i++) b[i]=(b[i]+b[i+mid-l+1]-sum)>>1;
	solve(l,mid);
	for (int i=l;i<=mid;i++) b[i]=(b[i]<<1)+sum-b[i+mid-l+1];
	for (int i=mid+1;i<=r;i++) b[i]=(b[i]-b[i-mid+l-1]+sum)>>1;
	solve(mid+1,r);
	for (int i=mid+1;i<=r;i++) b[i]=(b[i]<<1)-sum+b[i-mid+l-1];
}
int main()
{
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) b[i]=Read();
	solve(1,n);
//	for (int i=1;i<n;i++) printf("%d ",a[i]);printf("%d\n",a[n]);
	for (int i=1;i<n;i++){print(a[i]);putchar(' ');}
	print(a[n]);puts("");
}
