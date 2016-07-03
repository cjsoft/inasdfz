#include<iostream>
#include<stdio.h>
#define mod 998244353
using namespace std;
int a[50050],p[5];
int dp[50050];
int n,m,k,T;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&k,&m);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		while(m--){
			int id,l,r;
			scanf("%d%d%d",&id,&l,&r);
			if(id==1){
				int num;
				scanf("%d",&num);
				for(int i=l;i<=r;i++)
				a[i]=(a[i]+num)%k;
			}
			else if(id==2){
				int num;
				scanf("%d",&num);
				for(int i=l;i<=r;i++)
				a[i]=(a[i]*num)%k;
			}
			else{
				for(int i=0;i<k;i++) p[i]=0;
				for(int i=l;i<=r;i++){
					dp[i]=1;
					for(int j=0;j<k;j++)
					dp[i]=(dp[i]+dp[p[j]])%mod;
					p[a[i]]=i;
				}
				int ans=0;
				for(int i=0;i<k;i++)
				 ans=(ans+dp[p[i]])%mod;
				printf("%d\n",ans);				
			}
		}
	}
}
