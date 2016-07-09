#include <cstdio>
#include <algorithm>
#include <ctime>

using namespace std;

#define MAXN 1500009
long long b[MAXN],a[MAXN],tmp[MAXN];
int n;
long long readint(){
	int ch=getchar();
	long long ret=0;
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret;
}
void fastout(long long x){
	if (!x) return;
	fastout(x/10);
	putchar(48+x % 10);
}
void solve(int l,int r,int dep){
	if (l==r) {
		a[l]=b[l];
		return;
	}
	int mid=(l+r)>>1,len=(r-l+1)/2;
	for (int i=l;i<=r;i++){
		tmp[i]=b[i];
	}
	for (int i=0;i<len;i++){
		b[l+i]=tmp[l+i]+tmp[mid+i+1]-tmp[l]+tmp[mid+1];
		b[l+i]>>=1;
	}
	for (int i=0;i<len;i++){
		b[mid+i+1]=tmp[l+i]-tmp[mid+i+1]-tmp[mid+1]+tmp[l];
		b[mid+i+1]>>=1;
	}
	solve(l,mid,dep+1);
	solve(mid+1,r,dep+1);
}
int main(){
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		b[i^(n-1)]=readint();
	}
	solve(0,n-1,0);
	//fprintf(stderr,"%.3f\n",(double)clock()/CLOCKS_PER_SEC);
	for (int i=0;i<n;i++){
		if (!a[i]) putchar(48);
		else {
			fastout(a[i]);
		}	
			putchar(' ');
	}
//	fprintf(stderr,"%.3f\n",(double)clock()/CLOCKS_PER_SEC);
}
