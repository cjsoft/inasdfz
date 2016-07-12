#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<bitset>
#define BIT bitset<20010>
using namespace std;
BIT re,l[2],din,ls;
BIT operator +(const BIT &a,const BIT &b)
{
	int i=0;
	re=a^b; l[i]=a&b;
	int cnt=0;
	while(l[i]!=0)
	{
		l[i]<<=1;
		l[i^1]=l[i]&re;
		re=re^l[i];
		i^=1;
		cnt++;
	}
	return re;
}
char s[20010];
int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++) din[i]=s[len-1-i]=='1'? 1:0;
	int cnt=0;
	while(din!=1)
	{
		if(din[0])
		{
			ls=din<<1;
			din=din+ls;
			ls=1;
			din=din+ls;
		} else
		din>>=1;
		cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
