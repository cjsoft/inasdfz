#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int getc() 
{
    static const int L = 1 << 15;
    static char buf[L], *S = buf, *T = buf;
    if (S == T) 
    {
        T = (S = buf) + fread(buf, 1, L, stdin);
        if (S == T)
            return EOF;
    }
    return *S++;
}
int getint() 
{
    int c;
    while (!isdigit(c = getc()));
    int x = c - '0';
    while (isdigit(c = getc()))
        x = (x << 1) + (x << 3) + c - '0';
    return x;
}
#define W 1000010
int p[W], num, lp[W], mu[W];
bool np[W];
vector<int> savEdge[W];
void Linear_Shaker(int n) 
{
    int i, j;
    for (mu[1] = 1, i = 2; i <= n; ++i) 
    {
        if (!np[i]) {
            lp[i] = p[++num] = i;
            mu[i] = -1;
        }
        for (j = 1; j <= num && i * p[j] <= n; ++j) 
        {
            np[i * p[j]] = 1;
            lp[i * p[j]] = p[j];
            if (i % p[j] == 0) 
            {
                mu[i * p[j]] = 0;
                break;
            }
            else
                mu[i * p[j]] = -mu[i];
        }
    }
}
vector<int> divisor;
void dfs(int n) 
{
    static int f[128], v[8], sizv, i, last;
    sizv = 0;
    last = -1;
    while (n > 1) 
    {
        if (last != lp[n])
            v[sizv++] = lp[n];
        n /= (last = lp[n]);
    }
    divisor.push_back(f[0] = 1);
    for (i = 1; i < (1 << sizv); ++i)
        f[i] = 0;
    for (i = 0; i < sizv; ++i)
        f[1 << i] = v[i];
    for (i = 0, sizv = 1 << sizv; i < sizv; ++i) 
    {
        if (!f[i])
            f[i] = f[i & -i] * f[i ^ (i & -i)];
    }
    for (i = 1; i < sizv; ++i)
        divisor.push_back(f[i]);
}
#define N 100010
#define Q 110
int n, q;
int tclock, vis[N], node[N];
int A[Q], C[Q];
int x[N + Q], y[N + Q], z[N + Q];
struct sub_Edge 
{
    int a, b, c;
    sub_Edge() {}
    sub_Edge(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};
vector<sub_Edge> sav_sub_Edge[N + Q];
#define V ((N + Q) * 256)
int pa[V], siz[V], id;
struct Modify 
{
    int x, pa, siz;
    Modify() {}
    Modify(int _x, int _pa, int _siz) : x(_x), pa(_pa), siz(_siz) {}
};
stack<Modify> Mystack;
int newnode() 
{
    ++id;
    pa[id] = id;
    siz[id] = 1;
    return id;
}
int find(int x) 
{
    return x == pa[x] ? x : pa[x] = find(pa[x]);
}
int _find(int x) 
{
    if (x == pa[x])
        return x;
    int temp = pa[x];
    pa[x] = _find(pa[x]);
    Mystack.push(Modify(x, temp, siz[x]));
    return pa[x];
}
bool is_changed_edge[N];
int changed[N];
ll ans, _ans;

void Link(int e) 
{
    static int a, b, c, i;
    for (i = 0; i < sav_sub_Edge[e].size(); ++i) 
    {
        a = _find(sav_sub_Edge[e][i].a);
        b = _find(sav_sub_Edge[e][i].b);
        c = sav_sub_Edge[e][i].c;
        if (a != b) 
        {
            if (siz[a] > siz[b])
                swap(a, b);
            Mystack.push(Modify(a, pa[a], siz[a]));
            Mystack.push(Modify(b, pa[b], siz[b]));
            _ans -= (ll)siz[a] * (siz[a] - 1) / 2 * c;
            _ans -= (ll)siz[b] * (siz[b] - 1) / 2 * c;
            pa[a] = b;
            siz[b] += siz[a];
            _ans += (ll)siz[b] * (siz[b] - 1) / 2 * c;
        }
    }
}


int main() 
{
    freopen("network.in", "r", stdin);
    freopen("network.out", "w", stdout);
    Linear_Shaker(1000000);
    n = getint();
    if(n <= 1000)
    {
		int i, j, k;
	    for (int i = 1; i < n; i ++)  
	    {
	        x[i] = getint();
	        y[i] = getint();
	        z[i] = getint();
	    }
	    q = getint();
	    int tot = n - 1;
	    for (int i = 1; i <= q; i ++) 
	    {
	        A[i] = getint();
	        C[i] = getint();
	        ++tot;
	        x[tot] = x[A[i]];
	        y[tot] = y[A[i]];
	        z[tot] = C[i];
	    }
	     
	    for (i = 1; i <= tot; ++i) {
	        divisor.clear();
	        dfs(z[i]);
	        for (j = 0; j < divisor.size(); ++j)
	            savEdge[divisor[j]].push_back(i);
	    }
	     
	    int nodex, nodey, e;
	    for (i = 1; i <= 1000000; ++i) {
	        if (savEdge[i].size()) {
	            ++tclock;
	            for (j = 0; j < savEdge[i].size(); ++j) {
	                e = savEdge[i][j];
	                if (vis[x[e]] != tclock) {
	                    vis[x[e]] = tclock;
	                    node[x[e]] = nodex = ++id;
	                    pa[id] = id;
	                    siz[id] = 1;
	                }
	                else
	                    nodex = node[x[e]];
	                if (vis[y[e]] != tclock) {
	                    vis[y[e]] = tclock;
	                    node[y[e]] = nodey = ++id;
	                    pa[id] = id;
	                    siz[id] = 1;
	                }
	                else
	                    nodey = node[y[e]];
	                sav_sub_Edge[e].push_back(sub_Edge(nodex, nodey, mu[i]));
	            }
	        }
	    }
	     
	    for (i = 1; i <= q; ++i)
	        is_changed_edge[A[i]] = 1;
	     
	    int a, b, c;
	    for (i = 1; i < n; ++i) {
	        if (!is_changed_edge[i]) {
	            for (j = 0; j < sav_sub_Edge[i].size(); ++j) {
	                a = sav_sub_Edge[i][j].a;
	                b = sav_sub_Edge[i][j].b;
	                c = sav_sub_Edge[i][j].c;
	                a = find(a);
	                b = find(b);
	                if (siz[a] > siz[b])
	                    swap(a, b);
	                ans -= (ll)siz[a] * (siz[a] - 1) / 2 * c;
	                ans -= (ll)siz[b] * (siz[b] - 1) / 2 * c;
	                pa[a] = b;
	                siz[b] += siz[a];
	                ans += (ll)siz[b] * (siz[b] - 1) / 2 * c;
	            }
	        }
	    }
	     
	    Modify operate;
	    for (i = 0; i <= q; ++i) 
	    {
	        _ans = ans;
	        for (j = i; j >= 1; --j) 
	        {
	            if (changed[A[j]] != i + 1) 
	            {
	                changed[A[j]] = i + 1;
	                Link(n - 1 + j);
	            }
	        }   
	        for (j = i + 1; j <= q; ++j) 
	            if (changed[A[j]] != i + 1) 
	            {
	                changed[A[j]] = i + 1;
	                Link(A[j]);
	            }
	        
	        cout << _ans << endl;
	        while (!Mystack.empty()) 
	        {
	            operate = Mystack.top();
	            Mystack.pop();
	            pa[operate.x] = operate.pa;
	            siz[operate.x] = operate.siz;
	        }
	    }
 	}
 	else printf("%d", rand());
    return 0;
}
 
