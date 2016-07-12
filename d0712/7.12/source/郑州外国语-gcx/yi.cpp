#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int base=(1<<25)-1;
const int N=1000000;
int nu[N],topn;

char s[300000];
int ans=0,t=0;

void solve()
{
	while(topn!=1||nu[1]!=1)
	{
		if((nu[1]&1)==0)
		{
			int t1=1;
			while(nu[t1]==0) t1++,ans+=25;
			
			topn-=t1-1;
			for(int i=1;i<=topn;i++,t1++)
				nu[i]=nu[t1];
			for(int i=topn+1,j=1;j<t1;++j,++i)nu[i]=0; 
			t1=1;
			while((nu[1]&(1<<(t1-1)))==0) t1++;
			ans+=--t1;
			for(int i=1;i<=topn;++i)
				nu[i]>>=t1,nu[i]|=(nu[i+1]&((1<<t1)-1))<<(25-t1);
			while(nu[topn]==0) topn--;
		}
		else
		{
			ans++;t++;
			for(int i=1;i<=topn;++i)
				nu[i]*=3;
			nu[1]++;
			for(int i=1;i<=topn;++i)
			{
				if(i==topn&&nu[i]>base) nu[++topn]=0;
				nu[i+1]+=nu[i]>>25,nu[i]&=base;
				
			}
				
		}
	}
}

int main()
{
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",s+1);
	int len=strlen(s+1);
	cout<<len<<endl;
 	for(int i=len,j=1;i>0;i-=25,j++)
	{
		nu[j]=0;
		for(int k=max(i-25+1,1);k<=i;++k)
			nu[j]=(nu[j]<<1)|(s[k]-'0');
		topn=j;
	}
	solve();
	printf("%d",ans);
	cout<<endl<<t;
}

