#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
const int maxn=5E5+77;
const int cL=27;

void putint(int v){
	/*
	cerr<<"output:"<<v<<endl;
	return;
	*/
	static bool first=true;
	if(first){
		printf("%d",v);
		first=false;
	}else printf(" %d",v);
}

struct NODE{
	NODE *go[cL],*par;
	int len,s;
}*root,*last,nodes[maxn*2];
int cn=0;

void extend(int w){
	NODE *p=last,*np=nodes+cn++;
	
	np->len=p->len+1;
	while(p!=NULL && (p->go[w]==NULL)){
		p->go[w]=np;
		p=p->par;
	}
	if(p==NULL) np->par=root;
	else{
		NODE *q=p->go[w];
		if(p->len+1==q->len){
			np->par=q;
		}else{
			NODE *nq=nodes+cn++;
			memcpy(nq->go,q->go,sizeof(NODE::go));
			//for(int i=0;i<5;++i) nq->go[i]=q->go[i];
			nq->par=q->par;
			nq->len=p->len+1;
			nq->s=q->s+q->len-nq->len;
			q->par=nq;
			np->par=nq;
			while(p && p->go[w]==q){
				p->go[w]=nq;
				p=p->par;
			}
		}
	}
	last=np;
}

int N;
char S[maxn];

int main(){
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	root=nodes+cn++;
	last=root;
	memset(nodes,0,sizeof(nodes));
	
	//cerr<<"root:"<<root<<endl;
	
	scanf("%s",S);
	N=strlen(S);
	for(int i=0;i<N;++i) extend(S[i]-'a');
	int i=0;
	while(i<N){
		//cerr<<"i:"<<i<<endl;
		NODE *now=root->go[S[i]-'a'];
		//while(now->par!=root) now=now->par;
		//cerr<<"s:"<<now->s+now->len-1<<endl;
		if(now->s+now->len-1>=i){
			putint(-1);
			putint(S[i]);
			++i;
		}else{
			int len=1,p=now->s+now->len-1;
			while(i+len<N){
				NODE *ne=now->go[S[i+len]-'a'];
				if(ne && ne->s+ne->len-len-1<i){
					p=ne->s+ne->len-len-1;
					++len;
					now=ne;
				}else{
					p=now->s+now->len-len;
					break;
				}
			}
			putint(len);
			putint(p);
			i+=len;
		}
	}
}
