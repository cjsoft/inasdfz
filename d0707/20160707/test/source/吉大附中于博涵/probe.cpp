#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=1010,MAX=1e8;
struct ws{
    struct ps *o;
    int f,yf;
    ws *n,*h;
}w[N*N],*we;
struct ps{
    int art;
    ws *w,*i;
    ps *n;
    int dfs(int f,ps *e){
        if(this==e) return f;
        int re=0;
        for(;i;i=i->n){
            if(!i->f||i->o->art!=art+1) continue;
            int tre=i->o->dfs(min(f,i->f),e);
            re+=tre,f-=tre,i->f-=tre,i->h->f+=tre;
            if(!f) return re;
        }
        return re;
    }
}p[N],*s=p+N-1,*t=p+N-2,*ain=p+N-3,*aout=p+N-4;
int n,totout,totin,*mark[N];
inline bool chk(int v){
    for(int i=0;i<N;i++)
        p[i].art=0;
    for(ws *i=w;i<we;i++)
        i->f=i->yf;
    s->w->f=totout+v-totin;
    aout->w->f=v;
    int flow=0;
    while(t->art!=MAX){
        flow+=s->dfs(MAX,t);
        for(int i=0;i<N;i++)
            p[i].i=p[i].w,p[i].art=MAX,p[i].n=0;
        s->art=0;
        for(ps *b=s,*e=s;b;b=b->n){
            for(ws *i=b->w;i;i=i->n){
                if(i->o->art!=MAX||!i->f) continue;
                i->o->art=b->art+1;
                e=e->n=i->o;
            }
        }
    }
    return flow==totout+v;
}
inline void mkline(ps *a,ps *b,int f){
    we->yf=we->f=f,we->o=b,we->n=a->w;
    a->w=we++;
    we->yf=we->f=0,we->o=a,we->n=b->w;
    b->w=we++;
    a->w->h=b->w,b->w->h=a->w;
}
pair<bool,int> op[N];
bool in[N];
int main(){
    int tt;
    freopen("probe.in","r",stdin);
    freopen("probe.out","w",stdout);
    scanf("%d",&tt);
    while(tt--){
        scanf("%d",&n);
        we=w;
        memset(p,0,sizeof(p));
        totin=totout=0;
        for(int i=0;i<n;i++){
            char oo[10];
            int id;
            scanf("%s%d",oo,&id);
            op[i].first=oo[0]=='E';
            op[i].second=id;
        }
        for(int i=0;i<n;i++){
            int id=op[i].second;
            if(op[i].first){
                totin++;
                mkline(s,p+i,1);
                int j;
                if(id){
                    for(j=i+1;j<n;j++){
                        if(op[j].first&&op[j].second==id)
                            break;
                        if(!op[j].first){
                            if(op[j].second==0)
                                mkline(p+i,p+j,1);
                            else if(op[j].second==op[i].second){
                                mkline(p+i,p+j,1);
                                break;
                            }
                        }
                    }
                }else{
                    memset(in,0,sizeof(in));
                    for(j=i+1;j<n;j++){
                        if(op[j].first&&op[j].second)
                            in[op[j].second]=1;
                        if(!op[j].first){
                            if(op[j].second==0)
                                mkline(p+i,p+j,1);
                            else{
                                if(in[op[j].second])
                                    continue;
                                in[op[j].second]=1;
                                mkline(p+i,p+j,1);
                                break;
                            }
                        }
                    }
                }
                if(j==n)
                    mkline(p+i,aout,1);
            }else{
                totout++;
                mkline(p+i,t,1);
            }
        }
        memset(in,0,sizeof(in));
        for(int i=0;i<n;i++){
            if(op[i].first&&op[i].second)
                in[op[i].second]=1;
            if(!op[i].first){
                if(op[i].second==0){
                    mkline(ain,p+i,1);
                }else{
                    if(in[op[i].second])
                        continue;
                    in[op[i].second]=1;
                    mkline(ain,p+i,1);
                }
            }
        }
        mkline(ain,aout,MAX);
        mkline(s,ain,1);
        mkline(aout,t,1);
        int ba=max(0,totin-totout)-1,bb=n+10;
        while(ba+1!=bb){
            int bm=(ba+bb)/2;
            if(chk(bm))
                bb=bm;
            else
                ba=bm;
        }
        if(ba<=n)
            printf("%d\n",bb);
        else
            printf("OTHER\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
