#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <cctype>
#define PROC "skyfall"
using namespace std;
#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif
typedef long long LL;
struct IO{
	IO()
	{
		freopen(PROC".in","r",stdin);
		freopen(PROC".out","w",stdout);
	}
	~IO()
	{
		fclose(stdin);
		fclose(stdout);
	}
	template <class T>
	inline void getElementById(T &num)
	{
		num=0; char c;
		do
		{
			c=getchar();
		}
		while (!isdigit(c));
		while (isdigit(c))
		{
			num=num*10+c-'0';
			c=getchar();
		}
	}
} document;
int A, B, C;
const int maxn=5010, mod=1<<30;
bool notPrime[maxn*maxn];
int prime[maxn*maxn/4], pn, d[maxn*maxn], cnt[maxn*maxn];

inline void init(int N)
{
	d[1]=1;
	for (int i=2; i<=N; i++)
	{
		if (!notPrime[i])
		{
			prime[++pn]=i;
			d[i]=2;
			cnt[i]=2;
		}
		for (int j=1; j<=pn; j++)
		{
			int t=i*prime[j];
			if (t>N) break;
			notPrime[t]=1;
			if (i%prime[j]==0)
			{
				cnt[t]=cnt[i]+1;
				d[t]=d[i]/cnt[i]*(cnt[i]+1);
				break;
			}
			cnt[t]=2;
			d[t]=d[i]*2;
		}
	}
}
LL ans;
//#include <ctime>

int main()
{
	cin>>A>>B>>C;
	init(A*B*C);
//	fprintf(stderr,"%fs\n",1.0*clock()/CLOCKS_PER_SEC);
	for (int i=1; i<=A; i++)
		for (int j=1; j<=B; j++)
			for (int k=1; k<=C; k++)
				ans+=d[i*j*k];
	cout<<ans%mod<<endl;
//	fprintf(stderr,"%fs\n",1.0*clock()/CLOCKS_PER_SEC);
	return 0;
}
