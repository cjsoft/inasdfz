#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL read2()
{
	LL s=0,f=1;char ch=getchar();
	while(!('0'<=ch&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0';ch=getchar();}
	return s*f;
}
int n;
LL b[1500005];
int bitcount(int k)
{
	int s=0;
	while(k)
	   s+=(k&1),k>>=1;
	return s;
}
void solve(int l,int r)
{
	if(l+1==r)return;
	int mid=(l+r)/2,L2=(r-l+1)/2;
	b[r-1]-=b[mid-1];
	for(int i=l;i<mid-1;i++)
	    b[i]=b[i]-(b[i]+b[r-1]-b[i+L2])/2;
	for(int i=mid;i<r-1;i++)
	    b[i]=b[i]-b[i-L2];
	solve(l,mid);
	solve(mid,r);
}
int main()
{
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	//while(1){n=read();
	//for(int i=0;i<n;i++)
	//    b[i]=read();
	//for(int i=0;i<n;i++,cout<<endl)
	//    for(int j=0;j<n;j++)
	//        printf("%d ",(bitcount((i|j)^i)^1)&1);}
	n=read2();
	for(int i=0;i<n;i++)
		b[i]=read2();
	solve(0,n);
	for(int i=0;i<n;i++)
		printf("%d ",int(b[i]));printf("\n");
	return 0;
}
