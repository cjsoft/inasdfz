#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 10020
#define O2
//#define O2 __attribute__((optimize("O2")))

struct node{
	int next,to,w;
}e[maxn * 2];
int head[maxn],cnt;
int sum;
int n,q;

O2 inline int read(){
	register char ch = getchar();
	register int num = 0;
	while ( ch < '0' || ch > '9' ) ch = getchar();
	while ( ch >= '0' && ch <= '9' ) num = ch - '0' + num * 10 , ch = getchar();
	return num;
}
/*O2 inline void print(int x){
	char ch[20];
	register int cnt = 0;
	while ( x ) ch[++cnt] = char(x % 10 + '0') , x /= 10;
	while ( cnt ) putchar(ch[cnt--]);
	putchar(10);
}*/
O2 inline void adde(int x,int y,int w){
	e[++cnt].to = y;
	e[cnt].next = head[x];
	e[cnt].w = w;
	head[x] = cnt;
}
O2 inline int gcd(int x,int y){
	if ( !y ) return x;
	return gcd(y,x % y);
}
O2 inline void dfs(int x,int fa,int cur){
	if ( cur == 1 ) sum++;
	for (register int i = head[x] ; i ; i = e[i].next){
		if ( e[i].to != fa ){
			dfs(e[i].to,x,gcd(cur,e[i].w));
		}
	}
}
O2 int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	n = read();
	for (register int i = 1 ; i < n ; i++){
		register int u = read(),v = read(),w = read();
		adde(u,v,w) , adde(v,u,w);
	}
	q = read();
	for (register int i = 1 ; i <= n ; i++){
		dfs(i,0,0);
	}
	printf("%d\n",sum / 2);
	while ( q-- ){
		register int k,x;
		k = read() , x = read();
		e[k * 2 - 1].w = e[k * 2].w = x;
		sum = 0;
		for (register int i = 1 ; i <= n ; i++){
			dfs(i,0,0);
		}
		printf("%d\n",sum / 2);
	}
//	cerr<<(double)clock() / 1000<<endl;
	return 0;
}
