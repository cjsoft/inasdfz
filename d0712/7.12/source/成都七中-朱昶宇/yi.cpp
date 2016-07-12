#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <bitset>
#define PROC "yi"
using namespace std;
#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif
typedef long long LL;
const int maxn=10100, bwid=60, maxp=200;
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

struct bigN{
	LL a[maxp];
	bigN () {memset(a,0,sizeof a);}
	bool operator [] (const int N)
	{
		return (a[N/bwid]>>(N%bwid))&1;
	}
	inline void set(const int N)
	{
		a[N/bwid]|=1LL<<(N%bwid);
	}
	bigN operator + (const bigN c)
	{
		bigN b;
		for (int i=0; i<maxp-1; i++)
		{
			b.a[i]+=a[i]+c.a[i];
			if (b.a[i]>=(1LL<<bwid))
			{
				b.a[i+1]++;
				b.a[i]&=((1LL<<bwid)-1);
			}
		}
		return b;
	}
	bigN &operator >>= (const int N)
	{
		int num;
		if (N>=bwid)
		{
			num=N/bwid;
			for (int i=0; i<maxp-num; i++)
				a[i]=a[i+num];
			for (int i=maxp-num; i<maxp; i++)
				a[i]=0;
		}
		num=N%bwid;
		for (int i=0; i<maxp-1; i++)
		{
			a[i]=(a[i]>>num)|((a[i+1]&((1LL<<num)-1))<<(bwid-num));
		}
		return (*this);
	}
	int count()
	{
		int back=0;
		for (int i=0; i<maxp; i++)
			back+=__builtin_popcountll(a[i]);
		return back;
	}
} bs, b1;
char s[maxn];
int n, ans;

int main()
{
	scanf("%s",s);
	n=strlen(s);
	b1.set(0);
	for (int i=0; i<n; i++)
		if (s[i]=='1')
			bs.set(n-i-1);
	while (bs.count()>1||!bs[0])
	{
//		printf("%d %d %d\n",ans,bs.count(),bs[0]);
		if (bs[0])
		{
			bs=bs+bs+bs+b1;
			ans++;
		}
		else
		{
			int cnt=0;
			while (!bs[cnt])
				cnt++;
			bs>>=cnt;
			ans+=cnt;
		}
	}
	printf("%d\n",ans);
	return 0;
}

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
