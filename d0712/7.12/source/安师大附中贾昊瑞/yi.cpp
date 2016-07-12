#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <windows.h> 
#include<queue>
#include<map>
#include<set>
#include<list>
#include<ctime>
#include<deque>
#include<vector>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define F(i,j,n) for(int i=j;i<=n;i++)
#define D(i,j,n) for(int i=j;i>=n;i--)
using namespace std;
int n,x[10100],y[10100],ans;
const int mod=(1<<29)-1;
char s[300010];
void make(){
	register int i;
	while(s[n-1]=='0')n--,ans++;
	for(i=0;i<n;i++)
	x[(n-i-1)/29]=x[(n-i-1)/29]<<1|(s[i]-'0');
	n=(n-1)/29+1;
}
void out(int x[]){
	memset(s,0,sizeof(s));
	itoa(x[n-1],s,2);
	printf("\n");
	printf("n%d\n%s",n,s);
	D(i,n-2,0){
	printf(" ");
	for(register int j=1<<30;j;j>>=1)
	printf("%d",!(!(x[i]&j)));
	}
	printf("\n");
}

void ds(){
	register int i;
	for(i=0;i<n;i++)
		y[i]=x[i],x[i]=x[i]+(x[i]>>1)+((x[i+1]&1)<<28);
	x[0]++;//out(x);
	for(i=0;i<n;i++)
	x[i+1]+=(x[i]>>29),x[i]&=mod;
	if(x[n])n++;
//	out(x);
}
void cut(){
	register int i=0,j,o,p;
	while(!x[i])i++,ans+=29;
	j=x[i]&-x[i];if(j==1)return;
	o=log(j)/log(2)+1e-6;
	ans+=o;p=(1<<o)-1;
//	printf("%d %d %d\n",o,i,p);
	for(j=0;i<n;i++,j++)
	x[j]=x[i]>>o|((x[i+1]&p)<<(29-o));
//	printf("%d %d %d %d\n",o,n,i,j);
	for(i=j;i<=n;i++)x[i]=0;
	while(!x[j])j--;n=j+1;
}
int main() {
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	gets(s);n=strlen(s);
	make();
//	out();
	while(n^1||x[0]^1){
		ds();ans+=2;
//	out(x);printf("ans%d\n",ans);
		cut();
//	out(x);printf("cu ans%d\n",ans);
	}
	printf("%d\n",ans);
//	printf("%.3lf\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

