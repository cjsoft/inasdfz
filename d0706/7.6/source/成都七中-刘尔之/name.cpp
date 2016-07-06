#include<cstdio>
#include<iostream>
#define N 100001
#define f(x)if(d[x]<=s)c[x]^=1,d[x]^=b[x];
using namespace std;
int a[N],b[N],c[N],d[N];
int main(){
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	int n,m;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),d[i]=a[i];
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),b[i]^=a[i];
	for(scanf("%d",&m);m--;){
		int l,r,s;scanf("%d%d%d",&l,&r,&s);
		if(r-l>20){
			while(l&7){if(d[l]<=s)c[l]^=1,d[l]^=b[l];l++;}
			while(r+1&7){if(d[r]<=s)c[r]^=1,d[r]^=b[r];r--;}
			register int p=l,q=r,i=l;
			for(;i<r;i+=8){
				f(i);f(i+1);f(i+2);f(i+3);f(i+4);f(i+5);f(i+6);f(i+7);
			}
		}
		else for(int i=l;i<=r;i++)f(i);
	}
	long long ans=0;
	for(int i=1;i<=n;i++)ans+=c[i]?b[i]^a[i]:a[i];
	cout<<ans;
}
