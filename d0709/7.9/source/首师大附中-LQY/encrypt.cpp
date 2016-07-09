#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<ctime>
using namespace std;
inline int read()
{
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
char s[100000];
int n,len,j;
bool find(int x)
{
	len=0;
	int L;
	for(int k=0;k<x;k++)
	{
		L=0;
		while(s[k+L]==s[x+L]&&x+L<n)L++;
		if(L>len)len=L,j=k;
	}
	if(len==0)return 0;
	return 1;
}
int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;)
	{
		if(find(i))printf("%d %d ",len,j),i+=len;
		else printf("-1 %d ",s[i]),i++;
	}
	//printf("\n%lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

