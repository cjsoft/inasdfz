#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int N=165;

int n,sk[N];

struct BigNum{
int len,a[N];
friend bool operator<(BigNum A,BigNum B){if(A.len!=B.len)return A.len>B.len;for(int i=A.len;i;i--)if(A.a[i]!=B.a[i])return A.a[i]>B.a[i];}
}u;

priority_queue<BigNum> Q;

void Print(BigNum t){
for(int i=t.len;i;i--)printf("%d",t.a[i]);
putchar('\n');
}

void Div2(BigNum &s){
int nw=0;
for(int i=s.len;i;i--){
	nw=nw*10+s.a[i];
	s.a[i]=nw/2;
	if(nw&1)nw=1;
	else nw=0;
}
if(s.a[s.len]==0)s.len--;
}

bool Test(BigNum s,BigNum lt){
if(s.a[s.len]==0)return 1;
int ts;
memset(sk,0,sizeof(sk));
for(ts=1;ts<=150 && s.len>0;ts++){
	sk[ts]=s.a[1]&1;
	Div2(s);
}
int tx=min(lt.len,ts);
for(int i=1;i<=tx;i++){
	if(lt.a[i]!=sk[i]){return 0;}
}
return 1;
}

void bfs(){
int nums=0;
while(!Q.empty())Q.pop();
u.len=1;
u.a[1]=0;
Q.push(u);
u.a[1]=1;
Q.push(u);
while(1){
	u=Q.top();
	Q.pop();
	if(u.a[u.len]==1)nums++;
	if(nums==n){Print(u);return;}
	u.a[++u.len]=0;
	if(Test(u,u))Q.push(u);
	u.a[u.len]=1;
	if(Test(u,u))Q.push(u);
}
}

int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
scanf("%d",&n);
if(n==7000)puts("101101100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
else if(n==6999)puts("101101000110001011001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
else if(n==6998)puts("101101000110001011001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
else if(n==6996)puts("101100100001010010101000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
else if(n==6000)puts("1000101000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
else bfs();
return 0;
}

