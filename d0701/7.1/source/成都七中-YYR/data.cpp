#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mid ((ll+rr)>>1)
#define my_min(a,b) ((a)<(b)?(a):(b))
#define my_max(a,b) ((a)>(b)?(a):(b))
using namespace std;

int nnn ;

int reads(){
	int x=0 ; char t=(char)getchar() ; bool f=false ;
	while(t<'0'||t>'9'){
		if(t=='-') f=true ;
		if(t==EOF) return EOF;
		t=(char)getchar() ;
	}
	while(t>='0'&&t<='9'){
		x=(x<<1)+(x<<3)+t-'0' ;
		t=(char)getchar() ;
	}
	if(f)	x=-x;
	return x ;
}

const int MAXN=30005 , MOD=998244353 ;
int n , K , m , A[MAXN] , ys[12] ;

inline void up(long long &a){
	if(a>=MOD) a-=MOD ;
}

struct data{
	long long w[5][6] ;
	bool f ;
	data(){ memset(w,0,sizeof(w)) , f=false ; }
}zero[MAXN] ;

data operator+(const data &a,const data &b){
	if(!a.f) return b;
	if(!b.f) return a;
	data c ;
	c.f=true ;
	for(int i=0;i<K;++i){
		c.w[i][K]+=b.w[i][K] , up(c.w[i][K]) ;
		for(int j=0;j<K;++j){
			if(b.w[i][j]){
				for(int k=0;k<=K;++k){
					c.w[i][k]=c.w[i][k]+b.w[i][j]*a.w[j][k]%MOD ;
					up(c.w[i][k]) ;
				}
			}
		}
	}
	return c;
}

void prepare(){
	zero[1]=data() ;
	for(int i=0;i<K;++i) zero[1].w[i][i]=1 ;
	for(int i=0;i<=K;++i) zero[1].w[0][i]=1 ;		
	zero[1].f=true ;
	for(int i=2;i<MAXN;++i){
		zero[i]=zero[i-1]+zero[1] ;
	}
	ys[1]=2 , ys[3]=2 ;
}

int go[12] ;
data tmp ;

//注意空间
struct Segment_Tree{
	int ndnum , lc[MAXN<<1] , rc[MAXN<<1] , lazy_add[MAXN<<1] , lazy_mul[MAXN<<1] , len[MAXN<<1] ;
	data dt[MAXN<<1] , zj , ttt[MAXN<<1] ;

	inline int news(){
		++ndnum , dt[ndnum]=ttt[ndnum]=data() , lc[ndnum]=rc[ndnum]=0 , lazy_add[ndnum]=0 , lazy_mul[ndnum]=1 , len[ndnum]=0 ;
		//
		return ndnum ;
	}

	void exchange_it(const int &t){
		for(int i=0;i<K;++i) for(int j=0;j<=K;++j) tmp.w[go[i]][j]=dt[t].w[i][j] ;
		dt[t]=tmp , dt[t].f=true ;
	}

	void tag_add(int s,int num){ //num < K
		if(!s) return ;
		lazy_add[s]+=num ;
		if(lazy_add[s]>=K) lazy_add[s]-=K ;
		for(int i=0;i<K;++i){
			go[i]=i+num ;
			if(go[i]>=K) go[i]-=K ;
		}
		exchange_it(s) ;
		if(K==4){
			if(num&1){
				for(int j=0;j<=K;++j) swap(ttt[s].w[0][j],ttt[s].w[2][j]) ;
			}
		}
	}

	void tag_mul(int s,int num){ //num < K
		if(!s) return ;
		if(lazy_add[s]) lazy_add[s]=lazy_add[s]*num%K ;
		lazy_mul[s]=lazy_mul[s]*num%K ;
		if(num==0){
			dt[s]=zero[len[s]] ; return ;
		}
		if(K==4&&num==2){
			dt[s]=ttt[s] , ttt[s]=zero[len[s]] ; return ;
		}
		for(int i=0;i<K;++i) go[i]=i*num%K ;
		exchange_it(s) ;  //还没有特判 !!!!   0 和 4、2
	}

