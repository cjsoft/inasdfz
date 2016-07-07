#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
int i,j,k,m,n,s,t;
int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x;
}
char ch[50];
struct data{
	int l,r;
}b1[2010],b2[2010];
bool cmp(data a,data b)
{
	return a.r==b.r?a.l<b.l:a.r<b.r;
}
struct dat{
	int s,i;
}a[2010];
int n1,n2,sum,id[2010],now1,now2,fr[2010],bo[2010];
int main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	int T=read();
	while (T--)
	{
		for (i=0;i<=2000;i++)
		  bo[i]=fr[i]=id[i]=0;
		sum=0;
		n1=0;
		n2=0;
		n=read();
		for (i=1;i<=n;i++)
		{
			scanf("%s",ch+1);
			if (ch[1]=='E') a[i].s=1; else a[i].s=2;
			a[i].i=t=read();
			if (t!=0)
			{
		  	  if (a[id[t]].s==a[i].s)
			  {
			  	  if (a[i].s==1)
				    b1[++n1]=(data){id[t],i}; else
				    b2[++n2]=(data){id[t],i};
		      }
		      id[t]=i;
		    }
		}
		sort(b1+1,b1+n1+1,cmp);
		sort(b2+1,b2+n2+1,cmp);
		now1=1;
		now2=1;
		for (i=1;i<=n;i++)
          if (a[i].i==0)
          {
          	 if (a[i].s==2)
          	 {
          	    if (now1>n1) continue;
				if (i>=b1[now1].l&&i<=b1[now1].r) {a[i].i=a[b1[now1].l].i;now1++;} else
				if (i>b1[now1].r) break; 	
          	 } else
          	 {
          	 	if (now2>n2) continue;
          	 	if (i>=b2[now2].l&&i<=b2[now2].r) {a[i].i=a[b2[now2].l].i;now2++;} else
          	 	if (i>b2[now2].r) break;
          	 }
          }
		if (now1>n1&&now2>n2)
		{
		for (i=1;i<=n;i++)
		  if (a[i].i!=0)
		    if (!fr[a[i].i]) fr[a[i].i]=i;
		for (i=1;i<=n;i++)
		  if (a[i].i==0&&a[i].s==1)
		  for (j=i+1;j<=n;j++)
		    if (a[j].i!=0&&a[j].s==2&&fr[a[j].i]==j&&!bo[a[j].i])
		    {
		      a[i].i=a[j].i;
		      bo[a[j].i]=1;
		      break;
		    }
		for (i=1;i<=2000;i++)
		  bo[i]=0;
		for (i=1;i<=n;i++)
		  if (a[i].i==0&&a[i].s==2)
		    for (j=i-1;j;j--)
		      if (a[j].i!=0&&a[j].s==1&&id[a[j].i]==j&&!bo[a[j].i])
		      {
		      	a[i].i=a[j].i;
		      	bo[a[j].i]=1;
		      	break;
		      }
		for (i=1;i<=n;i++)
		  if (a[i].i!=0)
		    id[a[i].i]=i;
		for (i=1;i<=n;i++)
		  {
		  	if (a[i].i==0)
		  	  if (a[i].s==1) sum++; else sum--; else
		  	  if (id[a[i].i]==i&&a[i].s==1) sum++;
		  	sum=max(sum,0);
		  }
		printf("%d\n",max(sum,0));
	    } else puts("OTHER");
	}
}
