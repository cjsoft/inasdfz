#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int SIZE=1000005 ;
unsigned long long base=10007 , ci[20005] ;
const int MAXN=2005 ;
int n , p , q ;
int A[MAXN] , root[MAXN] ;

struct states{
	int l,r ;
	states(int _l=0,int _r=0){
		l=_l , r=_r ;
	}
}que[1000005];
int qnum , TTT , q1[MAXN] , q2[MAXN] , len1 , len2 ;

bool cmp(const states &a,const states &b){
	len1=len2=0 ;
	for(int i=a.l;i<=a.r;++i) q1[++len1]=A[i] ;
	for(int i=b.l;i<=b.r;++i) q2[++len2]=A[i] ;
	sort(q1+1,q1+len1+1) , sort(q2+1,q2+len2+1) ;
	int tmp=min(len1,len2) ;
	for(int i=1;i<=tmp;++i){
		if(q1[i]<q2[i]) return true ;
		if(q1[i]>q2[i]) return false ;
	}
	if(len1==len2) return a.l<b.l ;
	else return len1>len2 ;
}

void BAOLI(){
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			que[++qnum]=states(i,j) ;
		}
	}
	sort(que+1,que+qnum+1,cmp) ;
	for(int i=p;i<=q;++i){
		cout << que[i].l << ' ' << que[i].r << '\n' ;
	}
}

int main(){
	freopen("lian.in","r",stdin) ;
	freopen("lian.out","w",stdout) ;
	scanf("%d%d%d",&n,&p,&q) ;
	ci[0]=1 ;
	for(int i=1;i<=10005;++i) ci[i]=ci[i-1]*base ;
	for(int i=1;i<=n;++i) scanf("%d",&A[i]) ;
	BAOLI() ;
	return 0 ;
}
