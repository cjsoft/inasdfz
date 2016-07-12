#include <cstdio>
int ji[1100000];
inline int gen(int v){
    int &re=ji[v];
    if(re) return re;
    for(int i=1;i*i<=v;i++){
        if(v%i) continue;
        re++;
        if(i*i!=v)
            re++;
    }
    return re;
}
int main(){
    int a,b,c,ans=0;
    freopen("skyfall.in","r",stdin);
    freopen("skyfall.out","w",stdout);
    scanf("%d%d%d",&a,&b,&c);
    for(int i=1;i<=a;i++)
    for(int j=1;j<=b;j++)
    for(int k=1;k<=c;k++)
    ans+=gen(i*j*k);
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
