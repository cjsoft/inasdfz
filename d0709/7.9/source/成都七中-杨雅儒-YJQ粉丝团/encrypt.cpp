#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define my_min(a,b) ((a)<(b)?(a):(b))
#define my_max(a,b) ((a)>(b)?(a):(b))
using namespace std;

const int MAXN=500005 ;
char s[MAXN] ;
int q[MAXN<<1] , cnt[MAXN<<1] , tlen , ans[MAXN<<1] , anum ;

struct Suffix_Automaton{
	int ndnum , go[MAXN<<1][26] , par[MAXN<<1] , len[MAXN<<1] , root , last , min_pos[MAXN<<1] ;

	inline int news(){ return ++ndnum ; }

	inline void init(){ root=news() , last=root , memset(min_pos,0x3f,sizeof(min_pos)) ; }

	void copy_it(int a,int b){
		for(int i=0;i<26;++i) go[a][i]=go[b][i] ;
		par[a]=par[b] , len[a]=len[b] , min_pos[a]=min_pos[b] ;
	}

	void add(int w){
		int now=news() , tmp=last ;
		len[now]=len[last]+1 , min_pos[now]=len[now] ;
		for(;tmp&&!go[tmp][w];tmp=par[tmp]) go[tmp][w]=now ;
		if(!tmp) par[now]=root ;
		else{
			int p=go[tmp][w] ;
			if(len[p]==len[tmp]+1) par[now]=p ;
			else{
				int q=news() ;
				copy_it(q,p) ;
				len[q]=len[tmp]+1 , par[p]=par[now]=q ;
				for(;tmp&&go[tmp][w]==p;tmp=par[tmp]) go[tmp][w]=q ;
			}
		}
		last=now ;
	}

	void get_pos(){
		memset(cnt,0,sizeof(int)*(ndnum+2)) ;
		for(int i=1;i<=ndnum;++i) ++cnt[len[i]] ;
		for(int i=1;i<=ndnum;++i) cnt[i]+=cnt[i-1] ;
		for(int i=ndnum;i>=1;--i) q[cnt[len[i]]--]=i ;
		//len 从小到大排序
		for(int i=ndnum;i>1;--i){
			int t=q[i] ;
			min_pos[par[t]]=my_min(min_pos[par[t]],min_pos[t]) ;
		}
	}

	void solve(){
		int p=1 ;
		while(p<tlen){
			int now=root , cnt=0 ;
			for(int i=p;i<=tlen;++i){
				int tmp=go[now][s[i]-'a'] ;
				if(!tmp || min_pos[tmp]-cnt>=p) break ;
				now=go[now][s[i]-'a'] , ++cnt ;
			}
			if(!cnt) ans[++anum]=-1 , ans[++anum]=s[p] , ++p ;
			else ans[++anum]=cnt , ans[++anum]=min_pos[now]-cnt , p+=cnt ;
		}
		for(int i=1;i<=anum;++i) printf("%d ",ans[i]) ;
		printf("\n") ;
	}
}SAM;

//记得计算空间   注意下标输出时要减一
int main(){
	freopen("encrypt.in","r",stdin) ;
	freopen("encrypt.out","w",stdout) ;
	scanf("%s",s+1) ;
	SAM.init() ;
	tlen=strlen(s+1) ;
	for(int i=1;i<=tlen;++i) SAM.add(s[i]-'a') ;
	SAM.get_pos() ;
	SAM.solve() ;
	return 0 ;
}
