#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int K,tot,tot1,num;
struct hugeint
{
	int len,len1,a[50];
	hugeint()
	{
		len=0;len1=0;
		memset(a,0,sizeof(a));
	}
	void print()
	{
		printf("%d",a[len1]);
		for (int i=len1-1;i>=1;i--) printf("%07d",a[i]);printf("\n");
	}
}a[60010],b[60010],Ans[60010];
int operator %(hugeint a,int b)
{
	return a.a[1]%b;
}
hugeint operator /(hugeint a,int b)
{
	int x=0;
	for (int i=a.len1;i>=1;i--)
	{
		int t=x*10000000+a.a[i];
		a.a[i]=t/b;x=t%b;
	}
	while (a.len1>1&&a.a[a.len1]==0) a.len1--;
	return a;
}
bool operator <(hugeint a,hugeint b)
{
	if (a.len<b.len) return 1;
	if (a.len>b.len) return 0;
	for (int i=a.len1;i>=1;i--)
	{
		if (a.a[i]>b.a[i]) return 0;
		if (a.a[i]<b.a[i]) return 1;
	}
	return 1;
}
int judge(int id)
{
	hugeint x=b[id],y=b[id];
	while (x.len1>1||x.a[1]>0)
	{
		if (x%10!=y%2) return 0;
		x=x/10;y=y/2;
	}
	return 1;
}
int judge1(int id)
{
	hugeint x=b[id];int y;
	for (int i=1;i<=b[id].len;i++)
	{
		y=x%2;
		x=x/2;
	}
	return y==0;
}
void add(int id)
{
	int l=b[id].len%7,l1=b[id].len1;
	if (l==0) b[id].a[l1]+=1000000;else
	if (l==1) b[id].a[l1]++;else
	if (l==2) b[id].a[l1]+=10;else
	if (l==3) b[id].a[l1]+=100;else
	if (l==4) b[id].a[l1]+=1000;else
	if (l==5) b[id].a[l1]+=10000;else
	if (l==6) b[id].a[l1]+=100000;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&K);
	a[1].len=a[1].len1=1;a[1].a[1]=0;
	a[2].len=a[2].len1=1;a[2].a[1]=1;
	Ans[++num]=a[2];
	tot=2;
	for (int i=2;i<=500;i++)
	{
		//printf("%d %d\n",i,num);
		//printf("%d\n",i);
		if (num>=K) break;
		tot1=0;
		for (int j=1;j<=tot;j++)
		{
			b[++tot1]=a[j];
			b[tot1].len++;
			if (b[tot1].len%7==1) b[tot1].len1++;
			if (!judge1(tot1)) tot1--;
		}
		//printf("---\n");
		for (int j=1;j<=tot;j++)
		{
			b[++tot1]=a[j];
			b[tot1].len++;
			if (b[tot1].len%7==1) b[tot1].len1++;
			add(tot1);//b[tot1].print();
			if (!judge(tot1)) tot1--;else Ans[++num]=b[tot1];
		}
		//printf("---\n");
		tot=tot1;
		for (int j=1;j<=tot;j++) a[j]=b[j];
	}
	//printf("%d\n",num);
	sort(Ans+1,Ans+num+1);
	//for (int i=1;i<=num;i++) Ans[i].print();
	//for (int i=1;i<=K;i++) Ans[i].print();
	Ans[K].print();
}
