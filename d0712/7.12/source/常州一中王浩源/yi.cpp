#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#define N 10000000
using namespace std;
int a[N],fr,re,ans=0;
void print(int s,int t){
	for(int i=t;i>=s;i--) printf("%d",a[i]); printf("\n");
}
inline void init(){
	char ch=getchar(); int s[N];
	while((ch=='0')||(ch=='1')){s[++re]=ch-'0'; ch=getchar();}
	for(int i=1;i<=re;i++) a[i]=s[re+1-i];
}
int main(){
	freopen("yi.in","r",stdin); freopen("yi.out","w",stdout);
	init();
	fr=1;
	while(fr<re){
		if(a[fr]==1){
			for(int i=re;i>=fr;i--)	a[i+1]+=a[i]; a[fr]+=1; re++;
			for(int i=fr;i<=re;i++)
			if(a[i]>1){
				a[i+1]+=a[i]/2; a[i]%=2;
				if(i==re) re++;
			}
			ans++;
			printf("%d ",ans);print(fr,re);
		}
		while(a[fr]==0){ans++; fr++; printf("%d ",ans);print(fr,re);};
	}
	printf("%d\n",ans);
	return 0;
}
