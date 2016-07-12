#include<iostream>
#include<stdio.h>
#include<bitset>
#include<string.h>
#include<time.h>
#define maxn 15050
using namespace std;
struct node{
	bitset<maxn> bs;int l;
};
inline node work(node x){
	node ret;int jin=1;
	for(int i=0;i<=x.l+1;i++){
		int ls=x.bs[i]+(!i?0:x.bs[i-1])+jin;
		ret.bs[i]=ls&1,jin=ls>>1;
	}
	if(ret.bs[x.l+1]) ret.l=x.l+2;else ret.l=x.l+1;
	return ret;
}
char s[300050];node a; 
int main(){
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",s);
	int l=strlen(s);
	for(int i=0;i<l;i++)
		a.bs[i]=s[l-i-1]-'0';
	int cnt=0;a.l=l;
	while(a.l!=1){
		int ling=0;
		if(a.bs[0]) a=work(a),cnt++;
		while(!a.bs[ling]) ling++;
		cnt+=ling;a.bs>>=ling;a.l-=ling;
	}
	cout<<cnt<<endl;
}
