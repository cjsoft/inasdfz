#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxN 100010

int a[MaxN],b[MaxN],c[MaxN];

int read()
{
	int ans=0;
	char ch;
	ch=getchar();
	while (ch<'0'||ch>'9')
	      ch=getchar();
	while ('0'<=ch&&ch<='9')
	{
		ans*=10;
		ans+=(int)ch-48;
		ch=getchar();
	}
	return ans;
}

int main()
{
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	int n;
	n=read();
	for (int i=1;i<=n;i++)
	{
	    a[i]=read();
	    c[i]=a[i];
    }
	for (int i=1;i<=n;i++)
	    b[i]=read();
	int m;
	m=read();
	for (int i=1;i<=m;i++)
	{
		int l,r,t;
		l=read();
		r=read();
		t=read();
		for (int j=l;j<=r;j++)
			if (c[j]<=t)
				if (c[j]==a[j])
			    	c[j]=b[j];
				else
			    	c[j]=a[j];
	}
	long long ans=0;
	for (int i=1;i<=n;i++)
	    ans+=c[i];
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
}
