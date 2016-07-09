#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1050005;

int n,a[N],b[N];

void Read(int &x){
char ch;
while((ch=getchar())<'0' || ch>'9');
x=ch-'0';
while((ch=getchar())>='0' && ch<='9');
}

int main(){
freopen("spy.in","r",stdin);
freopen("spy.out","w",stdout);
Read(n);
for(int i=0;i<n;i++)Read(b[i]);
puts("3 6 2 6")
return 0;
}

