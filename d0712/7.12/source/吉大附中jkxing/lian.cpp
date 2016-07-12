#include <bits/stdc++.h>
using namespace std;
#define BASE 13131
int c[2005][2005];
unsigned int hsh[2005][2005];
struct node{int id,len;}tmp;
bool operator <(const node &a,const node &b)
{
	int len=min(a.len,b.len),pos=0;
    unsigned int *x=hsh[a.id],*y=hsh[b.id];
    for(int i=10;i>=0;i--) 
    if(pos+(1<<i)<=len&&x[pos+(1<<i)]==y[pos+(1<<i)]) pos+=(1<<i);
    if(pos<len) return c[a.id][pos+1]<c[b.id][pos+1];
	if(a.len==b.len) return a.id<b.id;
	return a.len>b.len;
}
node pq[2005];
int n,p,q,a[2005],l[100005],r[100005],top;
int main()
{
    freopen("lian.in","r",stdin);
    freopen("lian.out","w",stdout);
    cin>>n>>p>>q;
    for(int i=1;i<=n;i++) 
    {
    	scanf("%d",a+i);
    	pq[i].id=i;pq[i].len=1;
    	c[i][1]=hsh[i][1]=a[i];
    }
    make_heap(pq+1,pq+n+1);
    if(n>2000){puts("wa");return 0;}
    for(int cnt=n,i=1;i<=n*(n+1)/2-p+1;i++)
    {
    	tmp=pq[1];
    	pop_heap(pq+1,pq+cnt+1);
    	if(i>n*(n+1)/2-q) 
    	{
    		l[++top]=tmp.id;
    		r[top]=tmp.id+tmp.len-1;
    	}
    	if(tmp.id+tmp.len<=n)
    	{
    		int x=a[tmp.id+tmp.len];
    		for(int j=1;j<=tmp.len+1;j++)
    		if(j==tmp.len+1||c[tmp.id][j]>x)
    		{
    			for(int k=tmp.len+1;k>j;k--) c[tmp.id][k]=c[tmp.id][k-1];
    			c[tmp.id][j]=x;tmp.len++;
                for(int k=j;k<=tmp.len;k++) hsh[tmp.id][k]=hsh[tmp.id][k-1]*BASE+c[tmp.id][k];
                break;
    		}
    		pq[cnt]=tmp;
    		push_heap(pq+1,pq+cnt+1);
    	}
    	else cnt--;
    }
    for(int i=top;i;i--) printf("%d %d\n",l[i],r[i]);
}
