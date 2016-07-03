#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
const int L=26;
int K;

int pw10[1005][1005],lpw10[1005];

void Add(int *a,int &la,int *b,int &lb)
{
	la=max(la,lb);
	int t=0;
	for(int i=0;i<la;i++)
	{
		a[i]=a[i]+b[i]+t;
		t=a[i]>>L;
		a[i]&=(1<<L)-1;
	}
	if(t)a[la++]=t;
}

struct node
{
	int s2[90],s10[30];
	int len,l2;
	
	bool check()
	{
		int l=len/L;
		for(int i=0;i<l;i++)
			if(s10[i]!=s2[i])
				return 0;
		for(int i=0;l*L+i<len;i++)
			if((s2[l]>>i&1)!=(s10[l]>>i&1))
				return 0;
		return 1;
	}
	
	void output()
	{
		for(int i=len-1;i>=0;i--)
			putchar('0'+(s10[i/L]>>i%L&1));
		puts("");
	}
	
	void extend(int c)
	{
		if(c)
		{
			s10[len/L]|=1<<len%L;
			Add(s2,l2,pw10[len],lpw10[len]);
		}
		len++;
	}
	
}q[1033333];
int qh,qt;


void init()
{
	pw10[0][0]=1;
	lpw10[0]=1;
	for(int i=1;i<=1000;i++)
	{
		int t=0;
		for(int j=0;j<lpw10[i-1];j++)
		{
			pw10[i][j]=pw10[i-1][j]*10+t;
			t=pw10[i][j]>>L;
			pw10[i][j]&=(1<<L)-1;
		}
		lpw10[i]=lpw10[i-1];
		if(t)pw10[i][lpw10[i]++]=t;
	}
}

void work()
{
	qt=1;
	node t;
	while(qh<qt)
	{
		int ql=qh+1,qr=qt,c;
		for(c=0;c<2;c++)
			for(int i=ql;i<=qr;i++)
			{
				t=q[i];
				//if(c==0)t.output();
				t.extend(c);
				if(t.check())
				{
					q[++qt]=t;
					if(c==1)
					{
						if(--K==0)
						{
							t.output();
							return;
						}
					}
				}
			}
		qh=qr;
	}
}
//#include<ctime>
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>K;
	init();
	work();
	//cout<<clock()<<endl;
	return 0;
}

