#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

int k;
struct D{
	int nu[100],top;
	int f;
	void push(int x)
	{
		memset(nu,0,sizeof(nu));top=1;
		while(x>20) x-=20,top++;
		nu[top]=(1<<(x-1));
	}
};
bool operator <(D a,D b)
{
	if(a.top!=b.top) return a.top>b.top;
	for(int i=a.top;i;--i)
		if(a.nu[i]!=b.nu[i]) return a.nu[i]>b.nu[i];
	return 1;
}
D operator |(D a,D b)
{
	int t=max(a.top,b.top);
	for(int i=1;i<=t;++i)
		a.nu[i]|=b.nu[i];
	a.top=t;
	return a;
}

priority_queue<D> a,b,*x,*y;
const int mod=(1<<20)-1;
int last[100000],topl,La=0;
int findf()
{
	La++;
	for(int i=1;i<=topl;++i)
		last[i]*=5;
	for(int i=1;i<=topl;++i)
		last[i+1]+=last[i]>>20,
		last[i]&=mod;
	if(last[topl+1]) topl++;
	int t=1,tt=1,p;
	while((tt==1&&last[1]==1)||(last[tt]==0)) tt++,t+=20;
	if(tt==1||(last[tt]&1)==0) 
	{
		t++;
		p=last[tt]>>1;
		while((p&1)==0) t++,p>>=1;
	}
//	cout<<t+La<<endl;
	return t+La;
}
int ans[22],topa;
void pr(D p)
{
	for(int i=p.top,xx;i;--i)
	{
		memset(ans,0,sizeof(ans));
		xx=p.nu[i];
		topa=0;
		while(xx)
		{
			ans[++topa]=xx&1;
			xx>>=1;
		}
		for(int j=(i==p.top)?topa:20;j;--j)
			printf("%d",ans[j]);
		
	}

}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&k);
	if(k==1)
	{
		printf("1");
		return 0;
	}
	last[1]=1,topl=1;
	x=&a,y=&b;
	D p,p1,p2;
	p.push(1);p.f=0x3fffffff;
	y->push(p);
	k--;int top=1;
	int K=1;
	while(k)
	{
		if(x->empty())
		{	
			swap(x,y);
			top++;
			p.push(top);
			p.f=findf();
	
			y->push(p);
			k--;K++;
			p1=p;
		}
		else
		{
			p2=x->top();x->pop();
			p1=p2|p;
			if(p2.f<=top) 
				y->push(p2);
			else
//			if(p2.f>top)
			{
				p1.f=min(p.f,p2.f);
				if(p.f==p2.f) p1.f++;
				k--;K++;
				y->push(p2);y->push(p1);
				
			}
		}
		//	
	}
	pr(p1);
	return 0;
}

