#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=2050;
int val[N];
inline int cnt(int v){
    int c=0;
    while(v){
        c+=v&1;
        v>>=1;
    }
    return c;
}
double ni[N][N],ma[N][2*N];
int main(){
    freopen("spy.in","r",stdin);
    freopen("spy.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        //ma[i][i+n]=1;
        for(int j=0;j<n;j++){
            if(cnt((i|j)^i)%2)
                ma[i][j]=0;
            else
                ma[i][j]=1;
        }
        for(int j=n-1;j>=0;j--){
            ni[n-1-i][n-1-j]=(ma[i][j]*4-2)/n;
            //printf("%c",ma[i][j]>0?'+':'-');
        }
        //printf("\n");
    }
    /*for(int i=0;i<N;i++){
        for(int j=i+1;j<N&&ma[i][i]==0;j++)
            swap(ma[i],ma[j]);
        for(int j=i+1;j<N;j++){
            if(ma[j][i]){
                for(int k=0;k<2*N;k++){
                    ma[j][k]-=ma[i][k];
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            double ra=ma[j][i]/ma[i][i];
            if(ra){
                for(int k=0;k<2*N;k++){
                    ma[j][k]-=ra*ma[i][k];
                }
            }
        }
    }
    printf("\n");*/
    /*for(int i=0;i<N;i++){
        for(int j=N;j<2*N;j++)
            printf("%d ",(int)(ma[i][j]/ma[i][i]*N));
        printf("\n");
    }*/
    //printf("%d\n",(int)(ma[0][2*N-1]/ma[0][0]*N));
    ni[0][n-1]=(double)(2-n)/n;
    /*for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            printf("%d ",(int)(ni[i][j]*N));
        printf("\n");
    }*/
    for(int i=0;i<n;i++)
        scanf("%d",val+i);
    for(int i=0;i<n;i++){
        double v=0;
        for(int j=0;j<n;j++)
            v+=val[j]*ni[i][j];
        printf("%.0lf ",v);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
