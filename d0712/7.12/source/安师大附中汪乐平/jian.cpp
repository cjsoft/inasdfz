#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
#define ll long long
int n,i,a[100],s[100],f[100],ans;
ll m;
bool b[100];
void dfs(int x,ll y)
{
	int i,j;
	if(x==n&&!y)
	{
		f[0]=j=-1;i=0;
		while(i<n)if(j==-1||a[i]==a[j])f[++i]=++j;
        else j=f[j];
        if(n%(n-f[n])||!f[n])
        {
        	ans++;
        	if(ans==998244353)ans=0;
        }
		return;
	}
	for(i=0;i<=y;i++)if(!b[(i+x)%n])
	{
		b[(i+x)%n]=1;
		a[x]=i;
		dfs(x+1,y-i);
		b[(i+x)%n]=0;
	}
}
int main()
{
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	cin>>n>>m;
	if(m%n==0)dfs(0,m);
	cout<<ans/n<<endl;
	return 0;
}

