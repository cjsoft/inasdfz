#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=300005;
char s[N];
int len;
int ans=0,Now,jw,che;

void solve()
{
	jw=0;che=1;
	while(jw||len)
	{
		if(len)	Now=s[len]-'0',len--;
		else Now=0;
		Now=Now*che+jw;
		if(Now==1&&len==0) return ;
		if((Now&1)==0)
		{
			ans++;
			jw=Now>>1;
		}
		else
		{
			ans+=2;
			Now=Now*3+1;che*=3;
			jw=Now>>1;
		}
	}
	return ;
}

int main()
{
	freopen("yi.in","r",stdin);
//	freopen("yi.out","w",stdout);
	scanf("%s",s+1);
	len=strlen(s+1);
	solve();
	printf("%d",ans);
	return 0;
}

