#include<cstdio>
#include<cstring>

const int base=60;
const long long saffah=0xFFFFFFFFFFFFFFFLL;
long long s[310000];
int tot,len,ans;
char str[310000];


void readln(){
	scanf("%s",str);
	len=strlen(str);
	int top=(len-1)%base+1;
	tot=(len-1)/base+1;
	int i=len-1,k=0;
	while (i>base-1){
		++k;
		for (int j=i-(base-1);j<=i;j++){
			s[k]<<=1;s[k]+=str[j]-48;
		}
		i-=base;
	}
	++k;
	for (int j=0;j<=i;j++){s[k]<<=1;s[k]+=str[j]-48;}
}

void calc1(){
	if ((tot==1)&&(s[1]==1)) return;
	for (int i=1;i<=tot;i++) s[i]*=3;
	s[1]++;
	for (int i=1;i<tot;i++){
		s[i+1]+=s[i]>>base;
		s[i]&=saffah;
	}
	s[tot+1]=s[tot]>>base;
	s[tot]&=saffah;
	if (s[tot+1]) ++tot;

	++ans;
}

void calc2(){
	if ((tot==1)&&(s[1]==1)) return;
	int p=1;
	while (s[p]==0){
		++p;
		ans+=base;
	}
	--p;
	tot-=p;
	if (p) for (int i=1;i<=tot;i++) s[i]=s[i+p];
	p=0;
	while ((s[1] & (1<<p)) == 0) ++p;
	ans+=p;
	if (!p) return;
	long long TAT=(1<<p)-1;
	if (tot==1){
		s[1]>>=p;
		return;
	}
	for (int i=1;i<tot;i++){
		s[i]>>=p;
		s[i]|=(s[i+1] & TAT)<<(base-p);
	}
	s[tot]>>=p;
	if (!s[tot]) --tot;
}


int main(){
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);

	readln();
	//printf("%I64d",s[tot]);
	//for (int i=tot-1;i>=1;i--) printf("%08I64d",s[i]);
	ans=0;
	int tmp;
	if ((s[1] & 1) == 0) calc2();
	//printf("%I64d %I64d\n",s[tot],s[1]);
	//for (int i=tot;i>=1;i--) printf("%I64d ",s[i]);
	//printf("\n");
	while (!((tot==1)&&(s[1]==1))){
		calc1();
		//printf("%I64d\n",s[tot]);
		//printf("%d\n",ans);
		//for (int i=tot;i>=1;i--) printf("%I64d ",s[i]);
	//printf("\n");
		calc2();
		//printf("%d\n",ans);
		//printf("%I64d\n",s[tot]);
		//for (int i=tot;i>=1;i--) printf("%I64d ",s[i]);
	//printf("\n");
		//scanf("%d",&tmp);
	}
	printf("%d\n",ans);

	return 0;
}

