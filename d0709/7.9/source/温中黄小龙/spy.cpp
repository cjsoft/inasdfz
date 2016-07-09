#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 1500001

ll b[MAXN],a[MAXN];
ll nw[MAXN],sum1[MAXN],sum2[MAXN];

#define BIT 1000000000

void solve(int l,int r){
	if(l==r){
		sum2[l]=b[l];
		return;
	}
	int len=r-l+1;
	int mid=(l+r)>>1;
	solve(l,mid); solve(mid+1,r);
	for(int i=l;i<=mid;++i){
		int nx=i+(len>>1);
		ll t1=sum1[i],t2=sum2[i];
		sum1[i]+=sum1[nx];
		sum2[i]+=sum2[nx];
		sum1[nx]+=t2; sum2[nx]+=t1;
	}
}

ll getll(){
	ll x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
		x=x*10+ch-'0',ch=getchar();
	return x;
}
char s[20000000],*fp=s;
void putll(ll x){
	int tmp[20],len=0;
	while(x)tmp[len++]=x%10,x/=10;
	for(int j=len-1;j>=0;--j)
		*(fp++)='0'+tmp[j];
	*(fp++)=' ';
}

int main(){
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	int n=getll();
	for(int i=0;i!=n;++i)
		b[i]=getll();
	if(n<=4){
		if(n==1)printf("%I64d\n",b[0]);
		else if(n==2){
			printf("%I64d %I64d\n",b[0],b[1]-b[0]);
		}else{
			ll b0=-(b[3]-b[2]-b[1]-b[0])/2;
			printf("%I64d %I64d %I64d %I64d\n",b0,b[1]-b0,b[2]-b0,b[3]+b0-b[1]-b[2]);
		}
		return 0;
	} 
	for(int i=0;i!=n;++i)
		nw[i]=b[n-1];
	ll tmp=b[n-1]*((n>>1)-1);
	for(int i=0;i!=n-1;++i)tmp-=b[i];
	tmp/=-(n>>1);
	b[n-1]=0;
	for(int i=0;i!=n-1;++i)b[i]-=tmp,nw[i]-=tmp;
	nw[n-1]-=tmp;
	a[0]=tmp;
	solve(0,n-1);
	for(int i=1;i!=n;++i){
		a[i]=(sum2[i]-nw[i]*((n>>2)-1))/((n>>2));
	}
	for(int i=0;i!=n;++i)
		putll(a[i]);
	puts(s);
	
	return 0;
}
