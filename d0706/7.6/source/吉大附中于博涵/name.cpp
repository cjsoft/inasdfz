#include <cstdio>
const int N=100010;
int val[N][2],cho[N];
int main(){
    int n,m;
    freopen("name.in","r",stdin);
    freopen("name.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",val[i]);
    for(int i=0;i<n;i++) scanf("%d",val[i]+1);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        for(int i=a-1;i<b;i++){
            if(val[i][cho[i]]<=c)
                cho[i]=!cho[i];
        }
    }
    long long ans=0;
    for(int i=0;i<n;i++)
        ans+=val[i][cho[i]];
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
