#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=1500010;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,x,y,z,tot[N];
ll A[N],B[N],s[N],sum;
void dfs(int x,int s,int ss,int cnt)
{
	if(x>=m)
	{
		if(cnt%2||s==0) return;
		//printf("%d %d %d\n",s,ss,cnt);
		A[s]+=B[ss];
	//	tot[s]++;
		return;
	}
	int a=(1<<x);
//	if(!a) printf("a:%d\n",a);
	dfs(x+1,s,ss,cnt);
	if(ss&a) dfs(x+1,s+a,ss,cnt);
	else dfs(x+1,s+a,ss,cnt+1);
}
int main()
{
	int a,b,c,i,j;
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	n=read();
	m=0;
	while((1<<m)<n) m++;
	//printf("%d\n",m);
	for(i=0;i<n;i++)
		B[i]=read();
	for(i=0;i<n-1;i++)
		A[0]+=B[i];
	A[0]-=B[n-1]*(n/2-1);
	A[0]/=(n/2);
	for(i=0;i<n-1;i++)
		dfs(0,0,i,0);
//	for(i=1;i<=n-1;i++)
//		printf("%d\n",A[i]);
	for(i=1;i<=n-1;i++)
	{
		A[i]-=(ll)B[n-1]*(n/4-1)+A[0]*n/4;
		A[i]/=n/4;
	}
//	for(i=0;i<n;i++)
//		printf("%d\n",tot[i]);
	//printf("%lld\n",A[1]);
	for(i=0;i<=n-1;i++)
		printf("%lld ",A[i]);
}
