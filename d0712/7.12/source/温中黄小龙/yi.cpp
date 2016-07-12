#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int BITS=29;
const int MASK=(1<<BITS)-1;

#define MAXN 20001

struct BigInt{
	int data[MAXN],len;
	BigInt(){memset(data,0,sizeof(data));len=0;}
	int odd(){return data[0]&1;}
	int isI(){return len==1&&data[0]==1;}
	int cnt_zero(){
		int j=0,cnt=0;
		for(;j<len;++j)
			if(!data[j])cnt+=BITS;
			else break;
		int tmp=data[j];
		while(!(tmp&1))++cnt,tmp>>=1;
		return cnt;
	}
	void toright(int l){
		int bl=l/BITS,bg=l%BITS,qg=BITS-bg;
		int qmask=(1<<qg)-1,bmask=(1<<bg)-1;
		for(int i=0;bl<len;++i,++bl){
			int tdata=data[bl]>>bg;
			tdata+=(data[bl+1]&bmask)<<qg;
			data[bl]=0; data[bl+1]&=~bmask;
			data[i]=tdata;
		}
		while(!data[len-1])--len;
	}
	void div2(){
		for(int i=0;i!=len;++i)
			data[i]=(data[i]+((data[i+1]&1)<<BITS))>>1;
		while(!data[len-1])--len;
	}
	void dwodd(){
		for(int j=0;j!=len;++j){
			if(j!=0){
				data[j-1]+=(data[j]&1)<<(BITS-1);
				data[j]+=data[j]>>1; data[j]+=data[j-1]>>BITS;
				data[j-1]&=MASK;
			}else{
				data[j]+=data[j]>>1; ++data[j];
			}
		}
		data[len]+=data[len-1]>>BITS; data[len-1]&=MASK;
		if(data[len])++len;
	}
	void mul3(){
		int i,x;;
		for(i=0,x=0;i!=len;++i){
			data[i]=data[i]*3+x;
			x=data[i]>>BITS;
			data[i]&=MASK;
		}
		if(x)data[len++]=x;
	}
	void inc(){
		++data[0];
		for(int i=0;i!=len;++i){
			if(data[i]>=MASK){
				data[i]-=MASK;
				++data[i+1];
			}else{
				break;
			}
		}
		if(data[len])++len;
	}
	void scan(char*s){
		int n=strlen(s); len=0;
		for(int i=n-1,j=0;i>=0;i-=BITS,++j,++len){
			for(int k=max(0,i-BITS+1);k<=i;++k)
				data[j]=(data[j]<<1)+(s[k]=='1');
		}
	}
}a;

char s[300011];

int main(){
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",s);
	int cnt=0;
	a.scan(s);
	int flag=0,tcnt=0;
	int qcnt=0;
	while(!a.isI()){
		if(a.odd()){
			a.mul3(); a.inc();
			++cnt;
//			a.dwodd(); cnt+=2;
		}else{
			int zcnt=a.cnt_zero();
			cnt+=zcnt;
			a.toright(zcnt);
//			++cnt;
//			a.div2();
			
		}
	}
	printf("%d\n",cnt);
	return 0;
}
