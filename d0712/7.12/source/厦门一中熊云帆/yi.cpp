#include <bits/stdc++.h>

using namespace std;
const int N = 301000;
const int mod = (1<<29);

char s[N];
int a[N],cnt;
int x1,x2;
int len,ans;
int main(){
	freopen("yi.in","r",stdin);
	freopen("yi.out","w",stdout);
	scanf("%s",s);
	len = strlen(s);
	for (int i = len-1;i >= 0;i-=29){
		int x = 0;
		for (int j = max(0,i-28);j <= i;j++)
			x = (x << 1) + (s[j] == '1');
		a[++cnt] = x;
	}
	while (cnt != 1 || a[1] != 1){
		if (a[1]&1){
			for (int i = 1;i <= cnt;i++) 
				a[i] *= 3;
			a[1]++;
			for (int i = 1;i <= cnt;i++)
				if (a[i] >= mod){
					a[i+1] += a[i]/mod;
					a[i] &= (mod-1);
				}
			if (a[cnt+1] > 0) cnt++;
			x1++;
		}
		else{
			for (int i = cnt;i >= 1;i--){
				if (a[i]&1) a[i-1] += mod;
				a[i] /= 2;
			}
			if (a[cnt] == 0) cnt--;
			x2++;
		}
		cout << cnt << endl;
		printf("%d %d\n",x1,x2);
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}
