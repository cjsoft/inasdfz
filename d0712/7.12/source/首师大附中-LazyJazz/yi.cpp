#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[10010];
int n[20020],size=0,cnt=0;
void update()
{
	for(int i=size;i>0;i--)n[i]+=n[i-1];
	size++;n[0]++;
	bool got=0;int zerobitcount=0;
	for(int i=0;i<size;i++)
	{
		if(n[i]>1)size=max(size,i+2);
		n[i+1]+=n[i]>>1;
		n[i]&=1;
		if(n[i])got=1;
		if(!got)zerobitcount++;
	}
	cnt+=1+zerobitcount;size-=zerobitcount;
	for(int i=0;i<size;i++)n[i]=n[i+zerobitcount];
	for(int i=0;i<zerobitcount;i++)n[i+size]=0;
}
int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",str);size=strlen(str);
	for(int i=size-1,j=0;i>=0;i--,j++)
		n[j]=str[i]-'0';
	bool got=0;int zerobitcount;
	for(zerobitcount=0;zerobitcount<size&&!got;zerobitcount++)if(n[zerobitcount])got=1,zerobitcount--;
	cnt+=zerobitcount;size-=zerobitcount;
	for(int i=0;i<size;i++)n[i]=n[i+zerobitcount];
	for(int i=0;i<zerobitcount;i++)n[i+size]=0;
	while(size>1)
		update();
	printf("%d",cnt);
}
