#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 500010
#define INF 1000000000
using namespace std;
struct node{int x,y;}pre[N];
int n,pos;
int ws[N],wa[N],wb[N],wv[N],sa[N],rank[N],height[N],r[N],f[N][22],log[N];
char s[N];
int cmp(int *r,int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(int *r,int *sa,int n,int m)
{
	int i,j,p,*x=wa,*y=wb,*t;
	for (i=0;i<m;i++) ws[i]=0;
	for (i=0;i<n;i++) ws[x[i]=r[i]]++;
	for (i=1;i<m;i++) ws[i]+=ws[i-1];
	for (i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;
	for (j=1,p=1;p<n;j*=2,m=p)
	{
		for (p=0,i=n-j;i<n;i++) y[p++]=i;
		for (i=0;i<n;i++) if (sa[i]>=j) y[p++]=sa[i]-j;
		for (i=0;i<n;i++) wv[i]=x[y[i]];
		for (i=0;i<m;i++) ws[i]=0;
		for (i=0;i<n;i++) ws[wv[i]]++;
		for (i=1;i<m;i++) ws[i]+=ws[i-1];
		for (i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
		for (t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
}
void calheight(int *r,int *sa,int n)
{
	int i,j,k=0;
	for (i=1;i<=n;i++) rank[sa[i]]=i;
	for (i=0;i<n;height[rank[i++]]=k)
	for (k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
}
int ask(int x,int y)
{
	x++;
	int j=log[y-x+1];
	return min(f[x][j],f[y-(1<<j)+1][j]);
}
int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",s);n=strlen(s);
	for (int i=0;i<n;i++) r[i]=s[i];r[n]=0;
	da(r,sa,n+1,300);
	calheight(r,sa,n);
	for (int i=1;i<=n;i++) f[i][0]=height[i];
	for (int i=1;i<=n;i++)
		for (int j=20;j>=0;j--)if ((1<<j)<=i){log[i]=j;break;}
	for (int j=1;j<=20;j++)
		for (int i=1;i<=n;i++) if (i+(1<<j)-1>n) break;else
		f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
	for (int i=1;i<=n;i++)
	{
		pre[sa[i]].x=-INF;
		for (int j=i-1;j>=1;j--) if (ask(j,i)==0) break;else
		{
			if (pre[sa[i]].x>ask(j,i)) break;else
			{
				if (sa[j]<sa[i]&&(ask(j,i)>pre[sa[i]].x||(ask(j,i)==pre[sa[i]].x&&sa[j]<pre[sa[i]].y)))
				{
					pre[sa[i]].x=ask(j,i);
					pre[sa[i]].y=sa[j];
				}
			}
		}
		for (int j=i+1;j<=n;j++) if (ask(i,j)==0) break;else
		{
			if (pre[sa[i]].x>ask(i,j)) break;else
			{
				if (sa[j]<sa[i]&&(ask(i,j)>pre[sa[i]].x||(ask(i,j)==pre[sa[i]].x&&sa[j]<pre[sa[i]].y)))
				{
					pre[sa[i]].x=ask(i,j);
					pre[sa[i]].y=sa[j];
				}
			}
		}
	}
	pos=0;
	while (pos<n)
	{
		if (pre[pos].x==-INF){printf("-1 %d ",s[pos]);pos++;continue;}
		printf("%d %d ",pre[pos].x,pre[pos].y);
		pos+=pre[pos].x;
	}
}
