#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;
namespace fastIO{
    #define BUF_SIZE 100000
    #define OUT_SIZE 100000
    #define ll long long
    //fread->read
    bool IOerror=0;
    inline char nc(){
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
            //{printf("IO error!\n");system("pause");for (;;);exit(0);}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(ll &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(double &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (ch=='.'){
            double tmp=1; ch=nc();
            for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
        }
        if (sign)x=-x;
    }
    inline void read(char *s){
        char ch=nc();
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
        *s=0;
    }
    inline void read(char &c){
        for (c=nc();blank(c);c=nc());
        if (IOerror){c=-1;return;}
    }
    //getchar->read
    inline void read1(int &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(ll &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(double &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (ch=='.'){
            double tmp=1;
            for (ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar());
        }
        if (bo)x=-x;
    }
    inline void read1(char *s){
        char ch=getchar();
        for (;blank(ch);ch=getchar());
        for (;!blank(ch);ch=getchar())*s++=ch;
        *s=0;
    }
    inline void read1(char &c){for (c=getchar();blank(c);c=getchar());}
    //scanf->read
    inline void read2(int &x){scanf("%d",&x);}
    inline void read2(ll &x){
        #ifdef _WIN32
            scanf("%I64d",&x);
        #else
        #ifdef __linux
            scanf("%lld",&x);
        #else
            puts("error:can't recognize the system!");
        #endif
        #endif
    }
    inline void read2(double &x){scanf("%lf",&x);}
    inline void read2(char *s){scanf("%s",s);}
    inline void read2(char &c){scanf(" %c",&c);}
    inline void readln2(char *s){gets(s);}
    //fwrite->write
    struct Ostream_fwrite{
        char *buf,*p1,*pend;
        Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
        void out(char ch){
            if (p1==pend){
                fwrite(buf,1,BUF_SIZE,stdout);p1=buf;
            }
            *p1++=ch;
        }
        void print(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(double x,int y){
            static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,
                1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
                100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
            if (x<-1e-12)out('-'),x=-x;x*=mul[y];
            ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1;
            ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2);
            if (y>0){out('.'); for (size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i); print(x3);}
        }
        void println(double x,int y){print(x,y);out('\n');}
        void print(char *s){while (*s)out(*s++);}
        void println(char *s){while (*s)out(*s++);out('\n');}
        void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
        ~Ostream_fwrite(){flush();}
    }Ostream;
    inline void print(int x){Ostream.print(x);}
    inline void println(int x){Ostream.println(x);}
    inline void print(char x){Ostream.out(x);}
    inline void println(char x){Ostream.out(x);Ostream.out('\n');}
    inline void print(ll x){Ostream.print(x);}
    inline void println(ll x){Ostream.println(x);}
    inline void print(double x,int y){Ostream.print(x,y);}
    inline void println(double x,int y){Ostream.println(x,y);}
    inline void print(char *s){Ostream.print(s);}
    inline void println(char *s){Ostream.println(s);}
    inline void println(){Ostream.out('\n');}
    inline void flush(){Ostream.flush();}
    //puts->write
    char Out[OUT_SIZE],*o=Out;
    inline void print1(int x){
        static char buf[15];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(int x){print1(x);*o++='\n';}
    inline void print1(ll x){
        static char buf[25];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(ll x){print1(x);*o++='\n';}
    inline void print1(char c){*o++=c;}
    inline void println1(char c){*o++=c;*o++='\n';}
    inline void print1(char *s){while (*s)*o++=*s++;}
    inline void println1(char *s){print1(s);*o++='\n';}
    inline void println1(){*o++='\n';}
    inline void flush1(){if (o!=Out){if (*(o-1)=='\n')*--o=0;puts(Out);}}
    struct puts_write{
        ~puts_write(){flush1();}
    }_puts;
    inline void print2(int x){printf("%d",x);}
    inline void println2(int x){printf("%d\n",x);}
    inline void print2(char x){printf("%c",x);}
    inline void println2(char x){printf("%c\n",x);}
    inline void print2(ll x){
        #ifdef _WIN32
            printf("%I64d",x);
        #else
        #ifdef __linux
            printf("%lld",x);
        #else
            puts("error:can't recognize the system!");
        #endif
        #endif
    }
    inline void println2(ll x){print2(x);printf("\n");}
    inline void println2(){printf("\n");}
    #undef ll
    #undef OUT_SIZE
    #undef BUF_SIZE
};
using namespace fastIO;
const int N=30000,mo=998244353;
const long long lim=8e18;
struct matrix{
	int x[6][6];
}BB,num[N<<2],mi[N<<2],ans;
int n,m,K,A[N<<2],p[10],B[N<<2],size[N<<2];
matrix get(const matrix &k1,const matrix &k2,const int &n){
	memset(BB.x,0x00,sizeof BB.x);
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++){
			long long tmp=0;
			for (int k=0;k<=n;k++){
				tmp+=1ll*k1.x[i][k]*k2.x[k][j];
				if (tmp>=lim) tmp%=mo;
			}
			BB.x[i][j]=tmp%mo;
		}
	return BB;
}
void change(int k1){
	num[k1]=get(num[k1*2],num[k1*2+1],K);
	if (K==4) mi[k1]=get(mi[k1*2],mi[k1*2+1],2); 
}
matrix turn(const matrix &k1,const int k2){
	for (int i=0;i<=k2;i++)
		for (int j=0;j<=k2;j++)
			BB.x[p[i]][p[j]]=k1.x[i][j];
	return BB;
}
void add(int k1,int k2){
	A[k1]=(A[k1]+k2)%K;
	for (int i=0;i<K;i++) p[i]=(i+k2)%K;
	p[K]=K;
	num[k1]=turn(num[k1],K);
	if (K==4){
		for (int i=0;i<2;i++) p[i]=(i+k2)%2; p[2]=2;
		mi[k1]=turn(mi[k1],2);
	}
}
int gcd(int k1,int k2){
	if (k2==0) return k1; return gcd(k2,k1%k2);
}
void chen(int k1,int k2){
	A[k1]=A[k1]*k2%K; B[k1]=B[k1]*k2%K;
	int nu=gcd(k2,K);
	if (nu==K){
		memset(num[k1].x,0x00,sizeof num[k1].x);
		for (int i=0;i<=K;i++) num[k1].x[i][i]=1;
		for (int i=1;i<=K;i++) num[k1].x[0][i]=size[k1];
		if (K==4){
			memset(mi[k1].x,0x00,sizeof mi[k1].x);
			int K=2;
			for (int i=0;i<=2;i++) mi[k1].x[i][i]=1;
			for (int i=1;i<=K;i++) mi[k1].x[0][i]=size[k1];
		}
		return;
	}
	if (nu==1){
		for (int i=0;i<K;i++) p[i]=i*k2%K; p[K]=K;
		num[k1]=turn(num[k1],K);
		if (K==4){
			int K=2;
			for (int i=0;i<K;i++) p[i]=i*k2%K; p[K]=K;
			mi[k1]=turn(mi[k1],K);
		}
		return;
	}
	int k3=k2/2;
	for (int i=0;i<2;i++) p[i]=i*k3%2; p[2]=2;
	mi[k1]=turn(mi[k1],2);
	memset(num[k1].x,0x00,sizeof num[k1].x);
	for (int i=0;i<=K;i++) num[k1].x[i][i]=1;
	for (int i=0;i<2;i++)
		for (int j=0;j<=K;j++)
			if (j==0||j==2)
				num[k1].x[i<<1][j]=mi[k1].x[i][j>>1];
			else num[k1].x[i<<1][j]=mi[k1].x[i][2];
	memset(mi[k1].x,0x00,sizeof mi[k1].x);
	int K=2;
	for (int i=0;i<=2;i++) mi[k1].x[i][i]=1;
	for (int i=1;i<=K;i++) mi[k1].x[0][i]=size[k1];
}
void pushdown(int k1){
	if (B[k1]!=1){
		chen(k1*2,B[k1]); chen(k1*2+1,B[k1]); B[k1]=1;
	}
	if (A[k1]){
		add(k1*2,A[k1]); add(k1*2+1,A[k1]); A[k1]=0;
	}
}
void build(int k1,int k2,int k3){
	size[k1]=k3-k2+1; B[k1]=1;
	if (k2==k3){
		int k; read(k);
		for (int i=0;i<=K;i++)
			if (i!=k) num[k1].x[i][i]=1;
			else for (int j=0;j<=K;j++)
				num[k1].x[i][j]=1;
		if (K==4){
			k&=1;
			for (int i=0;i<=2;i++)
				if (i!=k) mi[k1].x[i][i]=1;
				else for (int j=0;j<=2;j++)
					mi[k1].x[i][j]=1;
		}
		return;
	}
	int mid=k2+k3>>1;
	build(k1*2,k2,mid);
	build(k1*2+1,mid+1,k3);
	change(k1);
}
void add(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		add(k1,k6);
		return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	add(k1*2,k2,mid,k4,k5,k6);
	add(k1*2+1,mid+1,k3,k4,k5,k6);
	change(k1);
}
void chen(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		chen(k1,k6); return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	chen(k1*2,k2,mid,k4,k5,k6);
	chen(k1*2+1,mid+1,k3,k4,k5,k6);
	change(k1);
}
void find(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		ans=get(ans,num[k1],K); return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	find(k1*2,k2,mid,k4,k5);
	find(k1*2+1,mid+1,k3,k4,k5);
}
void solve(){
	read(n); read(K); read(m);
	memset(A,0x00,sizeof A);
	memset(B,0x00,sizeof B);
	memset(num,0x00,sizeof num);
	memset(mi,0x00,sizeof mi);
	build(1,1,n);
	for (;m;m--){
		int k1; read(k1);
		if (k1==1){
			int k2,k3,k4; read(k2); read(k3); read(k4);
			add(1,1,n,k2,k3,k4);
		} else if (k1==2){
			int k2,k3,k4; read(k2); read(k3); read(k4);
			chen(1,1,n,k2,k3,k4);
		} else {
			memset(ans.x,0x00,sizeof ans.x);
			int k2,k3; read(k2); read(k3);
			for (int i=0;i<=K;i++) ans.x[i][i]=1;
			find(1,1,n,k2,k3);
			int num=0;
			for (int i=0;i<K;i++) num=(num+ans.x[i][K])%mo;
			println(num);
		}
	}
	return;
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int T;
	read(T);
	for (;T;T--) solve();
	return 0;
}
