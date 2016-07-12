#include<bits/stdc++.h>
#define N 310000
#define K 4
using namespace std;
typedef long long ll;
typedef unsigned int uint;
const uint M=(1ll<<K)-1;
char str[N];
uint a[N],top;
int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",str);
	int len=strlen(str);
	memset(a,0,sizeof(a)),top=0;
	for(int i=len-1;i>=0;i-=K)
	{
		for(int j=0;j<K;j++)
		{
			if(i-j>=0)
				a[top]|=(str[i-j]-'0')<<j;
		}
		top++;
	}
	int cnt=0;
	while(top!=1||a[0]!=1)
	{
		if(a[0]&1)
		{
			for(int i=0,up=1;i<=top||up!=0;i++)
			{
				ll temp=3ll*a[i]+up;
				a[i]=temp&M;
				up=temp>>K;
				if(i>top-1&&a[i]!=0)
					top=i+1;
			}
		}
		else
		{
			for(int i=0;i<top;i++)
			{
				a[i]>>=1;
				a[i]|=(a[i+1]&1)<<(K-1);
			}
			if(a[top-1]==0)
				top--;
		}
		cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
