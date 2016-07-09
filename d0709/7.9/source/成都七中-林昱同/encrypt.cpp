#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using std::min;
using std::max;
/*
namespace data
{
	const int INF=1e7;
	struct node
	{
		node *ls,*rs;
		int key;
		int value;
		int pos,minpos;
		int h,minh;
	};
	
	node u[1000000];
	int cntu=-1;
	node* new_node()
	{
		cntu++;
		u[cntu].key=rand();
		return u+cntu;
	}
	
	void update(node *p)
	{
		p->minpos=p->minh=INF;
		if(p->ls)
		{
			if(p->ls->minpos<p->minpos)
				p->minpos=p->ls->minpos;
			if(p->ls->minh<p->minh)
				p->minh=p->ls->minh;
		}
		if(p->rs)
		{
			if(p->rs->minpos<p->minpos)
				p->minpos=p->rs->minpos;
			if(p->rs->minh<p->minh)
				p->minh=p->rs->minh;
		}
		return;
	}
	
	void split(node *p,node *&ls,node *&rs)
	{
		if(p==NULL)
		{
			ls=rs=NULL;
			return;
		}
	}
	
}
*/
namespace solution
{
	int count[1000000];
	void asort(int *v,int *a,int *b,int n)
	{
		memset(count,0,sizeof(count));
		int ma=0;
		for(int i=1;i<=n;i++)
			count[v[a[i]]]++;
		for(int i=1;i<=n;i++)
			if(v[a[i]]>ma)
				ma=v[a[i]];
		for(int i=1;i<=ma;i++)
			count[i]+=count[i-1];
		for(int i=n;i>=1;i--)
			b[count[v[a[i]]]--]=a[i];
	}

	
	int sa[1000000],rank[1000000];
	int a[1000000],b[1000000];
	int height[1000000];
	void getsa(char *s,int n)
	{
		for(int i=1;i<=n;i++)
		{
			rank[i]=i;
			a[i]=s[i];
		}
		asort(a,rank,sa,n);
		rank[sa[1]]=1;
		for(int i=2;i<=n;i++)
			rank[sa[i]]=(s[sa[i]]!=s[sa[i-1]]?1:0)+rank[sa[i-1]];
		for(int i=1;i<=n;i<<=1)
		{
			for(int j=1;j<=n;j++)
			{
				a[j]=rank[sa[j]];
				b[j]=j+i<=n?rank[sa[j+i]]:0;
			}
			asort(b,sa,rank,n);
			asort(a,rank,sa,n);
			rank[sa[1]]=1;
			for(int j=2;j<=n;j++)
				rank[sa[j]]=((a[sa[j]]!=a[sa[j-1]]||b[sa[j]]!=b[sa[j-1]])?1:0)+rank[sa[j-1]];
		}
		return;
	}
	
	char s[1000000];
	void getheight(int n)
	{
		for(int p=0,i=1;i<=n;i++)
		{
			p++;
			while(s[sa[i]+p]!=s[sa[i-1]+p])
				p--;
			height[i]=p;
		}
		return;
	}

	struct num
	{
		int maxp;
		int len;
	};
	num st[1000000];
	int top;
	int ans1[600000],ans2[600000];
	
	void solve()
	{
		scanf("%s",s+1);
		int l=strlen(s+1);
		getsa(s,l);
		getheight(l);
		top=0;
		for(int i=1;i<=l;i++)
		{
			bool have=0;
			num whi;
			if(top>=1)
			{
				for(int j=top;j>=1;j--)
				{
					if(st[j].maxp<sa[i])
					{
						have=1;
						whi=st[j];
						break;
					}
				}	
			}
			if(!have)
			{
				if(!ans1[sa[i]]||ans1[sa[i]]==-1)
				{
					ans1[sa[i]]=-1;
					ans2[sa[i]]=s[sa[i]];
				}
			}
			else
			{
				int n1=min(whi.len,height[i]);
				int n2=whi.maxp;
				if(ans1[sa[i]]<n1||(ans1[sa[i]]==n1&&ans2[sa[i]]>n2))
				{
					ans1[sa[i]]=n1;
					ans2[sa[i]]=n2;
				}
			}
			num add;
			add.maxp=sa[i];
			add.len=height[i];
			while(top>=1&&st[top].len>add.len)
			{
				add.maxp=max(st[top].maxp,add.maxp);
				top--;
			}
			st[++top]=add;
		}
		for(int i=l;i>=1;i--)
		{
			bool have=0;
			num whi;
			if(top>=1)
			{
				for(int j=top;j>=1;j--)
				{
					if(st[j].maxp<sa[i])
					{
						have=1;
						whi=st[j];
						break;
					}
				}	
			}
			if(!have)
			{
				if(!ans1[sa[i]]||ans1[sa[i]]==-1)
				{
					ans1[sa[i]]=-1;
					ans2[sa[i]]=s[sa[i]];
				}
			}
			else
			{
				int n1=min(whi.len,height[i]);
				int n2=whi.maxp;
				if(ans1[sa[i]]<n1||(ans1[sa[i]]==n1&&ans2[sa[i]]>n2))
				{
					ans1[sa[i]]=n1;
					ans2[sa[i]]=n2;
				}
			}
			num add;
			add.maxp=sa[i];
			add.len=height[i];
			while(top>=1&&st[top].len>add.len)
			{
				add.maxp=max(st[top].maxp,add.maxp);
				top--;
			}
			st[++top]=add;
		}
		for(int i=1;i<=l;)
		{
			if(ans1[i]==-1)
			{
				printf("%d %d ",ans1[i],ans2[i]);
				i++;
			}
			else
			{
				printf("%d %d ",ans1[i],ans2[i]-1);
				i+=ans1[i];
			}
		}
		return;
	}
}

namespace baoli
{
	char s[1000000];
	void solve()
	{
		int l;
		scanf("%s",s);
		l=strlen(s);
		for(register int i=0;i<l;)
		{
			register int maxl=0,w;
			for(register int j=0;j<i;j++)
			{
				register int l=0;
				while(s[i+l]==s[j+l])
				{
					l++;
				}
				if(l>maxl)
				{
					w=j;
					maxl=l;
				}
			}
			if(maxl!=0)
			{
				printf("%d %d ",maxl,w);
				i+=maxl;
			}
			else
			{
				printf("%d %d ",-1,s[i]);
				i++;
			}
		}
	}
}

int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	baoli::solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
