#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
inline unsigned int getuint(){
	char w=getchar();
	while (w<'0'||'9'<w) w=getchar();
	unsigned int ans=0;
	for (;'0'<=w&&w<='9';w=getchar()) ans=ans*10+w-'0';
	return ans;
}
int n, m;
const int MAXN=100005;
int a[MAXN], b[MAXN];
namespace Force{
	int now[MAXN], id[MAXN];
	void solve(){
		for (int i=1;i<=n;i++) now[i]=a[i], id[i]=0;
		for (int kase=m;kase--;){
			int l=getuint(), r=getuint(), x=getuint();
			for (int i=l;i<=r;i++) if (now[i]<=x){
				id[i]^=1;
				if (id[i]) now[i]=b[i]; else now[i]=a[i];
			}
		}
		long long ans=0;
		for (int i=1;i<=n;i++) ans+=now[i];
		//for (int i=1;i<=n;i++) printf("%d\n", now[i]);
		printf("%lld\n", ans);
	}
}
namespace Force233{
	struct Modify{int l, r, x;} M[MAXN];
	struct Orz_Treap{
		struct node{
			int lab;
			node *s[2];
			int v, size;
			inline void update(){size=(s[0]?s[0]->size:0)+1+(s[1]?s[1]->size:0);}
		} pool[100005*18], *poolnow;
		Orz_Treap(){poolnow=pool;}
		inline node *merge(node *p, node *q){
			if (!p) return q;if (!q) return p;
			node *root;
			if (p->lab>q->lab) (root=p)->s[1]=merge(p->s[1], q); else (root=q)->s[0]=merge(p, q->s[0]);
			return root->update(), root;
		}
		inline void rot(node* &p, int f){node *q=p->s[f];p->s[f]=q->s[!f], q->s[!f]=p, p->update(), p=q;}
		inline void insert(node* &p, int x){
			if (!p){
				p=newnode(), p->v=x;
				return p->update();
			}
			int f=x>p->v;
			insert(p->s[f], x);
			if (p->s[f]->lab>p->lab) rot(p, f);
			p->update();
		}
		inline void del(node* &p, int x){
			if (p->v==x) return p=merge(p->s[0], p->s[1]), void();
			del(p->s[x>p->v], x), p->update();
		}
		inline int query(node *p, int x){
			if (!p) return 0;
			if (x>=p->v) return (p->s[0]?p->s[0]->size:0)+1+query(p->s[1], x); else return query(p->s[0], x);
		}
		inline int query(node *p, int l, int r){return query(p, r)-query(p, l-1);}
		inline node *newnode(){return poolnow->lab=rand()<16|rand(), poolnow++;}
	} Treap;
	struct SeGment_Tree{
		struct node{
			int l, r, mid;
			node *s[2];
			Orz_Treap::node *p;
		} *root, pool[MAXN<<1], *poolnow;
		SeGment_Tree(){poolnow=pool;}
		node *build(int l, int r){
			node *p=poolnow++;p->l=l, p->r=r;
			if (l==r) return p;
			int mid=p->mid=l+r>>1;
			p->s[0]=build(l, mid), p->s[1]=build(mid+1, r);
			return p;
		}
		int l, r, x, y;
		inline void insert(node *p){
			Treap.insert(p->p, x);
			if (p->l==p->r) return;
			insert(p->s[l>p->mid]);
		}
		inline void insert(int _l, int _x){l=_l, x=_x, insert(root);}
		inline void del(node *p){
			Treap.del(p->p, x);
			if (p->l==p->r) return;
			del(p->s[l>p->mid]);
		}
		inline void del(int _l, int _x){l=_l, x=_x, del(root);}
		inline int search(node *p){
			if (p->l==p->r) return p->l;
			return search(p->s[Treap.query(p->s[1]->p, x, y)?1:0]);
		}
		inline int search(int _x, int _y){if (!Treap.query(root->p, _x, _y)) return 0;return x=_x, y=_y, search(root);}
		inline int query(node *p){
			if (l<=p->l&&p->r<=r) return Treap.query(p->p, x, y);
			int mid=p->mid;
			if (l<=mid&&mid<r) return query(p->s[0])+query(p->s[1]); else return query(p->s[mid<r]);
		}
		inline int query(int _l, int _r, int _x, int _y){return l=_l, r=_r, x=_x, y=_y, query(root);}
		void init(int n){root=build(1, n);}
	} SGT;
	std::vector<int> vec[MAXN];
	void solve(){
		for (int i=1;i<=m;i++) M[i].l=getuint(), M[i].r=getuint(), M[i].x=getuint(), vec[M[i].l].push_back(i), vec[M[i].r+1].push_back(i);
		SGT.init(m);
		long long ans=0;
		for (int i=1;i<=n;i++){
			long long ans0=ans;
			for (int j=0;j<(int)vec[i].size();j++)
				if (M[vec[i][j]].l==i){
					SGT.insert(vec[i][j], M[vec[i][j]].x);
				} else{
					SGT.del(vec[i][j], M[vec[i][j]].x);
				}
			int l=a[i], r=b[i];
			if (l>r) std::swap(l, r);
			int t=SGT.search(l, r-1);
			if (t){
				int x=SGT.query(t, m, r, 1000000000);
				if (x&1) ans+=l; else ans+=r;
			} else{
				int x=SGT.query(t, m, r, 1000000000);
				if (x&1) ans+=b[i]; else ans+=a[i];
			}
			//printf("%lld\n", ans-ans0);
		}
		printf("%lld\n", ans);
	}
}
int main(){
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	n=getuint();
	for (int i=1;i<=n;i++) a[i]=getuint();
	for (int i=1;i<=n;i++) b[i]=getuint();
	m=getuint();
	if (n<=2000&&m<=2000) return Force::solve(), 0;
	Force233::solve();
	return 0;
}
