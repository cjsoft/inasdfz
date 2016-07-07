#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<ctime>
using namespace std;
inline int read()
{
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
typedef long long ll;
ll a[45];
int L,n;
char w[45];
bool check(ll ans)
{
	char s[45];
	for(int i=0;i<40;i++) s[i]='0';
	s[40]='\0';
	int cnt=1;
	while(ans>0)
	{
		if(ans&1) s[40-cnt]='1';
		ans>>=1;
		cnt++;
	}
	for(int i=0;i<=40-L;i++)
	{
		bool flag=1;
		for(int j=0;j<L;j++)
			if(w[j]!=s[j+i]) {flag=0;break;}
		if(flag) return 1;
	}
	return 0;
}
int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	n=read();
	ll counter=0;
	char s[40];
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		for(int j=0;j<40;j++)
		{
			a[i]<<=1;
			
			if(s[j]=='1') a[i]++;
		}
	}	
	L=read();scanf("%s",w);
	ll S=(ll)1<<n;
	for(ll i=0;i<S;i++)
	{
		ll ans=0;
		for(int j=0;j<n;j++)
			if(i&(1<<j)) 
			{
				if(ans==0)ans=a[j];
				else ans^=a[j];
			}
		if(check(ans))counter++;
	}
	printf("%lld\n",counter);
	return 0;
}

