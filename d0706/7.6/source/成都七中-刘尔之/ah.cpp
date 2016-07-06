#include<cstdio>
#include<vector>
#include<algorithm>
#define N 100001

std::vector<int>g[N];
int t,n,s[N],p[N],c[N],z[N],a[N];
int main(){
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	for(scanf("%d",&t);t--;printf("\n")){
		scanf("%d",&n);p[0]=a[0]=0;
		for(int i=1;i<=n;i++)g[i].clear(),z[i]=0;
		for(int i=1,x;i<=n;i++)scanf("%d",&x),
			x?(g[x].push_back(i),0):0;
		for(int i=1;i<=n;i++)scanf("%d",&c[i]),
			c[i]=c[i]^1?c[i]^-1:c[i];
		for(s[s[0]=1]=1;s[0];){int u=s[s[0]--];p[++p[0]]=u;
			for(int i=0;i<g[u].size();i++)s[++s[0]]=g[u][i];}
		for(int ii=n;ii;ii--){int u=p[ii];
			for(int i=0;i<g[u].size();i++)
				c[u]+=c[g[u][i]]>0?1:c[g[u][i]]<0?-1:0;}
		if(c[1]>0){printf("-1\n");continue;}
		if(c[1]<0){for(int i=1;i<=n;i++)
			if(!g[i].size()&&!c[i])a[++a[0]]=i;}
		else for(s[s[0]=1]=1;s[0];){
			int u=s[s[0]--];if(!g[u].size()&&!c[u])a[++a[0]]=u;
			for(int i=0;i<g[u].size();i++)if(!c[g[u][i]]||c[g[u][i]]==1)
				s[++s[0]]=g[u][i];}std::sort(a+1,a+a[0]+1);
		for(int i=0;i<=a[0];i++)printf("%d ",a[i]);
	}
}
