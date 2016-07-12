#include <cstdio>
#include <cstring>
const int N=20;
int n,m,ans=0;
int ji[N];
bool lock[N];
inline bool xy(int p){
    for(int i=0;i<n;i++){
        if(ji[i]<ji[(p+i)%n]) return false;
        if(ji[i]>ji[(p+i)%n]) return true;
    }
    return false;
}
void sea(int c,int d){
    if(c==n-1){
        ji[c]=m-d;
        if(lock[d])
            return;
        for(int i=1;i<n;i++)
            if(!xy(i))
                return;
        ans++;
        return;
    }
    for(int i=0;i<=m-d;i++){
        int cl=(i+c+1)%n;
        if(lock[cl])
            continue;
        lock[cl]=1;
        ji[c]=i;
        sea(c+1,d+i);
        lock[cl]=0;
    }
}
int main(){
    freopen("jian.in","r",stdin);
    freopen("jian.out","w",stdout);
    scanf("%d%d",&n,&m);
    if(n<=5&&m<=10)
        sea(0,0);
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
