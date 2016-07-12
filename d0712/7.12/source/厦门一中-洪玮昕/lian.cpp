#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
const int N=110;
int n,m,x,y,z,ansl,ansr,L,R;
int ans[N],ss[N],s[N],r[N],s1[N][N];
int main()
{
	int a,b,c,i,j,k,o;
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	scanf("%d%d%d",&n,&L,&R);
	for(i=1;i<=n;i++)
		scanf("%d",&s[i]);
	for(i=1;i<=n;i++)
	{
		r[i]=n;
		s1[i][n+1]=i;
	}
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			s1[i][s[j]]++;
	for(i=1;i<=R;i++)
	{
		memset(ans,0,sizeof(ans));
		for(j=1;j<=n;j++)
		{
			if(r[j]<j) continue;
			for(k=1;k<=n;k++)
			{
				if(ans[k]>s1[j][k]) break;
				if(ans[k]==s1[j][k]) continue;
				for(o=1;o<=n+1;o++)
					ans[o]=s1[j][o];
				ansl=j;
				ansr=r[j];
				break;
			}
		}
		if(i>=L) printf("%d %d\n",ansl,ansr);
		s1[ansl][s[ansr]]--;
		r[ansl]--;
	}
}
