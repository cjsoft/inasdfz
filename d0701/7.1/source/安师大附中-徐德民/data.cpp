#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,N,K,M,A[30005],F[30005],Mod=998244353;
void Zuo1(){
	int i,l,r,x,t;
	for(i=1;i<=N;i++)scanf("%d",&A[i]);
	while(M--){
		scanf("%d%d%d",&t,&l,&r);
		if(t==1){scanf("%d",&x);continue;}
		if(t==2){scanf("%d",&x);continue;}
		printf("%d\n",r-l+1);
		}
}
void Zuo2(){
	int i,l,r,x,t,l0,l1;
	for(i=1;i<=N;i++)scanf("%d",&A[i]);
	while(M--){
		scanf("%d%d%d",&t,&l,&r);
		if(t==1){
			scanf("%d",&x);
			for(i=l;i<=r;i++)A[i]=(A[i]+x)%K;
			continue;
			}
		if(t==2){
			scanf("%d",&x);
			for(i=l;i<=r;i++)A[i]=A[i]*x%K;
			continue;
			}
		F[l-1]=0;l0=l1=l-1;
		for(i=l;i<=r;i++){
			F[i]=(1+F[l0]+F[l1])%Mod;
			if(A[i]==0)l0=i;
			if(A[i]==1)l1=i;
			}
		printf("%d\n",(F[l0]+F[l1])%Mod);
		}
}
void Zuo3(){
	int i,l,r,x,t,l0,l1,l2;
	for(i=1;i<=N;i++)scanf("%d",&A[i]);
	while(M--){
		scanf("%d%d%d",&t,&l,&r);
		if(t==1){
			scanf("%d",&x);
			for(i=l;i<=r;i++)A[i]=(A[i]+x)%K;
			continue;
			}
		if(t==2){
			scanf("%d",&x);
			for(i=l;i<=r;i++)A[i]=A[i]*x%K;
			continue;
			}
		F[l-1]=0;l0=l1=l2=l-1;
		for(i=l;i<=r;i++){
			F[i]=((long long)1+(long long)F[l0]+(long long)F[l1]+(long long)F[l2])%Mod;
			if(A[i]==0)l0=i;
			if(A[i]==1)l1=i;
			if(A[i]==2)l2=i;
			}
		printf("%d\n",((long long)F[l0]+(long long)F[l1]+(long long)F[l2])%Mod);
		}
}
void Zuo4(){
	int i,l,r,x,t,l0,l1,l2,l3;
	for(i=1;i<=N;i++)scanf("%d",&A[i]);
	while(M--){
		scanf("%d%d%d",&t,&l,&r);
		if(t==1){
			scanf("%d",&x);
			for(i=l;i<=r;i++)A[i]=(A[i]+x)%K;
			continue;
			}
		if(t==2){
			scanf("%d",&x);
			for(i=l;i<=r;i++)A[i]=A[i]*x%K;
			continue;
			}
		F[l-1]=0;l0=l1=l2=l3=l-1;
		for(i=l;i<=r;i++){
			F[i]=((long long)1+(long long)F[l0]+(long long)F[l1]+(long long)F[l2]+(long long)F[l3])%Mod;
			if(A[i]==0)l0=i;
			if(A[i]==1)l1=i;
			if(A[i]==2)l2=i;
			if(A[i]==3)l3=i;
			}
		printf("%d\n",((long long)F[l0]+(long long)F[l1]+(long long)F[l2]+(long long)F[l3])%Mod);
		}
}
void Zuo5(){
	int i,l,r,x,t,l0,l1,l2,l3,l4;
	for(i=1;i<=N;i++)scanf("%d",&A[i]);
	while(M--){
		scanf("%d%d%d",&t,&l,&r);
		if(t==1){
			scanf("%d",&x);
			for(i=l;i<=r;i++)A[i]=(A[i]+x)%K;
			continue;
			}
		if(t==2){
			scanf("%d",&x);
			for(i=l;i<=r;i++)A[i]=A[i]*x%K;
			continue;
			}
		F[l-1]=0;l0=l1=l2=l3=l4=l-1;
		for(i=l;i<=r;i++){
			F[i]=((long long)1+(long long)F[l0]+(long long)F[l1]+(long long)F[l2]+(long long)F[l3]+(long long)F[l4])%Mod;
			if(A[i]==0)l0=i;
			if(A[i]==1)l1=i;
			if(A[i]==2)l2=i;
			if(A[i]==3)l3=i;
			if(A[i]==4)l4=i;
			}
		printf("%d\n",((long long)F[l0]+(long long)F[l1]+(long long)F[l2]+(long long)F[l3]+(long long)F[l4])%Mod);
		}
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&N,&K,&M);
		if(K==1)Zuo1();
		if(K==2)Zuo2();
		if(K==3)Zuo3();
		if(K==4)Zuo4();
		if(K==5)Zuo5();
	    }
	return 0;
}

