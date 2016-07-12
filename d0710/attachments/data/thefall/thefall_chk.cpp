#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

FILE *fscore,*freport,*fstd,*fin,*fout;

char s1[1000005],s2[1000005],rep[1000];

void get_a_line(FILE* &F,char *s)
{
	char c;
	while(1)
	{
		if(fscanf(F,"%c",&c)==EOF)break;
		if(c=='\n')break;
		*s=c;
		s++;
	}
	*s=0;
}

int check(int full_score)
{
	int cnt=0;
	for(int i=0;i<10;i++)
	{
		get_a_line(fstd,s1);
		get_a_line(fout,s2);
		if(strcmp(s1,s2)==0)cnt++;
	}
	sprintf(rep,"Correct %d/10.",cnt);
	return cnt;
}
int main(int argc,char *argv[])
{
	int score=0;
	for(int i=0;argv[4][i];i++)
		score=score*10+argv[4][i]-48;
	fscore=fopen(argv[5],"w");//得分文件
	freport=fopen(argv[6],"w");//报告文件
	fstd=fopen(argv[3],"r");//标准输出
	fin=fopen(argv[1],"r");//标准输入
	fout=fopen(argv[2],"r");//用户输出
	int tmp=check(score);
	fprintf(fscore,"%d",tmp);
	fprintf(freport,rep);
	fclose(fscore);//关闭得分文件
	fclose(freport);//关闭报告文件
	return 0;
}
