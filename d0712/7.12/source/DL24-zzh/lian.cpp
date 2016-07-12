#include<cstdio>
#include<algorithm>

int n,p,q;
int s[2100];
int cnt[2100][2100];
int maxcnt;
int tot;

struct lisan{
	int a,p;
	bool operator <(const lisan &b){
		return a<b.a;
	}
}cute[310000];

struct saffah{
	int l,r;
	bool operator <(const saffah &b){
		for (int i=1;i<=maxcnt;i++) if (cnt[r][i]-cnt[l-1][i]!=cnt[b.r][i]-cnt[b.l-1][i]) return cnt[r][i]-cnt[l-1][i]>cnt[b.r][i]-cnt[b.l-1][i];
		return l<b.l;
	}
}lovely[4200000];

void init(){
	scanf("%d%d%d",&n,&p,&q);
	for (int i=1;i<=n;i++){
		scanf("%d",&cute[i].a);
		cute[i].p=i;
	}
	std::sort(cute+1,cute+n+1);
	s[cute[1].p]=1;
	for (int i=2;i<=n;i++) s[cute[i].p]=s[cute[i-1].p]+(cute[i].a!=cute[i-1].a);
	maxcnt=s[cute[n].p];
	tot=0;
	for (int i=1;i<=n;i++) for (int j=i;j<=n;j++){
		++cnt[j][s[i]];
		lovely[++tot]=(saffah){i,j};
	}
	std::sort(lovely+1,lovely+1+tot);
}

int main(){
	freopen("lian.in","r",stdin);
	freopen("lian.out","w",stdout);
	init();
	for (int i=p;i<=q;i++) printf("%d %d\n",lovely[i].l,lovely[i].r);
	return 0;
}

