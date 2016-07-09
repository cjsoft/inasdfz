#include <bits/stdc++.h>

using namespace std;

const int N = 2001000;
struct Node{
	int id,go[26];
}nod[N];
char s[2010];
int len,root,cnt;
void solve1();
int main(){
	freopen("encrypt.in","r",stdin);
	freopen("encrypt.out","w",stdout);
	scanf("%s",s);
	len = strlen(s);
	printf("-1 %d ",s[0]);
	int p = 0;
	for (int i = 0;i < len;i++){
		int w = s[i]-'a';
		nod[p].go[w] = ++cnt;
		p = cnt;
		nod[p].id = i;
	}
	int star = 1;
	for (int i = 1;i < len;i++){
		if (i == star){
			int p = 0,ans = 0,ansj = 0;
			for (int j = i;j < len;j++){
				int w = s[j]-'a',x = nod[p].go[w];
				if (x){
					p = x;
					ans++;
					ansj = nod[p].id; 
				}
				else break;
			}
			if (ans){
				printf("%d %d ",ans,ansj-ans+1);
				star = i + ans;
			}
			else{
				printf("-1 %d ",s[i]);
				star = i+1;
			}
		}
		p = 0;
		for (int j = i;j < len;j++){
			int w = s[j]-'a',x = nod[p].go[w];
			if (x) p = x;
			else {
				nod[p].go[w] = ++cnt;
				p = cnt;
				nod[p].id = j;
			}
		}
	}
	return 0;
}
