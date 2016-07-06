#include <stdio.h>
#include <stdlib.h>
#define maxn 100000
int e[maxn+10][2],head[maxn+10],father[maxn+10],f[maxn+10],g[maxn+10],a[maxn+10],k,t,n,i;
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
void work1(int x)
{
	int i,y,s0=0,s1=0,s=0;
	if (head[x]==0)
	{
		if (f[x]==-1) a[k++]=x;
		g[x]=-100000;
		return;
	}
	for (i=head[x];i>0;i=e[i][0])
	{
		y=e[i][1];
		work1(y);
		if (f[y]==0) s0++;
		if (f[y]==1) s1++;
		s++;
	}
	if (s0>s1) f[x]=0;
		else if (s0<s1) f[x]=1;
			else f[x]=-1;
	if (s0+s1<s) g[x]=s0-s1;
		else g[x]=-100000;
	return;
}
void work2(int x)
{
	if (head[x]==0)
	{
		a[k++]=x;
		return;
	}
	int i;
	for (i=head[x];i>0;i=e[i][0])
		if ((f[e[i][1]]==-1) || (g[e[i][1]]==-1)) work2(e[i][1]);
	return;
}
int main()
{
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	for (scanf("%d",&t);t>0;t--)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			head[i]=0;
			e[i][0]=0;
		}
		for (i=1;i<=n;i++)
		{
			scanf("%d",&father[i]);
			if (father[i]>0)
			{
				e[i-1][1]=i;
				e[i-1][0]=head[father[i]];
				head[father[i]]=i-1;
			}
		}
		for (i=1;i<=n;i++)
			scanf("%d",&f[i]);
		k=0;
		work1(1);
		if (f[1]==0)
		{
			qsort(a,k,sizeof(a[0]),cmp);
			printf("%d",k);
			for (i=0;i<k;i++)
				printf(" %d",a[i]);
			printf("\n");
		}
		else if (f[1]==1) printf("-1\n");
		else
		{
			k=0;
			work2(1);
			qsort(a,k,sizeof(a[0]),cmp);
			printf("%d",k);
			for (i=0;i<k;i++)
				printf(" %d",a[i]);
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
