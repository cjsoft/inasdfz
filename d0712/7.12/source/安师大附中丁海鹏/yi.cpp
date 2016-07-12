#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;
long long bin[70],a[10000];
char s[310000],_[310000];
int n,len,cnt;
void div(){
	cnt++;
	for(int i=len;i>=1;i--){
		if(a[i]&1)a[i-1]+=bin[59];
		a[i]/=2;
	}if(a[len]==0)len--;
}

void add(){
	cnt++;
	for(int i=1;i<=len;i++){
		a[i]*=3;
	}a[1]++;
	for(int i=1;i<=len;i++){
		while(a[i]>=bin[59]){a[i+1]++,a[i]-=bin[59];}
	}if(a[len+1]!=0)len++;
}

void out(){
	printf("%d\n",len);
	for(int i=1;i<=len;i++)printf("%lld \n",a[i]);
	puts("");
}

int main(){
	bin[1]=1;
	for(int i=2;i<=63;i++)bin[i]=bin[i-1]<<1;
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		_[i]=s[n-i+1]-'0';
	}for(int i=1;i<=n;i++){
		a[(i-1)/58+1]+=bin[(i-1)%58+1]*_[i];
	}len=(n-1)/58+1;
	while(len!=1||a[1]!=1){
		if(a[1]&1)add();
		else div();
	}printf("%d\n",cnt);
	return 0;
}
