#include <bits/stdc++.h>
using namespace std; 
#define ll long long
int n;
ll a[1<<21],t1;
char getc(){
    static char *S,*T,buf[65536];
    if(S==T){T=(S=buf)+fread(buf,1,65536,stdin);if(S==T) return EOF;}
    return *S++;
}
int read(){
    static char ch;static int D;
    while(!isdigit(ch=getc()));
    for(D=ch-'0';isdigit(ch=getc());) D=D*10+ch-'0';
    return D;
}
void print(ll x)
{
    if(!x) putchar('0');
    else 
    {
        if(x/10) print(x/10);
        putchar(x%10+'0');
    }
}
int main()
{
    freopen("spy.in","r",stdin);
    freopen("spy.out","w",stdout);
   	n=read();
    for(int i=0;i<n;i++) a[i]=read();
    for(int i=0;i<n;i++) a[i]=a[i]*2-a[n-1];
    reverse(a,a+n);
    for(int k=n>>1;k;k>>=1)
    for(int i=0;i<n;i++)
    {
        if(i&k) continue;
        t1=(a[i]+a[i+k])>>1;
        a[i+k]=a[i]-t1;
        a[i]=t1;
    }
    for(int i=0;i<n;i++) printf("%lld ",a[i]);
    puts("");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
