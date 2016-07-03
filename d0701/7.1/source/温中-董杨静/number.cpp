#include<stdio.h>
#include<string.h>
#include<iostream>
#include<bitset>
using namespace std;
typedef long long LL;
const int maxn=2E4+77;

const int SS=30;

const LL DI=1ll<<SS;

struct HUGENUM{
	LL nums[80];
	int len;
	HUGENUM():len(1){memset(nums,0,sizeof(nums));}
	void operator =(const LL &v){
		nums[0]=v;
		len=1;
	}
	void operator <<=(int l){
		for(int i=0;i<len;++i) nums[i]<<=l;
		for(int i=0;i<len;++i) if(nums[i]>=DI){
			nums[i+1]+=nums[i]/DI;
			nums[i]%=DI;
		}
		if(nums[len]) ++len;
	}
	void operator +=(const HUGENUM &o){
		len=max(len,o.len);
		for(int i=0;i<len;++i){
			nums[i]=nums[i]+o.nums[i];
			if(nums[i]>=DI){
				nums[i+1]+=nums[i]/DI;
				nums[i]%=DI;
			}
		}
		if(nums[len]) ++len;
	}
	void operator -=(const HUGENUM &o){
		for(int i=0;i<o.len;++i){
			nums[i]-=o.nums[i];
			if(nums[i]<0){
				--nums[i+1];
				nums[i]+=DI;
			}
		}
		while(!nums[len-1]) --len;
	}
	void operator *=(LL v){
		for(int i=0;i<len;++i) nums[i]*=v;
		for(int i=0;i<len;++i) if(nums[i]>=DI){
			nums[i+1]+=nums[i]/DI;
			nums[i]%=DI;
		}
		if(nums[len]) ++len;
	}
}; 

struct NODE{
	bitset<700> ans;
	HUGENUM v;
	bool ok;
}nodes[maxn];
int cn=0;

void valid(NODE *n,LL v){
	int l=0;
	while(v>=SS){
		if(n->v.nums[l]){
			n->ok=false;
			return;
		}
		++l;
		v-=SS;
	}
	LL vv=1ll<<v;
	if(n->v.nums[l]%vv){
		n->ok=false;
		return;
	}
	n->ok=true;
}

int K;
void solve(NODE *n,int l){
	//cerr<<"l:"<<l<<endl;
	putchar('1');
	for(int i=l-1;i>=0;--i) putchar(n->ans[i]?'1':'0');
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cn=1;
	HUGENUM tv,vv;tv=1;vv=1;
	//cerr<<tv.len<<","<<vv.len<<endl;
	
	scanf("%d",&K);
	for(int i=0;;++i){
		//cerr<<"i:"<<i<<endl;
		//LL vv=1ll<<i;
		for(int j=0;j<cn;++j) valid(nodes+j,i+1);
		int t=cn;cn=0;
		for(int j=0;j<t;++j){
			if(nodes[j].ok) nodes[cn++]=nodes[j];
		}
		
		//cerr<<"cn:"<<cn<<endl;
		if(cn>=K){
			//for(int j=0;j<=K;++j) solve(nodes+j,i),puts("");
			solve(nodes+K-1,i);
			return 0;
		}else{
			//for(int j=0;j<cn;++j) solve(nodes+j,i),puts("");
			K-=cn;
		}
		
		t=cn;
		for(int j=0;j<t;++j){
			nodes[cn]=nodes[j];
			nodes[cn].ans[i]=1;
			nodes[cn].v+=tv;
			nodes[cn].v-=vv;
			//solve(nodes+cn,i);
			//puts("");
			++cn;
		}
		vv<<=1;
		tv*=10;
		
		//if(vv.len>50 && tv.len>50) return -1;
	}
}
