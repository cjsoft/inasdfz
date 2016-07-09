#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <map>
#define maxn 100010

using namespace std;

struct Edge{int to,wi;}ei[maxn<<1];
int tot=0;
vector<int> g[maxn];
void AddE(int f,int to,int wi){
	g[f].push_back(tot);
	ei[tot++]=(Edge){to,wi};
}
void AddEdge(int f,int to,int wi){
	AddE(f,to,wi);
	AddE(to,f,wi);
}
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
long long int ans=0;
inline void addi(map<int,int> &ma,int v,int ni){
	if(ma.find(v)==ma.end())ma[v]=ni;
	else ma[v]+=ni;
}
map<int,int> ma[maxn],up[maxn];
void dfs(int x,int fa){
	ma[x].clear();
	int i,ye,y,l=g[x].size();
	map<int,int>::iterator it;
	for(i=0;i<l;i++){
		ye=g[x][i];
		y=ei[ye].to;
		if(y!=fa){
			dfs(y,x);
			for(it=ma[y].begin();it!=ma[y].end();it++){
				addi(ma[x],gcd(ei[ye].wi,it->first),it->second);
			}
			addi(ma[x],ei[ye].wi,1);
		}
	}
	if(ma[x].find(1)!=ma[x].end())ans+=ma[x][1];
}
void dfs2(int x,int fa){
	int i,y,ye,l=g[x].size();
	map<int,int>::iterator it;
	for(i=0;i<l;i++){
		ye=g[x][i];
		y=ei[ye].to;
		if(y!=fa){
			up[y].clear();
			for(it=up[x].begin();it!=up[x].end();it++)
				addi(up[y],gcd(ei[ye].wi,it->first),it->second);
			for(it=ma[y].begin();it!=ma[y].end();it++)
				ma[x][gcd(ei[ye].wi,it->first)]-=it->second;
			for(it=ma[x].begin();it!=ma[x].end();it++)
				addi(up[y],gcd(ei[ye].wi,it->first),it->second);
			for(it=ma[y].begin();it!=ma[y].end();it++)
				addi(ma[x],gcd(ei[ye].wi,it->first),it->second);
			dfs2(y,x);
			if(up[y].find(1)!=up[y].end())ans+=up[y][1];
		}
	}
}
int n,q;
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	int i,x,y,w;
	scanf("%d",&n);
	for(i=1;i<=n-1;i++){
		scanf("%d%d%d",&x,&y,&w);
		AddEdge(x,y,w);
	}
	dfs(1,0),dfs2(1,0);printf("%I64d\n",ans>>1);
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&x,&w);
		ei[2*x-1].wi=w;
		ei[2*x-2].wi=w;
		ans=0;
		dfs(1,0),dfs2(1,0);
		printf("%I64d\n",ans>>1);
	}
	return 0;
}
