#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define K 27
#define N 1000005
int n,m,k,l,t,s,ans;
int a[N],b[N],mi[30];
char st[N];
int x(int X){
	return (X-1)/K+1;
}
int y(int X){
	return (X-1)%K;
}
int main(){
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	mi[0]=1;
	for (int i=1;i<=28;i++)mi[i]=mi[i-1]*2;
	scanf("%s",st+1);
	n=strlen(st+1);
	for (int i=1;i<=n;i++)a[x(i)]+=mi[y(i)]*(st[n-i+1]-48);
	t=1;
	while(n>t){
		if((a[x(t)]&mi[y(t)])==0){t++;ans++;continue;}
		for (int i=x(n);i>=x(t);i--)a[i]*=3;
		n++;
		a[x(t)]+=mi[y(t)];
		for (int i=x(t);i<=x(n);i++)
			if(a[i]>=mi[K]){
				a[i+1]+=a[i]>>K;
				a[i]=a[i]&(mi[K]-1);
				n=max(n,x(i)*K+1);
			}
		for (int i=x(n)*K+K;i>x(n)*K-K;i--)if(a[x(i)]&mi[y(i)]){n=i;break;}
		ans++;
	}
	printf("%d\n",ans);
}
