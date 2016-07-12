#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#define PROC "jian"
using namespace std;
#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif
typedef long long LL;
const int maxn=20;
struct IO{
	IO()
	{
		freopen(PROC".in","r",stdin);
		freopen(PROC".out","w",stdout);
	}
	~IO()
	{
		fclose(stdin);
		fclose(stdout);
	}
} document;
int n, m, a[maxn], ans;
bool vis[maxn];
bool chk()
{
	memset(vis,0,sizeof vis);
	for (int i=1; i<=n; i++)
	{
		if (vis[(a[i]+i)%n])
			return 0;
		vis[(a[i]+i)%n]=1;
		a[i+n]=a[i];
	}
	for (int i=1; i<n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (a[i+j]!=a[j])
			{
				if (a[i+j]>a[j]) return 0;
				break;
			}
			if (j==n) return 0;
		}
	}
//	for (int i=1; i<=n; i++)
//		printf("%d ",a[i]);
//	puts("OK!");
	return 1;
}

void dfs(int pos, int rest)
{
	if (pos==n)
	{
		a[pos]=rest;
		ans+=chk();
		return;
	}
	for (int i=0; i<=rest; i++)
	{
		a[pos]=i;
		dfs(pos+1,rest-i);
	}
}

int main()
{
/*	system("mode 140,50");
	for (n=1; n<11; n++)
	{
		for (int j=1; j<=5; j++)
		{
			ans=0;
			dfs(1,n*j);
			printf("%5d%c",ans," \n"[j==5]);
		}
	}*/
	cin>>n>>m;
	if (m%n==0)
		dfs(1,m);
	cout<<ans<<endl;
	return 0;
}


//sigma mu(n/d)(2^d-1)/n

/*
(DANGANRONPA)
����Reality slips far away���������š�
����Fiction comes alive as we start to play�����Գ��� ���Ǿ���ô��ʼ��Ϸ��
����Hope is no more behind a closed door�����౻�����ź�
����As we drift away from what was once before�������������������罥�н�Զ��
����Hope and hopelessness become one��ϣ��������϶�Ϊһ��
����It��s all meaningless we��ve already begun�������޹ؽ�Ҫ ��Ϊ��Ϸ���ѿ�ʼ��
����Yap, we are all one in the same���ǵģ���ʱ������ͬ�۹��á�
����Never opposites when we play the same game���������� ��Ϊ��������������
����So I listen to the world I know right from wrong���Ҵ����� ��Ϊ����������ڰס�
����If I can stay focused then I can stay strong������רע�ڴ� �Ҷ��ܸ���ǿ��
����If you ever wonder why I��m trapped inside���������֪����Ϊ�������ڴˡ�
����It��s really just because I told a pack of lies��ֻ��Ϊ����˵��̫����ԡ�
����Maybe for a dream, or maybe it was pride��������Ϊ������ ������Ϊ�������Ƿݽ�����
����Maybe for myself I often wonder why?��Ҳ������Ϊ�����Լ� ������ô����������˼����
����Until our very last breath��ֱ���������һ�κ�����
����We��re running after life, trying to avoid death�����Ƕ���׷����� ��ɢ������
����We walk a thin line between hope and despair����ϣ�������������Ѱ��һ��������
����Running from the truth but it��s already here��һζ���������൫��ȴ�޴����ڡ�
����Told so many lies I don��t know if they can find me����˵���������� Ҳ��֪��ʱ�ᱻ�𴩡�
����Only one life to live so choose wisely������ֻ��һ�� ���Ǳ������С�
����Heads or tails?�����滹�Ƿ��桿
����Do you know what side you��re on?�����ִ�����һ�桿
����Does it even matter if it��s on the same coin?���������Ǵ���ͬһöӲ���� ��Ҳ����η��ô����
����If you wanna achieve you gotta believe���������ʵ�� �ͱ��뽫��������ġ�
����The time is right now there��s the door here��s the keys��Կ���ڴ� ʱ���ѵ� ��ʱ������򿪴����ˡ�
����Just gotta chase the pain away��Ҫ��ʹ������������ͷ��
����Let it fade away����������ô������
����There��s a ray of hope beyond despair���ھ���֮�䷢����һ˿ϣ����
����Move on look for the truth in this world ��ȥ�� ������ٵ������з��ֱ���������ࡿ
����(Only one life to live so choose wisely)������ֻ��һ�� ���Ǳ������С�
����Break through the confusion����ɢ����
����Find a solution���ҳ��𰸡�
����Beat the twisted evil things��������Ť���������
����Just do it, go for it��ȥ��Ѱ�� ���ָɰɡ�
����Never������������ ���Ǵ�δ˵������
����Never say never������������
����Never say never�����Ǵ�δ˵������
����Never say never�����ǻ�δ������
����(DANGANRONPA)
����Don��t be hopeless stay focused����Ҫ�þ����ۼ���һ��
����Gotta grind every time until they��re open����Ҫĥ�ù��ò���֪�����������ʲô��
����Gotta climb real high where the rope is����Ҫ���Ĺ��߲���֪������ͨ��η���
����It is written in the sky see the opus������һ��д������еľ�����
����And you know this������֪�����ڽ���ʲô��
����Please don��t lose hope���벻Ҫʧȥϣ����
����Try to progress keep your eye on the scope��������ǰ���� ��Ҫ��Ŀ���뿪��ķ���
����For yourself or do it for your folks������Ϊ�����Լ� Ҳ��Ϊ������Χ�Ĵ�ҡ�
����Dedication gotta swear the oath��ÿһ�����������������ԡ�
����(DANGANRONPA)
����From this day forth stay on course������һ�������Ǽ���ǰ����
����No despair gotta have a heart������������ռ��˭�����顿
����Take no loss every step cost������ÿһ���׷ѡ�
����Everybody wanna see if you��ll fall off������ÿ���˶��ڵȴ����ʧ�ܡ�
����Keep your eye on the prize�������Ŀ��Ӧֱָ���յĴ󽱡�
����Been through the worst even cried on the side����Խ��Щ���˿����ı���ʱ�̡�
����No lie never know what you will find��ÿһ����Զ������뵽�ᱻ�������
����Gotta believe let��s keep hope alive!���������ϣ��֮�����ȼ�ա�
��������ס�
����Don��t throw yourself away����Ҫ�����Լ���
����Wipe all tears away������������᡿
����Even if the future seems uncertain������δ������ģ�����嵫��Ҳ�޹ؽ�Ҫ��
����Survive find true happiness in this world��Ŭ������ȥ�� ֱ���ҵ���ʵ������ϲ�á�
����So have a strong intention����ȷ���Ŀ�꡿
����And change direction��������ķ���
������cause the sky is the limit���Ѿ�û��ʲô�����������ˡ�
����Just do it, go for it��ȥ��Ѱ�� ���ָɰɡ�
����Never������������ ֻ�����Ǵ�δ˵������
����(For yourself or do it for your folks) ������Ϊ�����Լ� Ҳ��Ϊ������Χ�Ĵ�ҡ�
����Break through the confusion����ɢ����
����Find a solution���ҳ��𰸡�
����Beat the twisted evil things��������Ť���������
����Just do it, go for it��ȥ��Ѱ�� ���ָɰɡ�
����Never������������ ���Ǵ�δ˵������
������Gotta believe let��s keep hope alive!�����������ϣ��֮�����ȼ�ա�
����(DANGANRONPA)[2]
*/
