#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100005

int T,n,en,tag[N],head[N];

struct Edge{
	int to,next;
	Edge(){}
	Edge(int _to,int _next){to=_to,next=_next;}
}e[N];

inline int read(){
	int x=0,f=1;char cr;
	cr=getchar();
	while(cr<'0'||cr>'9'){if(cr=='-') f=-1;cr=getchar();}
	while(cr>='0'&&cr<='9') x=x*10+cr-'0',cr=getchar();
	return x*f;
}

void addEdge(int u,int v){e[++en]=Edge(v,head[u]);head[u]=en;}

int dfs(int x){
	if(!head[x]) return tag[x];
	int tmp=0,cnt=0,xx;
	for(int i=head[x];i;i=e[i].next){
		xx=dfs(e[i].to);
		if(x==0) cnt++;
		else tmp+=xx;
	}
	if(tmp<=-1) return -1;
	if(tmp>=1) return 1;
	//if(tmp==-1&&cnt<=2) return -1;
	return 0;
}

int main(){
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	int x;
	T=read();
	while(T--){
		en=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			addEdge(x,i);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&tag[i]);
			if(tag[i]==1) tag[i]=-1;
			else if(tag[i]==0) tag[i]=1;
			else tag[i]=0;
		}
		if(dfs(1)<0) printf("-1\n");
		else printf("0\n");
		fill(head,head+n+10,0);
	}
	return 0;
}
