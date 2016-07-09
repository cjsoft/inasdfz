#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=500005,INF=2100000000;

char s[N];
int n,sa[N],rank[N],rank2[N],height[N],ws[N],wa[N],log2[N],rmq[N][20],er[N],cursor,num[N],cnt;

int ReadStr(){
int le=0;
while((s[le]=getchar())<'a' || s[le]>'z');
le++;
while((s[le]=getchar())>='a' && s[le]<='z')le++;
return le;
}

bool cmp(int *r,int a,int b,int len){return (r[a]==r[b])&(r[a+len]==r[b+len]);}

void GetSA(char *r,int *sa,int n,int m){
int i,j,p,*x=rank,*y=rank2,*t;
for(i=0;i<m;i++)ws[i]=0;
for(i=0;i<n;i++)ws[x[i]=r[i]]++;
for(i=1;i<m;i++)ws[i]+=ws[i-1];
for(i=n-1;i>=0;i--)sa[--ws[x[i]]]=i;
for(j=p=1;p<n;j<<=1,m=p){
	for(p=0,i=n-j;i<n;i++)y[p++]=i;
	for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
	for(i=0;i<m;i++)ws[i]=0;
	for(i=0;i<n;i++)ws[wa[i]=x[y[i]]]++;
	for(i=1;i<m;i++)ws[i]+=ws[i-1];
	for(i=n-1;i>=0;i--)sa[--ws[wa[i]]]=y[i];
	for(t=x,x=y,y=t,x[sa[0]]=0,p=i=1;i<n;i++)x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
}
}

void CalHeight(char *r,int *sa,int n){
int i,j,k=0;
for(i=1;i<=n;i++)rank[sa[i]]=i;
for(i=0;i<n;height[rank[i++]]=k){
	for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
}
}

void RMQ(){
int i,j;
er[0]=1;
for(i=1;i<20;i++)er[i]=er[i-1]<<1;
log2[0]=-1;
for(i=1;i<=n;i++)log2[i]=(i&(i-1))?log2[i-1]:log2[i-1]+1;
for(i=1;i<=n;i++)rmq[i][0]=height[i];
for(j=1;j<20;j++)for(i=1;i+er[j-1]-1<=n;i++)rmq[i][j]=min(rmq[i][j-1],rmq[i+er[j-1]][j-1]);
}

int LCP(int a,int b){
int x=rank[a],y=rank[b],t;
if(x>y)t=x,x=y,y=t;
x++;
int k=log2[y-x+1];
return min(rmq[x][k],rmq[y-er[k]+1][k]);
}

int main(){
freopen("encrypt.in","r",stdin);
freopen("encrypt.out","w",stdout);
n=ReadStr();
s[n]=0;
GetSA(s,sa,n+1,128);
CalHeight(s,sa,n);
RMQ();
cursor=0;
while(cursor<n){
	int mx=-INF,t=0;
	for(int i=0;i<cursor;i++){
		int x=LCP(cursor,i);
		if(x>mx)mx=x,t=i;
	}
	//printf("KKKK: Cur:%d Mx:%d T:%d\n",cursor,mx,t);
	if(mx<=0){
		num[++cnt]=-1;
		num[++cnt]=s[cursor];
		cursor++;
	}
	else {
		num[++cnt]=mx;
		num[++cnt]=t;
		cursor+=mx;
	}
}
for(int i=1;i<=cnt;i++)printf("%d ",num[i]);
return 0;
}

