#include <bits/stdc++.h>
using namespace std;

const int N=500005;
char str[N];
int n,a[N],b[N],c[N];

void put()
{
	for(int i=1;i<=a[0];i++)cout<<a[i];cout<<endl;
}

int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",str+1);
	n=strlen(str+1);
	int i,j,ans=0;
	for(i=n;i>=1;i--)
	    a[++a[0]]=str[i]-'0';
	while(a[0]!=1)
	{
		//put();
		ans++;
		if(a[1]==0)
		{
			for(i=1;i<a[0];i++)
			    a[i]=a[i+1];
			a[a[0]--]=0;
		}
		else
		{
			b[0]=1;b[1]=0;c[0]=0;
			for(i=1;i<=a[0];i++)b[++b[0]]=a[i];
			for(i=1,j=1;i<=a[0]||i<=b[0]||j;i++)
			{
			    c[++c[0]]=a[i]+b[i]+j;
			    a[i]=0;b[i]=0;
			    j=c[c[0]]>>1;
			    c[c[0]]&=1;
			}
			for(i=0;i<=c[0];i++)a[i]=c[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}

