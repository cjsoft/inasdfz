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
　　Reality slips far away【真相已逝】
　　Fiction comes alive as we start to play【谎言成真 我们就这么开始游戏】
　　Hope is no more behind a closed door【真相被打入门后】
　　As we drift away from what was once before【让我们与曾经的世界渐行渐远】
　　Hope and hopelessness become one【希望与绝望合而为一】
　　It’s all meaningless we’ve already begun【但已无关紧要 因为游戏早已开始】
　　Yap, we are all one in the same【是的，此时我们正同舟共济】
　　Never opposites when we play the same game【绝不对立 因为我们命运相连】
　　So I listen to the world I know right from wrong【我大胆聆听 因为我已能明辨黑白】
　　If I can stay focused then I can stay strong【若我专注于此 我定能更加强大】
　　If you ever wonder why I’m trapped inside【如果你想知道我为何深陷于此】
　　It’s really just because I told a pack of lies【只因为我诉说了太多谎言】
　　Maybe for a dream, or maybe it was pride【或许是为了梦想 或许是为了心中那份骄傲】
　　Maybe for myself I often wonder why?【也或许是为了我自己 是这样么？我无数次思考】
　　Until our very last breath【直到我们最后一次呼吸】
　　We‘re running after life, trying to avoid death【我们都会追求得生 驱散死亡】
　　We walk a thin line between hope and despair【在希望与绝望间我们寻觅一线生机】
　　Running from the truth but it’s already here【一味想逃离真相但它却无处不在】
　　Told so many lies I don’t know if they can find me【诉说了无数谎言 也不知何时会被拆穿】
　　Only one life to live so choose wisely【生命只有一次 我们必须慎行】
　　Heads or tails?【正面还是反面】
　　Do you know what side you’re on?【你又处于哪一面】
　　Does it even matter if it’s on the same coin?【哪怕我们处于同一枚硬币上 你也无所畏惧么？】
　　If you wanna achieve you gotta believe【如果你想实现 就必须将其坚信于心】
　　The time is right now there’s the door here’s the keys【钥匙在此 时机已到 是时候由你打开大门了】
　　Just gotta chase the pain away【要将痛苦驱出我们心头】
　　Let it fade away【让它就这么暗淡】
　　There’s a ray of hope beyond despair【在绝望之间发现那一丝希望】
　　Move on look for the truth in this world 【去吧 在这虚假的世界中发现被藏匿的真相】
　　(Only one life to live so choose wisely)【生命只有一次 我们必须慎行】
　　Break through the confusion【驱散困惑】
　　Find a solution【找出答案】
　　Beat the twisted evil things【击败那扭曲罪恶的事物】
　　Just do it, go for it【去找寻吧 放手干吧】
　　Never…【永不言弃 我们从未说放弃】
　　Never say never【永不言弃】
　　Never say never【我们从未说放弃】
　　Never say never【我们还未放弃】
　　(DANGANRONPA)
　　Don’t be hopeless stay focused【不要让绝望聚集在一起】
　　Gotta grind every time until they’re open【你要磨得够久才能知道谜团里藏着什么】
　　Gotta climb real high where the rope is【你要爬的够高才能知道绳子通向何方】
　　It is written in the sky see the opus【这是一部写在天空中的巨著】
　　And you know this【而你知道它在讲述什么】
　　Please don’t lose hope【请不要失去希望】
　　Try to progress keep your eye on the scope【尝试着前进吧 不要将目光离开你的方向】
　　For yourself or do it for your folks【这是为了你自己 也是为了你周围的大家】
　　Dedication gotta swear the oath【每一次献身都必须献上誓言】
　　(DANGANRONPA)
　　From this day forth stay on course【从这一天起我们继续前进】
　　No despair gotta have a heart【绝望不会再占据谁的心灵】
　　Take no loss every step cost【不让每一步白费】
　　Everybody wanna see if you’ll fall off【尽管每个人都在等待你的失败】
　　Keep your eye on the prize【但你的目光应直指最终的大奖】
　　Been through the worst even cried on the side【跨越那些让人哭泣的悲伤时刻】
　　No lie never know what you will find【每一句谎言都不会想到会被你戳穿】
　　Gotta believe let’s keep hope alive!【你必须让希望之火继续燃烧】
　　【念白】
　　Don’t throw yourself away【不要放弃自己】
　　Wipe all tears away【擦干你的眼泪】
　　Even if the future seems uncertain【尽管未来仍是模糊不清但这也无关紧要】
　　Survive find true happiness in this world【努力活下去吧 直到找到真实带来的喜悦】
　　So have a strong intention【明确你的目标】
　　And change direction【修正你的方向】
　　’cause the sky is the limit【已经没有什么可以限制你了】
　　Just do it, go for it【去找寻吧 放手干吧】
　　Never…【永不言弃 只因我们从未说放弃】
　　(For yourself or do it for your folks) 【这是为了你自己 也是为了你周围的大家】
　　Break through the confusion【驱散困惑】
　　Find a solution【找出答案】
　　Beat the twisted evil things【击败那扭曲罪恶的事物】
　　Just do it, go for it【去找寻吧 放手干吧】
　　Never…【永不言弃 我们从未说放弃】
　　（Gotta believe let’s keep hope alive!）【你必须让希望之火继续燃烧】
　　(DANGANRONPA)[2]
*/
