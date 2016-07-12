#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
typedef long long LL;
const int maxn=3E5+77;
const int D=1E9+7;


char S[maxn];
LL V[maxn*10],T,ans=0;
int len,p,olen;

void update(){
	LL t=T<<1;
	if(V[p]>=t){
		if(p+1==len) ++len;
		V[p+1]+=V[p]/t;
		V[p]%=t;
		for(int i=p+1;i<len;++i){
			if(V[i]>2){
				if(i+1==len) ++len;
				V[i+1]+=V[i]>>1;
				V[i]&=1;
			}else break;
		}
	}
}

void distupdate(){
	for(int i=p+1;i<len;++i) V[i]*=T;
	T=1;
	update();
}

int main(){
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",S);
	olen=len=strlen(S);
	for(int i=0;i<len;++i) V[i]=S[len-i-1]-'0';
	T=1;p=0;
	//cerr<<len<<endl;
	while(p+1!=len || V[p]!=1){
		if(V[p]&1){
			V[p]*=3;++V[p];
			T*=3;
			if(T>=D) distupdate();
			else if(V[p]>=D) update();
		}else{
			if(p+1==len) ++len;
			V[p+1]*=T;
			V[p+1]+=V[p]>>1;
			++p;
			if(V[p]>=D){
				//return 1;
				update();
			}
		}
		++ans;
		//if(!(ans%1000)) cerr<<"ans:"<<ans<<"  p:"<<p<<" v[p]:"<<V[p]<<endl;
		//if(p+1==len && V[p]==0) break;
	}
	cout<<ans<<endl;
}
