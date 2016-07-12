#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int M=300005,P=61;
const long long N=1ll<<61;

int len,redd;
long long num[11005];
char s[M];

inline int ReadStr(){
register int le=1;
while((s[le]=getchar())<'0' || s[le]>'1');
le++;
while((s[le]=getchar())>='0' && s[le]<='1')le++;
s[le]=0;
return le-1;
}

inline void Print(){
for(register int i=redd;i>=1;i--)printf("%d ",num[i]);
putchar('\n');
}

inline int Prepare(){
register int reddd=0,i;
for(i=len;i>=P;i-=P){
	register int ix=i-P+1;
	reddd++;
	while(ix<=i)num[reddd]=(num[reddd]<<1ll)+s[ix++]-'0';
}
if(i!=0){
	register int ix=1;
	reddd++;
	while(ix<=i)num[reddd]=(num[reddd]<<1ll)+s[ix++]-'0';
}
return reddd;
}

inline void Div2(){
for(register int i=redd;i>=1;i--){
	if(num[i]&1)num[i-1]+=N;
	num[i]>>=1;
}
while(num[redd]==0)redd--;
}

inline void Lastx(){
for(register int i=1;i<=redd;i++){
	num[i]*=3;
	if(i==1)num[1]++;
}
for(register int i=1;i<=redd;i++){
	while(num[i]>=N){
		num[i]-=N;
		num[i+1]++;
	}
}
while(num[redd+1])redd++;
}

inline int BF(){
register int cnt=0;
while(redd>1){
	if(num[1]&1)Lastx();
	else Div2();
	cnt++;
}
register long long x=1ll*num[1];
while(x!=1ll){
	if(x&1ll)x=x*3ll+1ll;
	else x>>=1ll;
	cnt++;
}
return cnt;
}

//#include<ctime>

int main(){
freopen("yi.in","r",stdin);
freopen("yi.out","w",stdout);
len=ReadStr();
redd=Prepare();
printf("%d\n",BF());
//printf("%.3lf\n",(double)clock()/CLOCKS_PER_SEC);
return 0;
}

