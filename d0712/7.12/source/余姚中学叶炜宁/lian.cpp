#include<cstdio>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
struct node{int x,y;}q[4000010];
int n,P,Q,tot,a[2010],f[2010][2010];
ull mi[2010],H[2010][2010];
char s[15];
bool cmp(node x,node y)
{
	int l=1,r=n;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (H[x.y][mid]-H[x.x-1][mid]!=H[y.y][mid]-H[y.x-1][mid]) r=mid;else l=mid+1;
	}
	if (f[x.y][l]-f[x.x-1][l]==f[y.y][l]-f[y.x-1][l]) return x.x<y.x;
	return f[x.y][l]-f[x.x-1][l]>f[y.y][l]-f[y.x-1][l];
}
int read()
{
	char ch=getchar();
	while (ch>'9'||ch<'0') ch=getchar();
	int x=0;
	while (ch>='0'&&ch<='9'){x=(x<<3)+x+x+ch-'0';ch=getchar();}
	return x;
}
void print(int x)
{
	int l=0;
	if (!x) s[l++]=0;
	while (x){s[l++]=x%10+'0';x/=10;}
	for (int i=l-1;i>=0;i--) putchar(s[i]);
}
int main()
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	n=read();P=read();Q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	mi[0]=1;
	for (int i=1;i<=n;i++) mi[i]=mi[i-1]*6662333;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) f[i][j]=f[i-1][j];
		f[i][a[i]]++;
		for (int j=1;j<=n;j++) H[i][j]=H[i][j-1]+f[i][j]*mi[j];
	}
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++){q[++tot].x=i;q[tot].y=j;}
	sort(q+1,q+tot+1,cmp);
	for (int i=P;i<=Q;i++)
	{
		print(q[i].x);putchar(' ');print(q[i].y);
		puts("");
	}
}
