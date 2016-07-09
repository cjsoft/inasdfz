#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define ll long long
using namespace std;
int i,j,k,m,n,s,t;
ll b[1501000];
ll read()
{
	ll x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x;
}
char ch[50];
void print(int x){
    if (!x) putchar('0');
    int i;for (i=0;x;x/=10) ch[++i]=x%10+'0';
    for (;i;i--) putchar(ch[i]);
    putchar(' ');
}
int bc(int x)
{
	int ans=0;
	while (x)
	{
		if (x&1) ans++;
		x>>=1;
	}
	return ans;
}
void solve(int l,int r)
{
	if (l==r) return;
	int mid=(l+r)>>1;
	solve(l,mid);solve(mid+1,r);
    int mi=(r-l+1)>>1,i;
	ll s1,s2;
    for (i=l+1;i<=mid;i++)
      {
      	s1=b[i];s2=b[i+mi];
      	b[i]=(s1+s2)>>1;b[i+mi]=(s2-s1)>>1;
      }
    b[l+mi]=b[l+mi]-b[l];
    s1=0;
    for (i=mid+2;i<=r;i++)
      s1+=b[i];
    b[l]-=s1;
    b[l+mi]+=s1;
    
}
int main()
{
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	n=read();
/*	for (i=0;i<n;i++)
	{
	  for (j=0;j<n;j++)
		printf("%d",((bc((i|j)^i))+1)%2);
	  puts("");
    }*/
    for (i=0;i<n;i++)
      b[i]=read();
    solve(0,n-1);
    for (i=0;i<n;i++)
      print(b[i]);
    puts("");
}
