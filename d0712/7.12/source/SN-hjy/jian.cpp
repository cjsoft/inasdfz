#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int n,m,ans;
int pow[10]={1,11,121,1331,14641,161051,1000000,10000000};
map<int,int> vis;
bool check(int sta)
{
	int x=sta%11;
	while(sta)
	{
		if(x!=sta%11)return false;
		sta/=11;
	}
	return true;
}
void dfs(int k,int ret,int sta,int bit)
{
	if(k==n)
	{
		if(ret || check(sta))return;
		int mx=sta,temp=sta;
		//cout<<sta<<endl;
		for(int i = 1; i < n; i++)
		{
			sta/=11;
			sta+=(temp%11)*pow[n-1];
			temp=sta;
			mx=max(mx,temp);
		}
		//cout<<"excuse me? "<<k<<' '<<ret<<' '<<sta<<' '<<bit<<endl;
		if(!vis[mx])vis[mx]=1,ans++;
		return;
	}
	for(int i = 0; i <= ret; i++)
		if(!(bit&(1<<((i+n-k)%n))))
		{
			dfs(k+1,ret-i,sta+i*pow[k],bit|(1<<((i+n-k)%n)));
		}
}
int main(void)
{
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d%d",&n,&m);
	dfs(0,m,0,0);
	printf("%d\n",ans);
}
