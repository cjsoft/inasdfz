#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=300005;
char s[N];
int len;
int ans=0;

const int base=(1<<28)-1;
struct NUM{
	int nu[10000],top;
	void J()
	{
		for(int i=1;i<=top;++i)
			nu[i+1]+=nu[i]>>28,nu[i]&=base;
		while(nu[top+1]) top++;
	}

	void c()
	{
		for(int i=1;i<=top;++i)
			nu[i]>>=1,nu[i]+=(nu[i+1]&1)<<27;
		if(!nu[top]) top--;
	}
}jw,che;
NUM operator *=(NUM &a,int x)
{
	for(int i=1;i<=a.top;++i)
		a.nu[i]*=x;
	a.J();
}
NUM operator +=(NUM &a,int x)
{
	a.nu[1]+=x;
	a.J();
}
NUM operator +(NUM a,NUM b)
{
	a.top=max(a.top,b.top);
	for(int i=1;i<=a.top;++i)
		a.nu[i]+=b.nu[i];
	a.J();
	return a;
}
void solve()
{
	jw.top=0;che.top=1,che.nu[1]=1;
	int tt;
	while(1)
	{
		if(len)	tt=s[len]-'0',len--;
		else tt=0;
		//Now=Now*che+jw;
		if(tt) jw=jw+che;
		if(len==0&&jw.top==1&&jw.nu[1]==1) return ;
		if((jw.nu[1]&1)==0)
		{
			ans++;
			jw.c();
		}
		else
		{
			ans+=2;
			jw*=3;che*=3;
			jw+=1;
			jw.c();
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

