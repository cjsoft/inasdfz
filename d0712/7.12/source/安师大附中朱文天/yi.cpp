#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1000005
#define Bit 33554432

char s[N];
int n,m,ans,a[N];

void init(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=n;i>0;i-=25){
		int x=0;
		for(int j=max(1,i-25+1);j<=i;j++)
			x=x*2+s[j]-'0';
		a[++m]=x;
	}
}

void multi(){
	a[1]=a[1]*3+1;
	int t=a[1]/Bit;
	a[1]%=Bit;
	for(int i=2;i<=m;i++){
		a[i]=a[i]*3+t;
		t=a[i]/Bit;
		a[i]%=Bit;
	}
	a[++m]=t;
}

void divide(){
	int t=0;
	long long x;
	for(int i=m;i>=1;i--){
		a[i]=t*Bit+a[i];
		t=(a[i]&1);
		a[i]>>=1;
	}
	while(!a[m]) m--;
}

void solve(){
	while(!(m==1&&a[m]==1)){
		ans++;
		if(a[1]%2) multi();
		else divide();
	}
	printf("%d\n",ans);
}

int main(){
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	init();
	solve();
	return 0;
}
