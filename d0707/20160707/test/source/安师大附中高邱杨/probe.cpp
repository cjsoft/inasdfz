#include <bits/stdc++.h>
using namespace std;

const int N=2005;
int T,n,m;
int tong[N],gg[N],usd[N],lev[N];
bool ok;
struct code
{
	char tp;
	int id,tm;
}a[N],b[N];
pair<int,int> pr[N];
int spr;
struct Q
{
	int fr,ed;
	int x[N];
	void init(){fr=1;ed=0;}
	bool empty(){if(fr<=ed)return 0;return 1;}
	int front(){if(empty())return -1;return x[fr];}
	void push(int p){x[++ed]=p;}
	void pop(){if(!empty())x[ed--]=0;}
	void delfr(){if(!empty())x[fr++]=0;}
	int siz(){return ed-fr+1;}
	int getxmax(int k)
	{
		if(empty())return -1;
		if(x[ed]<k)return -1;
		for(int i=fr;i<=ed;i++)
		    if(x[i]>k)
			    return i;
	}
	void del(int k){if(empty())return ;for(int i=k;i<ed;i++)x[i]=x[i+1];x[ed--]=0;}
};

int main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	scanf("%d",&T);
	int i,j,k,ans;
	while(T--)
	{
		memset(lev,0,sizeof(lev));
		memset(tong,0,sizeof(tong));
		memset(usd,0,sizeof(usd));
		memset(gg,0,sizeof(gg));
		scanf("%d",&n);
		m=0;ok=1;ans=0;spr=0;
		Q E,L;
		E.init();L.init();
		for(i=1;i<=n;i++)
		    scanf("\n%c %d",&a[i].tp,&a[i].id),a[i].tm=i;
		for(i=1;i<=n;i++)
		    for(j=i+1;j<=n;j++)
		        if(a[i].tp=='E'&&a[j].tp=='L'&&a[i].id==a[j].id&&a[i].id&&!gg[i]&&!gg[j])
		        {
		        	gg[i]=gg[j]=1;
		        	pr[++spr]=make_pair(i,j);
		        }
		for(i=1;i<=n;i++)
		    if(!gg[i])
		        b[++m]=a[i];
		for(i=1;i<=m;i++)
		{
		    if(b[i].tp=='E')
		    {
		    	if(b[i].id==0)
		    	    E.push(b[i].tm);
		    	else
		    	{
		    		if(tong[b[i].id])
		    		{
		    			k=L.getxmax(tong[b[i].id]);
		    			if(k==-1)
		    			{
    		    			ok=0;
		    			    break;
		    		    }
		    		    L.del(k);
		    		}
		    		else
		    		    tong[b[i].id]=b[i].tm;
		    	}
		    }
		    else if(b[i].tp=='L')
		    {
		    	if(b[i].id)
		    	{
		    		if(tong[b[i].id])
		    		    tong[b[i].id]=0;
		    		else
						if(!E.empty())
		    				E.pop();
		    		    else 
						    if(!lev[b[i].id])
							    lev[b[i].id]=1;
		    				else
		    				{
		    					ok=0;
		    					break;
		    				}
		    	}
		    	else
		    	    L.push(b[i].tm);
		    }
		}
		if(!ok)
		{
			printf("OTHER\n");
			continue;
		}
		if(E.siz()*L.siz())
		{
		    for(i=E.ed;i>=E.fr;i--)
		        for(j=L.fr;j<=L.ed;j++)
		            if(E.x[i]<L.x[j])
		            {
		            	E.del(i);
		            	L.del(j);
		            	i++;
		            	j--;
		            }
		}
		for(i=L.fr;i<=L.ed;i++)
		{
			j=L.x[i];
			for(i=0;i<N;i++)
			{
			    if(tong[i]&&tong[i]<j)
			    {
			    	tong[i]=0;
			    	L.del(i);
			    	i--;
			    	break;
			    }
			}
		}
		if(E.siz()*L.siz())
		{
			for(i=1;i<=spr;i++)
			{
				ok=1;
				for(j=L.fr;j<=L.ed&&ok;j++)
				    for(k=E.ed;k>=E.fr&&ok;k--)
				        if(pr[i].first<L.x[j]&&L.x[j]<E.x[k]&&E.x[k]<pr[i].second)
				        {
				        	ok=0;
				        	L.del(j);
				        	E.del(k);
				        }
			}
		}
		for(i=0;i<N;i++)if(tong[i])ans++;
		ans+=E.siz();
		printf("%d\n",ans);
	}
	return 0;
}

