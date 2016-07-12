#include <bits/stdc++.h>
using namespace std;
const int MOD=268435456;
int n;
char buf[300005];int len;
int a[300005];
int ans;
void mul3()
{
	for(int i=0;i<n;i++)a[i]=a[i]*3+(i==0);
	for(int i=0;i<n;i++)a[i+1]+=a[i]/MOD,a[i]%=MOD;
	if(a[n]) n++;
}
void div2()
{
	for(int i=0;i<n;i++)
	{
		if(a[i]&1) a[i-1]+=MOD>>1;
		a[i]>>=1;
	}
	if(!a[n-1]) n--;
}
int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",buf);len=strlen(buf);
	reverse(buf,buf+len);
	for(n=0;n*28<len;n++)
		for(int i=min(len,(n+1)*28)-1;i>=n*28;i--)
			a[n]=a[n]*2+buf[i]-'0';
	while(n>1||a[0]!=1)
	{
		ans++;
		if(a[0]&1) mul3();
		else div2();
	}
	printf("%d\n",ans);
	return 0;
}
