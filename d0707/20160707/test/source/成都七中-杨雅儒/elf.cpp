#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

//LIMI会影响空间 !!!!!!!!!!   记得改回去 MAXM !!!!!
const int LIMI=17 , MAXM=40 ;
int n , s[45] , L , id[45] , go[45][2] , fail[45] , zhu[45] , znum , ys[45] ;
int tq[45] ;
long long ans , q[45] , ttt[45] , rev_q[45] ;

char get_c(){
	char t;
	while((t=(char)getchar())!=EOF) if(!isspace(t)) break ;
	return t ;
}

bool cmp(const int &a,const int &b){ return rev_q[a]>rev_q[b] ; }

int Gauss(int &z){
	int ret=0 ;
	z=0 ;
	for(int i=1;i<=n;++i){
		long long &t=q[i] ;
		for(int j=1;j<=MAXM;++j){
			if(t&(1ll<<(j-1))){
				if(id[j]) t^=q[id[j]] ;
				else{ id[j]=i , ys[i]=j ; break ; }
			}
			if(j==MAXM) ret++ ;
		}
	}
	for(int i=1;i<=MAXM;++i) if(!id[i]) ++z ;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=MAXM;++j) rev_q[i]+=((q[i]>>(MAXM-j))&1)<<(j-1) ;
	}
	for(int i=1;i<=n;++i) tq[i]=i ;
	sort(tq+1,tq+n+1,cmp) ;
	for(int i=1;i<=n;++i) ttt[i]=q[tq[i]] ;
	for(int i=1;i<=n;++i){
		q[i]=ttt[i] ;
		if(ys[tq[i]]){ id[ys[tq[i]]]=i ; }
	}
	for(int i=1;i<=MAXM;++i) if(id[i]) ys[id[i]]=i ;
	while(n>1 && !q[n]) --n ;
	for(int i=1;i<=n;++i){   //保证主元只存在于一行
		for(int j=ys[i]+1;j<=MAXM;++j){
			if((q[i]&(1ll<<(j-1)))&&id[j]){
				q[i]^=q[id[j]] ;
			}
		}
	}
	return ret;
}

void get_trans(){
	fail[1]=0 , go[0][s[1]]=1 ;
	for(int i=1;i<L;++i){
		int t=fail[i-1] ;
		while(t&&s[t+1]!=s[i]) t=fail[t] ;
		if(i!=1 && s[t+1]==s[i]) fail[i]=t+1 ;
		go[i][s[i+1]]=i+1 ;
		go[i][s[i+1]^1]=go[fail[i]][s[i+1]^1] ;
	}
}

int now , nxt ;
// 注意现在开的是 2^17 !!!!!!!!!!  空间还可以压
const int SIZE=5242885 , S_SIZE=131072 ;
int que[2][SIZE] , qnum[2] , xh[SIZE] , times[SIZE] , TTT , pos[45] ;
// pos[i] 表示第 i 列是第几个非主元
int zj[45] ; //第 i 行对非主元的影响
long long dp[2][SIZE] ;

void push_in(int s,long long tdp){
	if(times[s]!=TTT){
		times[s]=TTT , xh[s]=++qnum[nxt] , que[nxt][qnum[nxt]]=s , dp[nxt][qnum[nxt]]=0 ;
	}
	dp[nxt][xh[s]]+=tdp ;
}

int mg(int s1,int s2){
	return s1*S_SIZE+s2 ;
}

int get_s(int s,int t){
	if(t==1) return s/S_SIZE ;
	else return s%S_SIZE ;
}

long long solve_1(){
	long long ret=0 ;
	int cnt=0 ;
	for(int i=1;i<=MAXM;++i) if(!id[i]) pos[i]=++cnt ;
	for(int i=1;i<=n;++i){
		cnt=0 ;
		for(int j=1;j<=MAXM;++j){
			if(!id[j]){
				if((q[i]&(1ll<<(j-1)))) zj[i]+=(1ll<<cnt) ;
				++cnt ;
			}
		}
	}
	++TTT , now=0 , nxt=1 ;
	push_in(mg(0,0),1) ;
	for(int i=1;i<=n+1;++i){
		now=i&1 , nxt=now^1 , ++TTT , qnum[nxt]=0 ;
		for(int j=1;j<=qnum[now];++j){
			int tj=get_s(que[now][j],1) , sta=get_s(que[now][j],2) ;
			int nj , ns;
			bool suc=false ;
			for(int k=ys[i-1]+1;k<ys[i];++k){
				if(sta&(1ll<<(pos[k]-1))) tj=go[tj][1] ;
				else tj=go[tj][0] ;
				if(tj==L) suc=true ;
			}
			if(suc){ ret+=dp[now][j]*(1ll<<(n-i+1)) ; }
			else if(i!=n+1){
				nj=go[tj][0] , ns=sta ;
				if(nj==L) { ret+=dp[now][j]*(1ll<<(n-i)) ; }
				else push_in(mg(nj,ns),dp[now][j]) ;
				nj=go[tj][1] , ns=sta^zj[i] ;
				if(nj==L) { ret+=dp[now][j]*(1ll<<(n-i)) ; }
				else push_in(mg(nj,ns),dp[now][j]) ;
			}
		}
	}
	/*now=(n+1)&1 ;
	for(int i=1;i<=qnum[now];++i){
		int tj=get_s(que[now][i],1) , sta=get_s(que[now][i],2) ;
		for(int j=ys[n]+1;j<=MAXM;++j){
			if(sta&(1ll<<(pos[j]-1))) tj=go[tj][1] ;
			else tj=go[tj][0] ;
			if(tj==L){
				ret++ ; break ;
			}
		}
	}*/
	return ret ;
}

long long t_ret ;

void dfs(int t,int tj,long long ts){
	bool suc=false ;
	for(int i=ys[t-1]+1;i<ys[t];++i){
		tj=go[tj][(ts&(1ll<<(i-1)))?1:0] ;
		if(tj==L) suc=true ;
	}
	if(suc){
		t_ret+=(1ll<<(n-t+1)) ;
		return ;
	}
	if(t>n) return ;
	int nj=go[tj][0] ;
	if(nj==L){ t_ret+=(1ll<<(n-t)) ; }
	else dfs(t+1,nj,ts) ;
	nj=go[tj][1] ;
	if(nj==L){ t_ret+=(1ll<<(n-t)) ; }
	else dfs(t+1,nj,ts^q[t]) ;
}

long long solve_2(){
	dfs(1,0,0) ;
	return t_ret ;
}

void print(long long t){
	for(int i=0;i<=MAXM-1;++i){
		printf("%d",(t&(1ll<<i))?1:0) ;
	}
	printf("\n") ;
}

int main(){
	freopen("elf.in","r",stdin) ;
	freopen("elf.out","w",stdout) ;
	scanf("%d",&n) ;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=MAXM;++j){
			q[i]+=(((long long)get_c()-'0')<<(j-1)) ;
		}
	}
	scanf("%d",&L) ;
	for(int i=1;i<=L;++i) s[i]=get_c()-'0' ;
	int z; 
	int tmp=Gauss(z) ;
	ans=(1ll<<tmp) ;
	get_trans() ;
	ys[n+1]=MAXM+1 ;
	if(z<=LIMI) printf("%lld\n",ans*solve_1()) ;
	else printf("%lld\n",ans*solve_2()) ;
	return 0 ;
}
