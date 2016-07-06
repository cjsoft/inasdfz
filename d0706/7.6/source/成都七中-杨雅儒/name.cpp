#include<iostream>
#include<set>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define my_abs(x) ((x)<0?(-(x)):(x))
#define my_min(a,b) ((a)<(b)?(a):(b))
#define my_max(a,b) ((a)>(b)?(a):(b))
#define mid ((ll+rr)>>1)
using namespace std;

int reads(){
	int x=0 ; char t=(char)getchar() ; bool f=false ;
	while(t<'0'||t>'9'){
		if(t=='-') f=true ;
		if(t==EOF) return EOF ;
		t=(char)getchar() ;
	}
	while(t>='0'&&t<='9'){
		x=(x<<1)+(x<<3)+t-'0' ;
		t=(char)getchar() ;
	}
	if(f)	x=-x;
	return x;
}

const int MAXN=100005 , ST_SIZE=2000005 , KD_SIZE=100005 , INF=(1<<30)-1 , LIMI=1100 ;
int n , m , A[MAXN] , B[MAXN] , r_l[MAXN] , r_r[MAXN] , r_t[MAXN] ;
vector<int> vec[MAXN] ;
set<int>::iterator it ;

struct Segment_Tree{
	int ndnum , lc[ST_SIZE] , rc[ST_SIZE] , maxn[ST_SIZE] , size[ST_SIZE] , root ;
	set<int> st[ST_SIZE] ;

	inline int news(){ return ++ndnum ; }

	inline void update(int s){ maxn[s]=my_max(maxn[lc[s]],maxn[rc[s]]) ; }

	int a_pos , a_num ;
	bool is_add ;
	void add(int &s,int ll,int rr){
		if(!s) s=news() ;
		if(ll==rr){
			size[s]+=(is_add?1:-1) ;
			if(!is_add) it=st[s].find(a_num) , st[s].erase(it) ;
			else st[s].insert(a_num) ;
			if(size[s]) it=st[s].end() , --it , maxn[s]=(*it) ;
			else maxn[s]=0 ;
			return ;
		}
		if(a_pos<=mid) add(lc[s],ll,mid) ;
		else add(rc[s],mid+1,rr) ;
		update(s) ;
	}

	int q_l , q_r ;
	int query(int s,int ll,int rr){
		if(!s || (ll>q_r || rr<q_l)) return 0 ;
		if(ll>=q_l&&rr<=q_r) return maxn[s] ;
		return max(query(lc[s],ll,mid),query(rc[s],mid+1,rr)) ;
	}
}ST;

struct states{
	int x[2] ;  //pos 和 val
	states(int _x0=0,int _x1=0){ x[0]=_x0 , x[1]=_x1 ; }
}q[MAXN];
int qnum , DD , ys[MAXN] ;

bool cmp(const states &a,const states &b){ return a.x[DD]<b.x[DD] ; }

struct KD_Tree{
	int ndnum , lc[KD_SIZE] , rc[KD_SIZE] , root , minn[KD_SIZE][2] , size[KD_SIZE] , TTT , maxn[KD_SIZE][2] ;
	int fa[KD_SIZE] ;
	bool cans[KD_SIZE] ;
	states re[KD_SIZE] ;

	inline int news(){
		++ndnum , fa[ndnum]=lc[ndnum]=rc[ndnum]=size[ndnum]=0 , cans[ndnum]=true ;
		return ndnum;
	}

	void update(int s){
		size[s]=size[lc[s]]+size[rc[s]]+cans[s] ;
		maxn[s][0]=maxn[s][1]=minn[s][0]=minn[s][1]=INF ;
		if(cans[s]) for(int i=0;i<2;++i) minn[s][i]=re[s].x[i] , maxn[s][i]=re[s].x[i] ;
		if(lc[s]) minn[s][0]=my_min(minn[s][0],minn[lc[s]][0]) , minn[s][1]=my_min(minn[s][1],minn[lc[s]][1]) ;
		if(rc[s]) minn[s][0]=my_min(minn[s][0],minn[rc[s]][0]) , minn[s][1]=my_min(minn[s][1],minn[rc[s]][1]) ;
		if(lc[s]) maxn[s][0]=my_max(maxn[s][0],maxn[lc[s]][0]) , maxn[s][1]=my_max(maxn[s][1],maxn[lc[s]][1]) ;
		if(rc[s]) maxn[s][0]=my_max(maxn[s][0],maxn[rc[s]][0]) , maxn[s][1]=my_max(maxn[s][1],maxn[rc[s]][1]) ;
	}

