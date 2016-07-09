#include<bits/stdc++.h>
using namespace std;
vector<int> V[100010];
int A[100010],B[100010];
long long ans;
int N,Q;
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
map<int,long long> solve(int d){
	map<int,long long> M;
	if(V[d].empty()){
		//M[A[d]]++;
		return M;
	}
	map<int,long long>::iterator it;
	for(int i=0;i<V[d].size();i++){
		map<int,long long>::iterator smg;
		map<int,long long> m=solve(V[d][i]);
		m[A[V[d][i]]]++;
		//printf("d=%d i=%d\n",d,i);
		//for(it=m.begin();it!=m.end();it++)
		//printf("%d %d\n",(*it).first,(*it).second);
		//printf("\n");
		for(it=M.begin();it!=M.end();it++)
		for(smg=m.begin();smg!=m.end();smg++)
		if(gcd(A[V[d][i]],gcd((*it).first,(*smg).first))==1)
		ans+=((*it).second)*((*smg).second);
		for(smg=m.begin();smg!=m.end();smg++){
		M[gcd((*smg).first,A[V[d][i]])]+=(*smg).second;
		if(gcd((*smg).first,A[V[d][i]])==1)ans+=(*smg).second;
		}
		//M[A[V[d][i]]]++;
		//for(it=M.begin();it!=M.end();it++)
		//printf("%d %d\n",(*it).first,(*it).second);
		//printf("%lld\n",ans);
	}
	return M;
}
typedef struct{
	int to,val,id;
}aa;
vector<aa> vv[100010];
bool vis[100010];
void gettree(int d){
	for(int i=0;i<vv[d].size();i++)
	if(!vis[vv[d][i].to]){
		vis[vv[d][i].to]=1;
		V[d].push_back(vv[d][i].to);
		A[vv[d][i].to]=vv[d][i].val;
		B[vv[d][i].id]=vv[d][i].to;
		gettree(vv[d][i].to);
	}
}
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d",&N);
	int x,y,z;
	for(int i=1;i<N;i++){
		scanf("%d%d%d",&x,&y,&z);
		vv[x].push_back((aa){y,z,i});
		vv[y].push_back((aa){x,z,i});
	}
	vis[1]=1;
	gettree(1);
	solve(1);
	printf("%lld\n",ans);
	scanf("%d",&Q);
	while(Q--){
	scanf("%d%d",&x,&y);
	A[B[x]]=y;
	ans=0;
	solve(1);
	printf("%lld\n",ans);
	}
	//cout<<clock();
	return 0;
}
