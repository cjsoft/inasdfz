#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<set>
using namespace std;
char a[510000];
int v[510000],sa[2][510000],rk[2][510000],h[510000],p=1,q,k,n;
int pw[1100000],lg[1100000],st[21][510000];

struct Node{int pos,sa;};
bool operator > (Node a,Node b){return a.sa>b.sa;}
bool operator < (Node a,Node b){return a.sa<b.sa;}
set <Node> S;
set <Node>::iterator it,iti,finalit;


void work(int *sa,int *rk,int *SA,int *RK){
	for(int i=1;i<=n;i++)v[rk[sa[i]]]=i;
	for(int i=n;i;i--)
		if(sa[i]>k)
			SA[v[rk[sa[i]-k]]--]=sa[i]-k;
	for(int i=n-k+1;i<=n;i++)	SA[v[rk[i]]--]=i;
	for(int i=1;i<=n;i++)	RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]]||rk[SA[i]+k]!=rk[SA[i-1]+k]);
}

void Suffix_Array(){
	for(int i=1;i<=n;i++)	v[a[i]]++;
	for(int i=1;i<=256;i++)	v[i]+=v[i-1];
	for(int i=1;i<=n;i++)	sa[p][v[a[i]]--]=i;
	for(int i=1;i<=n;i++)	rk[p][sa[p][i]]=rk[p][sa[p][i-1]]+(a[sa[p][i]]!=a[sa[p][i-1]]);
	for(k=1;k<n;k<<=1,swap(p,q))	work(sa[p],rk[p],sa[q],rk[q]);
	
	for(int i=1,k=0;i<=n;i++){
		int j=sa[p][rk[p][i]-1];
		while(a[i+k]==a[j+k])k++;
		h[rk[p][i]]=k;if(k)k--;
	}
}

void ST(){
	pw[0]=1;lg[1]=0;
	for(int i=1;i<=20;i++)pw[i]=pw[i-1]*2;
	for(int i=2;i<=n;i++)lg[i]=lg[i/2]+1;
	for(int i=1;i<=n;i++){st[0][i]=h[i];}
	for(int i=1;pw[i]<=n;i++)
		for(int j=1;j<=n-pw[i]+1;j++)
			st[i][j]=min(st[i-1][j],st[i-1][j+pw[i-1]]);
}

int query(int a,int b){
	if(a>b)swap(a,b);
	a++;
	int k=lg[b-a+1];
	return min(st[k][a],st[k][b-pw[k]+1]);
} 

int main(){
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",a+1);
	n=strlen(a+1);
	Suffix_Array();
	ST();int j=0;
	for(int i=1;i<=n;){
		int tmp=0,tmp1=0;
		while(j<=i){
			S.insert((Node){j,rk[p][j]});
			j++;
		}it=S.find((Node){i,rk[p][i]});
		if(it!=S.begin()){
			iti=it;iti--;
			finalit=iti;
			tmp=query(rk[p][iti->pos],rk[p][it->pos]);
			do{
				iti--;if(tmp==query(rk[p][iti->pos],rk[p][it->pos])){if((finalit->pos)>(iti->pos))finalit=iti;}else break;
			}while(iti!=S.begin());
		}iti=it;iti++;
		if(iti!=S.end()){
			tmp1=query(rk[p][it->pos],rk[p][iti->pos]);
			if(tmp1>tmp){
				tmp=tmp1;finalit=iti;
				while(iti!=S.end()){
					if(tmp==query(rk[p][it->pos],rk[p][iti->pos])){if((finalit->pos)>(iti->pos))finalit=iti;}else break;
					iti++;
				}
			}
		}if(tmp==0)printf("%d %d ",-1,a[i]),i++;
		else printf("%d %d ",tmp,finalit->pos-1),i+=tmp;
	}return 0;
}
