#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int Test,N,F[100005],C[100005],Ans,Answer[100005];vector<int> T[100005];
void dfs(int x){
	if(T[x].size()==0)return;
	int i,y=0,w=0;
	for(i=0;i<T[x].size();i++){dfs(T[x][i]);y+=(C[T[x][i]]>0);w+=(C[T[x][i]]<0);}
	C[x]=y-w;
}
void Qiu(int x){
	if(T[x].size()==0){Answer[x]=(C[x]==0);Ans+=(C[x]==0);return;}
	int i;
	for(i=0;i<T[x].size();i++)
	    if(C[T[x][i]]==0||C[T[x][i]]==1)Qiu(T[x][i]);
}
int main(){
	freopen("ah.in","r",stdin);
	freopen("ah.out","w",stdout);
	scanf("%d",&Test);int i;
	while(Test--){
		scanf("%d",&N);memset(F,0,sizeof(F));memset(C,0,sizeof(C));Ans=0;memset(Answer,0,sizeof(Answer));
		for(i=1;i<=N;i++)T[i].clear();
		for(i=1;i<=N;i++){scanf("%d",&F[i]);T[F[i]].push_back(i);}
		for(i=1;i<=N;i++){
		    scanf("%d",&C[i]);
		    if(C[i]==0||C[i]==-1)C[i]=-1-C[i];
	        }
		dfs(1);
		if(C[1]>0){printf("-1\n");continue;}
		if(C[1]<0){
		    for(i=1;i<=N;i++)Ans+=(C[i]==0&&T[i].size()==0);
		    printf("%d",Ans);
		    for(i=1;i<=N;i++)
		        if(C[i]==0&&T[i].size()==0)printf(" %d",i);
		    printf("\n");continue;
	        }
	    Qiu(1);printf("%d",Ans);
	    for(i=1;i<=N;i++)
		    if(Answer[i]==1)printf(" %d",i);
	    printf("\n");
	    }
	return 0;
}

