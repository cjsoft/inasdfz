#include <stdio.h>
#include <iostream>
#include <string.h>
#include <set>
using namespace std;
const int N=500010,inf=1000000;
char a[N];
int sa[N],rank[N],ht[N],c[N],lg2[N],f[N][20],mn[N][20],pw[N];
struct A{int id,v[2];}p[N],p2[N];
int n;
void init(){
	int i,j,k,d,sj,pp;
	for(i=1;i<=n;i++) c[a[i]]=1;
	for(i=1;i<=256;i++) c[i]+=c[i-1];
	for(i=1;i<=n;i++) rank[i]=c[a[i]];
	for(d=1;d<=n;d<<=1){
		for(i=1;i<=n;i++)
			p[i]=(A){i,rank[i],i+d>n?0:rank[i+d]};
		for(j=1;j>=0;j--){
			fill(c,c+n+1,0);
			for(i=1;i<=n;i++) c[p[i].v[j]]++;
			for(i=1;i<=n;i++) c[i]+=c[i-1];
			for(i=n;i>=1;i--) p2[c[p[i].v[j]]--]=p[i];
			for(i=1;i<=n;i++) p[i]=p2[i];
		}
		for(i=1;i<=n;i++){
			rank[p[i].id]=rank[p[i-1].id];
		    if(p[i].v[0]!=p[i-1].v[0]||p[i].v[1]!=p[i-1].v[1]) rank[p[i].id]++;
		}
		if(rank[p[n].id]==n) break;
	}
	for(i=1;i<=n;i++) sa[rank[i]]=i;
	k=0;
	for(i=1;i<=n;i++){
		if(k) k--;
		j=sa[rank[i]-1];
		while(a[i+k]==a[j+k]) k++;
		ht[rank[i]]=k;
	}
	for(i=2;i<=n;i++) lg2[i]=lg2[i/2]+1;
	pw[0]=1;for(i=1;i<=20;i++) pw[i]=pw[i-1]*2;
	for(i=1;i<=n;i++) f[i][0]=ht[i],mn[i][0]=sa[i];
	for(j=1;(pp=(1<<j))<=n;j++)
	    for(i=1;i+pp-1<=n;i++){
	    	sj=i+(1<<j-1);
	    	if(f[i][j-1]<f[sj][j-1]) f[i][j]=f[i][j-1];
	    	else f[i][j]=f[sj][j-1];
	    	if(mn[i][j-1]<mn[sj][j-1]) mn[i][j]=mn[i][j-1];
	    	else mn[i][j]=mn[sj][j-1];
	    }
}
set<int> s;
set<int>::iterator itl,itr;
int lcp(int l,int r){
	l++;
	int len=lg2[r-l+1],t=r-pw[len]+1;
	return f[l][len]<f[t][len]?f[l][len]:f[t][len];
}
int getmin(int l,int r){
	int len=lg2[r-l+1],t=r-pw[len]+1;
	return mn[l][len]<mn[t][len]?mn[l][len]:mn[t][len];
}
int find1(int x,int v){
	int i,p,tx=x;
	for(i=lg2[x];i>=0;i--){
		p=x-(1<<i)+1;
		if(p>0&&f[p][i]>=v) x=p-1;
	}
	return getmin(x,tx);
}
int find2(int x,int v){
    int i,p,tx=x;x++;
	for(i=lg2[n-x+1];i>=0;i--){
		p=x+(1<<i)-1;
		if(p<=n&&f[x][i]>=v) x=p+1;
	}
	return getmin(tx,x-1);
}
void work(){
	int i,sp,step,j,x,y,llen,rlen;
	s.insert(-inf);s.insert(inf);
	for(i=1;i<=n;i+=step){
		itl=s.lower_bound(rank[i]);
		itr=itl;itl--;
		x=*itl;y=*itr;
		if(x!=-inf) llen=lcp(*itl,rank[i]);
		else llen=0;
		if(y!=inf) rlen=lcp(rank[i],*itr);
		else rlen=0;
		s.insert(rank[i]);
		sp=max(llen,rlen);
		if(sp==0) printf("-1 %d ",a[i]);
		else{
			int sj=inf;
			if(sp==llen) sj=min(sj,find1(rank[i],sp));
			if(sp==rlen) sj=min(sj,find2(rank[i],sp));
			printf("%d %d ",sp,sj-1);
		}
		step=max(sp,1);
		if(i+step<=n)
		for(j=i;j<i+step;j++) s.insert(rank[j]);
	}
}
int main(){
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",a+1);
	n=strlen(a+1);
	init();
	work();
	return 0;
}

