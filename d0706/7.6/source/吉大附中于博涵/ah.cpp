#include <cstdio>
#include <vector>
using namespace std;
const int N=100010;
struct ps{
    vector<ps *> w;
    ps *fa;
    int sy,zt;
    bool bwd;
    void fsea(){
        int own=0,oth=0;
        if(!w.size()){
            bwd=1;
            sy=zt;
            return;
        }
        for(int i=0;i<w.size();i++){
            ps *o=w[i];
            o->fsea();
            if(o->sy==0) own++;
            else if(o->sy==1) oth++;
        }
        if(own==oth) sy=-1;
        else if(own<oth) sy=1;
        else sy=0;
        bwd=(own+1>=oth);
    }
    void ssea(){
        for(int i=0;i<w.size();i++){
            ps *o=w[i];
            if(sy!=-1) o->sy=sy;
            if(!bwd) o->bwd=false;
            o->ssea();
        }
    }
}p[N];
inline int read(){
    int v=0,ch=1;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c=='-') ch=-1,c=getchar();
    while(c>='0'&&c<='9') v=v*10+c-'0',c=getchar();
    return v*ch;
}
int main(){
    freopen("ah.in","r",stdin);
    freopen("ah.out","w",stdout);
    int t=read();
    while(t--){
        int n=read();
        for(int i=0;i<=n;i++)
            p[i].w.clear();
        for(int i=1;i<=n;i++){
            int fa=read();
            p[i].sy=p[i].zt=-1;
            p[i].fa=p+fa;
            p[fa].w.push_back(p+i);
        }
        for(int i=1;i<=n;i++)
            p[i].zt=read();
        p[1].fsea();
        if(p[1].sy==1){
            printf("-1\n");
            continue;
        }else if(p[1].sy==0){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(p[i].w.size()||p[i].zt!=-1) continue;
                cnt++;
            }
            printf("%d",cnt);
            for(int i=1;i<=n;i++){
                if(p[i].w.size()||p[i].zt!=-1) continue;
                printf(" %d",i);
            }
            printf("\n");
        }else{
            int cnt=0;
            p[1].ssea();
            for(int i=1;i<=n;i++){
                if(p[i].w.size()||p[i].zt!=-1||p[i].sy==0) continue;
                if(!p[i].bwd&&p[i].sy==1) continue;
                cnt++;
            }
            printf("%d",cnt);
            for(int i=1;i<=n;i++){
                if(p[i].w.size()||p[i].zt!=-1||p[i].sy==0) continue;
                if(!p[i].bwd&&p[i].sy==1) continue;
                printf(" %d",i);
            }
            printf("\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
