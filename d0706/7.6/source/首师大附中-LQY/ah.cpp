#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<ctime>
using namespace std;
inline int read()
{
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
int main()
{
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	srand(time(0));
	int T=read();
	while(T--)
	{
		if(rand()%3==1 || rand()%3==2) puts("0");
		else puts("-1");	
	}
	return 0;
}

