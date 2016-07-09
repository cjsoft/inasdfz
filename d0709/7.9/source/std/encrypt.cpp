#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=500010;
struct node
{
	node *ch[26],*pre;
	int step,leftmost;
}pool[MAXN<<1],*root,*last,*cur=pool;
char str[MAXN];
inline void extend(int k,int id)
{
	node *u=cur++,*p=last;
	u->step=p->step+1,u->leftmost=id;
	for(;p&&!p->ch[k];p=p->pre)p->ch[k]=u;
	if(!p)u->pre=root;
	else
	{
		node *q=p->ch[k];
		if(p->step+1==q->step)u->pre=q;
		else
		{
			node *v=cur++;
			*v=*q;
			v->step=p->step+1;
			u->pre=q->pre=v;
			for(;p&&p->ch[k]==q;p=p->pre)p->ch[k]=v;
		}
	}
	last=u;
}
inline void solve()
{
	for(int i=0;str[i];)
	{
		node *u=root;
		int len=0;
		while(str[i]&&u->ch[str[i]-'a'])
		{
			u=u->ch[str[i]-'a'];
			len++;
			extend(str[i]-'a',i);
			i++;
		}
		if(len)printf("%d %d ",len,u->leftmost-len+1);
		else
		{
			extend(str[i]-'a',i);
			printf("-1 %d ",str[i++]);
		}
	}
	printf("\n");
}
inline void init()
{
	last=root=cur++;
	scanf("%s",str);
}
int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	init();
	solve();
    return 0;
}
