#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){srand(time(0));
	freopen("encrypt.in","w",stdout);
	int n=500000,c=26;
	for(int i=1;i<=n;i++)printf("%c",rand()%c+'a');
}
