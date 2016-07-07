#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
const int maxn=2005;
int n,m,s,cL,cE;
char tp[maxn];
int id[maxn],in[maxn];

int nex[maxn][maxn];


void init()
{
	scanf("%d",&m);
	n=2000;cL=cE=0;
	char ss[5];
	for(int i=1;i<=m;i++)
	{
		scanf("%s %d",ss,id+i);
		tp[i]=*ss;
		if(tp[i]=='L')cL++;
		else cE++;
	}
	for(int i=1;i<=n;i++)
		nex[i][m+1]=m+1;
	for(int j=m;j;j--)
	{
		for(int i=1;i<=n;i++)
			nex[i][j]=nex[i][j+1];
		nex[id[j]][j]=j;
	}
}

bool E0(int t)
{
	int k=-1;
	for(register int i=1;i<=n;i++)
		if(!in[i]&&tp[nex[i][t+1]]=='L')
			if(k==-1||nex[i][t+1]<nex[k][t+1])
				k=i;
	if(k!=-1)
		in[k]=1;
	else
		s++;
	return 0;
}

bool L0(int t)
{
	int k=-1;
	for(register int i=1;i<=n;i++)
		if(in[i]&&tp[nex[i][t+1]]=='E')
			if(k==-1||nex[i][t+1]<nex[k][t+1])
				k=i;
	if(k!=-1)
	{
		in[k]=0;
	}
	else if(s)
	{
		s--;
	}
	else
	{
		k=-1;
		for(register int i=1;i<=n;i++)
			if(in[i]&&(nex[i][t+1]==m+1||tp[nex[i][t+1]]=='L'))
				if(k==-1||nex[i][t+1]>nex[k][t+1])
					k=i;
		if(k==-1)return 1;
		in[k]=0;
	}
	return 0;
}

bool E(int x,int t)
{
	if(x==0)return E0(t);
	if(in[x]==1)return 1;
	in[x]=1;
	return 0;
}

bool L(int x,int t)
{
	if(x==0)return L0(t);
	if(in[x]==0)return 1;
	in[x]=0;
	return 0;
}

bool check(int s_)
{
	for(int i=1;i<=n;i++)
		in[i]=0;
	s=0;
	for(int i=1;i<=s_;i++)
		if(E(0,0))return 0;
	for(int i=1;i<=m;i++)
		if(tp[i]=='E')
		{
			if(E(id[i],i))return 0;
		}
		else
		{
			if(L(id[i],i))return 0;
		}
	return 1;
}

void work()
{
	int low=max(cL-cE,0)-1,high=n+1,mid;
	while(low+1<high)
	{
		mid=low+high>>1;
		if(check(mid))high=mid;
		else low=mid;
	}
	if(high==n+1)
		cout<<"OTHER"<<endl;
	else
		cout<<high+cE-cL<<endl;
}
//#include<ctime>
int main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	int CT;
	for(cin>>CT;CT--;)
	{
		init();
		work();
	}
	//cout<<clock()<<endl;
	return 0;
}

