#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n,m;

int ans=0,s[11];
bool use[11];
bool jud()
{
	memset(use,0,sizeof(use));
	for(int i=1;i<=n;++i)
	{
		int t=(s[i]+i)%n;
		if(use[t]) return 0;
		use[t]=1;
	}
	for(int i=2;i<=n;++i)
	{
		int j=0;
		while(s[(i+j-1)%n+1]==s[j%n+1]&&j<n) j++;
		if(j==n) return 0;
		if(s[(i+j-1)%n+1]>s[j%n+1])return 0;
	}
	return 1;
}
void dfs(int wz,int w,int li)
{
	if(wz>n)
	{
		if(w==0&&jud())
		{
			ans++;
		//	for(int i=1;i<=n;++i)
		//		cout<<s[i]<<" ";
		//	cout<<endl;
		} 
		return ;
	}
	for(int i=0;i<=min(w,li);++i)
	{
		s[wz]=i;
		dfs(wz+1,w-i,li);
	}
}

int main()
{
	freopen("jian.in","r",stdin);
	freopen("jian.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		s[1]=i;
		dfs(2,m-i,i);
	}
	printf("%d",ans);
	return 0;
}
