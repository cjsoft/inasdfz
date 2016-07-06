#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int getint(){
	int x=0; char ch=getchar(),fl=0;
	while(ch>'9'||ch<'0')fl=ch,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	if(fl=='-')return -x;
	return x;
}

int fat[MAXN];
int f[MAXN];
int v[MAXN];
int c1[MAXN],c2[MAXN],c0[MAXN];
vector<int> son[MAXN];

void dfs(int rt){
	if(!son[rt].size()){
		f[rt]=v[rt];
		return;
	}
	for(int p=0;p!=son[rt].size();++p){
		int u=son[rt][p];
		dfs(u);
		if(f[u]==0)++c0[rt];
		if(f[u]==1)++c1[rt];
		if(f[u]==-1)++c2[rt];
	}
	if(c0[rt]>c1[rt])f[rt]=0;
	if(c1[rt]>c0[rt])f[rt]=1;
	if(c1[rt]==c0[rt])f[rt]=-1;
}

vector<int> ans;
void getans(int rt){
	if(!son[rt].size()){
		if(v[rt]==-1)ans.push_back(rt);
		return;
	}
	for(int p=0;p!=son[rt].size();++p){
		int u=son[rt][p];
		if(f[u]==-1||(f[u]==1&&c1[u]-c0[u]<=1))getans(u);
	}
}

int main(){
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	
	
	int T=getint();
	while(T-->0){
		
		
		for(int i=0;i<MAXN;++i)son[i].clear();
		memset(c0,0,sizeof(c0));
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		
		
		int n=getint();
		for(int i=1;i<=n;++i)
			fat[i]=getint(),son[fat[i]].push_back(i);
		for(int i=1;i<=n;++i)
			v[i]=getint();
		
		
		dfs(1);
		
		
		if(f[1]==-1){
			ans.clear();
			getans(1);
			sort(ans.begin(),ans.end());
			printf("%d",ans.size());
			for(int i=0;i!=ans.size();++i)printf(" %d",ans[i]);
			printf("\n");
		}else if(f[1]==0){
			ans.clear();
			for(int i=1;i<=n;++i)
				if(!son[i].size()&&v[i]==-1)ans.push_back(i);
			printf("%d",ans.size());
			for(int i=0;i!=ans.size();++i)printf(" %d",ans[i]);
			printf("\n");
		}else{
			printf("-1\n");
		}
		
		
	}
	
	return 0;
}
