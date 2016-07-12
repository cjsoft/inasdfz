#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 501

int a[MAXN];

struct SG{
	int l,r;
}s[MAXN*MAXN];
int tot;

int t1,t2;
int tm1[MAXN],tm2[MAXN];
int cmp(SG s1,SG s2){
	t1=t2=0;
	for(int i=s1.l;i<=s1.r;++i)tm1[++t1]=a[i];
	for(int i=s2.l;i<=s2.r;++i)tm2[++t2]=a[i];
	sort(tm1+1,tm1+1+t1);sort(tm2+1,tm2+1+t2);
	for(int i=1;i<=t1&&i<=t2;++i)
		if(tm1[i]!=tm2[i])return tm1[i]<tm2[i];
	if(t1!=t2)return t1>t2;
	return s1.l<s2.l;
}

int main(){
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	int n,p,q;scanf("%d%d%d",&n,&p,&q);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			s[++tot].l=i,s[tot].r=j;
	sort(s+1,s+1+tot,cmp);
	for(int i=p;i<=q;++i)
		printf("%d %d\n",s[i].l,s[i].r);
	return 0;
}
