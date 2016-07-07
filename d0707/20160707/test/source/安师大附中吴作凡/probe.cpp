#include<algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include  <stdio.h>
#include   <math.h>
#include   <time.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <set>
#include      <map>
using namespace std;

const int N=5005;

int n,id[N],type[N],nxt[N],las[N],fst[N],Now[N];

int Num;

set<int> InE,InL,OutL;

bool E0()
{
	if(OutL.size())
	{
		int p=*OutL.begin();
		Now[id[p]]=1;OutL.erase(p);InL.insert(p);
	}
	else
		Num++;
	return 1;
}

bool E(int i)
{
	if(Now[id[i]])
		return 0;
	Now[id[i]]=1;
	if(!nxt[i])
		Num++;
	else if(type[nxt[i]])
		InE.insert(nxt[i]);
	else
		InL.insert(nxt[i]);
	return 1;
}

bool L0()
{
	if(InE.size())
	{
		int p=*InE.begin();
		Now[id[p]]=0;InE.erase(p);
	}
	else if(Num)
		Num--;
	else if(InL.size())
	{
		int p=*--InL.end();
		Now[id[p]]=0;InL.erase(p);OutL.insert(p);
	}
	else
		return 0;
	return 1;
}

bool L(int i)
{
	if(!Now[id[i]])
		return 0;
	Now[id[i]]=0;InL.erase(i);
	if(!nxt[i])
		return 1;
	if(!type[nxt[i]])
		OutL.insert(nxt[i]);
	return 1;
}

bool check(int k)
{
	InE.clear();InL.clear();OutL.clear();Num=0;
	for(int i=0;i<=2000;i++)
	{
		if(fst[i]&&!type[fst[i]])
			OutL.insert(fst[i]);
		Now[i]=0;
	}
	while(k--)
		E0();
	for(int i=1;i<=n;i++)
		if(type[i])
			if(!id[i])
			{
				if(!E0())
					return 0;
			}
			else
			{
				if(!E(i))
					return 0;
			}
		else
			if(!id[i])
			{
				if(!L0())
					return 0;
			}
			else
			{
				if(!L(i))
					return 0;
			}
	return 1;
}

void solve()
{
	scanf("%d",&n);
	for(int i=0;i<=2000;i++)
		nxt[i]=las[i]=fst[i]=0;
	int ss=0;
	for(int i=1;i<=n;i++)
	{
		char s[10];scanf("%s%d",s,&id[i]);
		if(*s=='E')
			type[i]=1,ss++;
		else
			type[i]=0,ss--;
		if(id[i])
		{
			if(!las[id[i]])
				fst[id[i]]=i;
			else
				nxt[las[id[i]]]=i;
			las[id[i]]=i;
		}
	}
	if(!check(n))
	{
		puts("OTHER");return;
	}
	int l=0,r=n,Ans=n;
	while(l<=r)
	{
		int Mid=l+r>>1;
		if(check(Mid))
			Ans=Mid,r=Mid-1;
		else
			l=Mid+1;
	}
	cout<<Ans+ss<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
#endif
	int t;cin>>t;
	while(t--)
		solve();
	return 0;
}

