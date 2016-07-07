#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<algorithm>
using namespace std;

char C;
bool tt;
bool list0[1005],list1[1005];
int s[2005][2][2005],ss,ti0,ti1;
int id,T,i,j,N,list[2005],sl[2005][2];

bool work0(int a1,int a2)
{
	int i;
	for(i=a1+1;i<a2;i++)
		if(list0[i]){ti0=i;return true;}
	return false;
}

bool work1(int a1,int a2)
{
	int i;
	for(i=a1+1;i<a2;i++)
		if(list1[i]){ti1=i;return true;}
	return false;
}

int main()
{
	freopen("probe.in","r",stdin);
	freopen("probe.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d\n",&N);
		list[0]=0;ss=0;tt=false;
		memset(list0,false,sizeof(list0));
		memset(list1,false,sizeof(list1));
		for(i=1;i<=2000;i++)
		{
			sl[i][0]=sl[i][1]=0;
			s[i][1][sl[i][1]]=0,s[i][0][++sl[i][0]]=-1;
		}
		for(i=1;i<=N;i++)
		{
			scanf("%c %d\n",&C,&id);
			switch(C)
			{
				case 'E':
					if(id)
					{
						if(s[id][0][sl[id][0]]<s[id][1][sl[id][1]])
						{
//							while(work1(s[id][0],s[id][1])&&work0(ti1,s[id][1]))list1[ti1]=list0[ti0]=false,ss--;
							if(s[id][0][sl[id][0]]==-1)s[id][0][sl[id][0]]=i;
							else s[id][0][++sl[id][0]]=i;
							ss++;
						}
						else 
						{
							if(work1(s[id][0][sl[id][0]],i))s[id][0][++sl[id][0]]=i,s[id][1][++sl[id][1]]=ti1,list1[ti1]=false;
							else tt=true;
						}
					}
					else list0[i]=true,ss++;
					break;
/*					s[id][0]++;ss++;
					if(s[id][1]==-1)s[id][1]=0;
					if(id&&s[id][0]-s[id][1]>1)
					{
						if(!s[0][1])tt=true;
						else s[0][1]--,s[id][1]++,ss--,sl--;
					}*/
				case 'L':
					if(id)
					{
						if(s[id][0][sl[id][0]]==-1) 
						{
							s[id][1][++sl[id][1]]=i,s[id][0][sl[id][0]]=0;
//							while(work1())
						}
						else 
						{
							if(s[id][1][sl[id][1]]<s[id][0][sl[id][0]])	
							{
//								while(work0(s[id][1],s[id][0])&&work1(ti0,s[id][0]))list1[ti1]=list0[ti0]=false,ss--;
								s[id][1][!!sl[id][1]]=i,ss--;
							}				
							else
							{
								if(work0(s[id][1][sl[id][1]],i))s[id][1][++sl[id][1]]=i,s[id][0][++sl[id][0]]=ti0,list0[ti0]=false,ss--;
								else tt=true;
							}
						}
					}
					else list1[i]=true;
					break;
/*					s[id][1]++;
					if(id&&s[id][1])ss--;
					if(!id&&ss>0)sl++;
					if(id&&s[id][1]-s[id][0]>=1)
					{
						if(!s[0][0])tt=true;
						else s[0][0]--,s[id][0]++;
					}*/
			}
		}
		for(i=1;i<=2000;i++)
		{
			if(!sl[i][1]&&s[i][0][sl[i][0]]==-1)continue;
			if(sl[i][0]>sl[i][1])
			{
				for(j=1;j<=sl[i][1];j++)
				{					
					while(work1(s[i][0][j],s[i][1][j])&&work0(ti1,s[i][1][j]))list1[ti1]=list0[ti0]=false,ss--;
					while(work0(s[i][1][j-1],s[i][0][j])&&work1(ti0,s[i][0][j]))list1[ti1]=list0[ti0]=false,ss--;
				}
				while(work0(s[i][1][j-1],s[i][0][j])&&work1(ti0,s[i][0][j]))list1[ti1]=list0[ti0]=false,ss--;
				list[++list[0]]=s[i][0][sl[i][0]];
			}
			else
			{
				for(j=1;j<=sl[i][0];j++)
				{
					while(work1(s[i][0][j],s[i][1][j])&&work0(ti1,s[i][1][j]))list1[ti1]=list0[ti0]=false,ss--;
					while(work0(s[i][1][j-1],s[i][0][j])&&work1(ti0,s[i][0][j]))list1[ti1]=list0[ti0]=false,ss--;
				}	
			}
		}
		for(i=1;i<=N;i++)
			if(list0[i])list[++list[0]]=i;
		sort(list+1,list+list[0]+1);j=N;
		while(!list1[j])j--;
		for(i=list[0];i;i--)
			if(j>list[i]){ss--,list1[j]=false;while(!list1[j])j--;}
		if(tt)printf("OTHER\n");
		else printf("%d\n",ss);
	}
	return 0;
}
