#include<iostream>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#define my_min(a,b) ((a)<(b)?(a):(b))
#define my_max(a,b) ((a)>(b)?(a):(b))
using namespace std;

map<long long,int> mp ;

int reads(){
	char t=(char)getchar() ; bool f=false ; int x=0 ;
	while(t<'0'||t>'9'){
		if(t=='-') f=true ;
		if(t==EOF) return EOF;
		t=(char)getchar() ;
	}
	while(t>='0'&&t<='9'){
		x=(x<<1)+(x<<3)+t-'0' ;
		t=(char)getchar() ;
	}
	if(f) x=-x ;
	return x;
}

const int MAXN=100005 , MAXM=1000005 ;
vector<int> vec1[MAXM] ;
//vec1为质因数 
int n , first[MAXN] , nexts[MAXN<<1] , to[MAXN<<1] , w[MAXN<<1] , egnum=1 ;
int size[MAXN] , max_size[MAXN] , lord , all ;
bool ban[MAXN<<1] ;

int gcd(const int &a,const int &b){ return (b?(gcd(b,a%b)):a) ; }

void add_edge(int a,int b,int c){
	nexts[++egnum]=first[a] , first[a]=egnum , to[egnum]=b , w[egnum]=c ;
}

int prime[MAXM] , pnum , min_p[MAXM] ;
bool not_prime[MAXM] ;
void xianshai(){
	for(int i=2;i<MAXM;++i){
		if(!not_prime[i]) prime[++pnum]=i , min_p[i]=i ;
		for(int j=1;j<=pnum&&prime[j]*i<MAXM;++j){
			not_prime[prime[j]*i]=true , min_p[prime[j]*i]=prime[j] ;
			if(i%prime[j]==0) break ;
		}
	}
}

void dfs_1(int a,int fa){
	size[a]=1 , max_size[a]=0 ;
	for(int i=first[a];i;i=nexts[i]){
		if(to[i]!=fa && !ban[i]) dfs_1(to[i],a) , size[a]+=size[to[i]] , max_size[a]=my_max(max_size[a],size[to[i]]) ;
	}
	max_size[a]=my_max(max_size[a],all-size[a]) ;
	if(!lord || max_size[a]<max_size[lord]) lord=a ;
}

void dfs_2(int a,int fa){
	size[a]=1 ;
	for(int i=first[a];i;i=nexts[i])
		if(to[i]!=fa && !ban[i]) dfs_2(to[i],a) , size[a]+=size[to[i]] ;
}

long long ans=0 , zj ;
int cnt[MAXM] , times[MAXM] , TTT , nums , q[MAXN] , qnum ;
int calc_num ;

inline void up(const int &t){
	if(times[t]!=TTT) times[t]=TTT , cnt[t]=0 ;
}

void dfs(int now,int pro,bool f){
	if(now>(int)vec1[calc_num].size()) {
		up(pro) ;
		if(f) zj-=cnt[pro] ;
		else zj+=cnt[pro] ;
		return ;
	}
	int tmp=vec1[calc_num][now-1] ;
	dfs(now+1,pro,f) ;
	dfs(now+1,pro*tmp,f^1) ;
}

void dfs_3(int a,int fa,int now_gcd){
	if(now_gcd==1) ++ans ;
	calc_num=now_gcd , zj=0 , dfs(1,1,0) , q[++qnum]=now_gcd ;
	ans+=zj ;
	for(int i=first[a];i;i=nexts[i]){
		if(to[i]!=fa&&!ban[i]) dfs_3(to[i],a,gcd(now_gcd,w[i])) ;
	}
}

void DC(int s){
	++TTT ;
	for(int i=first[s];i;i=nexts[i]){
		qnum=0 ;
		dfs_3(to[i],s,w[i]) ;
		for(int j=1;j<=qnum;++j){
			int t=q[j] ;
			for(int k=1;k*k<=t;++k){
				if(t%k==0){
					up(k) , cnt[k]++ ;
				}
				if(k*k==t) break ;
				up(t/k) , cnt[t/k]++ ;
			}
		}
	}

	for(int i=first[s];i;i=nexts[i]){
		if(!ban[i]) ban[i]=ban[i^1]=true , dfs_2(to[i],0) , all=size[to[i]] , dfs_1(to[i],lord=0) , DC(lord) ;
	}
}

void prepare(){
	xianshai() ;
	for(int i=2;i<MAXM;++i){
		int t=i , len=0 ;
		while(t){
			int tmp=min_p[t] ;
			if(!len || vec1[t][len-1]!=tmp)
				vec1[t].push_back(tmp) , ++len ;
			if(min_p[t]==t) break ;
			t/=tmp ;
		}
	}
}

int r_a[MAXN] , r_b[MAXN] ;

void ddd(int a,int fa,int now_gcd){
	if(now_gcd==1) ans++ ;
	for(int i=first[a];i;i=nexts[i]){
		if(to[i]!=fa){
			ddd(to[i],a,gcd(now_gcd,w[i])) ;
		}
	}
}

/*int size2[7005][7005] ;
int nnn ;

void dfs_5(int a,int fa){
	size2[nnn][a]=1 ;
	for(int i=first[a];i;i=nexts[i])
		if(to[i]!=fa && !ban[i]) dfs_5(to[i],a) , size2[nnn][a]+=size2[nnn][to[i]] ;
}*/

int main(){
	freopen("network.in","r",stdin) ;
	freopen("network.out","w",stdout) ;
	//prepare() ;
	n=reads() ;
	for(int i=1;i<n;++i){
		int u=reads(),v=reads(),w=reads() ;
		r_a[i]=u , r_b[i]=v ;
		add_edge(u,v,w) , add_edge(v,u,w) ;
		mp[(long long)u*100002+v]=egnum;
		mp[(long long)v*100002+u]=egnum ;
	}
	int Q=reads() ;
	//all=n , dfs_1(1,lord=0) , DC(lord) ;
	for(int i=1;i<=n;++i){
		for(int j=first[i];j;j=nexts[j]){
			ddd(to[j],i,w[j]) ;
		}
	}
	printf("%lld\n",ans/2) ;
	for(int i=1;i<=Q;++i){
		int k=reads() , x=reads() ;
		int t=mp[(long long)r_a[k]*100002+r_b[k]] ;
		w[t]=w[t^1]=x ;
		ans=0 ;
		//for(int j=1;j<=egnum;++j) ban[j]=false ;
		//all=n , dfs_1(1,lord=0) , DC(lord) ;
		for(int i=1;i<=n;++i){
			for(int j=first[i];j;j=nexts[j]){
				ddd(to[j],i,w[j]) ;
			}
		}
		printf("%lld\n",ans/2) ;
	}
	return 0 ;
}
