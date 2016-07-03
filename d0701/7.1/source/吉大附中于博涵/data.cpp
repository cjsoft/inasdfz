#include <cstdio>
#include <cstring>
const int N=30;
int n,k;
int val[N];
struct as{
    as *to[5];
    int sea(int c,int e);
}rt[1000000],*ce;
int as::sea(int c,int e){
    if(c==e) return 0;
    int re=sea(c+1,e);
    if(!to[val[c]]){
        re++;
        memset(ce,0,sizeof(as));
        to[val[c]]=ce++;
    }
    re+=to[val[c]]->sea(c+1,e);
    return re;
}
int main(){
    int t,m,a,b,c,d;
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&k,&m);
        for(int i=0;i<n;i++)
            scanf("%d",val+i);
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            b--;
            if(a==1){
                scanf("%d",&d);
                for(int i=b;i<c;i++)
                    val[i]=(val[i]+d)%k;
            }else if(a==2){
                scanf("%d",&d);
                for(int i=b;i<c;i++)
                    val[i]=(val[i]*d)%k;
            }else{
                ce=rt+1;
                memset(rt,0,sizeof(as));
                printf("%d\n",rt->sea(b,c));
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
