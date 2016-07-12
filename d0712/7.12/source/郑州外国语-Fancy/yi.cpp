#include <cstring>
#include <cstdio>
const int N=300005;
int n,m,ans,sum,st,a[N<<1],b[N<<1];
char s[N];
inline void Times()
{
	for(st=1,ans++;!a[st];st++) ans++;
	for(m=n,n=0;st<=m;st++)
		b[++n]=a[st]?3:0;
	b[1]++;a[st=1]=0;sum=0;
	for(int i=1;i<=n;i++)
	{
		a[i]+=b[i];
		a[i+1]=(a[i]>>1);
		a[i]&=1;
		sum+=a[i];
	}
	while(a[n+1])
	{
		n++;
		a[n+1]=(a[n]>>1);
		a[n]&=1;
		sum+=a[n];
	}
}
int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",s);
	n=strlen(s);
	for(int i=1;i<=n;i++)
		sum+=((a[i]=s[n-i]-'0')==1);
	while(sum>1) Times();
	for(st=1;!a[st];st++) ans++;
	printf("%d\n",ans);
}