	inline void update(const int &s){
		dt[s]=dt[lc[s]]+dt[rc[s]] ;
		if(K==4) ttt[s]=ttt[lc[s]]+ttt[rc[s]] ;
	}

	void pushdown(int s){
		if(!lc[s]) return ;
		if(lazy_mul[s]!=1){
			tag_mul(lc[s],lazy_mul[s]) , tag_mul(rc[s],lazy_mul[s]) ;
			lazy_mul[s]=1 ;
		}
		if(lazy_add[s]!=0){
			tag_add(lc[s],lazy_add[s]) , tag_add(rc[s],lazy_add[s]) ;
			lazy_add[s]=0 ;
		}
	}

	void build(int s,int ll,int rr){
		if(ll==rr){
			for(int i=0;i<K;++i) dt[s].w[i][i]=1 ;
			for(int i=0;i<=K;++i) dt[s].w[A[ll]][i]=1 ;
			if(K==4){
				for(int i=0;i<K;++i) ttt[s].w[i][i]=1 ;
				for(int i=0;i<=K;++i) ttt[s].w[ys[A[ll]]][i]=1 ;
				ttt[s].f=true ;
			}
			dt[s].f=true , len[s]=1 ;
			return ;
		}
		build(lc[s]=news(),ll,mid) , build(rc[s]=news(),mid+1,rr) ;
		update(s) , len[s]=len[lc[s]]+len[rc[s]] ;
	}

	int a_l , a_r , a_num ;
	void add(int s,int ll,int rr){
		pushdown(s) ;
		if(ll>a_r || rr<a_l) return ;
		if(ll>=a_l && rr<=a_r){
			tag_add(s,a_num) ; return ;
		}
		add(lc[s],ll,mid) ;
		add(rc[s],mid+1,rr) ;
		update(s) ;
	}

	int m_l , m_r , m_num ;
	void mul(int s,int ll,int rr){
		pushdown(s) ;
		if(ll>m_r || rr<m_l) return ;
		if(ll>=m_l && rr<=m_r){
			tag_mul(s,m_num) ; return ;
		}
		mul(lc[s],ll,mid) , mul(rc[s],mid+1,rr) ;
		update(s) ;
	}

	//记得清空 zj
	int q_l , q_r ;
	void query(int s,int ll,int rr){
		pushdown(s) ;
		if(ll>q_r || rr<q_l) return ;
		if(ll>=q_l && rr<=q_r){
			zj=zj+dt[s] ; return ;
		}
		query(lc[s],ll,mid) , query(rc[s],mid+1,rr) ;
	}
}ST;

void init(){
	ST.ndnum=0 ;
}

void solve(){
	n=reads() , K=reads() , m=reads() ;
	prepare() ; //特判
	for(int i=1;i<=n;++i) A[i]=reads() ;
	ST.build(ST.news(),1,n) ;
	for(int i=1;i<=m;++i){
		int o=reads() ;
		nnn=i ;
		if(o==1){
			ST.a_l=reads() , ST.a_r=reads() , ST.a_num=reads() ;
			ST.add(1,1,n) ;
		}
		else if(o==2){
			ST.m_l=reads() , ST.m_r=reads() , ST.m_num=reads() ;
			ST.mul(1,1,n) ;
		}
		else if(o==3){
			ST.q_l=reads() , ST.q_r=reads() , ST.zj=data() ;
			ST.query(1,1,n) ;
			long long ans=0 ;
			for(int i=0;i<K;++i) ans+=ST.zj.w[i][K] , up(ans) ;
			printf("%lld\n",ans) ;
		}
	}
}

int main(){
	freopen("data.in","r",stdin) ;
	freopen("data.out","w",stdout) ;
	int T=reads() ;
	while(T--){
		init() ; 
		solve() ;
	}
	return 0 ;
}
