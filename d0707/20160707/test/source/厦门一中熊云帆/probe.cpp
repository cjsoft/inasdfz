#include <bits/stdc++.h>

using namespace std;
const int N = 2010;
int read(){
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || '9' < ch) {if (ch == '-') f = -1;ch = getchar();}
	while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0',ch = getchar();
	return x * f;
}
char readchar(){
	char ch = getchar();
	while (ch != 'E' && ch != 'L') ch = getchar();
	return ch;
}


char ch,c[N];
bool b[N];
int a[N],d[N],x,y;
int T,n,sum,id;
void solve1();
void solve2();
int main(){
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	T = read();
	while (T--){
		n = read();
		if (n > 15) solve1();
		else solve2();
	}
	return 0;
}
void solve1(){
		bool flag = 0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		sum = 0;
		for (int i = 1;i <= n;i++){
			ch = readchar();id = read();
			if (ch == 'E'){
				sum++;			
				if (id == 0) a[i] = 2001;
				else{
					if (b[id] == 0){b[id] = 1;a[i] = id;}
					else{
						int j = i-1,tip = 0;
						while (a[j] != id){
							if (a[j] == -2001) tip = j;
							j--;
						}
						if (tip == 0) flag = 1;
						else{
							a[tip] = 0;
							a[j] = 0;
							a[i] = id;
						}
					}
				}
			}
			else{
				sum--;
				if (id == 0){
					a[i] = -2001;
				}
				else{
					if (b[id] == 1) {
						for (int j = 1;j < i;j++) if (a[j] == id) a[j] = 0; 
						b[id] = 0;
					}
					else{
						bool nosol = 1;
						for (int j = 1;j < i;j++){
							if (a[j] == 2001) {
								a[j] = 0;
								nosol = 0;
								break;
							}
						}
						if (nosol) flag = 1;
					}
				}		
			}
			
			int sig = 0,del = 0,t = 1;

			for (int j = 1;j <= i;j++){
				if (a[j] > 0) sig++;
				if (a[j] < 0){
					del++;
					if (del > sig) flag = 1;
					if (del == sig){
						del = 0;sig = 0;
						for (int k = t;k <= j;k++) {
							if (a[k] > 0 && a[k] < 2001) b[a[k]] = 0;
							a[k] = 0;
						}
						t = j+1;
					}
				}
			}
			
		}

	if (flag == 1) puts("OTHER");
	else printf("%d\n",sum);
}
void solve2(){
	static bool bo[2010];
	static int x[20];
	static char ch2[110];
	static int id2[110];
	memset(bo,0,sizeof(bo));
	bool fflag = 1;
	int cnt = 0,ans = n;
	for (int i = 1;i <= n;i++) c[i] = readchar(),d[i] = read(),bo[d[i]] = 1;
	for (int i = 1;i <= 2000;i++) 
		if (bo[i]){
			x[++cnt] = i;
		}
	for (int i = 1;i <= 2000;i++)
		if (bo[i] == 0 && cnt <= n){
			x[++cnt] = i;
		}
	for (int i = 0;i < (1<<cnt);i++){
		int xx = 0;
		for (int j = 1;j <= cnt;j++){
			int u = 1<<j>>1;
			if (i&u){
				xx++;
				ch2[xx] = 'E';
				id2[xx] = x[j];
			}
		}
		for (int j = 1;j <= n;j++){
			xx++;
			ch2[xx] = c[j];
			id2[xx] = d[j];
		}
		
		bool flag = 0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		sum = 0;
		for (int i2 = 1;i2 <= xx;i2++){
			char ch = ch2[i2];
			int id = id2[i2];
			if (ch == 'E'){
				sum++;			
				if (id == 0) a[i2] = 2001;
				else{
					if (b[id] == 0){b[id] = 1;a[i2] = id;}
					else{
						int j = i2-1,tip = 0;
						while (a[j] != id){
							if (a[j] == -2001) tip = j;
							j--;
						}
						if (tip == 0) flag = 1;
						else{
							a[tip] = 0;
							a[j] = 0;
							a[i2] = id;
						}
					}
				}
			}
			else{
				sum--;
				if (id == 0){
					a[i2] = -2001;
				}
				else{
					if (b[id] == 1) {
						for (int j = 1;j < i2;j++) if (a[j] == id) a[j] = 0; 
						b[id] = 0;
					}
					else{
						bool nosol = 1;
						for (int j = 1;j < i2;j++){
							if (a[j] == 2001) {
								a[j] = 0;
								nosol = 0;
								break;
							}
						}
						if (nosol) flag = 1;
					}
				}		
			}
			
			int sig = 0,del = 0,t = 1;

			for (int j = 1;j <= i2;j++){
				if (a[j] > 0) sig++;
				if (a[j] < 0){
					del++;
					if (del > sig) flag = 1;
					if (del == sig){
						del = 0;sig = 0;
						for (int k = t;k <= j;k++) {
							if (a[k] > 0 && a[k] < 2001) b[a[k]] = 0;
							a[k] = 0;
						}
						t = j+1;
					}
				}
			}
			
		}

		if (flag == 0){fflag = 0;ans = min(ans,sum);}
	}
	if (fflag == 1) puts("OTHER");
	else printf("%d\n",ans);
}
