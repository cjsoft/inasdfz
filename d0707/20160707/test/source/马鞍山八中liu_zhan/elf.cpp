#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int a[20][40],b[40],f[20],k,n,len,i,j,s;
char str[1000];
bool check()
{
	int i,j;
	int ans[40];
	for (i=0;i<40;i++)
		ans[i]=0;
	for (i=0;i<k;i++)
		for (j=0;j<40;j++)
			ans[j]^=a[f[i]][j];
	for (i=0;i<40-len;i++)
	{
		for (j=0;j<len;j++)
			if (ans[i+j]!=b[j]) break;
		if (j==len) return true;
	}
	return false;
}
void work(int x)
{
	int i;
	if (check()) s++;
	for (i=x+1;i<n;i++)
	{
		f[k++]=i;
		work(i);
		k--;
	}
	return;
}
int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%s\n",str);
		for (j=0;j<40;j++)
		a[i][j]=str[j]-48;
	}
	scanf("%d",&len);
	scanf("%s",str);
	for (i=0;i<strlen(str);i++)
		b[i]=str[i]-48;
	k=0;
	s=0;
	work(-1);
	printf("%d",s);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
