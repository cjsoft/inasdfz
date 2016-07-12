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
	fscore=fopen(argv[5],"w");//�÷��ļ�
	freport=fopen(argv[6],"w");//�����ļ�
	fstd=fopen(argv[3],"r");//��׼���
	fin=fopen(argv[1],"r");//��׼����
	fout=fopen(argv[2],"r");//�û����
	int tmp=check(score);
	fprintf(fscore,"%d",tmp);
	fprintf(freport,rep);
	fclose(fscore);//�رյ÷��ļ�
	fclose(freport);//�رձ����ļ�
	return 0;
}
