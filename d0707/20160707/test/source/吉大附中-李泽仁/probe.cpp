#include <bits/stdc++.h>
#define N 2010
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int n, cnt, in0, out0;
int in[N], out[N];

void Doit()
{
	n = read();
	for(int i = 1; i <= 2000; i ++)
		in[i] = 0;
	int flag = 0, cnt = 0;
	for(int i = 1; i <= n; i ++)
	{
		char ch[5];
		int x;
		scanf("%s", ch);
		x = read();
		if(flag) continue;
		if(ch[0] == 'E')
		{
			if(x)
			if(in[x] == 1)
			{
				if(!out0) flag = 1;
				else out0 --;
			}
			else in[x] = 1;
			else in0 ++;
			cnt ++;
		}
		else
		{
			if(x)
			if(in[x] == -1)
			{
				if(!in0) flag = 1;
				else in0 --;
			}
			else in[x] = -1;
			else out0 ++;
			cnt = max(0, cnt - 1);
		}
	}
	if(flag) printf("OTHER\n");
	else printf("%d\n", cnt);
}

int main()
{
	freopen("probe.in", "r", stdin);
	freopen("probe.out", "w", stdout);
	int T = read();
	while(T --) Doit();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
