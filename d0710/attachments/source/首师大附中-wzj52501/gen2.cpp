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
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
int mx;
int isp(int n) {
	for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
	return 1;
}
int main() {
	rep(i,1,5000) if(isp(i)) mx=i;
	printf("%d\n",mx);
	return 0;
}

