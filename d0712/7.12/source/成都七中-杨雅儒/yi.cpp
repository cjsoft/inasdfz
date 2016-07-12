#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const unsigned int L=(1ll<<32)-1 ;
unsigned int ci[33] , zj[33] ;  //ci[i]为2的i次  zj[i]表示只有低i位全部为1的数
struct btst{
	unsigned int w[10005] ;
	int len ;
	btst(){
		memset(w,0,sizeof(w)) ;
	}

	void mul_2(){
		int x=0 ;
		for(int i=1;i<=len;++i){
			int tmp=x ;
			if(w[i]&ci[31]) x=1 ;
			else x=0 ;
			w[i]=(w[i]<<1)+tmp ;
		}
		if(x) w[++len]=x ;
	}

	void get_right(int num){
		unsigned int x=0 ;
		for(int i=len;i>=1;--i){
			unsigned int tmp=x ;
			x=(w[i]&zj[num])<<(32-num) ;
			w[i]>>=num , w[i]+=tmp ;
		}
		while(len>1 && !w[len]) --len ;
	}

	void add_1(){
		bool suc=false ;
		for(int i=1;i<=len;++i){
			if(w[i]==L) w[i]=0 ;
			else{ w[i]++ , suc=true ; break ; }
		}
		if(!suc) w[++len]=1 ;
	}

	int maintain(){
		int t1=0 , t2=0 ;
		for(int i=1;i<=len;++i){
			if(w[i]){
				t1=i-1 ;
				for(int j=0;j<=31;++j)
					if(w[i]&ci[j]){ t2=j ; break ; }
				break ;
			}
		}
		if(t1){
			for(int i=t1+1;i<=len;++i) w[i-t1]=w[i] ;
			for(int i=len-t1+1;i<=len;++i) w[i]=0 ;
			len=len-t1 ;
		}
		if(t2) get_right(t2) ;
		return t1*32+t2 ;
	}
}bt1 , bt2;

btst operator+(const btst &a,const btst &b){
	btst c;
	c.len=max(a.len,b.len)+2 ;
	unsigned int x=0 ;
	for(int i=1;i<=c.len;++i){
		long long tmp=(long long)a.w[i]+b.w[i]+x ;
		c.w[i]=(unsigned int)(tmp&zj[32]) , x=(unsigned int)(tmp>>32) ;
	}
	while(c.len>1 && !c.w[c.len]) --c.len ;
	return c;
}

char s[300005] ;

int main(){
	freopen("yi.in","r",stdin) ;
	freopen("yi.out","w",stdout) ;
	ci[0]=1 ;
	for(int i=1;i<=31;++i) ci[i]=ci[i-1]<<1 ;
	for(int i=1;i<=32;++i) zj[i]=(1ll<<i)-1 ;
	scanf("%s",s+1) ;
	int len=strlen(s+1) , cnt=0 ;
	unsigned int tmp=0 ;
	for(int i=len;i>=1;--i){
		++cnt ;
		tmp+=((unsigned int)(s[i]-'0')<<(cnt-1)) ;
		if(cnt==32){
			bt1.w[++bt1.len]=tmp ;
			tmp=cnt=0 ;
		}
	}
	if(tmp){ bt1.w[++bt1.len]=tmp ; }
	long long ans=bt1.maintain() ;
	while(bt1.len!=1 || bt1.w[1]!=1){
		if(bt1.w[1]&1){
			bt2=bt1 , bt2.mul_2() ;
			bt1=bt1+bt2 ;
			bt1.add_1() ;
			ans++ ;
		}
		else ans+=bt1.maintain() ;
	}
	printf("%lld\n",ans) ;
	return 0 ;
}
