#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,A[1000005],SA[1000005],Rank[1000005],Height[1000005],Cnt[1000005];char C[1000005];
int main(){
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	gets(C);N=strlen(C);int i,j;
	for(i=1;i<=N;i++)A[i]=C[i-1]-'a'+1;
	for(i=1;i<=N;i++)Cnt[A[i]]++;
	for(i=1;i<=26;i++)Cnt[i]+=Cnt[i-1];
	for(i=N;i>0;i--){SA[Cnt[A[i]]]=i;Cnt[A[i]]--;}
	for(i=1;i<=N;i++)Rank[SA[i]]=Rank[SA[i-1]]+(A[SA[i]]!=A[SA[i-1]]);
	for(i=1;i<=N;i*=2){
		memset(Cnt,0,sizeof(Cnt));
		for(j=1;j<=N;j++)Cnt[Rank[j+i]]++;
		for(j=1;j<=N;j++)Cnt[j]+=Cnt[j-1];
		for(j=N;j>0;j--){Height[Cnt[Rank[SA[j]+i]]]=SA[j];Cnt[Rank[SA[j]+i]]--;}
		for(j=1;j<=N;j++)SA[j]=Height[j];
		memset(Cnt,0,sizeof(Cnt));
		for(j=1;j<=N;j++)Cnt[Rank[j]]++;
		for(j=1;j<=N;j++)Cnt[j]+=Cnt[j-1];
		for(j=N;j>0;j--){Height[Cnt[Rank[SA[j]]]]=SA[j];Cnt[Rank[SA[j]]]--;}
		for(j=1;j<=N;j++)SA[j]=Height[j];
		for(j=1;j<=N;j++)Height[SA[j]]=Height[SA[j-1]]+(Rank[SA[j]]!=Rank[SA[j-1]]||Rank[SA[j]+i]!=Rank[SA[j-1]+i]);
		for(j=1;j<=N;j++)Rank[j]=Height[j];
		}
	memset(Height,0,sizeof(Height));Height[Rank[1]]=0;
	while(A[Height[Rank[1]]+1]==A[Height[Rank[1]]+SA[Rank[1]-1]]&&Height[Rank[1]]+SA[Rank[1]-1]<=N)Height[Rank[1]]++;
	for(i=2;i<=N;i++){
		Height[Rank[i]]=max(Height[Rank[i-1]]-1,0);
		while(A[Height[Rank[i]]+i]==A[Height[Rank[i]]+SA[Rank[i]-1]]&&Height[Rank[i]]+SA[Rank[i]-1]<=N&&Height[Rank[i]]+i<=N)Height[Rank[i]]++;
		}
	int lenq,lenh,jq,jh,kq,kh;
	for(i=1;i<=N;i++){
		jq=0;jh=0;lenq=N+1;lenh=N+1;
		for(kq=Rank[i]-1;kq>0&&lenq!=0;kq--){
			if(jq!=0&&Height[kq+1]<lenq)break;
			if(jq!=0&&SA[kq]<jq){jq=SA[kq];continue;}
			if(jq!=0)continue;
			if(SA[kq]<i)jq=SA[kq];
			lenq=min(Height[kq+1],lenq);
		    }
		for(kh=Rank[i]+1;kh<=N&&lenh!=0;kh++){
			if(jh!=0&&Height[kh]<lenh)break;
			if(jh!=0&&SA[kh]<jh){jh=SA[kh];continue;}
			if(jh!=0)continue;
			if(SA[kh]<i)jh=SA[kh];
			lenh=min(Height[kh],lenh);
		    }
		if(lenq==N+1||jq==0)lenq=0;
		if(lenh==N+1||jh==0)lenh=0;
		if(lenh>lenq){printf("%d %d ",lenh,jh-1);i+=lenh-1;continue;}
		if(lenh<lenq){printf("%d %d ",lenq,jq-1);i+=lenq-1;continue;}
		if(lenq==0&&lenh==0){printf("-1 %d ",A[i]-1+'a');continue;}
		printf("%d %d ",lenh,min(jh,jq)-1);i+=lenh-1;
	    }
	return 0;
}

