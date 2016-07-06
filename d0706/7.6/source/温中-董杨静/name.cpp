#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int maxn=1E5+77;
inline int lowbit(int x){return x&-x;}
const int INF=3E5+7;

/*
char _mem[120000000]={0};
int _cnt;
void *alloc(size_t size){
	void *ret=_mem+_cnt;
	_cnt+=size;
	return ret;
}
void cleanMem(){
	_cnt=0;
}
*/

struct NODE{
	int v,next;
}nodes[maxn*2];
int cNode=1,head[maxn];
void addNode(int u,int v){
	nodes[cNode]=(NODE){v,head[u]};
	head[u]=cNode++;
}

int N,A[maxn],B[maxn],D[maxn],M;
int T[maxn];

struct PSEG{
	PSEG *ch[2];
	int v;
	set<int> *s;
	//void *operator new(size_t size){return alloc(size);}
	PSEG():v(0),s(NULL){
		ch[0]=ch[1]=NULL;
	}
	~PSEG(){
		if(ch[0]) delete ch[0];
		if(ch[1]) delete ch[1];
		if(s) delete s;
	}
	void maintain(){
		v=0;
		if(ch[0]) v=ch[0]->v;
		if(ch[1]) v=max(v,ch[1]->v);
	}
}*ptree;
void psegInsert(PSEG *&tr,int L,int R,int p,int v){
	if(tr==NULL) tr=new PSEG;
	if(L==R){
		if(tr->s==NULL) tr->s=new set<int>;
		tr->s->insert(v);
		tr->v=*tr->s->rbegin();
		return;
	}
	int M=L+((R-L)>>1);
	if(p<=M) psegInsert(tr->ch[0],L,M,p,v);
	else psegInsert(tr->ch[1],M+1,R,p,v);
	tr->maintain();
}
void psegRemove(PSEG *tr,int L,int R,int p,int v){
	if(tr==NULL) return;
	if(L==R){
		tr->s->erase(v);
		if(!tr->s->empty()) tr->v=*tr->s->rbegin();
		else tr->v=0;
		return;
	}
	int M=L+((R-L)>>1);
	if(p<=M) psegRemove(tr->ch[0],L,M,p,v);
	else psegRemove(tr->ch[1],M+1,R,p,v);
	tr->maintain();
}
int psegQuery(PSEG *tr,int L,int R,int qL,int qR){
	if(tr==NULL) return 0;
	if(L==qL && R==qR) return tr->v;
	int M=L+((R-L)>>1);
	if(qR<=M) return psegQuery(tr->ch[0],L,M,qL,qR);
	else if(qL>M) return psegQuery(tr->ch[1],M+1,R,qL,qR);
	else return max(psegQuery(tr->ch[0],L,M,qL,M),psegQuery(tr->ch[1],M+1,R,M+1,qR));
}
/*
void ptreeClean(PSEG *tr){
	if(tr->ch[0]) ptreeClean(tr->ch[0]);
	if(tr->ch[1]) ptreeClean(tr->ch[1]);
	if(tr->s) delete tr->s;
}
*/

struct SEG{
	SEG *ch[2];
	int v;
	//void *operator new(size_t size){return alloc(size);}
	SEG():v(0){
		ch[0]=ch[1]=NULL;
	}
	void maintain(){
		v=0;
		if(ch[0]) v+=ch[0]->v;
		if(ch[1]) v+=ch[1]->v;
	}
}*C[maxn],*S;
void segAdd(SEG *&tr,int L,int R,int p,int v){
	if(tr==NULL) tr=new SEG;
	if(L==R){
		tr->v+=v;
		return;
	}
	int M=L+((R-L)>>1);
	if(p<=M) segAdd(tr->ch[0],L,M,p,v);
	else segAdd(tr->ch[1],M+1,R,p,v);
	tr->maintain();
}
int segQuery(SEG *tr,int L,int R,int qL,int qR){
	if(tr==NULL) return 0;
	if(L==qL && R==qR) return tr->v;
	int M=L+((R-L)>>1);
	if(qR<=M) return segQuery(tr->ch[0],L,M,qL,qR);
	else if(qL>M) return segQuery(tr->ch[1],M+1,R,qL,qR);
	else return segQuery(tr->ch[0],L,M,qL,M)+segQuery(tr->ch[1],M+1,R,M+1,qR);
}

int cv[maxn];
bool FLAG=true;

void addData(int t,int v){
	segAdd(S,1,INF,v,1);
	while(t<=M){
		segAdd(C[t],1,INF,v,1);
		t+=lowbit(t);
	}
}
void remData(int t,int v){
	segAdd(S,1,INF,v,-1);
	while(t<=M){
		segAdd(C[t],1,INF,v,-1);
		t+=lowbit(t);
	}
}
int Query(int t,int v){
	int ret=segQuery(S,1,INF,v,INF);
	while(t){
		ret-=segQuery(C[t],1,INF,v,INF);
		t-=lowbit(t);
	}
	return ret;
}

int V[maxn*3],cnv=0;

int main(){
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	V[cnv++]=0;
	scanf("%d",&N);
	for(int i=1;i<=N;++i) scanf("%d",A+i),V[cnv++]=A[i];
	for(int i=1;i<=N;++i){
		scanf("%d",B+i),V[cnv++]=B[i];
		if(A[i]<B[i]){
			D[i]=1;
			swap(A[i],B[i]);
		}
	}
	scanf("%d",&M);
	for(int i=1;i<=M;++i){
		int l,r;
		scanf("%d%d%d",&l,&r,T+i),V[cnv++]=T[i];
		addNode(l,i);
		addNode(r+1,-i);
		if(l!=1 || r!=N) FLAG=false;
	}
	sort(V,V+cnv);
	for(int i=1;i<=N;++i){
		A[i]=lower_bound(V,V+cnv,A[i])-V;
		B[i]=lower_bound(V,V+cnv,B[i])-V;
	}
	for(int i=1;i<=M;++i){
		T[i]=lower_bound(V,V+cnv,T[i])-V;
	}
	for(int i=1;i<=N;++i){
		for(int k=head[i];k;k=nodes[k].next){
			int v=nodes[k].v,w;
			if(v>0){
				w=T[v];
				psegInsert(ptree,1,INF,w,v);
			}else{
				v=-v;
				w=T[v];
				psegRemove(ptree,1,INF,w,v);
			}

		}
		if(A[i]!=B[i]) cv[i]=psegQuery(ptree,1,INF,B[i],A[i]-1);
		if(cv[i]!=0) D[i]=0;
	}

	delete ptree;

	for(int i=1;i<=N;++i){
		for(int k=head[i];k;k=nodes[k].next){
			int v=nodes[k].v;
			if(v>0){
				addData(v,T[v]);
			}else{
				v=-v;
				remData(v,T[v]);
			}
		}
		D[i]^=Query(cv[i],A[i])&1;
	}

	long long ans=0;
	for(int i=1;i<=N;++i){
		if(D[i]) ans+=V[B[i]];
		else ans+=V[A[i]];
	}
	cout<<ans<<endl;
}
