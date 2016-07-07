#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int LEN=40,N=100;
int n,m,sy,cc=LEN-1;
long long ans;
long long val[N],cv;
int xjw[N];
long long xjv;
long long dpa[LEN][1<<15],dpb[LEN][1<<15];
void baoli(int p,long long c){
    if(p==n){
        for(int i=0;i<=LEN-m;i++){
            if(((c>>i)&((1<<m)-1))==cv){
                ans++;
                break;
            }
        }
        return;
    }
    baoli(p+1,c);
    baoli(p+1,c^val[p]);
}
char cont[100];
inline int compress(long long v){
    int re=0;
    for(int i=LEN-1;i>=0;i--){
        if(xjv&(1ll<<i)) continue;
        re<<=1;
        re|=(v>>i)&1;
    }
    return re;
}
inline long long extract(int v){
    long long re=0;
    for(int i=LEN-1,c=LEN-n-1;i>=0;i--){
        re<<=1;
        if(xjv&(1ll<<i)) continue;
        re|=(v>>(c--))&1;
    }
    return re;
}
inline long long hou(long long v,int w=m){
    return v&((1<<w)-1);
}
int tui(int s,int t,int e,int nv){
    if(s-t+1>=m) return s;
    long long v=cv>>(m-(s-t+1));
    v<<=t-e;
    v|=nv;
    int len;
    for(len=s-e+1;len>=0;len--){
        if(len>=m){
            if(hou(v>>(len-m),m)==cv)
                break;
        }else{
            if(hou(v,len)==(cv>>(m-len)))
                break;
        }
    }
    return e+len-1;
}
int main(){
    freopen("elf.in","r",stdin);
    freopen("elf.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",cont);
        for(int j=0;j<LEN;j++)
            val[i]=val[i]*2+cont[j]-'0';
    }
    scanf("%d%s",&m,cont);
    for(int i=0;i<m;i++)
        cv=cv*2+cont[i]-'0';
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            if(val[j]>val[i]) swap(val[j],val[i]);
        if(val[i]==0){
            sy=n-i;
            n=i;
            break;
        }
        int p;
        for(p=LEN-1;p>=0;p--)
            if(val[i]&(1ll<<p)) break;
        xjw[i]=p;
        xjv|=1ll<<p;
        for(int j=i+1;j<=n;j++)
            if(val[j]&(1ll<<p))
                val[j]^=val[i];
    }
    for(int i=0;i<n;i++){
        int p=xjw[i];
        for(int j=0;j<i;j++)
            if(val[j]&(1ll<<p))
                val[j]^=val[i];
    }
    if(n<=25){
        baoli(0,0);
    }else if(n==LEN){
        ans=1;
    }else{
        long long qw=((1ll<<(LEN-xjw[n-1]))-1)<<xjw[n-1];
        dpa[LEN-1][0]=1;
        int la=LEN;
        for(int i=0;i<n;i++){
            memset(dpb,0,sizeof(dpb));
            int nv=compress(val[i]);
            for(int s=LEN-1;s>=la-1&&s>=0;s--){
                int te=tui(s,la,xjw[i],0);
                for(int j=0;j<1<<(LEN-n);j++)
                    dpb[te][j]+=dpa[s][j];
                te=tui(s,la,xjw[i],1);
                for(int j=0;j<1<<(LEN-n);j++)
                    dpb[te][j^nv]+=dpa[s][j];
            }
            memcpy(dpa,dpb,sizeof(dpb));
            la=xjw[i];
        }
        for(int i=0;i<1<<(LEN-n);i++){
            long long yv=extract(i);
            for(int s=LEN-1;s>=m-1;s--){
                long long nyv=yv|((cv<<(s-m+1))&qw);
                for(int j=0;j+m-1<=s;j++){
                    if(hou(nyv>>j)==cv){
                        ans+=dpa[s][i];
                        break;
                    }
                }
            }
        }
    }
    ans<<=sy;
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
