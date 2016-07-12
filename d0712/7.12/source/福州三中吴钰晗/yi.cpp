#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ui unsigned int
int read()
{
	int s=0,f=1;char ch=getchar();
	while(!('0'<=ch&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0';ch=getchar();}
	return s*f;
}
int n;
char z[300005];
unsigned int p[100005],jw[100005],mod;
int ans=0,cs;
int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",&z[1]);n=strlen(z+1);mod=1;mod=(mod<<32);mod--;
	for(int i=1;i<=n;i++)
	   {int w=n+1-i,zu=(w-1)/32+1;
	    p[zu]=(p[zu]<<1)+(z[i]=='1');
	   }
	int e=(n-1)/32+1;
	for(int i=1;i<=e;i++)
	   {ull pp=p[i];
	    for(int j=1;j<=cs;j++)pp*=3;
		pp+=jw[i];jw[i]=0;
	    for(int j=0;j<32;j++)
	        if((pp>>j)&1)
	           {ui s=1;s<<=j;
			    if(i==e&&pp==s)
	               break;
	            pp=pp+(pp<<1)+s;cs++;
	            if(cs==19)
	               {jw[i+1]=(pp>>32);
	                pp&=mod;
	                ull ss;
				    for(int k=i+1;k<=e;k++)
	                   {ss=(ull)p[k]*1162261467+jw[k];jw[k]=0;
	                    p[k]=(ss&mod);
	                    jw[k+1]=(ss>>32);
					   }
					if(jw[e+1])p[e+1]=jw[e+1],jw[e+1]=0,e++;
					cs=0;
				   }
	            ans+=2;
			   }
			else
			    ans++;
		jw[i+1]=(pp>>32);
		if(pp>>32)
		   e=max(e,i+1);
	   }
	printf("%d\n",ans);
	return 0;
}
