#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define maxn 1010

using namespace std;

struct Option{int fl,id;}opt[maxn];
struct Range{int f,t;}ri[maxn][2];
int len[2]={0};
vector<int> g[maxn<<1],st[maxn][2],ed[maxn][2];
int n,t;
char s[10]={0};
bool flag[maxn]={0};
bool check(int c){
	memset(flag,0,sizeof(flag));
	int i,j,ml,mx;
	for(i=1;i<=n;i++){
		for(j=0;j<st[i][c].size();j++)
			flag[st[i][c][j]]=1;
		for(j=0;j<ed[i][c].size();j++){
			if(flag[ed[i][c][j]])
				return false;
		}
		if(opt[i].fl==c^1&&opt[i].id==0){
			ml=10000,mx=-1;
			for(j=1;j<=len[c];j++)
				if(flag[j]&&ri[j][c].t<ml)
					ml=ri[j][c].t,mx=j;
			if(mx!=-1)flag[mx]=0;
		}
	}
	return true;
}
void init(){
	len[0]=len[1]=0;
	for(int i=1;i<=2000;i++)g[i].clear();
	for(int i=1;i<=n;i++){
		st[i][0].clear(),st[i][1].clear();
		ed[i][0].clear(),ed[i][1].clear();
	}
}
int main(){
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	int i,j,x,y;
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%s%d",s,&x);
			opt[i].fl=(s[0]!='E');
			opt[i].id=x;
			if(x)g[x].push_back(i);
		}
		for(i=1;i<=2000;i++){
			for(j=0;j+1<g[i].size();j++){
				x=g[i][j],y=g[i][j+1];
				if(opt[x].fl==opt[y].fl){
					ri[++len[opt[x].fl]][opt[x].fl]=(Range){x,y};
					st[x][opt[x].fl].push_back(len[opt[x].fl]);
					ed[y][opt[x].fl].push_back(len[opt[x].fl]);
				}
			}
		}
		if(check(1)&&check(0)){
			int ans=0;
			for(i=1;i<=n;i++){
				if(!opt[i].fl)ans++;
				else ans--; 
				if(ans<0)ans=0;
			}
			printf("%d\n",ans);
		}
		else printf("OTHER\n");
	}
	return 0;
}
