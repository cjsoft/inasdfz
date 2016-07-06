#include <bits/stdc++.h>

using namespace std;

const int N = 101000;


int read(){
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || '9' < ch){if (ch == '-') f = -1;ch = getchar();}
	while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0',ch = getchar();
	return x*f;
}

void write(int p){
	if (p <= 9) putchar(p+'0');
	else{
		write(p/10);
		putchar(p%10+'0');
	}
}

struct Edge{
	int end,next;
}edge[N<<1];
int first[N],efn;

int ans[N],len;
int T,n,fa[N],a[N],b[N],m;
void check(int);
void addedge(int,int);
void dfs1(int);
void dfs2(int);
int main(){
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	T = read();
	while (T--){
		n = read();m = 0;efn = 0;len = 0;
		memset(first,0,sizeof(first));
		for (int i = 1;i <= n;i++) {
			fa[i] = read();
			if (i != 1) addedge(fa[i],i);
		}
		for (int i = 1;i <= n;i++) {
			a[i] = read();
			if (a[i] == 0) a[i] = -1;
			else if (a[i] == -1) a[i] = 0;
		}
		check(1);
		if (a[1] > 0){
			puts("-1");
		}
		else{
			if (a[1] < 0)dfs1(1);
			else dfs2(1);
			write(m);putchar(' ');
			sort(ans+1,ans+1+m);
			for (int i = 1;i <= m;i++){
				write(ans[i]);
				putchar(' ');
			}
			putchar('\n');
		}
	}
	return 0;
}
void addedge(int x,int y){
	edge[++efn].end = y;
	edge[  efn].next = first[x];
	first[x] = efn;
}
void check(int p){
	int sum = a[p];
	for (int h = first[p];h;h = edge[h].next){
		int u = edge[h].end;
		check(u);
		sum += a[u];
	}
	b[p] = sum;
	if (sum > 0) a[p] = 1;
	if (sum < 0) a[p] = -1;
//	printf("%d %d %d\n",p,fa[p],a[p]);
}
void dfs1(int p){
	bool flag = 1;
	for (int h = first[p];h;h = edge[h].next){
		int u = edge[h].end;
		flag = 0;
		dfs1(u);
	}
	if (flag && a[p] == 0) ans[++m] = p;
}
void dfs2(int p){
	bool flag = 1;
	for (int h = first[p];h;h = edge[h].next){
		int u = edge[h].end;
		flag = 0;
		if (a[u] == 0 || b[u] == 1) dfs2(u);
	}
	if (flag && a[p] == 0) ans[++m] = p;	
}
