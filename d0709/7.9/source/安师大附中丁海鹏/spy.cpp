#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

long long a[2100000],s,n,ans[2100000];
int tmp[2100000];

int bct(int k){
	int cnt=0;
	while(k){
		cnt+=k&1;
		k>>=1;
	}return cnt;
}

int main(){
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	scanf("%lld",&n);
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",(bct((i|j)^i)+1)%2);
		}printf("\n");
	}*/
	for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
			s+=a[i];
	}

	if(n==2){
		printf("%lld %lld\n",a[0],a[1]-a[0]);
		return 0;
	}
	
	ans[0]=(s-n/2*a[n-1])/(n/2);
	for(int i=0;i<n;i++){
		a[i]-=ans[0];
	}for(int i=1;i<n;i++){
		tmp[0]=0;s=0;
		for(int j=0;j<n;j++){
			if((bct((i|j)^j)+1)%2==1)tmp[++tmp[0]]=j,s+=a[j];
		}ans[i]=(s-n/4*a[n-1])/(n/4);
		for(int j=1;j<=tmp[0];j++){
			a[tmp[j]]-=ans[i];
		}
	}for(int i=0;i<n;i++){
		printf("%lld ",ans[i]);
	}return 0;
}
