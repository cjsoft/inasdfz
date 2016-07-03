#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

long long Mod=49999999999993;
int mod=999983,n,m,K;

struct Node{
	long long num;
	int next;
}h[5000];
int H[1000000],num,a[110000],f[110000],T;

int find(long long hs){
	if(H[hs%mod]==0)return 0;
	for(int i=H[hs%mod];i;i=h[i].next){
		if(h[i].num==hs)return 1;
	}return 0;
}

int ins(long long hs){
	h[++num].num=hs;
	h[num].next=H[hs%mod];
	H[hs%mod]=num;
}

void clear(){
	memset(a,0,sizeof(a));
}

int main(){
	int tag,l,r,t;
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		clear();
		scanf("%d %d %d",&n,&K,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}while(m--){
			scanf("%d",&tag);
			if(tag==1){
				scanf("%d %d %d",&l,&r,&t);
				for(int i=l;i<=r;i++){
					a[i]=(a[i]+t)%K;
				}
			}else if(tag==2){
				scanf("%d %d %d",&l,&r,&t);
				for(int i=l;i<=r;i++){
					a[i]=(a[i]*t)%K;
				}
			}else{
				int ans=0;num=0;
				memset(H,0,sizeof(H));
				memset(h,0,sizeof(h));
				memset(f,0,sizeof(f));
				scanf("%d %d",&l,&r);
				f[l]=1;
				while(f[r+1]==0){
					long long hs=0;
					for(int i=l;i<=r;i++){
						if(f[i]){
							hs=(hs*13+a[i]+8)%Mod;
						}
					}if(!find(hs)){ans++;ins(hs);}
					int i=l;f[l]++;
					while(f[i]==2){f[i]=0;f[++i]++;}
				}printf("%d\n",ans);
			}
		}
	}return 0;
}
