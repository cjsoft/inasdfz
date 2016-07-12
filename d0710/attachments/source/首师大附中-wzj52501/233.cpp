#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
using namespace std;
const int SIZE=1<<16;
char buffer[SIZE],*head,*tail;
inline char Getchar() {
	if(head==tail) {
		int l=fread(buffer,1,SIZE,stdin);
		tail=(head=buffer)+l;
	}
	return *head++;
}
inline int read() {
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
int main() {
	double g=9.7803185,R=6378137;
	printf("%.8lf\n",sqrt(2*g*R));
	return 0;
}

