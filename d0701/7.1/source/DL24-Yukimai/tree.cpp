#define yuki(x, y) for(int i = x; i < (y); ++i)
#define yukj(x, y) for(int j = x; j < (y); ++j)
#define yukii(x, y) for(int i = x; i <= (y); ++i)
#define yukji(x, y) for(int j = x; j <= (y); ++j)
#define yuk(x, y, z) for(int x = y; x < (z); ++x)
#define yui(x, y, z) for(int x = y; x >= (z); --x)
#define sclr(x) memset(x, 0, sizeof(x))
#define sclr1(x) memset(x, -1, sizeof(x))
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
typedef long long lol;
/*int ans[20][20], curs = 1, dp[20][2], n;
struct tree
{
    vector<int> sons[20];
    int mds(int i, int j)
    {
        if(~dp[i][j]) return dp[i][j];
        int cans = j;
        if(j)
            yuk(k, 0, sons[i].size())
                cans += mds(sons[i][k], 0);
        else
            yuk(k, 0, sons[i].size())
                cans += max(mds(sons[i][k], 0), mds(sons[i][k], 1));
        return dp[i][j] = cans;
    }
    vector<int>& operator[](int x){return sons[x];}
    void dfsprint(int x)
    {
        printf("%d ", x);
        yuki(0, sons[x].size()) dfsprint(sons[x][i]);
    }
    void print()
    {
        dfsprint(1);
        puts("");
    }
}*mark;
queue<tree*> q;
set<lol> st;
void debug(tree *t)
{
    t->print();
}
bool trytoinsert(tree *t)
{
    tree &tt = *t;
    int alc = 0, mp[20], fa[20], outd[20];
    sclr(outd);
    lol cans = 0ll;
    fa[1] = 0;
    queue<int> q1;
    priority_queue<int, vector<int>, greater<int> > pq;
    q1.push(1);
    while(!q1.empty())
    {
        int cur = q1.front();
        q1.pop();
        mp[cur] = ++alc;
        yuki(0, tt[cur].size())
            q1.push(tt[cur][i]);
    }
    q1.push(1);
    while(!q1.empty())
    {
        int cur = q1.front();
        q1.pop();
        yuki(0, tt[cur].size())
        {
            fa[mp[tt[cur][i]]] = mp[cur];
            ++outd[mp[cur]];
            q1.push(tt[cur][i]);
        }
    }
    yukii(1, curs+1)
        if(!outd[i]) pq.push(i);
    while(!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        cans *= curs+1;
        cans += fa[cur]-1;
        if(!(--outd[fa[cur]])) pq.push(fa[cur]);
    }
    if(st.count(cans)) return false;
    st.insert(cans);
    return true;
}
void calcans(tree *t)
{
    sclr1(dp);
    ++ans[curs+1][max(t->mds(1, 0), t->mds(1, 1))];
}
void bfs()
{
    mark = new tree;
    q.push(mark);
    mark = new tree;
    q.push(mark);
    while(!q.empty())
    {
        tree *curt = q.front();
        q.pop();
        if(curt == mark)
        {
            st.clear();
            q.push(mark);
            ++curs;
            if(curs >= n) break;
            continue;
        }
        yukii(1, curs)
        {
            tree *nw = new tree(*curt);
            nw->sons[i].push_back(curs+1);
            if(trytoinsert(nw))
            {
                q.push(nw);
                calcans(nw);
            }else
                delete nw;
        }
        delete curt;
    }
}*/
const int ans[][16] = {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,3,2,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,12,2,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,15,25,2,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,88,42,2,0,0,0,0,0,0,0,0,0},
{0,0,0,0,91,273,63,2,0,0,0,0,0,0,0,0},
{0,0,0,0,0,700,640,88,2,0,0,0,0,0,0,0},
{0,0,0,0,0,612,2856,1275,117,2,0,0,0,0,0,0},
{0,0,0,0,0,0,5814,8550,2280,150,2,0,0,0,0,0},
{0,0,0,0,0,0,4389,29260,21175,3773,187,2,0,0,0,0},
{0,0,0,0,0,0,0,49588,106260,46046,5888,228,2,0,0,0},
{0,0,0,0,0,0,0,32890,296010,313950,91000,8775,273,2,0,0},
{0,0,0,0,0,0,0,0,430560,1261260,802620,167076,12600,322,2,0}};
int main(int argc, char **argv)
{
#ifndef snowoi
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
#endif // snowoi
    int n;
    scanf("%d", &n);
    yuki(0, n)
    {
        yukji(0, n)
            printf("%d ", ans[i][j]);
        puts("");
    }
	return 0;
}
