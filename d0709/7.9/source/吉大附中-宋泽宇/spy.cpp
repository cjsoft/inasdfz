#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define ll long long
int n;
ll b[1600000],tmp;
int st[110],top;
ll read()
{
	char c;
	int type=0;
	ll ret=0;
	for(c=getchar();c<'0'||c>'9';c=getchar())
		if(c=='-')type=1;
	for(;c>='0'&&c<='9';c=getchar())ret=ret*10+c-'0';
	if(type)ret=-ret;
	return ret;
}
int cal(int x)
{
	int ret=0;
	for(;x;x-=x&-x)ret++;
	return ret;
}
void print(int x)
{
	top=0;
	while(x)st[++top]=x%10,x/=10;
	for(int i=top;i>=1;i--)putchar(st[i]+'0');
	putchar(' ');
}
int main()
{
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)b[i]=read();
	tmp=b[0];
	for(int i=2;i<=n;i<<=1)
	{
		int t1=i>>1;
		for(int j=0;j<n;j+=i)
			for(int k=0;k<t1;k++)
			{
				ll t=b[j+k+t1];
				b[j+k+t1]=t-b[j+k];
				b[j+k]=t+b[j+k];
			}
	}
	int t=n>>1;
	for(int i=1;i<n;i++)
		tmp-=b[i]/t*(cal(i)+1&1);
	print(tmp);
	for(int i=1;i<n;i++)
	print(b[i]/t);
	return 0;
}
