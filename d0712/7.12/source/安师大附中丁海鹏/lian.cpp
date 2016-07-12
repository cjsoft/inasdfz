#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node{
	int l,r;
}ans[4100000];

const int bs=2333;
const long long Mod=49999999999993ll;

long long bin[2100];
long long hsh[2100][2100];
int cnt[2100][2100],n,L,R,a[2100],num;

long long toz(long long x){
	return (x+Mod)%Mod;
}

long long hash(int pos,int l,int r){
	return toz(hsh[r][pos]-hsh[l-1][pos]);
}

int count(int x,int l,int r){
	return cnt[r][x]-cnt[l-1][x];
}

int cmp1(int l1,int r1,int l2,int r2){
	int l=0,r=n+1;
	while(l+1<r){
		int mid=l+r>>1;
		if(hash(mid,l1,r1)==hash(mid,l2,r2))l=mid;
		else r=mid;
	}return count(r,l1,r1)<count(r,l2,r2);
}

int cmp(const void *a,const void *b){
	Node x=*(Node *)a;
	Node y=*(Node *)b;
	int l1=x.l,r1=x.r,l2=y.l,r2=y.r;
	if(hash(n,l1,r1)==hash(n,l2,r2))return l1>l2?1:-1;
	else return cmp1(l1,r1,l2,r2);
}

int main(){
	bin[1]=1;
	for(int i=2;i<=2010;i++)bin[i]=bin[i-1]*bs%Mod;
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d %d %d",&n,&L,&R);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cnt[i][j]=cnt[i-1][j]+(a[i]==j);
			hsh[i][j]=hsh[i-1][j]+(a[i]>j?0:bin[a[i]]);
		}
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans[++num]=(Node){i,j};
		}
	}qsort(ans+1,num,sizeof(Node),cmp);
	for(int i=L;i<=R;i++){
		printf("%d %d\n",ans[i].l,ans[i].r);
	}return 0; 
}
