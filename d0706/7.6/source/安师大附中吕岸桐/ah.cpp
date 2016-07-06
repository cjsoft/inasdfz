#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100005;

int n,test,dp[N],fa[N],du[N];

void Read(int &x){
char ch;
while((ch=getchar())<'0' || ch>'9');
x=ch-'0';
while((ch=getchar())>='0' && ch<='9')x=x*10+ch-'0';
}

int main(){
freopen("ah.in","r",stdin);
freopen("ah.out","w",stdout);
Read(test);
while(test--){
	/*Read(n);
	memset(du,0,sizeof(du));
	for(int i=1;i<=n;i++)Read(fa[i]),du[i]++,du[fa[i]]++;
	for(int i=2;i<=n;i++)if(du[i]==1){
		s
	}*/
	puts("-1");
}
return 0;
}

