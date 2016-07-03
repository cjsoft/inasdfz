#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct node
{
	int num[700],x;
}now,w,tmp,t;
int div()
{
	int i,x=0,len=0;
	for (i=tmp.x;i>=1;i--)
	{
		x=x*10+tmp.num[i];
		if (len || x>=2) t.num[++len]=x/2,x%=2;
	}
	for (i=1;i<=len;i++) tmp.num[i]=t.num[len-i+1];
	tmp.x=len;return x;
}
int calc()
{
	int x=now.x;tmp=now;
	while (x--) div();
	x=now.x+1;
	while (1)
	{
		if (div()) return x;
		x++;
	}
}
bool operator<(node a,node b)
{
	if (a.x!=b.x) return a.x>b.x;
	int i;
	for (i=a.x;i>=1;i--)
	if (a.num[i]!=b.num[i]) return a.num[i]>b.num[i];
}
priority_queue<node> Q;
void print(){for (int i=now.x;i;i--) printf ("%d",now.num[i]);printf ("\n");}
int main()
{
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	int k,l,i;
	scanf ("%d",&k);
	if (k==1){printf ("1");return 0;}
	for (i=2;i<=700;i++) w.num[i-1]=0,w.num[i]=1,w.x=i,Q.push(w);k--;
	while (k)
	{
		now=Q.top();Q.pop();k--;
		if (k==0){print();return 0;}k--;
		if (k==0){now.num[1]=1;print();return 0;}
		l=calc();
		for (i=now.x+1;i<l && i<=700;i++)
		now.num[i]=1,now.x=i,Q.push(now),now.num[i]=0;
	}
	return 0;
}

