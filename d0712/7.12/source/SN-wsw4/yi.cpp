#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <ctime>
#define maxn 300010

using namespace std;

struct BigInt{bitset<maxn> bs;int len;};
inline void tim3(BigInt &a){
	int jin=0,x;
	for(int i=0;i<a.len;i++){
		x=jin;
		if(a.bs[i])x+=3;
		a.bs[i]=x&1;
		jin=x>>1;
	}
	while(jin){a.bs[a.len++]=jin&1;jin>>=1;}
}
inline void add1(BigInt &a){
	int jin=1,t;
	for(int i=0;i<a.len;i++){
		if(!jin)break;
		t=a.bs[i]^jin;
		jin=a.bs[i]&jin;
		a.bs[i]=t;
	}
	while(jin){a.bs[a.len++]=jin&1;jin>>=1;}
} 
inline void givev(BigInt &a,char s[],int l){
	a.len=l;
	for(int i=0;i<l;i++)
		if(s[i]=='1')a.bs[l-i-1]=1;
}
BigInt a,b;
char s[maxn]={0};
int main(){
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	int i,j,ans=0;
	scanf("%s",s);
	givev(a,s,strlen(s));
	while(a.len!=1){ 
		i=0;
		while(!a.bs[i])i++;
		a.bs>>=i;
		a.len-=i;
		ans+=i;
		if(a.len==1)break;
		else {
			tim3(a);
			add1(a);
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
