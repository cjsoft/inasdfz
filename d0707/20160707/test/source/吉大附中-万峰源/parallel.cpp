#include<bits/stdc++.h>
using namespace std;
char op[100];
char str[55];
char r(char a)
{
	if(a=='0')	return '1';
	return '0';
}
int main()
{
	for(int c=0;c<20;c++)
	{
		sprintf(op,"parallel%d.in",c);
		freopen(op,"r",stdin);
		sprintf(op,"parallel%d.out",c);
		freopen(op,"w",stdout);
		while(scanf("%s",str)!=EOF);
		int len=strlen(str);
		for(int i=0;i<len;i++)
			printf("%c?",r(str[i]));
		puts("");
		for(int i=0;i<len-1;i++)
			printf("%c%c",r(str[i]),str[i]);
		fclose(stdin);
		fclose(stdout);
	}
}
