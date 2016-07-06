#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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

const int MAXN=100005 ;
int first[MAXN] , nexts[MAXN<<1] , to[MAXN<<1] , egnum=1 , dep[MAXN] , q[MAXN] , qnum ;
int zj[MAXN] ;
int colo[MAXN] ;

void add_edge(int a,int b){
	nexts[++egnum]=first[a] , first[a]=egnum , to[egnum]=b ;
}

void init(){
	egnum=1 ;
	memset(first,0,sizeof(first)) ;
}

void dfs_1(int a,int fa,int d){
	bool f=false ;
	dep[a]=d ;
	for(int i=first[a];i;i=nexts[i]) if(to[i]!=fa) dfs_1(to[i],a,d+1) , f=true ;
	if(!f && colo[a]==-1){
		q[++qnum]=a ;
	}
}

void dfs_2(int a,int fa){
	int num=0 ;
	for(int i=first[a];i;i=nexts[i]) if(to[i]!=fa) {
		dfs_2(to[i],a) ;
		if(colo[to[i]]==0) num++ ;
		else num-- ;
	}
	if(colo[a]!=-1) return ;
	if(num>0) colo[a]=0 ;
	else colo[a]=1 ;
}

bool cmp(const int &a,const int &b){ return dep[a]<dep[b] ; }
int cs[MAXN] ;

void dfs(int now,bool f){
	for(int i=1;i<=qnum;++i){
		int t=q[i] ;
		if(cs[t]==-1){
			cs[t]=now ;
			dfs() ;
		}
	}
}

void solve(){
	int n=reads() ;
	for(int i=1;i<=n;++i){
		int f=reads() ;
		if(f) add_edge(f,i) ;
	}
	for(int i=1;i<=n;++i) colo[i]=reads() , cs[i]=-1 ;
	dfs_1(1,0) ;
	dfs(1,0) ;
	if(colo[1]==0){
		printf("%d\n",0) ;
	}
	else printf("%d\n",-1) ;
}

int main(){
	freopen("ah.in","r",stdin) ;
	freopen("ah.out","w",stdout) ;
	int T=reads() ;
	while(T--){
		init() ;
		solve() ;
	}
	return 0 ;
}
