#include <bits/stdc++.h>
using namespace std; 
struct Cbig
{
	unsigned int a[100005],len;
	void set(int p){a[p/30]|=(1<<p%30);}
	bool test(int p){return a[p/30]&(1<<p%30);}
	void div()
	{
		for(int i=0;i<=len/30;i++) 
		{
			a[i]>>=1;
			if(test((i+1)*30)) a[i]|=(1<<29);
		}
		len--;
	}
	void modify()
	{
		a[0]=a[0]*3+1;
		for(int i=1;i<=len/30;i++) a[i]=a[i]*3;
		for(int i=0;i<=len/30;i++) 
		{
			if(a[i]>=(1<<30))
			{
				a[i+1]+=(a[i]/(1<<30));
				a[i]&=(1<<30)-1;
			}
		}
		len+=2;
		if(!test(len)) len--;
	}
}x;
char s[300005];
int cnt;
int main()
{
    freopen("yi.in","r",stdin);
    freopen("yi.out","w",stdout);
    scanf("%s",s);x.len=strlen(s)-1;
    for(int i=0;i<=x.len;i++) 
    if(s[i]=='1') x.set(x.len-i);
	while(x.len>0)
	{
		if(!x.test(0)) x.div();
		else x.modify();
		cnt++;
	}
	cout<<cnt<<endl;
}
