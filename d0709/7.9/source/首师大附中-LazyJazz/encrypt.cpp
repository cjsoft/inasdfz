#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 500050
#define val(x) ((x)>=len?0:A[x])
using namespace std;
char str[MAXN];
int A[MAXN],B[MAXN],match[MAXN];
struct Adjacency_List
{
	int first[MAXN],next[MAXN],value[MAXN],cnt_Edge=1;
	void AddEdge(int u,int v)
	{
		value[cnt_Edge]=v;
		next[cnt_Edge]=first[u];
		first[u]=cnt_Edge++;
	}
	void Reset()
	{
		cnt_Edge=1;
		memset(first,0,sizeof(first));
	}
}adj_first,adj_second;
int suffix_array(char *s)
{
	int len=strlen(s),colorcnt=0,floor=1;
	for(int i=0;i<len;i++)B[s[i]]=1;
	for(int i=1;i<256;i++)B[i]+=B[i-1],colorcnt=B[i];
	for(int i=0;i<len;i++)A[i]=B[s[i]];
	while(colorcnt<len)
	{
		adj_first.Reset();adj_second.Reset();
		for(int i=0;i<len;i++)adj_second.AddEdge(val(i+floor),i);
		for(int i=colorcnt;i>=0;i--)
			for(int j=adj_second.first[i];j;j=adj_second.next[j])
				adj_first.AddEdge(A[adj_second.value[j]],adj_second.value[j]);
		int lastf=0,lasts=0,cntp=0;
		for(int i=0;i<=colorcnt;i++)
			for(int j=adj_first.first[i];j;j=adj_first.next[j])
			{
				int v=adj_first.value[j];
				if(A[v]==lastf&&val(v+floor)==lasts)B[v]=cntp;
				else B[v]=++cntp;
				lastf=A[v];
				lasts=val(v+floor);
			}
		colorcnt=cntp;
		for(int i=0;i<len;i++)A[i]=B[i];
		floor<<=1;
	}
	for(int i=0;i<len;i++)B[A[i]]=i;
	for(int i=0,k=0;i<len;i++)
	{
		if(k)k--;if(A[i]==len)continue;
		int j=B[A[i]+1];
		while(s[i+k]==s[j+k])k++;
		match[A[i]]=k;
	}
}
void write(int x)
{
	int n[10],p=0;
	while(x)n[p++]=x%10,x/=10;
	for(int i=p-1;i>=0;i--)putchar(n[i]+'0');putchar(' ');
}
int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",str);int n=strlen(str);
	suffix_array(str);
	int p=0;
	while(p<n)
	{
		bool got=0;
		int start=0,last=0;
		for(int i=A[p],m=match[i];m;i++,m=min(m,match[i]))
		{
			//if(p==10)printf("%d %d %d %d\n",m,B[i+1],last,start);
			if(m<last)break;
			if(B[i+1]<p)
			{
				if(!got||B[i+1]<start)
				{
					got=1;
					start=B[i+1];
					last=m;
				}
			}
		}
		for(int i=A[p]-1,m=match[i];m;i--,m=min(m,match[i]))
		{
			//if(p==10)printf("%d %d %d %d\n",m,B[i],last,start);
			if(m<last)break;
			if(B[i]<p)
			{
				if(!got||B[i]<start||m>last)
				{
					got=1;
					start=B[i];
					last=m;
				}
			}
		}
		if(got)
		{
			//printf("%d %d ",last,start);
			write(last);write(start);
			p+=last;
		}
		else
		{
			putchar('-');
			putchar('1');
			putchar(' ');
			write(str[p]);
			//printf("-1 %d ",(int)str[p]);
			p++;
		}
	}
}
