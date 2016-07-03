/* This is sample grader for the contestant */

#include "oath.h"
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<stdbool.h>
#include<assert.h>
#include<time.h>
using namespace std;

Data F(const Data &a,const Data &b)
{return Data(a.x+b.x);}

int main()
{
	freopen("oath.in","r",stdin);
	freopen("oath.out","w",stdout);
	int qn;
	int id,l,r,x;
	Init();
	scanf("%d",&qn);
	for(int tp,qi=1;qi<=qn;qi++)
	{
		scanf("%d",&tp);
		if(tp==1)
		{
			scanf("%d%d",&id,&x);
			Add_element(id,Data(x));
		}
		else if(tp==2)
		{
			scanf("%d",&id);
			Del_element(id);
		}
		else
		{
			scanf("%d%d%d",&id,&l,&r);
			printf("%d\n",Query_range(id,l,r));
		}
	}
	return 0;
}

