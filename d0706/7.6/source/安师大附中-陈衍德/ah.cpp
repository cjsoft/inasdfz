#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int f[100010];
int l[100010],cnt;
int z[100010],o[100010];
int zz[100010],oo[100010];
int v[100010];
int T,n;
int main(){
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		cnt++;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
		scanf("%d",&f[i]);
		l[f[i]]=cnt;
		}
		memset(z,0,sizeof(z));
		memset(o,0,sizeof(o));
		memset(zz,0,sizeof(zz));
		memset(oo,0,sizeof(oo));
		for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
		if(v[i]==0){
			int x=i;
			while(x&&!zz[x]){
			z[x]++;
			if(x!=1)zz[x]=1;
			x=f[x];
			}
		}
		if(v[i]==1){
			int x=i;
			while(x&&!oo[x]){
			o[x]++;
			if(x!=1)oo[x]=1;
			x=f[x];
			}
		}
		}
		/*int A=0,B=0;
		for(int i=0;i<=n;i++)
		if(z[f[i]]>o[f[i]])A++;
		else if(z[f[i]]<o[f[i]])B++;
		else A++,B++;*/
		if(z[1]>=o[1])printf("0\n");
		else printf("-1\n");
	}
	return 0;
}
