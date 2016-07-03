#include<iostream>
#include<stdio.h>
#include<queue>
#include<bitset>
#define N 690
using namespace std;
bitset<N> operator+(const bitset<N> &a,const bitset<N> &b){
	bitset<N> c;int jin=0;
	for(int i=0;i<N;i++){
		int ls=a[i]+b[i]+jin;
		c[i]=ls&1;
		jin=ls>>1;
	}
	return c;
} 
struct node{
	bitset<N> num;int w;
	bool operator<(const node &x)const{
		if(w!=x.w) return w>x.w;
		for(int i=w-1;i>=0;i--) if(num[i]!=x.num[i]) return num[i]>x.num[i];
		return 0;
	}
};
priority_queue<node> q;
bitset<N> ten[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ten[0]=1;
	for(int i=1;i<N;i++) ten[i]=(ten[i-1]<<3)+(ten[i-1]<<1);
	int n;scanf("%d",&n);
	q.push((node){0,0});
	while(!q.empty()){
		node now=q.top();q.pop();
		bitset<N> ls=now.num+ten[now.w];
		if(--n==0){
			for(int i=now.w;i>=0;i--) cout<<ls[i];cout<<endl;
			return 0;
		}
		int t=now.w+1;
		if(!ls[t]) q.push((node){ls,t});
		if(!now.num[now.w+1]) q.push((node){now.num,now.w+1});
	}
}
