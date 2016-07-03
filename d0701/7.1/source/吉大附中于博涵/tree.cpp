#include <cstdio>
const int N=410,MOD=998244353;
int dpa[N][N],dpb[N][N];
int main(){
    int n;
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    dpa[1][1]=1;
    for(int i=0;i<=n;i++) printf("%d ",(dpa[1][i]+dpb[1][i])%MOD);
    printf("\n");
    for(int t=2;t<=n;t++){
        for(int y=1;y<t;y++){
            for(int l=y/2;l<=y;l++){
                for(int r=(t-y)/2;r<=t-y;r++){
                    dpa[t][l+r]=(dpa[t][l+r]+(long long)dpa[y][l]*dpb[t-y][r])%MOD;
                    dpb[t][l+r]=(dpb[t][r+l]+(long long)dpb[y][l]*(dpb[t-y][r]+dpa[t-y][r])+(long long)dpa[y][l+1]*dpa[t-y][r])%MOD;
                }
            }
        }
        for(int i=0;i<=n;i++) printf("%d ",(dpa[t][i]+dpb[t][i])%MOD);
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
