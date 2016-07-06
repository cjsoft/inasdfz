#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct edge{
	int t,nxt;
}a[100009];
int fir[100009],now[100009],cur;
int ans[100009],cnt;
int f[100009],T,n,t[100009],st;
void init(){
	memset(fir,0,sizeof(fir));
	memset(now,0,sizeof(now));
	memset(a,0,sizeof(a));
	memset(ans,0,sizeof(ans));
	cur=0,cnt=0;
	st=0;
	memset(t,0,sizeof(t));
}
int readint(){
	int ch=getchar(),ret=0,sgn=1;
	while((ch<'0' || ch>'9') && (ch!='-')) ch=getchar();
	if (ch=='-') sgn=-1,ch=getchar();
	while(ch>='0' && ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*sgn;
}
void addedge(int from,int to){
	cur++;
	if (fir[from]==0) fir[from]=cur;
	a[cur].t=to;
	a[now[from]].nxt=cur;
	now[from]=cur;
}
int sgn(int x){
	if (x>0) return 1;
	else if (x<0) return -1;
	return 0;
}
void dfs(int cur){
	now[cur]=t[cur];
	for (int i=fir[cur];i;i=a[i].nxt){
		dfs(a[i].t);
		if (t[a[i].t]==1) now[cur]++;
		else if (t[a[i].t]==-1) now[cur]--;
	}
	t[cur]=sgn(now[cur]);
}
void getans(int cur,int tp){
	if (!fir[cur] && !t[cur]) ans[cur]=1,cnt++;
	for (int i=fir[cur];i;i=a[i].nxt){
		if (now[a[i].t]!=0 && now[a[i].t]!=1) continue;
		getans(a[i].t,min(now[a[i].t],tp));
	}
}
void getallleaf(int cur){
	if (!fir[cur] && !t[cur]) ans[cur]=1,cnt++;
	for (int i=fir[cur];i;i=a[i].nxt){
		getallleaf(a[i].t);
	}
}
void fastoutput(int x){
	if (!x) return;
	fastoutput(x/10);
	putchar((x%10)+48);
}
int main(){
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
		n=readint();
		for (int i=1;i<=n;i++){
			f[i]=readint();
		}
		for (int i=2;i<=n;i++){
			addedge(f[i],i);
		}
		for (int i=1;i<=n;i++){
			t[i]=readint();
			if (t[i]==0) t[i]=-1;
			else if (t[i]==-1) t[i]=0;
		}
		memset(now,0,sizeof(now));
		dfs(1);
		if (t[1]==-1){
			getallleaf(1);
		}
		else if (t[1]==1){
			printf("-1\n");
			continue;
		}
		else {
			getans(1,1);
		}
		printf("%d ",cnt);
		//sort(ans+1,ans+1+cnt);
		for (int i=1;i<=n;i++){
			//printf("%d ",ans[i]);
			if (ans[i])
				fastoutput(i),putchar(' ');
		}
		putchar(10);
	}
}
