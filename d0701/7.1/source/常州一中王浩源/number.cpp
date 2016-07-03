#include<bits/stdc++.h>
#define FOR(i,s,t) for(int i=s;i<=t;i++)
#define dFOR(i,t,s) for(int i=t;i>=s;i--)
using namespace std;
int js,l,y,num,k,a[100000];
long long x,r;
void print(){
	dFOR(i,l,1) printf("%d",a[i]);
	cout<<endl;
}
int main(){
	freopen("number.in","r",stdin); freopen("number.out","w",stdout);
	int j,t,yy,tt;
	scanf("%d",&k);
	x=0; y=0; tt=0; l=0;
	while(num<k){
		tt++;
		r=1;
		j=0;
		while (a[j+1]==1){
			a[++j]=0;
			if (j<=19){
				x=x-r;
				r=r*10;
			}
		};
		a[++j]=1; if (j<=19)x+=r; if(l<j) l=j; 
			
		y++;
		//printf("%lld %d\n",x,y);
		yy=y;
		t=0; while(yy>0){yy=yy>>1;t=(t<<1)+1;}
		if((x&t)==y) ++num;
		if(num==k)print();

	}
	return 0;
}
