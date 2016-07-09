#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const static int N=10005,M=N*10;

static int n,en,h[N],siz[N],cnt_point,Mx_point,q,A[N],B[N],Q1[N],Q2[N],F[M],G[M],cnt_Q1,cnt_Q2,vis[N];
static long long ans;

struct Edge{
int b,v,next;
}e[N<<1];

inline void AddEdge(register int sa,register int sb,register int sc){
e[++en].b=sb;
e[en].v=sc;
e[en].next=h[sa];
h[sa]=en;
}

inline void Read(register int &x){
register char ch;
while((ch=getchar())<'0' && ch>'9');
x=ch-'0';
while((ch=getchar())>='0' && ch<='9')x=x*10+ch-'0';
}

inline void dfs_siz(register int u,register int fat){
siz[u]=1;
for(register int i=h[u];i;i=e[i].next){
	int v=e[i].b;
	if(v==fat)continue;
	dfs_siz(v,u);
	siz[u]+=siz[v];
}
}

inline void dfs(register int u,register int fat,register int poi){
siz[u]=max(siz[u],siz[poi]-siz[u]);
if(siz[u]>siz[Mx_point])Mx_point=u;
for(int i=h[u];i;i=e[i].next){
	int v=e[i].b;
	if(v==fat)continue;
	dfs(v,u,poi);
}
}

inline int gcd(int x,int y){return !y?x:gcd(y,x%y);}

static int fat;

inline void dfs1(register int u,register int gcdit){
register int tfat=fat,i,v,x;
for(i=h[u];i;i=e[i].next){
	v=e[i].b;
	if(v==tfat)continue;
	x=gcd(e[i].v,gcdit);
	Q1[++cnt_Q1]=x;
	fat=u;
	//printf("Ahs: %d %d %d\n",u,v,fat);
	dfs1(v,x);
}
}

inline void dfs2(register int u,register int gcdit){
register int tfat=fat,i,v,x;
for(i=h[u];i;i=e[i].next){
	v=e[i].b;
	if(v==tfat)continue;
	x=gcd(e[i].v,gcdit);
	Q2[++cnt_Q2]=x;
	fat=u;
	//printf("Bhs: %d %d %d\n",u,v,fat);
	dfs2(v,x);
}
}

inline void Solve(register int u,register int v,register int last,register int newe){
register int i,j,tx,l,r;
cnt_Q1=0;
cnt_Q2=0;
fat=v;
dfs1(u,0);
fat=u;
dfs2(v,0);
for(i=1;i<=cnt_Q1;i++)F[Q1[i]]++;
for(i=1;i<=cnt_Q2;i++)G[Q2[i]]++;
sort(Q1+1,Q1+cnt_Q1+1);
sort(Q2+1,Q2+cnt_Q2+1);
cnt_Q1=unique(Q1+1,Q1+cnt_Q1+1)-Q1-1;
cnt_Q2=unique(Q2+1,Q2+cnt_Q2+1)-Q2-1;
Q1[++cnt_Q1]=0;
Q2[++cnt_Q2]=0;
F[0]=G[0]=1;
//for(int i=1;i<=cnt_Q1;i++)printf("As:%d %d\n",F[Q1[i]],Q1[i]);
//for(int i=1;i<=cnt_Q2;i++)printf("Bs:%d %d\n",G[Q2[i]],Q2[i]);
for(i=1;i<=cnt_Q1;i++){
	for(j=1;j<=cnt_Q2;j++){
		tx=gcd(Q1[i],Q2[j]),l=gcd(newe,tx),r=gcd(last,tx);
		if(l>1 && r==1)ans-=1ll*F[Q1[i]]*G[Q2[j]];/*,printf("A:%lld\n",ans);*/
		else if(l==1 && r>1)ans+=1ll*F[Q1[i]]*G[Q2[j]];/*,printf("B:%lld\n",ans);*/
	}
}
for(i=1;i<=cnt_Q1;i++)F[Q1[i]]=0;
for(i=1;i<=cnt_Q2;i++)G[Q2[i]]=0;
printf("%lld\n",ans);
}

inline void BF(){
register int i,j;
for(i=1;i<=n;i++){
	cnt_Q1=0;
	fat=0;
	dfs1(i,0);
	for(j=1;j<=cnt_Q1;j++)ans+=Q1[j]==1;
}
}

//#include<ctime>

int main(){
freopen("network.in","r",stdin);
freopen("network.out","w",stdout);
Read(n);
register int i,u,v,w,ix,x,y;
for(i=1;i<n;i++){
	Read(u);Read(v);Read(w);
	AddEdge(u,v,w);AddEdge(v,u,w);
}
BF();
printf("%lld\n",ans/=2);
Read(q);
while(q--){
	Read(ix);Read(x);
	y=e[ix<<1].v;
	e[ix<<1].v=x;
	e[(ix<<1)-1].v=x;
	Solve(e[ix<<1].b,e[(ix<<1)-1].b,y,x);
}
//printf("%.3lf\n",(double)clock()/CLOCKS_PER_SEC);
return 0;
}

