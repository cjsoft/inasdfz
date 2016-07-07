#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long power[50];
long long a[50],ans;
char s[50][50],st[50];
int n,l;

void check(long long x)
{
	int k=39;
	char s[50];
	strcpy(s,"0000000000000000000000000000000000000000");
	while (x>0)
	{
		s[k]=(char)(x%2+48);
		k--;
		x/=2;
	}
	int l=strlen(s),ll=strlen(st);
	for (int i=0;i<l-ll+1;i++)
	{
		bool mark=true;
		for (int j=0;j<ll;j++)
		     if (s[i+j]!=st[j])
		     {
		     	mark=false;
		     	break;
		     }
	    if (mark)
	    {
	    	ans++;
	    	break;
	    }
	}
}

void search(int x,long long y)
{
	if (x==n+1)
	{
	   check(y);
	   return;
    }
    search(x+1,y^a[x]);
    search(x+1,y);
}

int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	power[0]=1;
	for (int i=1;i<=39;i++)
	    power[i]=power[i-1]*2;
	scanf("%d\n",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s\n",s[i]);
		a[i]=0;
		for (int j=0;j<strlen(s[i]);j++)
		    a[i]+=((long long)s[i][j]-48)*power[39-j];
	}
	scanf("%d\n",&l);
	scanf("%s",st);
	ans=0;
	search(1,0);
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
}
