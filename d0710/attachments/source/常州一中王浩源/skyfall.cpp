#include<bits/stdc++.h>
using namespace std;
int ans,A,B,C,x;
int main(){
	freopen("skyfall.in","r",stdin); freopen("skyfall.out","w",stdout);
	scanf("%d%d%d",&A,&B,&C);
	for(int i=1;i<=A;i++){
		for(int j=1;j<=B;j++){
			for(int k=1;k<=C;k++){
				x=i*j*k;
				for(int l=1;l<=(int)(sqrt(x));l++)
				if(x%l==0){
					if(l*l==x) ans++; else ans=ans+2;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
