#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef unsigned long long ULL;
const int L=25,Lmask=(1<<L)-1,maxn=500005;
char str[maxn];
int n,ans,s[maxn];

void init()
{
	gets(str);
	n=strlen(str);
	reverse(str,str+n);
	for(int i=0;i<n;i++)
		s[i/L]|=(str[i]=='1')<<(i%L);
	n=(n-1)/L+1;
}

ULL single_digit(ULL &t)
{
	int cnt=L;
	ULL r=1;
	while(cnt)
	{
		if(t&1)t=t*3+1,r*=3;
		else t>>=1,cnt--;
		ans++;
	}
	return r;
}

void work()
{
	ULL t,j;
	int i;
	while(n>1)
	{
		j=s[0];
		t=single_digit(j);
		for(i=0;i<n||j;i++)
		{
			j+=t*s[i+1];
			s[i]=j&Lmask;
			j>>=L;
		}
		for(n=i;n>1&&s[n-1]==0;n--);
	}
	t=s[0];
	while(t!=1)
	{
		if(t&1)t=t*3+1;
		else t>>=1;
		ans++;
	}
	printf("%d\n",ans);
}
//#include<ctime>
int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	init();
	work();
	//cout<<clock()<<endl;
	return 0;
}

