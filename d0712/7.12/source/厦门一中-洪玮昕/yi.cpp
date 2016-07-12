#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=300100;
int n,m,x,y,z,ans;
int s[N],ss[N];
char ch[N];
int main()
{
	int a,b,c,i,j;
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for(i=1;i<=n;i++)
		s[i]=ch[n-i+1]-'0';
	while(1)
	{
		while(n>0&&s[1]==0)
		{
			for(i=1;i<n;i++)
				s[i]=s[i+1];
			s[n]=0;
			n--;
			ans++;
		}
		if(n==1) break;
		for(i=1;i<=n;i++)
			ss[i+1]=s[i];
		ss[1]=1;
		for(i=1;i<=n+1;i++)
		{
			s[i]+=ss[i];
			s[i+1]+=s[i]/2;
			s[i]%=2;
		}
		if(s[n+2]) n+=2;
		else n++;
	//	for(i=n;i;i--)
	//		printf("%d",s[i]);
	//	printf("\n");
		ans++;
	}
	printf("%d\n",ans);
}
