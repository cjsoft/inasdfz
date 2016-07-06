#include<iostream>
#include<stdio.h>
using namespace std;
int n,m;
int a[100050],b[100050];
int main(){
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	scanf("%d",&m);
	while(m--){
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		for(int i=l;i<=r;i++)
			if(a[i]<=x) swap(a[i],b[i]);
	}
	long long sum=0;
	for(int i=1;i<=n;i++)
		sum+=(long long)a[i];
	cout<<sum<<endl;
}
