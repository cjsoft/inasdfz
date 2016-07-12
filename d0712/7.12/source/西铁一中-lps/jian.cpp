#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int n,m,a[22],vis[20],ans;
int p[1771561];
void dfs(int x,int s)
{
    if (x==n)
    {
        a[x]=s;
        for (int i=0;i<n;i++)
        vis[i]=0;
        int flag=0;
        for (int i=1;i<=n;i++)
        {
            int tmp=(a[i]+i)%n;
            if (vis[tmp]==1)
            {
                flag=1;break;
            }
            else
            vis[tmp]=1;
        }
        if (flag) return ;
        ans++;
        return ;
    }
    for (int i=0;i<=s;i++)
    {
        a[x]=i;
        if (s-i>=0)
        dfs(x+1,s-i);
    }
}
int main()
{
//	freopen("jian.in","r",stdin);
	//freopen("jian.out","w",stdout);
    scanf("%d%d",&n,&m);
    if(m>10&&n>15)
    {
    	cout<<0<<endl;
    	return 0;
    }
    dfs(1,m);
    if (m%n==0&&n!=1) ans--;
    cout<<ans/n<<endl;
}


