#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define N 1500005
int n,m,k,l,t,s;
ll ans,b[N];
int a[N];
ll read(){
	ll x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x;
}
void erfen(int l,int r){
	if(l==r){
		a[l]=b[l];
		return;
	}
	int mid=l+r>>1;
	ll s=b[r]-b[mid];
	int L=r-l+1;
	for (int i=l;i<=mid;i++){
		ll x=b[i],y=b[i+L/2];
		b[i]=(x+y-s)/2;
		b[i+L/2]=(y-x+s)/2;
	}
	erfen(l,mid);
	erfen(mid+1,r);
}
void write(int x){
	char st[11];
	if(x<0)x=-x;
	t=0;
	while(x){
		st[++t]=x%10+48;
		x/=10;
	}
	for (int i=t;i;i--)putchar(st[i]);
}
int main(){
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++)b[i]=read();
	erfen(1,n);
	for (int i=1;i<n;i++){write(a[i]);putchar(' ');}
	write(a[n]);
	puts("");
}
