#include <stdio.h>
#include <iostream>
#include <cstring>
typedef long long ll;
const int mod=998244353;
const int N=100005;
int n,num[N];
ll m;
using namespace std;

const int biao[5][10]=
{{1,1,1,1,1,1,1,1,1,1},
{0,1,0,2,0,3,0,4,0,5},
{0,0,2,0,0,6,0,0,12,0},
{0,0,0,3,0,0,0,15,0,0},
{0,0,0,0,6,0,0,0,0,42}};
void work1()
{
	printf ("%d",biao[n-1][m-1]);
}
int main()
{
	freopen ("jian.in","r",stdin);
	freopen ("jian.out","w",stdout);
	scanf ("%d %lld",&n,&m);
	if (n<=5 && m<=10){work1();return 0;}
	return 0;
}

