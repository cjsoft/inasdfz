#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <queue>
#define PROC "lian"
using namespace std;
#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif
typedef long long LL;
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
const int maxn=2010, baseup=23333, mod=998244353;
int base[maxn], n, L, R, a[maxn], cnt[maxn][maxn];
struct hja{
	int l, r, val;
	inline int siz()
	{
		return r-l+1;
	}
};
#define left (num<<1)
#define right ((num<<1)|1)
struct SMT{
	hja tree[maxn<<2];
	int id, nowp;
	
	inline void update(int num)
	{
		tree[num].val=((LL)tree[left].val*base[tree[right].siz()]+tree[right].val)%mod;
	}
	
	inline void build(int num, int l, int r)
	{
		tree[num].l=l;
		tree[num].r=r;
		if (l==r)
		{
			tree[num].val=cnt[id][l];
			return;
		}
		int mid=(l+r)>>1;
		build(left,l,mid);
		build(right,mid+1,r);
		update(num);
	}
	
	inline void modify(int num, int pos)
	{
		if (tree[num].l==tree[num].r)
		{
			tree[num].val=cnt[id][pos];
			nowp--;
			return;
		}
		int mid=(tree[num].l+tree[num].r)>>1;
		if (pos<=mid)
			modify(left,pos);
		else
			modify(right,pos);
		update(num);
	}
} state[maxn];
#undef left
#undef right
#define left(x) (x<<1)
#define right(x) ((x<<1)|1)
inline int segComp(const SMT &s1, const SMT &s2, int p1, int p2)
{
	if (s1.tree[p1].l==s1.tree[p1].r)
	{
		if (s1.tree[p1].val==s2.tree[p2].val)
			return -1;
		return s1.tree[p1].val<s2.tree[p2].val;
	}
	if (s1.tree[left(p1)].val==s2.tree[left(p2)].val)
		return segComp(s1,s2,right(p1),right(p2));
	else
		return segComp(s1,s2,left(p1),left(p2));
}
#undef left
#undef right

struct yjq{
	int p;
	yjq (int p=0):p(p){}
	bool operator < (const yjq &an) const
	{
		int back=segComp(state[p],state[an.p],1,1);
		if (back==-1) return p>an.p;
		return back;
	}
};

priority_queue<yjq> q;

int main()
{
	scanf("%d%d%d",&n,&L,&R);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	base[0]=1;
	for (int i=1; i<=n; i++)
		base[i]=(LL)base[i-1]*baseup%mod;
	for (int i=1; i<=n; i++)
	{
		state[i].id=i;
		state[i].nowp=n;
		for (int j=i; j<=n; j++)
			cnt[i][a[j]]++;
		state[i].build(1,1,n);
	}
	for (int i=1; i<=n; i++)
		q.push(yjq(i));
	for (int i=1; i<=R; i++)
	{
		int p=q.top().p;
		q.pop();
		if (i>=L)
			printf("%d %d\n",p,state[p].nowp);
		cnt[p][a[state[p].nowp]]--;
		state[p].modify(1,a[state[p].nowp]);
		if (state[p].nowp>=p)
			q.push(yjq(p));
	}
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
