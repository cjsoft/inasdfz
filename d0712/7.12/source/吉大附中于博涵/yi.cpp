#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=1000000;
char cont[N];
unsigned int val[N/32];
int main(){
    int n,len,ans=0;
    freopen("yi.in","r",stdin);
    freopen("yi.out","w",stdout);
    scanf("%s",cont);
    n=strlen(cont);
    for(int i=0,j=n-1;i<j;i++,j--)
        swap(cont[i],cont[j]);
    for(int i=0;i<n;i++)
        if(cont[i]=='1')
            val[i/32]+=1<<(i%32);
    len=n/32;
    while(len||val[0]!=1){
        //tt=max(tt,len);
        ans++;
        if(val[0]&1){
            long long jin=1;
            len+=2;
            for(int i=0;i<=len;i++){
                long long y=val[i];
                y=y+(y<<1)+jin;
                val[i]=y;
                jin=y>>32;
            }
            while(!val[len])
                len--;
        }else{
            for(int i=0;i<=len;i++){
                val[i]>>=1;
                val[i]+=val[i+1]<<31;
            }
            while(!val[len])
                len--;
        }
    }
    //fprintf(stderr,"%d\n",tt*32);
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
