#include<iostream>
#include<set>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n , last[2005] , A[2005] ;
int r_o[2005] ;
int is_in[1005] ;

char get_c(){
	char t;
	while((t=(char)getchar())!=EOF) if(!isspace(t)) break ;
	return t;
}

struct cmp{
	bool operator()(const int &a,const int &b){
		return a>b ;
	}
};

set<int,cmp> st2 ;
set<int,cmp>::iterator it2 ;
set<int> st1 ;
set<int>::iterator it1 ;

void init(){
	for(int i=1;i<=n;++i) last[i]=-1002 ;
	memset(is_in,-1,sizeof(is_in)) ;
	st1.clear() , st2.clear() ;
}

void solve(){
	scanf("%d",&n) ;
	init() ;
	int sum=0 ;
	for(int i=1;i<=n;++i){
		char c=get_c() ;
		scanf("%d",&A[i]) ;
		if(c=='E') r_o[i]=true , ++ sum ;
		else r_o[i]=false , -- sum ;
	}
	for(int k=0;k<=1000;++k){
		bool fail=false ;
		st1.clear() , st2.clear() ;
		for(int i=1;i<=k;++i){
			st1.insert(-i) ;
		}
		for(int i=1;i<=n;++i){
			if(r_o[i]==1){
				int t=A[i] ;
				if(!t){
					st1.insert(i) ;
				}
				else{
					if(is_in[t]==1){
						it2=st2.lower_bound(i-1) ;
						if(it2==st2.end()) fail=true ;
						else{
							int tmp=*it2 ;
							A[tmp]=t ;
							st2.erase(it2) ;
						}
					}
					is_in[t]=1 ;
					last[t]=i ;
				}
			}
			else{
				int t=A[i] ;
				if(!t){
					st2.insert(i) ;
				}
				else{
					if(is_in[t]==0){
						it1=st1.lower_bound(last[t]+1) ;
						if(it1==st1.end()) fail=true ;
						else{
							int tmp=*it1 ;
							A[tmp]=t ;
							st1.erase(it1) ;
						}
					}
					is_in[t]=0 ;
					last[t]=i ;
				}
			}
		}
		int cnt1=0 , cnt2=0 ;
		for(it1=st1.begin();it1!=st1.end();++it1) ++cnt1 ;
		for(it2=st2.begin();it2!=st2.end();++it2) ++cnt2 ;
		if(cnt1<cnt2) fail=true ;
		if(!fail && sum+k>=0){
			printf("%d\n",sum+k) ;
			return ;
		}
	}
	printf("OTHER\n") ;
}

int main(){
	freopen("probe.in","r",stdin) ;
	freopen("probe.out","w",stdout) ;
	int T ;
	scanf("%d",&T) ;
	while(T--) solve() ;
	return 0 ;
}
