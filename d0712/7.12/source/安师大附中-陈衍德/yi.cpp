#include<bits/stdc++.h>
using namespace std;
int A[30010],B[30010];
char s[300010];
int n;
const int z=1048576;
void mul(){
	int jw=0;
	for(int i=1;i<=n;i++){
	A[i]=A[i]*3+jw;
	//for(int i=n;i>=1;i--)
	//	printf("%d ",A[i]);
	//	printf("\n");
	jw=A[i]>>20,A[i]&=z-1;
	//for(int i=n;i>=1;i--)
	//	printf("%d ",A[i]);
	//	printf("%d\n",jw);
	}
	A[n+1]+=jw;
	if(A[n+1])n++;
	while(A[n]>=z)A[n+1]+=A[n]>>20,A[n]&=z-1,n++;
	//printf("%lld\n",(1ll*A[3]<<40ll)+(1ll*A[2]<<20)+A[1]);
}
void add(){
	A[1]++;
	int pos=1;
	while(A[pos]>=z)A[pos+1]+=A[pos]>>20,A[pos]&=z-1,n=max(n,pos+1),pos++;
	//for(int i=n;i>=1;i--)
	//	printf("%d ",A[i]);
	//	printf("\n");
}
void div(){
	int rem=0;
	for(int i=n;i>=1;i--){
		int tmp=rem;
		rem=(A[i]+(rem<<20))&1;
		A[i]=(A[i]+(tmp<<20))>>1;
		if(A[n]==0)n--;
	}
	//for(int i=n;i>=1;i--)
	//	printf("%d ",A[i]);
	//	printf("\n");
}
int main(){
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	A[i/20+1]+=(s[len-1-i]-'0')<<(i%20);
	n=(len-1)/20+1;
	int cnt=0;
	//printf("%lld\n",(1ll*A[3]<<40ll)+(1ll*A[2]<<20)+A[1]);
	while(!(n==1&&A[1]==1)){
		if(A[1]&1)mul(),add();
		else div();
		cnt++;
		//printf("%lld\n",(1ll*A[3]<<40ll)+(1ll*A[2]<<20)+A[1]);
	}
	printf("%d\n",cnt);
	return 0;
}
