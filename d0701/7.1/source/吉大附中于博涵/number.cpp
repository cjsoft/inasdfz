#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int L=1024;
struct bitset{
    unsigned int val[L/32];
    bitset(){
        memset(val,0,sizeof(val));
    }
    bitset(int v){
        memset(val,0,sizeof(val));
        val[0]=v;
    }
    bool read(int p){
        return (val[p/32]>>(p%32))&1;
    }
    void write(int p,bool v){
        val[p/32]|=1<<(p%32);
    }
    void zy(int p){
        int jin=0;
        for(int i=0;i<L/32-1;i++){
            int njin=val[i]>>(32-p);
            val[i]=(val[i]<<p)+jin;
            jin=njin;
        }
    }
};
bitset pow[L];
long long ans=1;
bitset av[600000];
inline void ptr(bitset &a){
    int j=L-1;
    while(j&&!a.read(j)) j--;
    while(j>=0)
        printf("%d",a.read(j--));
    printf("\n");
}
inline bitset operator +(const bitset &a,const bitset &b){
    bitset re;
    int jin=0;
    for(int i=0;i<L/32-1;i++){
        long long av=a.val[i],bv=b.val[i];
        long long cv=jin+av+bv;
        jin=cv>>32;
        re.val[i]=cv;
    }
    /*ptr(a);
    ptr(b);
    ptr(re);*/
    return re;
}
inline bool cmp(const bitset &a,const bitset &b){
    for(int i=L/32-1;i>=0;i--){
        if(a.val[i]==b.val[i]) continue;
        return a.val[i]<b.val[i];
    }
    return false;
}
bitset tcs[L],tji[L];
void sea(int cp){
    bitset &cs=tcs[cp],&ji=tji[cp];
    bitset &ncs=tcs[cp+1],&nji=tji[cp+1];
    if(cp>700||cs.read(cp)) return;
    ncs=cs,nji=ji;
    sea(cp+1);
    ji.write(cp,1);
    ncs=cs+pow[cp],nji=ji;
    sea(cp+1);
    av[ans++]=ji;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    pow[0]=1;
    for(int i=1;i<L;i++){
        bitset za=pow[i-1],zb=pow[i-1];
        za.zy(1),zb.zy(3);
        pow[i]=za+zb;
    }
    sea(0);
    //printf("%d\n",ans);
    sort(av,av+ans,cmp);
    //printf("%d\n",ans);
    int k;
    scanf("%d",&k);
    ptr(av[k]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
