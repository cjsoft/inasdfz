#include<iostream>
#include<stdio.h>
using namespace std;
int n;
long long b[1050005];
void work(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1,w=(r-l+1)>>1;
	work(l,mid);work(mid+1,r);
	for(int i=l;i<=mid;i++){
		long long x=b[i],y=b[i+w];
		b[i]=x+y;
		b[i+w]=y-x;
	}
	if(w>=2)
		for(int i=l;i<=r;i++)
			b[i]>>=1LL;
}
int main(){
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%I64d",&b[i]);
	work(1,n);
	long long sum=0LL;
	for(int i=2;i<=n;i++) sum+=b[i];
	b[1]-=sum;b[1]>>=1LL;
	for(int i=1;i<=n;i++)
		printf("%d%c",(int)b[i],i==n?'\n':' ');
}
