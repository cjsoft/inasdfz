#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
#define ll long long
#define L 1048576
char _buf[L],*S,*T,_buf1[L+1],*S1=_buf1,c;
inline char gc()
{
	if(S==T)
	{
		T=(S=_buf)+fread(_buf,1,L,stdin);
		if(S==T)return 0;
	}
	return *S++;
}
void get(ll &x)
{
	for(c=gc();c<'0'||c>'9';c=gc());
	for(x=c^'0',c=gc();c>='0'&&c<='9';c=gc())x=(x<<3)+(x<<1)+(c^'0');
}
inline void pc(char c)
{
	if(S1==_buf1+L)
	{
		fwrite(_buf1,1,L,stdout);
		S1=_buf1;
	}
	*S1++=c;
}
void out(int x)
{
	if(x>9)out(x/10);
	pc(x%10^'0');
}
ll a[L],k;
int N,i,j;
int main()
{
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	scanf("%d",&N);
	for(i=0;i<N;i++)get(a[i]);
	reverse(a,a+N);
	for(i=0;i<N;i++)a[i]=(a[i]<<1)-a[0];
	for(i=1;i<N;i<<=1)for(j=0;j<N;j++)if(i&j)
	{
		k=a[j]+a[j^i]>>1;
		a[j]=a[j^i]-a[j]>>1;
		a[j^i]=k;
	}
	for(i=0;i<N;i++)
	{
		out(a[i]);
		pc(' ');
	}
	fwrite(_buf1,1,S1-_buf1,stdout);
	return 0;
}

