#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <list>
#include <bitset>
#include <queue>
#define PROC "number"
//#define bs bitset< maxn >
#define sbs bs
using namespace std;
#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif
typedef long long LL;
int k, i;
const int maxn=690;

struct bs{
	LL num[12];
	bs operator ^ (const bs &an) const
	{
		bs back;
		for (int i=0; i<=11; i++)
			back.num[i]=num[i]^an.num[i];
		return back;
	}
	bs operator >> (const int &N) const
	{
		bs back;
		for (int i=0; i<=10; i++)
			back.num[i]=(num[i]>>N)|((num[i+1]&((1LL<<(N))-1))<<(60-N));
		back.num[11]>>=N;
		return back;
	}
	bs operator << (const int &N) const
	{
		bs back;
		for (int i=11; i; i--)
			back.num[i]=(num[i]<<N)|((num[i-1]>>(60-N)));
		back.num[0]<<=N;
		return back;
	}
	bool operator [] (const int &N) const
	{
		return (num[N/60]>>(N%60))&1;
	}
	void operator >>= (const int &N)
	{
		for (int i=0; i<=10; i++)
			num[i]=(num[i]>>N)|((num[i+1]&((1LL<<(N))-1))<<(60-N));
		num[11]>>=N;
	}
	bs operator + (const bs &an)
	{
		bs back;
		back.num[0]=0;
		for (int i=0; i<=11; i++)
		{
			back.num[i]+=num[i]+an.num[i];
			if (back.num[i]>=(1LL<<60))
			{
				back.num[i]-=(1LL<<60);
				back.num[i+1]=1;
			}
			else
				back.num[i+1]=0;
		}
		return back;
	}
	void set(const int &N)
	{
		num[N/60]|=1LL<<(N%60);
	}
};


struct state{
	bs s2;
	sbs s1;
} now;
bs po10;
list<state> v;
queue<state> q;

void print(const sbs &a)
{
	bool flag=0;
	for (int i=maxn-1; i>=0; i--)
	{
		if (a[i])
			flag=1;
		if (flag) cout<<a[i];
	}
	cout<<endl;
}

int main()
{
	freopen(PROC".in","r",stdin);
	freopen(PROC".out","w",stdout);
	cin>>k;
	k--;
	if (!k)
	{
		cout<<1<<endl;
		return 0;
	}
	v.push_back(now);
	now.s1.set(0);
	v.push_back(now);
	po10.set(0);
	po10.set(2);
	bs tmp;
	for (i=1; ; i++)
	{
//		printf("===> %d(%d)\n",i,k);
		for (list<state>::iterator it=v.begin(); it!=v.end(); )
		{
			if (it->s2[0])
			{
				v.erase(it++);
				continue;
			}
//			print(it->s1);
			now=*it;
			now.s1.set(i);
			now.s2=(now.s2+po10)>>1;
			k--;
			if (!k) break;
			(it->s2)>>=1;
			q.push(now);
			it++;
		}
		if (!k) break;
		while (!q.empty())
		{
			v.push_back(q.front());
			q.pop();
		}
		tmp=po10;
		po10=(po10+po10);
		po10=(po10+po10);
		po10=(po10+tmp);
	}
	print(now.s1);
//	cerr<<(double)clock()/CLOCKS_PER_SEC<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
