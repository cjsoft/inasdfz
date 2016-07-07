#include <bits/stdc++.h>
using namespace std;

const int N=45;
int n,m,ans;
char a[N][N],b[N];
long long A[N],nowb,x[N];

int solve(long long now)
{
	int i,j,k;
	for(i=39;i>=0;i--)x[i]=x[i+1]*2+((now&(1ll<<(39-i)))>>(39-i));
	for(i=0;i+m<41;i++)
		if(x[i]-(x[i+m]<<m)==nowb)
			return 1;
	return 0;
}

map<long long,int> M;
map<long long,int>::iterator it;

void dfs(int i,long long now)
{
	if(i>n)
	{
		M[now]++;
		return ;
	}
	dfs(i+1,now);
	dfs(i+1,now^A[i]);
}

int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++)
	{
        cin>>a[i];
	    for(j=39;j>=0;j--)
		    A[i]+=(1ll<<(39-j))*(a[i][j]-'0');
    }
	scanf("%d",&m);
	cin>>b;
	for(i=m-1;i>=0;i--)nowb=nowb+(1ll<<(m-1-i))*(b[i]-'0');
	dfs(1,0);
	it=M.begin();
	while(it!=M.end())
	{
		ans+=solve((*it).first)*((*it).second);
		it++;
	}
	printf("%d",ans);
	return 0;
}

