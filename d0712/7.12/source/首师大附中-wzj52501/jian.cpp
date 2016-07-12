#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
using namespace std;
inline int read() {
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
int n,m,A[50],vis[50],ans;
int count() {
	memset(vis,0,sizeof(vis));
	rep(i,1,n) {
		int x=(A[i]+i)%n;
		if(vis[x]) return 0;
		vis[x]=1;
	}
	rep(i,1,n) A[i+n]=A[i];
	rep(i,2,n) {
		int ok=0;
		rep(j,0,n-1) {
			if(A[j+1]<A[i+j]) return 0;
			if(A[j+1]>A[i+j]) {ok=1;break;}
		}
		if(!ok) return 0;
	}
	return 1;
}
int dfs(int cur,int c) {
	if(cur==n) {
		A[cur]=m-c;
		ans+=count();
	}
	else rep(i,0,m-c) A[cur]=i,dfs(cur+1,c+i);
}
int main() {
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	n=read();m=read();dfs(1,0);
	printf("%d\n",ans);
	return 0;
}

