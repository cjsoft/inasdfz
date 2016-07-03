#include<bits/stdc++.h>
#define ll long long
#define N 20010
#define L 400
#define P 1000000009
using namespace std;
inline void Mu(int *a,int b)
{
    int k=0;
    for (int i=1;i<=a[0];++i)
	{
        a[i]=a[i]*b+k;
        k=a[i]>>1;
        a[i]=a[i]&1;
    }
    for (;a[0]<L&&k;k=k>>1) a[++a[0]]=k&1;
}
inline void A(int *a,const int *b)
{
    a[0]=max(a[0],b[0]);
    int k=0;
    for (int i=1;i<=a[0];++i){
        a[i]+=b[i]+k;
        k=a[i]>>1;
        a[i]=a[i]&1;
    }
    for (;a[0]<L&&k;k=k>>1) a[++a[0]]=k&1;
}
inline int getH(int *a,int len)
{
    int ret=0;
    for (int i=1;i<=len;++i)
        ret=((ll)ret*233%P+a[i])%P;
    return ret;
}
void print(int *a,int len)
{
    for(int i=len;i;--i)
		printf("%d",a[i]);
    puts("");
}
struct node
{
    int H,len;
    int b[L];
};
node q[N];int qh,qt,lastqh,lastqt;
int nn;
int t[L];
main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    scanf("%d",&nn);--nn;
    if (!nn){puts("1");return 0;}
    lastqh=qh=0;
	lastqt=qt=2;
    q[1].len=1;
	q[1].H=0;
    q[1].b[0]=1;
	q[1].b[1]=0;
    q[2].len=1;
	q[2].H=1;
    q[2].b[0]=1;
	q[2].b[1]=1;
    t[0]=1;
	t[1]=1;
    for (;;lastqh=qh,lastqt=qt)
	{
        Mu(t,10);
        for (int k=0;k<2;++k)
		{
            qh=lastqh;
            while (qh<lastqt)
			{
                q[++qt]=q[++qh];
                ++q[qt].len;
                q[qt].H=((ll)q[qt].H*233%P+k)%P;
                if (k) A(q[qt].b,t);
                if (q[qt].H!=getH(q[qt].b,q[qt].len)) --qt;
                else if (k) --nn;
                if (!nn)
				{
					print(q[qt].b,q[qt].len);
                    return 0;
                }
            }
        }
    }
}	
