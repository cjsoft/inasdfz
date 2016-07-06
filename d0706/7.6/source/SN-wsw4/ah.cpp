#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define maxn 100010

using namespace std;

int read(){
	char c=getchar();
	int y=0,tim=1;
	while(c>'9'||c<'0'){
		if(c=='-')tim=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		y=y*10+c-'0';
		c=getchar();
	}
	return tim*y;
}
void print(int x){
	if(x==0)putchar('0');
	int s=1;
	while(s*10<=x)s*=10;
	while(s){
		putchar(x/s+'0');
		x%=s,s/=10;
	}
}
vector<int> g[maxn];
int t,n,val[maxn]={0},su[maxn]={0};
void dfs(int x){
	int i,y,l=g[x].size();
	for(i=0;i<l;i++){
		y=g[x][i];
		dfs(y);
		val[x]+=val[y];
	}
	su[x]=val[x];
	if(val[x]>0)val[x]=1;
	if(val[x]<0)val[x]=-1;
}
vector<int> vi;
void work1(){
	int i,x;
	for(i=1;i<=n;i++){
		if(g[i].size()==0&&val[i]==0)
			vi.push_back(i);
	}
}
void dfs2(int x){
	if(!(su[x]==0||su[x]==-1))return;
	int i,y,l=g[x].size();
	if(l==0&&val[x]==0)vi.push_back(x);
	for(i=0;i<l;i++){
		y=g[x][i];
		dfs2(y);
	} 
}
void work2(){
	int i,x;
	dfs2(1);
	sort(vi.begin(),vi.end());
}
int main(){
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	int i,x;
	t=read();
	while(t--){
		n=read();
		for(i=1;i<=n;i++){
			x=read();
			if(x)g[x].push_back(i);
		}
		for(i=1;i<=n;i++){
			x=read();
			if(x==1)val[i]=-1;
			if(x==0)val[i]=1;
			if(x==-1)val[i]=0;
		}
		dfs(1);
		if(val[1]==-1)putchar('-'),putchar('1');
		else {
			if(val[1]==1)work1();
			else work2();
			print(vi.size());
			for(i=0;i<vi.size();i++)
				putchar(' '),print(vi[i]);
		}
		putchar('\n');
		for(i=1;i<=n;i++)g[i].clear();
		vi.clear();
	}
	return 0;
}
