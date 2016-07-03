#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=30005,Sh=999973;
const long long Lh=888888888888883ll;

int n,k,m,test,A[N],h[N*40],St[N],hn,Ls,Rs,cnt;

struct Hash{
long long L;
int next;
}ha[N*40];

void Read(int &x){
char ch;
while((ch=getchar())<'0' || ch>'9');
x=ch-'0';
while((ch=getchar())>='0' && ch<='9')x=x*10+ch-'0';
}

void AddHash(int s,long long l){
ha[++hn].L=l;
ha[hn].next=h[s];
h[s]=hn;
}

int FindHash(int s,long long l){
for(int i=h[s];i;i=ha[i].next){
	if(ha[i].L==l)return i;
}
return 0;
}

void dfs(int ix){
if(ix>Rs){
	int sh=0;
	long long lh=0;
	for(int i=Ls;i<=Rs;i++){
		if(St[i]){sh=(sh*133+A[i]+31)%Sh;lh=(lh*233ll+A[i]+12)%Lh;}
	}
	if(!FindHash(sh,lh)){AddHash(sh,lh);cnt++;}
	return;
}
St[ix]=1;
dfs(ix+1);
St[ix]=0;
dfs(ix+1);
}

int main(){
freopen("data.in","r",stdin);
freopen("data.out","w",stdout);
Read(test);
while(test--){
	Read(n);Read(k);Read(m);
	for(int i=1;i<=n;i++)Read(A[i]);
	while(m--){
		int opt,l,r,x;
		Read(opt);Read(l);Read(r);
		if(opt<3)Read(x);
		if(opt==1){
			for(int i=l;i<=r;i++){A[i]=A[i]+x;if(A[i]>=k)A[i]-=k;}
		}
		if(opt==2){
			for(int i=l;i<=r;i++){A[i]=A[i]*x;if(A[i]>=k)A[i]%=k;}
		}
		if(opt==3){
			Ls=l;Rs=r;
			memset(h,0,sizeof(h));
			hn=cnt=0;
			dfs(Ls);
			printf("%d\n",cnt-1);
		}
	}
}
return 0;
}

