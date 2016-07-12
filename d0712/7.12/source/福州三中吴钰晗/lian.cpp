#include<bits/stdc++.h>
using namespace std;
int read()
{
	int s=0,f=1;char ch=getchar();
	while(!('0'<=ch&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0';ch=getchar();}
	return s*f;
}
#define ull unsigned long long
int n,QL,QR,w;
unsigned int ha[2005][4096],cf[2005],ss;
int cs[2005][4096];
int s[2005];
int en[2005];
int an1[4000005],an2[4000005];
int mi()
{
	int m;
	for(int i=n;i>=1;i--)
	    if(en[i]<=n)
	       {m=i;break;}
	for(int i=m-1;i>=1;i--)
	   {if(ha[i][1]==ha[m][1])
	       continue;
	    int x=1;
	    while(x<=w)
	      {if(ha[i][x<<1]==ha[m][x<<1])
	      	  x=x*2+1;
	       else
	          x*=2;
		  }
		//cout<<i<<" "<<m<<" "<<x-w<<" "<<cs[i][x-w]<<" "<<cs[m][x-w]<<endl;
		if(cs[i][x-w]<cs[m][x-w])m=i;
	   }
	return m;
}
int main()
{
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	n=read(),QL=read(),QR=read();
	cf[0]=1;
	cf[1]=1000000007;for(int i=1;i<=n;i++)cf[i]=cf[i-1]*cf[1];
	for(int i=1;i<=n;i++)
		s[i]=read(),en[i]=i;
	for(w=1;w<=n;w<<=1);
	for(int i=1;i<=n;i++)
	   {ss=cf[s[i]];cs[i][s[i]]++;
	    for(int j=s[i]+w;j;j>>=1)
	        ha[i][j]+=ss;
	   }
	for(int i=n*(n+1)/2;i>=1;i--)
	   {int ww=mi();
	    an1[i]=ww,an2[i]=en[ww];//cout<<ww<<"_"<<en[ww]<<endl;
	    ss=cf[s[en[ww]+1]];cs[ww][s[en[ww]+1]]++;
	    for(int j=s[en[ww]+1]+w;j;j>>=1)
	        ha[ww][j]+=ss;
		en[ww]++;
	   }
	for(int i=QL;i<=QR;i++)
	    printf("%d %d\n",an1[i],an2[i]);
	return 0;
}
