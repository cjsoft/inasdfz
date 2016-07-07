#include<bits/stdc++.h>
using namespace std;
#define LL long long
int read()
{
	int s=0,f=1;char ch=getchar();
	while(!('0'<=ch&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
	while(('0'<=ch&&ch<='9')){s=(s<<3)+(s<<1)+ch-'0';ch=getchar();}
	return s*f;
}
LL read2()
{
	LL s=0,f=1;char ch=getchar();
	while(!('0'<=ch&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
	while(('0'<=ch&&ch<='9')){s=(s<<1)+ch-'0';ch=getchar();}
	return s*f;
}
int n,m;
LL a[45],b,ans;
int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	    a[i]=read2();
	m=read();
	b=read2();
	for(int i=0;i<(1<<n);i++)
	   {LL s=0;
	    for(int j=0;j<n;j++)
	        if((i>>j)&1)
	           s^=a[j+1];
	    int p=0;
	    for(int j=0;j+m<=40;j++)
	        {if(((s>>j)&((1<<m)-1))==b)
	           {p=1;break;}
			}
	    ans+=p;
	   }
	cout<<ans<<endl;
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
#define LL long long
int read()
{
	int s=0,f=1;char ch=getchar();
	while(!('0'<=ch&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
	while(('0'<=ch&&ch<='9')){s=(s<<3)+(s<<1)+ch-'0';ch=getchar();}
	return s*f;
}
LL read2()
{
	LL s=0,f=1;char ch=getchar();
	while(!('0'<=ch&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
	while(('0'<=ch&&ch<='9')){s=(s<<1)+ch-'0';ch=getchar();}
	return s*f;
}
int n,m,n1,n2;
LL a[45],b;
int be[2000009];LL bv[(1<<20)+20];int cs[(1<<20)+20],bn[(1<<20)+20],bw=1,mod=2000009;
void put(LL v)
{
	int u=v%mod;
	for(int i=be[u];i;i=bn[i])
	    if(bv[i]==v)
	       {cs[i]++;return;}
	bw++;bn[bw]=be[u];be[u]=bw;bv[bw]=v;cs[bw]=1;
}
LL ans=0;
void que(LL v)
{
	int u=v%mod;
	for(int i=be[u];i;i=bn[i])
	    if(bv[i]==v)
	        {ans+=cs[i];return;
			}
}
int main()
{
	//freopen("elf.in","r",stdin);
	//freopen("elf.out","w",stdout);
	n=read();n1=n/2;n2=n-n1;
	for(int i=1;i<=n;i++)
	    a[i]=read2();
	m=read();
	b=read2();
	for(int i=0;i<(1<<n1);i++)
	   {LL s=0;
	    for(int j=0;j<n1;j++)
	        if((i>>j)&1)
	           s^=a[j+1];
	    put(s);
	   }
	for(int i=0;i<(1<<n2);i++)
	   {LL s=0;
	    for(int j=0;j<n2;j++)
	        if((i>>j)&1)
	           s^=a[n-j];
	    if(b==0)
	        que(s);
	   }
	cout<<ans<<endl;
	return 0;
}*/