	void init(){
		ndnum=0 ; TTT=0 ;
	}

	void del(int s){
		cans[s]=false , ++TTT ;
		while(s) update(s) , s=fa[s] ;
	}

	states in_s ;
	void insert(int &s,int dep){
		if(!s){
			s=news() , re[s]=in_s , ys[re[s].x[0]]=s , update(s) , ++TTT ;
			return ;
		}
		DD=dep&1 ;
		if(in_s.x[DD]<re[s].x[DD]) insert(lc[s],dep+1) , fa[lc[s]]=s ;
		else insert(rc[s],dep+1) , fa[rc[s]]=s ;
		update(s) ;
	}

	void build(int &s,int ll,int rr,int dep){
		if(ll>rr) return ;
		s=news() , DD=dep&1 ;
		int m=mid ;
		nth_element(q+ll,q+m,q+rr+1,cmp) ;
		re[s]=q[m] , ys[re[s].x[0]]=s ;
		if(ll!=rr){
			build(lc[s],ll,m-1,dep+1) , build(rc[s],m+1,rr,dep+1) ;
			if(lc[s]) fa[lc[s]]=s ;
			if(rc[s]) fa[rc[s]]=s ;
		}
		update(s) ;
	}

	void dfs(int s){
		if(!s) return ;
		if(cans[s]) q[++qnum]=re[s] ;
		dfs(lc[s]) , dfs(rc[s]) ;
	}

	void maintain(){  //记得调用 !!!
		if(TTT>LIMI){
			qnum=0 , dfs(root) , init() ;
			build(root,1,qnum,0) ;
		}
	}

	int q_x[2] ;	
	int query(int s){
		if(!s || !size[s] || (q_x[0]>maxn[s][0] || q_x[1]>maxn[s][1])){
			return 0 ;
		}
		if(q_x[0]<=minn[s][0] && q_x[1]<=minn[s][1]){
			return size[s] ;
		}
		int ret=0 ;
		if(cans[s] && (q_x[0]<=re[s].x[0] && q_x[1]<=re[s].x[1])) ret++ ;
		return query(lc[s])+query(rc[s])+ret ;
	}
}KDT;

void solve(){
	long long ans=0 ;
	for(int i=1;i<=n;++i){
		int len=(int)vec[i].size() ;
		for(int j=0;j<len;++j){
			int t=vec[i][j] ;
			bool is_del=false ;
			if(t<0) t=-t , is_del=true ;
			ST.is_add=!is_del , ST.a_pos=r_t[t] , ST.a_num=t ;
			ST.add(ST.root,1,INF) ;
			if(!is_del){
				KDT.in_s=states(t,r_t[t]) , KDT.insert(KDT.root,0) ;
			}
			else{
				KDT.del(ys[t]) ;
			}
			KDT.maintain() ;
		}
		int tmp=0 ;
		bool f=false , now=0 ;
		ST.q_l=B[i] , ST.q_r=A[i] ;
		if(A[i]!=B[i]){
			if(ST.q_l>ST.q_r) swap(ST.q_l,ST.q_r) , f=true ;
			ST.q_r-- ;
			tmp=ST.query(ST.root,1,INF) ;
			if(tmp && f) now^=1 ;
		}
		KDT.q_x[0]=tmp+1 , KDT.q_x[1]=my_max(A[i],B[i]) ;
		int ttt=KDT.query(KDT.root) ;
		if(ttt&1) now^=1 ;
		if(now) ans+=B[i] ;
		else ans+=A[i] ;
	}
	printf("%lld\n",ans) ;
}

int main(){
	freopen("name.in","r",stdin) ;
	freopen("name.out","w",stdout) ;
	n=reads() ;
	for(int i=1;i<=n;++i) A[i]=reads() ;
	for(int i=1;i<=n;++i) B[i]=reads() ;
	m=reads() ;
	for(int i=1;i<=m;++i){
		r_l[i]=reads() , r_r[i]=reads() , r_t[i]=reads() ;
		vec[r_l[i]].push_back(i) , vec[r_r[i]+1].push_back(-i) ;
	}
	solve() ;
	return 0;
}
