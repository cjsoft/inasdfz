#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
struct A{
	int a[710];
	bool operator<(const A& b)const{
	    if(a[0]!=b.a[0]) return a[0]>b.a[0];
	    for(int i=a[0];i>=1;i--)
	    	if(a[i]!=b.a[i]) return a[i]>b.a[i];
	}
}t,a1,a2;
priority_queue<A> q;
void out(A x){
	for(int i=x.a[0];i>=1;i--) printf("%d",x.a[i]);
	printf("\n");
}
bool div(A& x){
	int i,tmp=0;
	for(i=x.a[0];i>=1&&tmp<2;i--) tmp=tmp*10+x.a[i];
	if(tmp<2) return x.a[1];
	if(i<x.a[0]-1) x.a[0]--;
	for(i++;i>=1;i--){
		x.a[i]=tmp/2;
		if(i==1) return tmp&1;
		tmp=tmp%2*10+x.a[i-1];
	}
}
void cg(A x){
	int p=x.a[0],cnt=0,i,tp;
	while(1){
		cnt++;
		tp=div(x);
		if(tp&&cnt>p) break;
	}
	for(i=p+1;i<cnt;i++){
		t.a[0]++;
		t.a[i]=1;
		q.push(t);
		t.a[i]=0;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,i;
	scanf("%d",&n);
	n--;
	a1.a[0]=a2.a[0]=1;
	a1.a[1]=1;a2.a[1]=0;
	for(i=1;i<=700;i++){
		a1.a[0]++;
		a1.a[a1.a[0]]=1;
		q.push(a1);
		a1.a[a1.a[0]]=0;
		a2.a[0]++;
		a2.a[a2.a[0]]=1;
		q.push(a2);
		a2.a[a2.a[0]]=0;
	}
	for(i=1;i<=n;i++){
		t=q.top();q.pop();
		if(i==n){out(t);return 0;}
		cg(t);
	}
	return 0;
}
