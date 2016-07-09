#include<cstdio>
#define FOR(l,r) for(int i=l;i<=r;i++)
#define ll long long
#define N 1500010
int n,a[N]; ll b[N];
using namespace std;
ll read(){
	ll x=0; char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
	return x;
}
void solve(int l,int r){
	if(l==r){a[l]=b[l]; return;} 
	int mid=(l+r)>>1; ll tmp=b[r]-b[mid];
	FOR(l,mid)b[i]=(b[i]+b[mid+1+i-l]-tmp)>>1;
	FOR(mid+1,r)b[i]-=b[l+i-mid-1];
	solve(l,mid); solve(mid+1,r);
}
void pint(int x)
{
	int tmp[20],*t=tmp;
	for(;x;x/= 10)*t++=x%10+'0';
	if(t==tmp)putchar('0');
	else for(--t;t>=tmp;--t) putchar(*t);
	putchar(' ');
}
int main(){
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	n=read(); FOR(1,n)b[i]=read(); solve(1,n);
	FOR(1,n)pint(a[i]);
	return 0;
}
