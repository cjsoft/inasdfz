#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define maxn 500009
char s[maxn];
int sa[maxn],t[maxn],t2[maxn],c[maxn],n,m,rank[maxn],hei[maxn];
void build_sa(){
    int i,*x=t,*y=t2;
    m=256;
    for (i=0;i<m;i++) c[i]=0;
    for (i=0;i<n;i++) c[x[i]=s[i]]++;
    for (i=1;i<m;i++) c[i]+=c[i-1];
    for (i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
    for (int k=1;k<=n;k<<=1){
        int p=0;
        //for (i=n-k;i<n;i++) y[p++]=i;
		for (i=n-1;i>=n-k;--i) y[p++] = i;
        for (i=0;i<n;i++) if (sa[i]>=k) y[p++]=sa[i]-k;
        for (i=0;i<m;i++) c[i]=0;
        for (i=0;i<n;i++) c[x[y[i]]]++;
        for (i=1;i<m;i++) c[i]+=c[i-1];
        for (i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        p=1;x[sa[0]]=0;
        for (i=1;i<n;i++) 
            x[sa[i]]=(y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k])?p-1:p++;
        if (p>=n) break;
        m=p;
    }
    for (int i=n;i>=1;i--)
    	sa[i]=sa[i-1]+1;
    sa[0]=0;
    for (int i=1;i<=n;i++) rank[sa[i]]=i;
}
bool vis[maxn];
int lcp[5009][5009];
int main(){
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",s);
	n=strlen(s);
	build_sa();
	int i,j,k=0;
	for(i=1,k=0;i<=n;hei[rank[i++]]=k)
		for(k?k--:0,j=sa[rank[i]-1];s[i+k-1]==s[j+k-1];k++);
	for (int i=n;i>=1;i--){
		s[i]=s[i-1];
	}
	for (int i=1;i<=n;i++){
		int p=rank[i],v=n-i+1;
		while(p<=n){
			lcp[sa[p]][i]=lcp[i][sa[p]]=v;
			p++,v=min(v,hei[p]);
		}
	}
	int cur=1;
	while(cur!=n+1){
		int p,v=0;
		for (int j=1;j<cur;j++){
			if (lcp[j][cur]>v){
				v=lcp[j][cur];
				p=j;
			}
		}
		if (!v){
			printf("-1 %d ",s[cur]);
			cur++;
		}
		else{
			printf("%d %d ",v,p-1);
			cur+=v;
		}
	}
}
