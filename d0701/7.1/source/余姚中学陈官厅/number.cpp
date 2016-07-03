#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define P 100000000
using namespace std;
typedef long long ll;
struct Big{
	int bit[100];
};
ll mi[100];
int num,a[300],k,i,L;
Big A[10005];
void print(Big x)
{
	//for (int i=0;i<=x.bit[0];i++)printf("%d ",x.bit[i]);puts("");
	printf("%d",x.bit[x.bit[0]]);
	int i,xx;
	for (i=x.bit[0]-1;i>0;i--)
	{
		xx=P/10;
		while (xx)
		{
			printf("%d",x.bit[i]/xx);
			x.bit[i]%=xx;xx/=10;
		}
	}
	puts("");
}
void clear(Big &x)
{
	for (i=0;i<=64;i++)
		x.bit[i]=0;
}
Big operator * (Big a,int b)
{
	//printf("A ");print(a);printf("B %d\n",b);
	for (int i=1;i<=a.bit[0];i++)
		a.bit[i]*=b;
	int now=1;
	while (a.bit[now]>P)
	{
		a.bit[now+1]+=a.bit[now]/P;
		a.bit[now]%=P;
		now++;
	}
	while (a.bit[a.bit[0]+1]>0)
		a.bit[0]++;
	//print(a);
	return a;
}
Big operator + (Big a,int b)
{
	a.bit[1]+=b;
	int now=1;
	while (a.bit[now]>P)
	{
		a.bit[now]-=P;
		now++;
		a.bit[now]++;
	}
	while (a.bit[a.bit[0]+1]>0)
		a.bit[0]++;
	return a;
}
bool cmp (Big a,Big b)
{
	//print(a);print(b);
	if (a.bit[0]<b.bit[0])return 1;
	if (a.bit[0]>b.bit[0])return 0;
	for (int i=a.bit[0];i;i--)
	{
		if (a.bit[i]<b.bit[i])return 1;
		if (a.bit[i]>b.bit[i])return 0;
	}
	return 1;
}
int judge()
{
	//puts("?");
	//printf("%d %d\n",a[0],a[1]);
	Big x;
	int i;
	for (i=0;i<=64;i++)
		x.bit[i]=0;
	ll mod=mi[a[0]],now=0,sum=0;
	for (i=a[0];i;i--)
	{
		now=now*10%mod+a[i];
		sum=sum*2+a[i];
	}
	//printf("%lld %lld\n",now,sum);
	if (now!=sum)return 0;
	if (a[a[0]]==1)
	{
		//printf("%d %d\n",a[0],a[1]);
		//print(x);
		//puts("OK");
		//for (i=a[0];i;i--)printf("%d",a[i]);puts("?");
		for (i=a[0];i;i--)
			x=x*10+a[i];
		//print(x);
		num++;
		A[num]=x;
	}
	return 1;
}
void dfs()
{
	if (a[0]>L)return;
	if (a[0]!=0 && !judge())return;
	a[++a[0]]=1;
	dfs();
	a[a[0]]=0;
	dfs();
	a[0]--;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for (mi[0]=1,i=1;i<=62;i++)mi[i]=mi[i-1]*2;
	L=62;
	scanf("%d",&k);
	a[0]=0;
	dfs();
	printf("%d\n",num);
	//for (i=1;i<=num;i++)print(A[i]);
	//return 0;
	sort(A+1,A+1+num,cmp);
	print(A[k]);
}
