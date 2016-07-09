#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int n=32;
int a,b,c,i,j;
struct node {
	int k[n+1],v;
}f[n+1];

inline int bitcount(int x) {
	int sum=0;
	while (x>0) {
		if (x%2==1) sum++;
		x/=2;
	}
	return sum;
}

int cmp(const void *a,const void *b) {
	node x=*(node *)a,y=*(node *)b;
	for (int i=n-1;i>=0;i--) {
		if (x.k[i]<y.k[i]) return 1;
		if (x.k[i]>y.k[i]) return -1;
	}
	return -1;
}

int main() {
	freopen ("t.out","w",stdout);
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++)
			f[i].k[j]=1^bitcount (j-i&j)%2;
		f[i].v=i;
	}
	
	for (i=0;i<n;i++) {
		printf ("%3d: ",f[i].v);
		for (j=0;j<n;j++)
			printf ("%3d ",f[i].k[j]);
		printf ("\n");
	}
	printf ("_____________________\n");
	qsort (f+1,n,sizeof (node),cmp);
	for (i=0;i<n;i++) {
		printf ("%3d: ",f[i].v);
		for (j=0;j<n;j++)
			printf ("%3d ",f[i].k[j]);
		printf ("\n");
	}
	return 0;
}
