#include <cstring>
#include <cstdio>
const int N=100010,SEED=131,MOD=1e9+7;
int pow[N],hash[N];
__attribute__((__optimize__(("-O3")))) inline int genhash(int a,int b){
    int re=hash[b];
    if(a)
        re-=(long long)hash[a-1]*pow[b-a+1]%MOD;
    if(re<0) re+=MOD;
    return re;
}
char cont[N];
__attribute__((__optimize__(("-O3")))) int main(){
    int n;
    freopen("encrypt.in","r",stdin);
    freopen("encrypt.out","w",stdout);
    scanf("%s",cont);
    n=strlen(cont);
    pow[0]=1;
    for(int i=1;i<=n;i++)
        pow[i]=(long long)pow[i-1]*SEED%MOD;
    hash[0]=cont[0];
    for(int i=1;i<n;i++)
        hash[i]=((long long)hash[i-1]*SEED+cont[i])%MOD;
    for(int c=0;c<n;){
        int ba=0,bb=n-c+1,fa;
        while(ba+1!=bb){
            int bm=(ba+bb)/2;
            fa=-1;
            for(int i=0;i<c;i++){
                if(genhash(i,i+bm-1)==genhash(c,c+bm-1)){
                    fa=i;
                    break;
                }
            }
            if(fa!=-1)
                ba=bm;
            else
                bb=bm;
        }
        fa=-1;
        for(int i=0;i<c;i++){
            if(genhash(i,i+ba-1)==genhash(c,c+ba-1)){
                fa=i;
                break;
            }
        }
        if(ba==0){
            printf("-1 %d ",cont[c]);
            c++;
        }else{
            printf("%d %d ",ba,fa);
            c+=ba;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
