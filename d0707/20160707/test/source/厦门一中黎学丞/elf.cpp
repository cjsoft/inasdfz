#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define ll long long
using namespace std;
const int m=40;
int i,j,k,n,s,t,L,n1,ans;
bool bo;
ll a[50],b,now,w;
int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x;
}
char ch[50];
int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	n=read();
    for (i=1;i<=n;i++)
    {
    	scanf("%s",ch+1);
      for (j=1;j<=m;j++)
      {
        a[i]*=2;
        a[i]+=ch[j]-'0';
      }
     }
    L=read();
    w=1;
    scanf("%s",ch+1);
    for (i=1;i<=L;i++)
      {
      	b*=2;
      	b+=ch[i]-'0';
      	w*=2;
      }
    n1=(1<<n)-1;
    for (i=0;i<=n1;i++)
    {
    	now=0;
    	j=i;
    	k=0;
    	while (j)
    	{
    		k++;
    		if (j&1) now^=a[k];
    	    j>>=1;
    	}
    	bo=0;
    	for (j=L;j<=m;j++)
    	{
    		if (now%w==b) {bo=1;break;}
    		now>>=1ll;
    	}
    	if (bo) ans++;
    }
    printf("%d\n",ans);
}
