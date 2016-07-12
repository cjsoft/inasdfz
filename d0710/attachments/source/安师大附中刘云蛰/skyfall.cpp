#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
const int mod=1<<30;
const int N=25000000;
int d[N+5],p[N/2+5];
bool fl[N+5];
void init(){
	int i,j,t,k,s;
	d[1]=1;
	for(i=2;i<=N;i++){
		if(!fl[i]){
			p[++p[0]]=i;
			d[i]=2;
		}
		for(j=1;j<=p[0]&&(t=p[j]*i)<=N;j++){
			fl[t]=1;
			if(i%p[j]==0){
				k=i;s=0;
			    while(k%p[j]==0) k/=p[j],s++;
			    d[t]=d[i]/(s+1)*(s+2);
				break;
			}
			d[t]=d[i]*2;
		}
	}
}
int main(){
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	init();
	int a,b,c,i,j,k;
	long long ans=0;
	scanf("%d %d %d",&a,&b,&c);
	for(i=1;i<=a;i++)
	    for(j=1;j<=b;j++)
	        for(k=1;k<=c;k++)
	            ans+=d[i*j*k];
	printf("%lld\n",ans%mod);
	return 0;
}
