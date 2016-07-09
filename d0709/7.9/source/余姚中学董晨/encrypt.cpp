#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll unsigned long long
#define N 500005
#define M 6662333
int n,m,k,l,t,s,r,x,y;
char st[N];
ll sum[N],h[N];
ll que(int l,int r){
	int s=r-l+1;
	return sum[r]-sum[l-1]*h[s];
}
int check(int len){
	for (int i=1;i<t;i++)
		if(que(i,i+len-1)==que(t,t+len-1))return i;
	return 0;
}
int main(){
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",st+1);
	n=strlen(st+1);
	h[0]=1;
	for (int i=1;i<=n;i++){
		h[i]=h[i-1]*M;
		sum[i]=sum[i-1]*M+st[i];
	}
	t=1;
	while(t<=n){
		l=0,r=n-t+1;
		while(l<r){
			int mid=l+r+1>>1;
			if(check(mid))l=mid;
			else r=mid-1;
		}
		if(l==0){printf("-1 %d ",st[t]);t++;}
		else{
			printf("%d %d ",l,check(l)-1);
			t+=l;
		}
	}
	puts("");
}
