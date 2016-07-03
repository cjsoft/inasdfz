#include<algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include  <stdio.h>
#include   <time.h>
#include   <math.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <set>
#include      <map>
using namespace std;

const int N=700,T=27,Mod=(1<<T)-1;

int K;

struct BigNum
{
	int len,t[90];
	
	inline bool operator[](int x)
	{
		return (t[x/27+1]>>(x%27))&1;
	}
}ten[N];

inline void operator*=(BigNum& A,int B)
{
	for(int i=1;i<=A.len;i++)
		A.t[i]*=B;
	int i;
	for(i=1;i<=A.len||A.t[i];i++)
		A.t[i+1]+=A.t[i]>>27,A.t[i]&=Mod;
	A.len=i-1;
}

inline void operator+=(BigNum& A,const BigNum& B)
{
	A.len=max(A.len,B.len);
	for(int i=1;i<=A.len;i++)
		A.t[i]+=B.t[i];
	int i;
	for(i=1;i<=A.len||A.t[i];i++)
		A.t[i+1]+=A.t[i]>>27,A.t[i]&=Mod;
	A.len=i-1;
}

struct Sta
{
	BigNum t;string s;
}Z,O;

queue<Sta> Q,Q2;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
#endif
	cin>>K;
	if(K==1)
		cout<<1<<endl,exit(0);
	Z.s="0";O.s="1";O.t.len=O.t.t[1]=1;
	ten[0].len=ten[0].t[1]=1;
	for(int i=1;i<N;i++)
		ten[i]=ten[i-1],ten[i]*=10;
	Q.push(Z);Q.push(O);K--;
	while(1)
	{
		int len=Q.front().s.size();
		while(!Q.empty()&&Q.front().s.size()==len)
		{
			Sta s=Q.front();Q.pop();
			if(s.t[len]==0)
			{
				Sta nxt=s;nxt.s+="0";Q.push(nxt);
				nxt=s;nxt.s+="1";nxt.t+=ten[len];Q2.push(nxt);
				K--;
				if(!K)
				{
					for(int i=len;~i;i--)
						putchar(nxt.s[i]);
					return 0;
				}
			}
		}
		while(!Q2.empty())
			Q.push(Q2.front()),Q2.pop();
	}
	return 0;
}
