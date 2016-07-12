#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
const int bit=29,N=1<<bit;
const int M=301000;
int a[M],len;
char s[M];
void init(){
	int n,i,k,t,j;
	scanf("%s",s+1);
	n=strlen(s+1);
	len=(n-1)/bit+1;
	k=0;
	for(i=n;i>=1;i-=bit){
		t=0;
		for(j=max(1,i-bit+1);j<=i;j++){
			t=t*2+s[j]-'0';
		}
		a[++k]=t;
	}
}
bool check(){return len==1&&a[1]==1;}
int div(){
	int i,j,k=0,p,q,num;
	for(i=1;i<=len;i++){
	    for(j=0;j<bit;j++)
	    	if(a[i]&(1<<j)) break;
	    if(j<bit) break;
	}
	num=(i-1)*bit+j;
	p=(1<<j)-1;q=bit-j;
	a[len+1]=0;
	for(i;i<=len;i++)
		a[++k]=(a[i]>>j)|((a[i+1]&p)<<q);
	if(!a[k]) k--;
	len=k;
	return num;
}
void multi(){
	int i;
	for(i=1;i<=len;i++) a[i]*=3;
	a[1]++;
	a[len+1]=0;
	for(i=1;i<=len;i++)
		if(a[i]>=N) a[i+1]+=a[i]>>bit,a[i]&=N-1;
	if(a[len+1]) len++;
}
int main(){
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	int ans=0;
	init();
	while(!check()){
		if(a[1]&1) multi(),ans++;
		else ans+=div();
	}
	printf("%d",ans);
	return 0;
}
