#include<algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include  <stdio.h>
#include   <math.h>
#include   <time.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <map>
#include      <set>
using namespace std;

typedef unsigned long long LL;

const int N=400005,T=25,All=(1<<T)-1;

int len,n,t[N],Ans;
char s[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
#endif
	gets(s);len=strlen(s);
	int w=0;n=1;
	for(int i=len-1;~i;i--)
	{
		t[n]+=s[i]-'0'<<w;
		w++;
		if(w==T&&i)
			w=0,n++;
	}
	w=0;
	LL A=1,fi=t[1],W=0;
	while(n!=1||fi!=1)
	{
		Ans++;
		if(fi&1)
			fi=fi*3+1,A*=3;
		else
			w++,fi>>=1;
		if(w==T)
		{
			LL Now=fi;
			int i;
			W=max(W,fi);
			for(i=1;i<=n||Now||t[i];i++)
			{
				Now+=t[i+1]*A;t[i]=Now&All;Now>>=T;
			}
			while(!t[n])
				n--;
	//		cout<<n<<endl;
			w=0;A=1;fi=t[1];//B=0;
		}
	}
	printf("%d\n",Ans,clock(),W);
	return 0;
}

