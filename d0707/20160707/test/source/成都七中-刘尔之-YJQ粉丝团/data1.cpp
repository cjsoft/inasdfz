#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){srand(time(0));
	freopen("elf.in","w",stdout);
	int n=3,l=5;
	printf("%d\n",n);
	for(int i=1;i<=n;i++,printf("\n"))
		for(int j=0;j<40;j++)printf("%d",rand()&1);
	printf("%d\n",l);
	for(int i=1;i<=l;i++)printf("%d",rand()&1);
}
