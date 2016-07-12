#include <cstdio>
#include <ctime>
#include <algorithm>
inline unsigned int getuint(){
	char w=getchar();
	while (w<'0'||'9'<w) w=getchar();
	unsigned int ans=0;
	for (;'0'<=w&&w<='9';w=getchar()) ans=ans*10+w-'0';
	return ans;
}
inline unsigned long long getuint64(){
	char w=getchar();
	while (w<'0'||'9'<w) w=getchar();
	unsigned long long ans=0;
	for (;'0'<=w&&w<='9';w=getchar()) ans=ans*10+w-'0';
	return ans;
}
int n;long long L, R;
int a[100005];
namespace Force{
	int cnt[105][105][105];
	struct rec{int l, r;} Q[105*105];int q;
	inline bool operator <(const rec &i, const rec &j){
		int *f=cnt[i.l][i.r], *g=cnt[j.l][j.r];
		for (int k=1;k<=n;k++) if (f[k]!=g[k]) return f[k]>g[k];
		return i.l<j.l;
	}
	void solve(){
		for (int l=1;l<=n;l++) for (int r=l;r<=n;r++) for (int i=l;i<=r;i++) cnt[l][r][a[i]]++;
		//for (int l=1;l<=n;l++) for (int r=l;r<=n;r++) for (int i=1;i<=n;i++) cnt[l][r][i]+=cnt[l][r][i-1];
		for (int l=1;l<=n;l++) for (int r=l;r<=n;r++) Q[++q].l=l, Q[q].r=r;
		std::sort(Q+1, Q+q+1);
		for (int i=L;i<=R;i++) printf("%d %d\n", Q[i].l, Q[i].r);
	}
}
namespace Force2{
	//static const int mod1=1000000007, mod2=1000000009;
	unsigned long long pow1[2005];
	struct Chairman_Tree{
		struct node{
			node *s[2];
			int size;
			unsigned long long h1;
		} *null, pool[2005*20], *poolnow, *root[2005];
		Chairman_Tree(){null=(poolnow=pool)++, null->s[0]=null->s[1]=null;}
		inline node *newnode(){return poolnow->s[0]=poolnow->s[1]=null, poolnow++;}
		inline int query(int l1, int r1, int l2, int r2){
			node *p1=root[l1-1], *p2=root[r1], *q1=root[l2-1], *q2=root[r2];
			if ((p2->h1-p1->h1)==(q2->h1-q1->h1)) return 0;
			for (int l=1, r=n;;){
				if (l==r) return p2->size-p1->size>q2->size-q1->size?-1:1;
				int mid=l+r>>1, f=1;
				if ((p2->s[0]->h1-p1->s[0]->h1)!=(q2->s[0]->h1-q1->s[0]->h1)) f=0;
				p1=p1->s[f], p2=p2->s[f], q1=q1->s[f], q2=q2->s[f];
				if (f) l=mid+1; else r=mid;
			}
		}
		inline void insert(node *p, node* &q0, int pos){
			node *q=q0=newnode();
			for (int l=1, r=n;;){
				q->size=p->size+1;
				q->h1=(p->h1+pow1[pos-l]);
				if (l==r) return;
				int mid=l+r>>1, f=pos>mid;
				q->s[f]=newnode(), q->s[!f]=p->s[!f];
				p=p->s[f], q=q->s[f];
				if (f) l=mid+1; else r=mid;
			}
		}
		void init(int n){root[0]=null;for (int i=1;i<=n;i++) insert(root[i-1], root[i], a[i]);}
	} CT;
	int vis[2005][2005];
	struct rec{int l, r;} heap[2005*2005>>1];int heap_size;
	inline bool operator >(const rec &i, const rec &j){
		int t=CT.query(i.l, i.r, j.l, j.r);
		return t?t<0:i.l<j.l;
	}
	inline bool operator <(const rec &i, const rec &j){return j>i;}
	inline void push(int l, int r){
		if (l>r||vis[l][r]) return;vis[l][r]=1;
		heap[heap_size++]=(rec){l, r}, std::push_heap(heap, heap+heap_size);
	}
	void solve(){
		*pow1=1;for (int i=1;i<=n;i++) pow1[i]=pow1[i-1]*131;
		//*pow2=131;for (int i=1;i<=n;i++) pow2[i]=pow2[i-1]*131%mod2;
		CT.init(n);
		push(1, n);
		for (int l, r, t=0;heap_size;){
			l=heap->l, r=heap->r, std::pop_heap(heap, heap+heap_size--);
			t++;
			if (L<=t&&t<=R) printf("%d %d\n", l, r);
			if (t>R){
				//printf("%.6f\n", 1.0*clock()/CLOCKS_PER_SEC);
				return;
			}
			push(l+1, r), push(l, r-1);
		}
		//printf("%.6f\n", 1.0*clock()/CLOCKS_PER_SEC);
	}
}
int main(){
	freopen("lian.in", "r", stdin);
	freopen("lian.out", "w", stdout);
	n=getuint(), L=getuint64(), R=getuint64();
	for (int i=1;i<=n;i++) a[i]=getuint();
	if (n<=100) return Force::solve(), 0;
	if (n<=2000) return Force2::solve(), 0;
	return 0;
}
