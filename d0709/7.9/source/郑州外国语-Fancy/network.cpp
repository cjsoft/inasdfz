#include <cstdio>
const int N=7005;
int n,Q,ecnt,head[N];
long long ans;
struct node{int to,cost,next;}E[N<<1];
int gcd(int x,int y)
{
	return !y?x:gcd(y,x%y);
}
void Dfs(int x,int f,int num)
{
	ans+=(num==1);
	for(int e=head[x],y;e;e=E[e].next)
		if((y=E[e].to)!=f)
			Dfs(y,x,gcd(E[e].cost,num));
}
inline int Calc()
{
	ans=0;
	for(int i=1;i<=n;i++) Dfs(i,0,0);
	return ans>>1;
}
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,x,y,z;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		E[++ecnt]=(node){y,z,head[x]};head[x]=ecnt;
		E[++ecnt]=(node){x,z,head[y]};head[y]=ecnt;
	}
	printf("%d\n",Calc());
	scanf("%d",&Q);
	for(int i=1,x,y;i<=Q;i++)
	{
		scanf("%d%d",&x,&y);
		x<<=1;
		E[x-1].cost=E[x].cost=y;
		printf("%d\n",Calc());
	}
}
