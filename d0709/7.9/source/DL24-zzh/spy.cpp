#include<cstdio>
int n;
long long dat[22][1100000];
long long a[1100000];
long long b[1100000];
void get(int ceng,int l,int r){
	if (l==r){
		a[l]=dat[ceng][l];
		return;
	}
	int mid=(l+r)>>1;
	int t=((r-l)+1)>>1;
	for (int i=mid+1;i<=r;i++) dat[ceng+1][i]=(dat[ceng][i]-dat[ceng][i-t])>>1;
	for (int i=l;i<=mid;i++) dat[ceng+1][i]=(dat[ceng][i]+dat[ceng][i+t])>>1;
	get(ceng+1,l,mid);
	get(ceng+1,mid+1,r);
}

int main(){
    freopen("spy.in","r",stdin);
    freopen("spy.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%I64d",b+i);
	int t=n>>1;
	for (int i=t;i<n;i++) dat[1][i]=b[i]-b[i-t];
	for (int i=0;i<t;i++) dat[1][i]=b[i+t]-(b[n-1]-b[i]);
	get(1,0,t-1);
	get(1,t,n-1);
	for (int i=0;i<n;i++) printf("%I64d ",a[i]);
	printf("\n");
	return 0;
}
