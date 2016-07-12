#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<set>
using namespace std;
int n;
struct E
{
	int x,y;
}p[300051];
int c[300051];
int hash[300051];
int l,r;
bool cmp(E a,E b)
{
	for(int i=a.x;i<=a.y;i++)
	  hash[c[i]]++;
	for(int i=b.x;i<=b.y;i++)
	  hash[c[i]]--;
	int tp=0;
	for(int i=1;i<=n;i++)
	{
	  if(hash[i]>0)
	  {tp=1;break;}
	  if(hash[i]<0)
	  {tp=-1;break;}
    }
	for(int i=1;i<=n;i++)
	  hash[i]=0;
	if(tp==-1)return 0;
	if(tp==0)return a.x<b.x;
	if(tp==1)return 1;
}
void init()
{
	scanf("%d%d%d",&n,&l,&r);
	for(int i=1;i<=n;i++)
	  scanf("%d",&c[i]);
	int tot=1;
	for(int i=1;i<=n;i++)
	  for(int j=i;j<=n;j++,tot++)
	    {p[tot].x=i;p[tot].y=j;}
	int w=n*(n+1)/2;
	sort(p+1,p+w+1,cmp);
	for(int i=l;i<=r;i++)
	  printf("%d %d\n",p[i].x,p[i].y);
}
int main()
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	init();
	return 0;
}
