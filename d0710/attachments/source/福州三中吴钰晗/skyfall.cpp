#include<bits/stdc++.h>
using namespace std;
#define LL long long
int read()
{
	int s=0,f=1;char ch=getchar();
	while(!('0'<=ch&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0';ch=getchar();}
	return s*f;
}
int A,B,C;
int pr[5005];
int be[5005],bn[50005],bv[50005],bl[50005],bw=1;
void put(int u,int v,int l)
{
	bw++;bn[bw]=be[u];be[u]=bw;bv[bw]=v;bl[bw]=l;
}
int cs[5005];
int ans;
int main()
{
	freopen("skyfall.in","r",stdin);
	freopen("skyfall.out","w",stdout);
	for(int i=2;i<=5000;i++)
	    if(!pr[i])
	      {//printf("%d_%d\n",i,++k);
	       for(int j=i;j<=5000;j+=i)
	           {pr[j]=1;
			    int k=j,s=0;
			    while(k%i==0)k/=i,s++;
			    put(j,i,s);
			   }
		  }
	A=read(),B=read(),C=read();LL ma=0;
	for(int a=1;a<=A;a++)
	for(int b=1;b<=B;b++)
	{for(int c=1;c<=C;c++)
	   {for(int i=be[a];i;i=bn[i])cs[bv[i]]+=bl[i];
	    for(int i=be[b];i;i=bn[i])cs[bv[i]]+=bl[i];
	    for(int i=be[c];i;i=bn[i])cs[bv[i]]+=bl[i];
	    int sum=1;
		for(int i=be[a];i;i=bn[i])sum*=cs[bv[i]]+1,cs[bv[i]]=0;
	    for(int i=be[b];i;i=bn[i])sum*=cs[bv[i]]+1,cs[bv[i]]=0;
	    for(int i=be[c];i;i=bn[i])sum*=cs[bv[i]]+1,cs[bv[i]]=0;
	    ans+=sum;
	   }ans&=2147483647;}
	cout<<ans<<endl;
	return 0;
}
