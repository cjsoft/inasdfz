#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
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
	int x=0,f=1;char c=Getchar();
	for(;!isdigit(c);c=Getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=Getchar()) x=x*10+c-'0';
	return x*f;
}
int main() {
	freopen("233.in","r",stdin);
	printf("%d\n",read());
	return 0;
}

