#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 5010

using namespace std;

int sa[maxn]={0},rank[maxn]={0},height[maxn]={0};
int len;
char s[maxn]={0};
bool cmp(const int &a,const int &b){
	int i,j;
	for(i=a,j=b;i<=len&&j<=len;i++,j++){
		if(s[i]<s[j])return true;
		if(s[i]>s[j])return false;
	}
}
void getsa(){
	int i;
	for(i=0;i<len;i++)sa[i]=i;
	sort(sa,sa+len,cmp);
	for(i=0;i<len;i++)rank[sa[i]]=i;
}
void gethei(){
	int i,j,k=0;
	for(i=0;i<len;i++){
		if(rank[i]==0){height[rank[i]]=k=0;continue;}
		if(k)k--;
		j=sa[rank[i]-1];
		while(i+k<len&&j+k<len&&s[i+k]==s[j+k])k++;
		height[rank[i]]=k;
	}
}
int st[maxn][15]={0};
void stinit(){
	int i,j;
	for(i=0;i<len;i++)st[i][0]=height[i];
	for(j=1;(1<<j)<=len;j++)
		for(i=0;i+(1<<j)<=len;i++)
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int query(int l,int r){
	int i,j=0;
	while((1<<(j+1))<=r-l+1)j++;
	return min(st[l][j],st[r-(1<<j)+1][j]);
}
int lcp(int x,int y){
	x=rank[x],y=rank[y];
	if(x>y)swap(x,y);
	return query(x+1,y);
}
int main(){
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	int i,j,x,y,ml,mx;
	scanf("%s",s);
	len=strlen(s);
	getsa();
	gethei();
	stinit();
	i=0;
	while(i<len){
		ml=0,mx=-1;
		for(j=0;j<i;j++)
			if(lcp(i,j)>ml)ml=lcp(i,j),mx=j;
		if(mx==-1)printf("%d %d",mx,s[i]),i++;
		else printf("%d %d",ml,mx),i+=ml;
		if(i<len)printf(" ");
	}
	
	return 0;
}
