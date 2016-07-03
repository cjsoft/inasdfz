#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int nn,i,j,k,m,n,s,t,n1,y,bo,x,ans,tot,a2,mx,mmx,wmx,ii,kk,k1,n2,i1;
int bin[50];
struct data{
	char x[2500];
	int len;
}a[30][1010],gd,ten[3100],dw[5100],kb;
int tt[3100];
bool cmp(const data &a,const data &b)
{
	if (a.len==b.len)
	{
		for (int i=a.len;i;i--)
		  if (a.x[i]<b.x[i]) return 1; else
		  if (a.x[i]>b.x[i]) return 0;
		return 1;
	} else return a.len<b.len;
}
int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x;
}
data cal(data a,const data &b)
{
	a.len=max(a.len,b.len);
	int i,n=a.len;
	for (i=1;i<=n;i++)
	{
	  a.x[i]+=b.x[i];
	  if (a.x[i]>1)
	  {
	    a.x[i]-=2;
	    a.x[i+1]++;
	  }
    }
    if (a.x[n+1]) a.len++;
   // mx=max(mx,a.len);
    return a;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int tsw=700;
	int dwy=30;
	n=read();
	if (n==1)
	{puts("0");return 0;}
	if (n==2)
	{puts("10");return 0;}
	if (n==3)
	{puts("11");return 0;}
    nn=n&1;
    n>>=1;
    tt[2]=1;
    a[2][1].len=4;
    a[2][1].x[1]=0;
    a[2][1].x[2]=1;
    a[2][1].x[3]=0;
    a[2][1].x[4]=1;
    ten[2]=a[2][1];
    for (i=3;i<=tsw;i++)
    {
      gd.len=ten[i-1].len+1;
      gd.x[1]=0;
      for (j=1;j<=ten[i-1].len;j++)
        gd.x[j+1]=ten[i-1].x[j];
      ten[i]=cal(ten[i],gd);
      gd.len=ten[i-1].len+3;
      gd.x[1]=0;
      gd.x[2]=0;
      gd.x[3]=0;
      for (j=1;j<=ten[i-1].len;j++)
        gd.x[j+3]=ten[i-1].x[j];      
      ten[i]=cal(ten[i],gd);
    }
    tt[2]=0;
    for (i=2;;i++)
    {
    	ii=i%dwy;
    	tt[i]++;
    	a[ii][tt[i]]=ten[i];
    	for (j=1;j<=tt[i];j++)
    	{
    		gd=a[ii][j];
    		for (k=i+1;k<=a[ii][j].len;k++)
    		  if (a[ii][j].x[k]) break; else
    		  {
    		  	if (k>tsw) break;  //!!!
    		  //	wmx=max(wmx,k-i);
    		  	kk=k%dwy;
    		  	tt[k]++;
    		  	k1=tt[k];
    		    a[kk][k1]=cal(gd,ten[k]);
    	/*	     a[kk][k1]=kb;
    		    n2=max(a[ii][j].len,ten[k].len);
    		    for (i1=1;i1<=n2;i1++)
    		    {
    		    	   a[kk][k1].x[i1]=a[ii][j].x[i1]+ten[k].x[i1];
	                   if (a[kk][k1].x[i1]>1)
	                  {
	                   a[kk][k1].x[i1]-=2;
	                   a[kk][k1].x[i1+1]++;
	                  }
    		    }
    		    if (a[kk][k1].x[n2+1]) n2++;
    		    a[kk][k1].len=n2;*/
    		  }
    	}
    //	if (i==tsw) break;  ////!!!
    	tot+=tt[i];
    //	mmx=max(mmx,tt[i]);
    	if (tot>n) break;   ////!!!!!
    }
    ii=i%dwy;
    sort(a[ii]+1,a[ii]+tt[i]+1,cmp);
    j=n-tot+tt[i];
    a[ii][j].x[1]+=nn;
    for (k=i;k;k--)
      printf("%d",a[ii][j].x[k]);
    puts("");
  /*  for (i=tsw;i<=tsw;i++)  ///!!!
    {
      sort(a[i]+1,a[i]+tt[i]+1,cmp);
      for (j=1;j<=tt[i];j++)
      {
      	tot++;
      	printf("%d ",tot);
      	for (k=i;k;k--)
      	  printf("%d",a[i][j].x[k]);
      	puts("");
      	tot++;
      	printf("%d ",tot);
      	a[i][j].x[1]=1;
      	for (k=i;k;k--)
      	  printf("%d",a[i][j].x[k]);
      	puts("");
      }
    }*/
    //  printf("%d %d %d %d %d\n",i,tot*2,mx,mmx,wmx);
}
