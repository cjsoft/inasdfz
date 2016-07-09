#include <cstdio>
#include <cstdlib>
#include <ctime>
int main()
{
	freopen("encrypt.in","w",stdout);
	srand(time(0));
	int n=8;
	for(int i=1;i<=n;i++)
		printf("%c",rand()%3+'a');
}
