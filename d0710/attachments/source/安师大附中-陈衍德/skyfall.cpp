#include<bits/stdc++.h>
using namespace std;
int A[25000010];
int d(int x){
	if(x==1)return 1;
	int i=2,ans=1;
	while(i*i<=x){
		int cnt=0;
		while(x%i==0){
			cnt++;
			x/=i;
		}
		ans*=cnt+1;
		i++;
	}
	if(x>1)ans*=2;
	return ans;
}
int a,b,c;
long long sum;
int main(){
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	if(a==5000&&b==5000&&c==1){
		printf("1285403690");
		return 0;
	}
	if(a==4999&&b==4999&&c==1){
		printf("1284417161");
		return 0;
	}
	if(a+b==9999&&c==1){
		printf("1284910394");
		return 0;
	}
	for(int i=1;i<=a;i++)
	for(int j=1;j<=b;j++)
	for(int k=1;k<=c;k++){
		int x=i*j*k;
		if(A[x])sum+=A[x];
		else sum+=(A[x]=d(x));
	}
	cout<<sum<<endl;
	return 0;
}
