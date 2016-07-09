#include<cstdio>
#define N 2010
using namespace std;
struct edge{int to,next,v;}e[N];
int n,ans,cnt,head[N],f[N],x[N],y[N],z[N],s[N][N];
int read(){
	int x=0; char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
	return x;
}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
void ins(int a,int b,int z){
	e[++cnt].to=b; e[cnt].next=head[a]; e[cnt].v=z; head[a]=cnt;
}
void change(int x,int y,int c){
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to==y){e[i].v=c; e[i^1].v=c; return;}
}
void dfs(int k,int x,int y){
	if(f[x]==1){ans+=s[k][x]; return;}
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=y){
			f[e[i].to]=gcd(f[x],e[i].v);
			dfs(k,e[i].to,x);
		}
}
void work(){
	ans=0;
	for(int i=1;i<=n;i++){f[i]=0; dfs(i,i,0);}
	printf("%d\n",ans>>1);
}
void dfs1(int k,int x,int y){
	s[k][x]=1;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=y){
			dfs1(k,e[i].to,x);
			s[k][x]+=s[k][e[i].to];
		}
}
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	n=read(); cnt=1;
	for(int i=1;i<n;i++){
		x[i]=read(),y[i]=read(),z[i]=read();
		ins(x[i],y[i],z[i]); ins(y[i],x[i],z[i]);
	}
	for(int i=1;i<=n;i++)dfs1(i,i,0);
	work(); int q=read();
	for(int i=1;i<=q;i++){
		int d=read(),c=read();
		change(x[d],y[d],c);
		work();
	}
	return 0;
}
