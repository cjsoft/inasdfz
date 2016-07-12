#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int N;long long M,P,PP,Ans,Mod=998244353;
bool V[100005];int Prime[100005],Tot,U[100005];
void Shai(){
    int i,j;U[1]=1;
    for(i=2;i<=100000;i++){
        if(V[i]==0){Tot++;Prime[Tot]=i;U[i]=-1;}
        for(j=1;j<=Tot&&(long long)i*(long long)Prime[j]<=100000;j++){
            V[i*Prime[j]]=1;
            if(i%Prime[j]!=0){U[i*Prime[j]]=-U[i];continue;}
            U[i*Prime[j]]=0;break;
            }
        }
}
long long Kuai(long long d,int z){
	if(z==0)return 1;
	if(z%2==0)return Kuai(d*d%Mod,z/2);
	return Kuai(d*d%Mod,z/2)*d%Mod;
}
int main(){
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d%lld",&N,&M);P=M/N;int i,j;P%=Mod;PP=(P+1)%Mod;Shai();
	if(M%N!=0){printf("0\n");return 0;}
	for(i=1;i<=N;i++){
		if(N%i!=0)continue;
		if(U[N/i]==1){Ans+=Kuai(PP,i);Ans%=Mod;Ans=(Ans+Mod-Kuai(P,i))%Mod;continue;}
		if(U[N/i]==-1){Ans+=Kuai(P,i);Ans%=Mod;Ans=(Ans+Mod-Kuai(PP,i))%Mod;continue;}
	    }
	Ans=(long long)Ans*(long long)Kuai(N,Mod-2)%Mod;printf("%lld\n",Ans);
	return 0;
}

