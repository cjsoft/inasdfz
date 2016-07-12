#include <bits/stdc++.h>

using namespace std;

int main()
{
	system("g++ yi.cpp -o yi -g -O2");
	system("g++ data.cpp -o data -g -O2");
	for(int i = 1; i <= 10000; i++)
	{
		printf("Case %d : ", i);
		system("data");
		int t = clock();
		system("yi");
		t = clock() - t;
		if(t > 1000) puts("TLE");
		else printf("%d\n", t);
	}
	return 0;
}
