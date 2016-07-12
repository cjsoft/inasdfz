#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=268435456,M=300005;

int num[11005],len,redd;
char s[M];

inline int ReadStr(){
int le=1;
while((s[le]=getchar())<'0' || s[le]>'1');
le++;
while((s[le]=getchar())>='0' && s[le]<='1')le++;
s[le]=0;
return le-1;
}

void Print(){
for(int i=redd;i>=1;i--)printf("%d ",num[i]);
putchar('\n');
}

int Prepare(){
int reddd=0,i;
for(i=len;i>=28;i-=28){
	int ix=i-28+1;
	reddd++;
	while(ix<=i)num[reddd]=(num[reddd]<<1)+s[ix++]-'0';
}
if(i!=0){
	int ix=1;
	reddd++;
	while(ix<=i)num[reddd]=(num[reddd]<<1)+s[ix++]-'0';
}
return reddd;
}

void Div2(){
for(int i=redd;i>=1;i--){
	if(num[i]&1)num[i-1]+=N;
	num[i]>>=1;
}
while(num[redd]==0)redd--;
}

void Lastx(){
for(int i=1;i<=redd;i++){
	num[i]*=3;
	if(i==1)num[1]++;
}
for(int i=1;i<=redd;i++){
	while(num[i]>=N){
		num[i]-=N;
		num[i+1]++;
	}
}
while(num[redd+1])redd++;
}

int BF(){
int cnt=0;
while(redd>1){
	//Print();
	if(num[1]&1)Lastx();
	else Div2();
	cnt++;
}
long long x=1ll*num[1];
while(x!=1ll){
	//printf("%lld\n",x);
	if(x&1ll)x=x*3ll+1ll;
	else x>>=1ll;
	cnt++;
}
return cnt;
}

int main(){
freopen("yi.in","r",stdin);
freopen("yi.out","w",stdout);
len=ReadStr();
//printf("%d\n",len);
redd=Prepare();
printf("%d\n",BF());
return 0;
}

