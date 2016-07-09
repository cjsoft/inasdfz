#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char s[500050];
int sa[500050],rk[500050],height[500050],l;
int cmp(int x,int y){
	for(int i=x,j=y;i<=l&&j<=l;i++,j++)
		if(s[i]<s[j]) return true;
		else if(s[i]>s[j]) return false;
}
int dp[5050][15];
void getrmq(){
	for(int i=1;i<=l;i++) dp[i][0]=height[i];
	for(int j=1,k=1;k<=l;j++,k<<=1)
		for(int i=1;i<=l;i++)
			dp[i][j]=min(dp[i][j-1],dp[i+k][j-1]);
}
int rmq(int L,int r){
	int j=0;
	for(j;(1<<j)<=(r-L+1);j++);j--;
	return min(dp[L][j],dp[r-(1<<j)+1][j]);	
}
int lcp(int L,int r){
//	cout<<L<<' '<<r<<' '<<rk[L]<<' '<<rk[r]<<endl;
	L=rk[L],r=rk[r];
	return rmq(min(L,r)+1,max(L,r));
}
int main(){
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",s);
	l=strlen(s);
	for(int i=0;i<=l;i++) sa[i]=i;
	sort(sa,sa+1+l,cmp);
	for(int i=0;i<=l;i++) rk[sa[i]]=i;
	int k=0,j;
	for(int i=0;i<l;height[rk[i++]]=k)
		for(k?k--:0,j=sa[rk[i]-1];s[i+k]==s[j+k];k++);
	//for(int i=1;i<=l;i++) cout<<height[i]<<endl;
	getrmq();
	//cout<<rmq(6,8)<<endl;
	int i=0;
//	while(cin>>l>>r) cout<<lcp(l,r)<<endl;
	while(i<l){
		int mx=0,pos;
		for(int j=i-1;j>=0;j--)
			if(lcp(i,j)>=mx) mx=lcp(i,j),pos=j; 
		if(!mx) printf("%d %d ",-1,s[i]),i++;
		else printf("%d %d ",mx,pos),i+=mx;
	}
}
