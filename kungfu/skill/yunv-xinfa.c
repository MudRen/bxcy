// yunv-xinfa.c ��Ů�ķ�

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
mapping skl;	
string *sname;	
int i;	

        if ( me->query("gender") == "����")
                return notify_fail("���޸����ԣ������ѵ���������ϰ��Ů�ķ���\n");

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ���򻹲�����\n");
/*

	if (
	me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
//	|| me->query_skill("mizong-xinfa",1)
	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunlong-shengong",1)
//	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("zixia-shengong",1) )
*/
skl = this_player()->query_skills();	
sname  = keys(skl);	
for (i=0;i<sizeof(skl);i++){	
if (sname[i]=="yijing-force") continue;	
if (sname[i]=="yunv-xinfa") continue; 	
if (sname[i]=="yunu-xinjing") continue;   	
if( SKILL_D(sname[i])->valid_enable("force") )	
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��Ů�ľ�����\n");
}
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("��Ů�ķ�ֻ����ѧ(learn)�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"yunv-xinfa/" + func;
}

