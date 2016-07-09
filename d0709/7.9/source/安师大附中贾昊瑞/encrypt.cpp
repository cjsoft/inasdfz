#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<deque>
#include<vector>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define F(i,j,n) for(int i=j;i<=n;i++)
#define D(i,j,n) for(int i=j;i>=n;i--)
#define ll long long
using namespace std;
void in(int&a);void in(ll&a);
int f[100010];char s[100010];int a[200020],n,p;
void getFail(char* P)
{
	int m = strlen(P);
	f[0] = 0;
	f[1] = 0;
	for(int i = 1; i < m; i++)
	{
		int j = f[i];
		while(j && P[i] != P[j])
		{
			j = f[j];
		}
		f[i + 1]=P[i]==P[j]?j+1:0;
	}
}

int find(char* T, int x)
{
	char*P=T+x;
	register int m = strlen(P),j = 0,i,mx=0;
	getFail(P);
//	for(i=0;i<m;i++)printf("%c %d\n",P[i],f[i]);
	for(i= 0; i < n; i++)
	{
		while(j && P[j] != T[i])
			j = f[j];
		if(P[j] == T[i])j++;
//		printf("%d %d\n",i,j);
		if(j>mx&&i-j+1<x)mx=j,p=i-mx+1;
	}
	return mx;
}
int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	gets(s);int i,j,m=0;n=strlen(s);
	for(i=0;i<n;){
	j=find(s,i);
	if(j==0){a[m++]=-1;a[m++]=s[i];i++;}
	else {a[m++]=j;a[m++]=p;i+=j;}//printf("%d\n",i);
	}
	for(i=0;i<m;i++)printf("%d ",a[i]);
	return 0;
}
void in(ll&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=getchar();}if(y)a=-a;}
void in(int&a){register char c;register bool y=false;c=getchar();a=0;
while(c<'0'||c>'9'){if(c=='-'){c=getchar();y=true;break;}c=getchar();}
while(c>='0'&&c<='9'){a=(a<<3)+(a<<1)+c-'0';c=getchar();}if(y)a=-a;}
