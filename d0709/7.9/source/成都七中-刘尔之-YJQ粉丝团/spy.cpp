#include<cstdio>
long long b[1500001],x,y;
int iin(){int u=0;char c=0;while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')u=u*10+c-'0',c=getchar();return u;}
int main(){
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	int n=iin();for(int i=1;i<=n;i++)b[n-i]=iin();
	for(int i=n-1;~i;i--)b[i]=b[i]*2-b[0];
	for(int k=2;k<=n;k<<=1)for(int i=0;i<n;i+=k)
	for(int j=i;j<i+k/2;j++)x=b[j],y=b[j+k/2],
	b[j]=x+y,b[j+k/2]=x-y;for(int i=0;i<n;b[i++]/=n);
	for(int i=0;i<n;i++)printf("%d ",b[i]);return 0;
}
