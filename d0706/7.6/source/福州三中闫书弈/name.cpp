#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<map>
using namespace std;
int n,m,t,a[100010],b[100010],c[100010],l[100010],r[100010],w[100010],x[300010],f[300010],p,g[100010],d[100010],e[100010],q;
long long ans;
map<int,int> h;
struct orz
{
	int a,b;
	double c;
}u[300010],v[200010];
inline bool cmp(orz a,orz b)
{
	return a.c<b.c;
}
inline bool cmp2(int a,int b)
{
	return e[a]<e[b];
}
inline bool cmp3(orz a,orz b)
{
	return a.c>b.c;
}
int read()
{
	int s=0,f=1;
	char x;
	for(x=getchar();(x<'0' || x>'9') && x!='-';x=getchar());
	if(x=='-')
	  f=-1;
	else
	  s=x-'0';
	for(x=getchar();x>='0' && x<='9';x=getchar())
	  s=(s<<3)+(s<<1)+x-'0';
	return s*f;
}
inline void add(int i,int j,int k,int l,int r,int x)
{
	//cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<r<<"\n";
	//system("pause");
	if(l<=j && k<=r)
	  f[i]+=x;
	else
	  {
	   if(l<=(j+k>>1))
	     add(i<<1,j,j+k>>1,l,r,x);
	   if(r>(j+k>>1))
	     add((i<<1)|1,(j+k>>1)+1,k,l,r,x);
	  }
}
inline int ask(int i,int j,int k,int x)
{
	if(j==k)
	  return f[i];
	if(x<=(j+k>>1))
	  return f[i]+ask(i<<1,j,j+k>>1,x);
	else
	  return f[i]+ask((i<<1)|1,(j+k>>1)+1,k,x);
}
inline void half(int lm,int rm,int ln,int rn)
{
	//cout<<lm<<" "<<rm<<" "<<ln<<" "<<rn<<"\n";
	int i,mm=(lm+rm>>1),q,q2=(rn-ln+1);
	if(lm==rm)
	  {
	   for(i=ln;i<=rn;i++)
	     d[g[i]]=lm;
	   return;
	  }
	q=rm-mm;
	for(i=1;i<=q;i++)
	  {
	   u[i].a=l[mm+i];
	   u[i].b=r[mm+i];
	   u[i].c=w[mm+i];
      }
    for(i=ln;i<=rn;i++)
      {
       u[q+i-ln+1].a=i;
       u[q+i-ln+1].b=1;
       u[q+i-ln+1].c=a[g[i]]-0.5;
       u[q+i-ln+1+q2].a=i;
       u[q+i-ln+1+q2].b=-1;
       u[q+i-ln+1+q2].c=b[g[i]]-0.5;
       e[g[i]]=0;
      }
    q+=2*q2;
    sort(u+1,u+q+1,cmp);
    for(i=1;i<=q;i++)
      if(fabs(u[i].c-int(u[i].c))<0.1)
      {
       // cout<<i<<"^\n";
        add(1,1,p,u[i].a,u[i].b,1);
      }
      else
      {
        //cout<<i<<" "<<u[i].a<<"&\n";
        e[g[u[i].a]]+=u[i].b*ask(1,1,p,g[u[i].a]);
    }
    for(i=1;i<=q;i++)
      if(fabs(u[i].c-int(u[i].c))<0.1)
        add(1,1,p,u[i].a,u[i].b,-1);
    //for(i=ln;i<=rn;i++)
    //  cout<<e[g[i]]<<"\n";
    sort(g+ln,g+rn+1,cmp2);
    for(i=ln;i<=rn;i++)
      if(e[g[i]])
        break;
    if(i>ln)
      half(lm,mm,ln,i-1);
    if(i<=rn)
      half(mm+1,rm,i,rn);
}
inline void cdq(int L,int R)
{
	if(L==R)
	  return;
	int i,j,m=(L+R>>1),q=0;
	for(i=L;i<=m;i++)
	  if(u[i].a)
	    {
	     v[++q]=u[i];
	     v[q].c=w[u[i].b];
	    }
	for(i=m+1;i<=R;i++)
	  if(!u[i].a)
	    {
	     v[++q]=u[i];
	     v[q].c=a[u[i].b]-0.5;
	    }
	sort(v+1,v+q+1,cmp3);
	for(i=1;i<=q;i++)
	  if(v[i].a)
	    add(1,1,p,l[v[i].b],r[v[i].b],1);
	  else
	    e[v[i].b]+=ask(1,1,p,v[i].b);
	for(i=1;i<=q;i++)
	  if(v[i].a)
	    add(1,1,p,l[v[i].b],r[v[i].b],-1);
	cdq(L,m);
	cdq(m+1,R);
}
int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	int i,j;
	n=read();
	for(i=1;i<=n;i++)
	  a[i]=read();
	for(i=1;i<=n;i++)
	  {
	   b[i]=read();
	   if(b[i]>a[i])
	     swap(a[i],b[i]);
	   else
	     c[i]=1;
	   x[++t]=a[i];
	   x[++t]=b[i];
	  }
	m=read();
	for(i=1;i<=m;i++)
	  {
	   l[i]=read();
	   r[i]=read();
	   w[i]=read();
	   x[++t]=w[i];
      }
    sort(x+1,x+t+1);
    for(i=1,j=0;i<=t;i++)
      if(!j || x[i]>x[j])
        x[++j]=x[i];
    t=j;
    for(i=1;i<=t;i++)
      h[x[i]]=i;
    for(i=1;i<=n;i++)
      {
       a[i]=h[a[i]];
       b[i]=h[b[i]];
      }
    for(i=1;i<=m;i++)
      w[i]=h[w[i]];
    for(p=1;p<n;p<<=1);
    for(i=1;i<=n;i++)
      g[i]=i;
    half(0,m,1,n);
    for(i=1;i<=n;i++)
      {
       if(d[i])
         c[i]=1;
       u[i].a=0;
       u[i].b=i;
       u[i].c=d[i]+0.5;
       e[i]=0;
      }
    for(i=1;i<=m;i++)
      {
       u[i+n].a=1;
       u[i+n].b=i;
       u[i+n].c=i;
      }
    sort(u+1,u+n+m+1,cmp3);
    cdq(1,n+m);
    for(i=1;i<=n;i++)
      {
       c[i]^=(e[i]&1);
       if(c[i])
       {
         ans+=x[a[i]];
         //cout<<i<<" "<<a[i]<<" "<<c[i]<<" "<<e[i]<<" "<<d[i]<<"\n";
     }
       else
       {
         ans+=x[b[i]];
        // cout<<i<<" "<<b[i]<<"\n";
     }
      }
    cout<<ans<<"\n";
	return 0;
}
