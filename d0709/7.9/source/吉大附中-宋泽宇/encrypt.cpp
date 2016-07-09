#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[11000];
int n;
int main()
{
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",s);
	n=strlen(s);
	int now=0;
	while(now<n)
	{
		int len=-1,pos;
		for(int i=0;i<now;i++)
		{
			int l;
			for(l=1;s[now+l-1]==s[i+l-1];l++);
			l--;
			if(l>len)len=l,pos=i;
		}
		if(len>0)printf("%d %d ",len,pos),now+=len;
		else printf("-1 %d ",s[now]),now++;
	}
	return 0;
}
