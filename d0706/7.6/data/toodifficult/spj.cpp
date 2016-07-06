#include <stdlib.h>
#include <string.h>
#include  <stdio.h>
#include   <math.h>
#include   <time.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <set>
#include      <map>
#include<algorithm>
#include <iostream>
using namespace std;

FILE *fin, *fout, *fstdout, *freport;

void Done(int report)
{
	fprintf(freport, "%d\n", report);
	fclose(freport);
	exit(0);
}

const int N=1000005;

char A[N],B[N];

int main(int argc, char* argv[])
{
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "r");
	fstdout = fopen(argv[3], "r");
	freport = fopen(argv[5], "w");
	int t=0;
	for(int i=0;i<=9;i++)
	{
		fscanf(fout,"%s",A);
		fscanf(fstdout,"%s",B);
		if(strcmp(A,B)==0)
			t+=2;
	}
	Done(t);
}

