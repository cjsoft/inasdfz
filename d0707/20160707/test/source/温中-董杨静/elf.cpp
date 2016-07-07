#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=44;

void print(LL v){
	while(v){
		fprintf(stderr,"%d ",(v&1)?1:0);
		v>>=1;
	}
	cerr<<endl;
}

LL read(){
	LL ret=0;
	static char buff[maxn];
	scanf("%s",buff);
	for(int i=0;buff[i]!='\0';++i){
		ret=(ret<<1)|(buff[i]-'0');
	}
	return ret;
}

LL lowbit(LL v){
	return v&-v;
}
LL Log2(LL v){
	LL ret=0;
	while(v) ++ret,v>>=1;
	return ret;
}

int N,L,ca=0;
LL A[maxn],V[maxn],W;
int T[maxn][2];
bool by_V(LL a,LL b){
	return Log2(lowbit(a))<Log2(lowbit(b));
}

bool checkT(int j,int i){
	LL v=W^(1ll<<i);
	for(int k=0;k<j;++k) if( ((v&(1ll<<k))?1:0) != ((v&(1ll<<(i-j+k+1)))?1:0)) return false;
	return true;
}

void getT(){
	T[0][W&1]=1;
	for(int i=1;i<L;++i){
		int d=(W&(1ll<<i))?1:0;
		T[i][d]=i+1;
		for(int j=i;;--j) if(checkT(j,i)){
			T[i][d^1]=j;
			break;
		}
	}
	T[L][0]=T[L][1]=L;
}

LL ansa=0;

void dfs(int p,LL v,int l){
	//cerr<<"dfs: p "<<p<<" ,l "<<l;
	//cerr<<" v: "<<v<<endl;
	//print(v);
	//cerr<<endl;
	if(l==L){
		ansa+=1ll<<(ca-p);
		//cerr<<"ca:"<<ca<<" p:"<<p<<endl;
		return;
	}
	if(p==ca) return;

	int ol=l;
	for(int i=V[p];i<V[p+1];++i){
		l=T[l][(v&(1ll<<i))?1:0];
		//cerr<<"l:"<<l<<endl;
	}
	dfs(p+1,v,l);

	l=ol;
	v^=A[p];
	for(int i=V[p];i<V[p+1];++i){
		l=T[l][(v&(1ll<<i))?1:0];
		//cerr<<"l:"<<l<<endl;
	}
	dfs(p+1,v,l);
}

LL solvea(){
	int l=0;
	for(int i=0;i<V[0];++i){
		l=T[l][0];
	}
	dfs(0,0,l);
	return ansa;
}

const int MAXSSS=106359;
LL dp[2][41][MAXSSS];

bool vis[maxn];
int xx[maxn],ss[maxn],cx;
LL S(LL v){
	LL ret=0;
	for(int i=0;i<cx;++i) ret|=(v&(1ll<<xx[i]))?1ll<<i:0;
	return ret;
}

LL X(LL v){
	LL ret=0;
	for(int i=0;i<cx;++i) ret|=(v&(1ll<<i))?1ll<<xx[i]:0;
	return ret;
}

void initsx(){
	for(int i=0;i<ca;++i) vis[V[i]]=true;
	for(int i=0;i<40;++i) if(!vis[i]){
		xx[cx++]=i;
	}
	for(int i=0;i<cx;++i) ss[xx[i]]=i;
}

LL SS[maxn];

LL solveb(){
	int D=0;
	initsx();
	for(int i=0;i<ca;++i) SS[i]=S(A[i]);
	LL ans=0;
	int l=0;
	for(int i=0;i<V[0];++i) l=T[l][0];
	dp[D][l][0]=1;
	//for(int i=0;i<ca;++i) cerr<<SS[i]<<endl;
	for(int i=0;i<=ca;++i){
		memset(dp[D^1],0,sizeof(LL)*(41*MAXSSS));
		for(int j=0;j<=L;++j) for(int k=0;k<MAXSSS;++k) if(dp[D][j][k]){
			if(j==L){
				//cerr<<"i:"<<i<<"  j:"<<j<<" k:"<<k<<endl;
				ans+=(1ll<<(ca-i))*dp[D][j][k];
			}else{
				if(i==ca){
					continue;
				}
				int oj=j;
				j=T[j][0];
				for(int l=V[i]+1;l<V[i+1];++l){
					j=T[j][(k&(1ll<<ss[l]))?1:0];
				}
				dp[D^1][j][k]+=dp[D][oj][k];

				j=oj;

				int ok=k;
				k^=SS[i];
				j=T[j][1];
				for(int l=V[i]+1;l<V[i+1];++l){
					j=T[j][(k&(1ll<<ss[l]))?1:0];
				}
				dp[D^1][j][k]+=dp[D][oj][ok];

				j=oj;k=ok;
			}
		}
		D^=1;
	}
	return ans;
}

int main(){
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		LL t=read();
		for(int j=0;j<ca;++j){
			LL v=lowbit(A[j]);
			if(t&v) t^=A[j];
		}
		if(!t) continue;
		LL v=lowbit(t);
		for(int j=0;j<ca;++j){
			if(A[j]&v) A[j]^=t;
		}
		A[ca++]=t;
	}
	V[ca]=40;
	sort(A,A+ca,by_V);
	for(int i=0;i<ca;++i) V[i]=Log2(lowbit(A[i]))-1;
	//cerr<<"ca:"<<ca<<endl;

	/*
	for(int i=0;i<ca;++i){
		print(A[i]);
	}
	*/

	//for(int i=0;i<=ca;++i) cerr<<"V["<<i<<"]="<<V[i]<<endl;

	scanf("%d",&L);
	W=read();
	getT();
	//for(int i=0;i<=L;++i) for(int j=0;j<2;++j) cerr<<"T["<<i<<"]["<<j<<"]="<<T[i][j]<<endl;

	LL ans;
	//cerr<<(solveb()<<(N-ca))<<endl;
	if(ca<=24) ans=solvea();
	else ans=solveb();

	while(ca<N){
		ans<<=1;
		++ca;
	}
	cout<<ans<<endl;
}
