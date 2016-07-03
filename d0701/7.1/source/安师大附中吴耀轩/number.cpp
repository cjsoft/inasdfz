#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <time.h>
using namespace std;
const int maxn = 805;
const int maxm = 20005;
const int N = 700;
const int S = 24;
const int M = 1<<S;
int Inc[maxn][maxn];
int _Inc[maxn][maxn];
struct Number {
    int b[maxn],len;
    void Add(const int number)
    {
        ++len;
        if (number) {
            register int *inc=_Inc[len];
            for (register int j=(len-1)/S+1;j<=inc[0]+1;j++) {
            	register int t=b[j]+inc[j];
            	b[j]=t&(M-1),b[j+1]+=t>>S;
            }
        }
    }
    bool judge(const int num)
    {
    	int p=(len-1)/S,q=len-p*S-1;
        return ((b[p+1]>>q)&1)==num;
    }
    void print()
    {
    	int i=(len-1)/S,j=len-i*S-1;
    	for (++i;j>=0;j--) printf("%d",(b[i]>>j)&1);
        for (--i;i>=1;i--)
        for (j=S-1;j>=0;j--)
            printf("%d",(b[i]>>j)&1);
        puts("");
//       printf("%d\n",clock());
    }
};
Number q[2][maxm];
int tail[2],sum,op;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("number.in","r",stdin);
        freopen("number.out","w",stdout);
    #endif
    scanf("%d",&sum);--sum;
    if (!sum) {puts("1");return 0;}
    Inc[1][0]=Inc[1][1]=1;
    for (int i=2;i<=N;i++)
    {
        int *f=Inc[i-1],*g=Inc[i];
        for (int i=1;i<=f[0];i++)
            g[i+1]+=f[i],g[i+3]+=f[i];
        for (int i=1;i<=N;i++)
            g[i+1]+=g[i]>>1,g[i]&=1;
        int &_len=g[0];_len=N;
        while (!g[_len]) --_len;
    }
    for (int i=1;i<=N;i++)
    {
        int *f=Inc[i],*g=_Inc[i];
        for (int i=1;i<=f[0];i+=S) {
        	int &num=g[++g[0]];
            for (int j=0;j<S;j++)
            	num|=f[i+j]<<j;
        }
    }
     
     
    register Number s0,s1,s;
    s.len=0;
    memset(s.b,0,sizeof(s.b));
    s0=s;s0.Add(0);q[op][++tail[op]]=s0;
    s1=s;s1.Add(1);q[op][++tail[op]]=s1;
    
    while (true) 
    {
        register int &t=tail[op^1];t=0;
        register Number *f=q[op],*g=q[op^1];
        for (register int k=0;k<2;k++)
        for (register int j=1;j<=tail[op];j++)
        {
            Number i=f[j];i.Add(k);
            if (!i.judge(k)) continue;
            if (k) --sum;g[++t]=i;
            if (!sum) {i.print();return 0;}
        }
        op^=1;
	}
    return 0;
}
