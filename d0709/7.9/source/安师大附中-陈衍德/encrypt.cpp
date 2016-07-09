#include<bits/stdc++.h>
using namespace std;
const int B=31,MOD=1234105493;
long long h[500010],p[500010];
int SA[500010],Rank[500010],hei[500010];
char s[500010];
int N;
long long get(int l,int r){
	return (h[r]-h[l-1]*p[r-l+1]%MOD+MOD)%MOD;
}
int lcp(int a,int b){
	if(s[a]!=s[b])return 0;
	int lb=0,ub=min(N-a,N-b);
	while(lb<ub){
		int mid=(lb+ub+1)>>1;
		if(get(a,a+mid)==get(b,b+mid))lb=mid;
		else ub=mid-1;
	}
	return lb+1;
}
bool cmp(int a,int b){
	if(s[a]!=s[b])return s[a]<s[b];
	int z=lcp(a,b);
	return s[a+z]<s[b+z];
}
int main(){
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",s+1);
	N=strlen(s+1);
	p[0]=1;
	for(int i=1;i<=N;i++){
	SA[i]=i;
	p[i]=p[i-1]*B%MOD;
	h[i]=(h[i-1]*B+s[i]-'a'+1)%MOD;
	}
	sort(SA+1,SA+N+1,cmp);
	for(int i=1;i<=N;i++)
	Rank[SA[i]]=i;
	for(int i=2;i<=N;i++)
	hei[i]=lcp(SA[i-1],SA[i]);
	//for(int i=1;i<=N;i++)
	//printf("%d ",SA[i]);
	//printf("\n");
	for(int i=1;i<=N;){
		int len=0,j=0,z=1000000;
		for(int k=Rank[i];k>=1;k--){
			if(z<len)break;
			if(SA[k]<i&&(z>len||(z==len&&SA[k]<j)))len=z,j=SA[k];
			z=min(z,hei[k]);
		}
		z=1000000;
		for(int k=Rank[i];k<=N;k++){
			if(z<len)break;
			if(SA[k]<i&&(z>len||(z==len&&SA[k]<j)))len=z,j=SA[k];
			z=min(z,hei[k+1]);
		}
		if(len==0)printf("-1 %d ",s[i]),i++;
		else printf("%d %d ",len,j-1),i+=len;
	}
	return 0;
}
