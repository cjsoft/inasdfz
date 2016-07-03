#include <cstdio>
#include <algorithm>
#include <bitset>
inline unsigned int getuint(){
	char w=getchar();
	while (w<'0'||'9'<w) w=getchar();
	unsigned int ans=0;
	for (;'0'<=w&&w<='9';w=getchar()) ans=ans*10+w-'0';
	return ans;
}
struct Hash_Table{
	static const int MAXN=1000005, hash_size=10000007;
	long long a[MAXN];int head[hash_size], next[MAXN], n;
	inline bool find(long long x){for (int i=head[x%hash_size];i;i=next[i]) if (a[i]==x) return true;return false;}
	inline void insert(long long x){
		int h=x%hash_size;
		a[++n]=x, next[n]=head[h], head[h]=n;
	}
} HT;
int K;
namespace Force{
	void solve(){
		int bitl;
		HT.insert(0);
		for (long long n=1;;n++){
			for (bitl=62;~n>>bitl&1;bitl--);
			if (!HT.find(n^1<<bitl)) continue;
			long long s=0, t=(1ll<<bitl+1)-1;
			for (int i=bitl;~i;i--) s=(s*10+(n>>i&1))&t;
			if (s!=n) continue;
			HT.insert(n);
			//printf("%d %lld %lld\n", K, n, s);
			if (!--K){
				//printf("%lld %lld\n", n, s);
				for (int i=bitl;~i;i--) putchar(n>>i&1?'1':'0');puts("");
				return;
			}
		}
	}	
}
inline void print(long long n){
	int bitl;
	for (bitl=62;~n>>bitl&1;bitl--);
	for (int i=bitl;~i;i--) putchar(n>>i&1?'1':'0');puts("");
}
bool ok(long long n){
	int bitl;
	for (bitl=62;~n>>bitl&1;bitl--);
	long long s=0, t=(1ll<<bitl+1)-1;
	for (int i=bitl;~i;i--) s=(s*10+(n>>i&1))&t;
	return s==n;
}
namespace Force1{
	struct rec{long long x;int bit;};
	inline bool operator <(const rec &i, const rec &j){return i.x>j.x;}
	rec heap[1000005];int heap_size;
	void solve(){
		rec t;t.x=1, t.bit=0;
		heap[heap_size++]=t, std::make_heap(heap, heap+heap_size);
		for (rec t;heap_size;){
			t=*heap;std::pop_heap(heap, heap+heap_size--);
			if (ok(t.x)){
				//printf("%d %lld\n", K, t.x);
				if (!--K) return print(t.x), void();
				t.bit++, t.x^=1ll<<t.bit;
				heap[heap_size++]=t, std::push_heap(heap, heap+heap_size);
				t.x^=1ll<<t.bit, t.bit--;
			}
			t.x^=1ll<<t.bit, t.x^=1ll<<(++t.bit);
			heap[heap_size++]=t, std::push_heap(heap, heap+heap_size);
		}
	}
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	//for (int i=1;i<=300;i++) K=i, Force::solve();return 0;
	K=getuint();
	if (K<=300) return Force::solve(), 0;
	if (K<=500000) Force1::solve();
	return 0;
}
