#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
#define N 500011
#define lcp(x,y)min(a[lg[y-x]][x+1],a[lg[y-x]][y-(1<<lg[y-x])+1])
using namespace std;char s[N];set<int>se;
int n,rk[N],c[N],xx[N*2],yy[N*2],h[N];
void sa(){int m=300,*x=xx,*y=yy;
	for(int i=1;i<=n;i++)c[x[i]=s[i]]++;
	for(int i=1;i<=m;i++)c[i]+=c[i-1];
	for(int i=n;i;i--)rk[c[x[i]]--]=i;
	for(int k=1;k<=n;k<<=1){int p=0;
		for(int i=n-k+1;i<=n;i++)y[++p]=i;
		for(int i=1;i<=n;i++)if(rk[i]>k)y[++p]=rk[i]-k;
		for(int i=1;i<=m;i++)c[i]=0;
		for(int i=1;i<=n;i++)c[x[y[i]]]++;
		for(int i=1;i<=m;i++)c[i]+=c[i-1];
		for(int i=n;i;i--)rk[c[x[y[i]]]--]=y[i];
		y[rk[1]]=p=1;for(int i=2;i<=n;i++)
			y[rk[i]]=p+=x[rk[i]]^x[rk[i-1]]||x[rk[i]+k]^x[rk[i-1]+k];
		swap(x,y);if((m=p)==n)break;
	}
	for(int i=1;i<=n;i++)c[i]=x[i];
	for(int i=1,k=0;i<=n;h[c[i++]]=k)
		for(k?k--:k;s[i+k]==s[rk[c[i]-1]+k];k++);
}
int lg[N],a[20][2*N],b[20][2*N];
int fd1(int p,int i,int z){int l=1,r=p,m;
	while(l^r)m=l+r>>1,lcp(m,i)<z?l=m+1:r=m;
	return m=lg[p-l+1],min(b[m][l],b[m][p-(1<<m)+1]);}
int fd2(int p,int i,int z){int l=p,r=n,m;
	while(l^r)m=l+r+1>>1,lcp(i,m)<z?r=m-1:l=m;
	return m=lg[l-p+1],min(b[m][p],b[m][l-(1<<m)+1]);}
int main(){
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",s+1);n=strlen(s+1);sa();
	for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)a[0][i]=h[i],b[0][i]=rk[i];
	for(int k=1;k<=lg[n];k++)for(int i=1;i<=n+1;i++)
		a[k][i]=min(a[k-1][i],a[k-1][i+(1<<k-1)]),
		b[k][i]=min(b[k-1][i],b[k-1][i+(1<<k-1)]);
	se.insert(0);se.insert(n+1);
	for(int i=1;i<=n;){
		set<int>::iterator it=se.lower_bound(c[i]);
		int v=*it,u=*--it,x=lcp(u,c[i]),y=lcp(c[i],v);
		if(!x&&!y)printf("-1 %d ",s[i]);
		else if(x==y)printf("%d %d ",x,min(fd1(u,c[i],x),fd2(v,c[i],y))-1);
		else printf("%d %d ",max(x,y),x>y?(fd1(u,c[i],x)-1):(fd2(v,c[i],y)-1));
		for(int j=1;j<=max(1,max(x,y));j++)se.insert(c[i++]);
	}
	return 0;
}
