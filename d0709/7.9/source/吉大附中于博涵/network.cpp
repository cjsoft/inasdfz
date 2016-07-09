#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100010;
int val[N],ans;
inline int gcd(int a,int b){
    if(a==0) return b;
    if(b==0) return a;
    if(a==1||b==1) return 1;
    return __gcd(a,b);
}
struct ps{
    vector<pair<int *,ps *> > w;
    ps *fa;
    int *fav,dep,cnt;
    void fsea(){
        cnt=1;
        for(vector<pair<int *,ps *> >::iterator i=w.begin();i!=w.end();++i){
            if(i->second->dep) continue;
            i->second->dep=dep+1;
            i->second->fa=this;
            i->second->fav=i->first;
            i->second->fsea();
            cnt+=i->second->cnt;
        }
    }
    void upsea(ps *f,int q){
        if(!this) return;
        vector<pair<int *,ps *> >::iterator i=w.begin();
        while(i->second!=f) ++i;
        ++i;
        while(i!=w.end()){
            if(i->second->dep<dep) continue;
            i->second->dwsea(gcd(q,*(i->first)));
            ++i;
        }
        if(fa)
            fa->upsea(this,gcd(q,*fav));
    }
    void dwsea(int q){
        if(q==1){
            ans+=cnt;
            return;
        }
        for(vector<pair<int *,ps *> >::iterator i=w.begin();i!=w.end();++i){
            if(i->second->dep<dep) continue;
            i->second->dwsea(gcd(q,*(i->first)));
        }
    }
}p[N];
int main(){
    int n,q,a,b;
    freopen("network.in","r",stdin);
    freopen("network.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&a,&b,val+i);
        p[a].w.push_back(make_pair(val+i,p+b));
        p[b].w.push_back(make_pair(val+i,p+a));
    }
    p[1].dep=1;
    p[1].fsea();
    ans=0;
    for(int i=1;i<=n;i++){
        p[i].dwsea(0);
        if(p[i].fa)
            p[i].fa->upsea(p+i,*(p[i].fav));
    }
    printf("%d\n",ans);
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&a,&b);
        val[a]=b;
        ans=0;
        for(int i=1;i<=n;i++){
            p[i].dwsea(0);
            if(p[i].fa)
                p[i].fa->upsea(p+i,*(p[i].fav));
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
