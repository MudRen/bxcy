// bingxue-xinfa.c  ��ѩ�ķ�
// By lucas

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	mapping skl;
	string *sname;
int i;	
        skl = me->query_skills();
        sname = keys(skl);
if ( me->query("gender") == "����" && me->query_skill("bingxue-xinfa",1) > 49) 	
return notify_fail("���޸����ԣ���������������������ı�ѩ�ķ���\n");	
        if ((int)me->query_skill("force", 1) < 10)
               return notify_fail("��Ļ����ڹ���򻹲�����������ѧϰ��ѩ�ķ���\n");
for (i=0;i<sizeof(skl);i++){	
if (sname[i]=="bingxue-xinfa") continue;	
if (sname[i]=="yijing-force") continue;	
if( SKILL_D(sname[i])->valid_enable("force") )	
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
 	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("guiyuan-tunafa",1) ||
me->query_skill("zixia-shengong",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("huashan-neigong",1))
*/
                return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��ѩ�ķ�����\n");
}
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("��ѩ�ķ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"bingxue-xinfa/" + func;
}

