#include <stdio.h>
#include <iostream>
#include <cstring>
const int N=500005;
typedef unsigned long long ll;
const int bit=61;
const ll full=(1ll<<(bit-1))-1;
int n,len,ans=0,pos;
ll num[N];
char s[N];
using namespace std;

bool one(){return (n==1 && num[1]==1);}
void change()
{
	int i;
	for (i=1,n=1;i<=len;i++)
	{
		if (s[len-i+1]=='1') num[n]+=(1ll<<((i-1)%bit));
		if (i%bit==0 && i<len) n++;
	}
}
void mul()
{
	int i;ans++;
	for (i=1;i<=n;i++) num[i]+=(num[i]<<1);num[1]++;
	for (i=1;i<=n;i++) num[i+1]+=(num[i]>>bit),num[i]&=(full<<1|1);
	for (n++;num[n]>0;n++) num[n+1]+=(num[n]>>bit),num[n]&=(full<<1|1);n--;
}
void div()
{
	for (pos=1;!num[pos];pos++);
	ans+=(pos-1)*bit;
	int i,j;
	for (i=0;((1ll<<i)&num[pos])==0;i++);ans+=i;
	for (j=pos;j<=n;j++) num[j-pos+1]=(num[j]>>i)|((num[j+1]&((1ll<<i)-1))<<(bit-i));
	for (j=n-pos+2;j<=n;j++) num[j]=0;
	n=n-pos+1;
	while (!num[n]) n--;
}
int main()
{
	freopen ("yi.in","r",stdin);
	freopen ("yi.out","w",stdout);
	scanf ("\n%s",s+1);len=strlen(s+1);
	change();
	while (!one())
	{
		if (num[1]&1) mul();
		else div();
	}
	printf ("%d",ans);
	return 0;
}

