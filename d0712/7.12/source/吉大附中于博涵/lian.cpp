#include <cstdio>
#include <ctime>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int N=2010,PS=1000000;
int num[N];
vector<struct xs *> pts[4*N];
int cnew=0;
struct xs{
    int s,v,e,rk;
    xs *l,*r;
    void insert(int p,int a,int b);
}*rt,*pl,*pe=pl+PS;
xs *alloc(int a,int b,int c){
    if(pe==pl+PS)
        pl=pe=new xs[PS],memset(pl,0,PS*sizeof(xs));
    cnew++;
    xs *re=pe++;
    if(a+1==b){
        re->v=0,re->s=re->e=c;
    }else{
        int m=(a+b)/2;
        re->s=c;
        re->l=alloc(a,m,c);
        re->r=alloc(m,b,re->l->e+1);
        re->e=re->r->e+1;
    }
    pts[re->e].push_back(re);
    return re;
}
xs *alloc(const xs *o){
    if(pe==pl+PS)
        pl=pe=new xs[PS],memset(pl,0,PS*sizeof(xs));
    cnew++;
    memcpy(pe,o,sizeof(xs));
    pts[pe->e].push_back(pe);
    return pe++;
}
map<pair<xs *,int>,xs *> ji;
void xs::insert(int p,int a,int b){
    if(a+1==b){
        v++;
        return;
    }
    int m=(a+b)/2;
    if(p<m){
        if(ji[make_pair(l,p)]){
            l=ji[make_pair(l,p)];
        }else{
            xs *n=alloc(l);
            ji[make_pair(l,p)]=n;
            l=n;
            l->insert(p,a,m);
        }
    }else{
        if(ji[make_pair(r,p)]){
            r=ji[make_pair(r,p)];
        }else{
            xs *n=alloc(r);
            ji[make_pair(r,p)]=n;
            r=n;
            r->insert(p,m,b);
        }
    }
}
inline bool cmp(xs *a,xs *b){
    if(!a->l)
        return a->v>b->v;
    if(a->l->rk!=b->l->rk)
        return a->l->rk<b->l->rk;
    return a->r->rk<b->r->rk;
}
xs *prt[N][N];
inline bool cmp2(pair<int,int> a,pair<int,int> b){
    if(prt[a.first][a.second]->rk!=prt[b.first][b.second]->rk)
        return prt[a.first][a.second]->rk<prt[b.first][b.second]->rk;
    return a.first<b.first;
}
pair<int,int> stans[N*N];
map<int,int> lisan;
int main(){
    int n,p,q,lic=1;
    freopen("lian.in","r",stdin);
    freopen("lian.out","w",stdout);
    scanf("%d%d%d",&n,&p,&q);
    for(int i=0;i<n;i++){
        scanf("%d",num+i),num[i]--;
        lisan[num[i]]=0;
    }
    lisan.begin()->second=0;
    for(map<int,int>::iterator i=++lisan.begin();i!=lisan.end();++i){
        i->second=lic++;
    }
    for(int i=0;i<n;i++)
        num[i]=lisan[num[i]];
    rt=alloc(0,lic,0);
    for(int s=0;s<n;s++){
        xs *la=rt;
        for(int e=s;e<n;e++){
            if(ji[make_pair(la,num[e])]){
                prt[s][e]=ji[make_pair(la,num[e])];
            }else{
                ji[make_pair(la,num[e])]=prt[s][e]=alloc(la);
                prt[s][e]->insert(num[e],0,lic);
                //prt[s][e]->chg(n,e,0,n+1);
            }
            la=prt[s][e];
        }
    }
    //fprintf(stderr,"%d\n",clock());
    for(int i=0;i<=rt->e;i++){
        sort(pts[i].begin(),pts[i].end(),cmp);
        pts[i][0]->rk=0;
        for(unsigned int j=1;j<pts[i].size();j++)
            pts[i][j]->rk=pts[i][j-1]->rk+cmp(pts[i][j-1],pts[i][j]);
    }
    //fprintf(stderr,"%d\n",clock());
    int ansc=0;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            stans[ansc++]=make_pair(i,j);
    sort(stans,stans+ansc,cmp2);
    //fprintf(stderr,"%d\n",clock());
    for(int i=p-1;i<q;i++)
        printf("%d %d\n",stans[i].first+1,stans[i].second+1);
    //fprintf(stderr,"%d\n",cnew);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
