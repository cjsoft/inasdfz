#include<bits/stdc++.h>
#define N 110000
#define pr pair<int,int>
using namespace std;
typedef long long ll;
struct Query
{
	int x,y,tim,type;
	friend bool operator < (const Query &a,const Query &b)
	{
		return a.x<b.x;
	}
}Q[N<<1];
int A[N],B[N];
int T[N];
bool now[N];
set<int>s;
int val(int x)
{
	return now[x]?B[x]:A[x];
}
int main()
{
	freopen("tt.in","r",stdin);
	freopen("mine.out","w",stdout);
	int n,m,i,j,k,l,r,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",A+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",B+i);
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&l,&r,T+i);
		Q[i+i-1].x=l;
		Q[i+i-1].tim=i;
		Q[i+i-1].type=1;
		Q[i+i].x=r+1;
		Q[i+i].tim=i;
		Q[i+i].type=-1;
	}
	sort(Q+1,Q+m+m+1);
	for(i=1,j=1;i<=n;i++)
	{
		while(j<=m+m&&Q[j].x==i)
		{
			if(Q[j].type==1)
				s.insert(Q[j].tim);
			else
				s.erase(Q[j].tim);
			j++;
		}
		if(s.size()>0)
		{
			set<int>::iterator it=s.end();
			int flag=-1;
			do
			{
				it--;
				if(min(A[i],B[i])<=T[*it]&&T[*it]<=max(A[i],B[i]))
				{
					flag=A[i]<B[i];
					break;
				}
			}
			while(it!=s.begin());
			if(flag!=-1)
				now[i]=flag;
			for(;it!=s.end();it++)
			{
				if(val(i)<=T[*it])
					now[i]^=1;
			}
		}
		
	}
	ll ans=0;
	for(i=1;i<=n;i++)
	{
		ans+=val(i);
	}
	printf("%lld\n",ans);
	return 0;
}
