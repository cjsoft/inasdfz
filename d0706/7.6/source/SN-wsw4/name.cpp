#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstring>
#define maxn 100010

using namespace std;

int read(){
	char c=getchar();
	int y=0,tim=1;
	while(c>'9'||c<'0'){
		if(c=='-')tim=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		y=y*10+c-'0';
		c=getchar();
	}
	return tim*y;
}
int n,m,vi[maxn][2]={0};
int xi[maxn]={0};
void work1(){
	long long int ans=0;
	int i,l,r,t;
	for(i=1;i<=n;i++)vi[i][0]=read();
	for(i=1;i<=n;i++)vi[i][1]=read();
	m=read();
	while(m--){
		l=read();r=read();t=read();
		for(i=l;i<=r;i++)
			if(vi[i][xi[i]]<=t)xi[i]^=1;
	}
	for(i=1;i<=n;i++)ans+=vi[i][xi[i]];
	cout<<ans<<endl;
}

int main(){
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	int i,x,y;
	n=read();
	work1();
	return 0;
}
