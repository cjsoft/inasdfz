#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=500005 ;
char s[MAXN];
int ans[MAXN<<1] , anum , len ;

int get_match(int i,int j){
	int ret=0 ;
	while(1){
		if(s[i]==s[j]) ++ret ;
		else break ;
		++i , ++j ;
		if(i>len || j>len) break ;
	}
	return ret;
}

void solve(){
	len=strlen(s+1) ;
	int p=1 ;
	while(p<len){
		int tj=-1 , tlen=0 ;
		for(int i=1;i<p;++i){
			int tmp=get_match(i,p) ;
			if(tmp>tlen){
				tj=i , tlen=tmp ;
			}
		}
		if(tj!=-1) ans[++anum]=tlen , ans[++anum]=tj-1 , p+=tlen ;
		else ans[++anum]=-1 , ans[++anum]=s[p] , ++p ;
	}
	for(int i=1;i<=anum;++i){
		printf("%d ",ans[i]) ;
	}
	printf("\n") ;
}

int main(){
	freopen("encrypt.in","r",stdin) ;
	freopen("BAOLI_encrypt.out","w",stdout) ;
	scanf("%s",s+1) ;
	solve() ;
	return 0 ;
}
