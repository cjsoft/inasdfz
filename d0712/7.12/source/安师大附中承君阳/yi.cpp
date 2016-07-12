#include<bits/stdc++.h>
using namespace std;
int l,r,i,t,T,a[1<<20];
char s[1<<20];
main()
{
	for(freopen("yi.in","r",stdin),freopen("yi.out","w",stdout),scanf("%s",s);r=strlen(s)-1,i=0;i<=r;i++)a[i]=s[r-i]-48;
	while(l<r)
	{
		if(!a[l])l++;
		else
		{
			for(t=1,i=l;i<=r;i++)a[i]=a[i]*3+t,t=a[i]>>1,a[i]&=1;
			while(t)a[++r]=t&1,t>>=1;
		}
		T++;
	}
	cout<<T;
}
//DiZhiKaChang
