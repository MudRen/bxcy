// mingyu-shengong.c ڤ����
// By sylh and yp

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
mapping skl;	
string *sname;	
int i;	
	int lvl = (int)me->query_skill("yihua-force", 1);

       if ( !wizardp(this_player()) && (me->query("family/family_name") != "�ƻ���"))
                return notify_fail("�㲻���ƻ������Ӳ���ʹ��ڤ����.\n
                                    Ҫ������λ����֪������ɲ���.\n");
    if ( me->query("gender") != "Ů��")
		return notify_fail("�ƻ���������������,����֪���˿ɲ�����!\n");
skl = this_player()->query_skills();	
sname  = keys(skl);	
for (i=0;i<sizeof(skl);i++){	
if (sname[i]=="beiming-shengong") continue;	
if (sname[i]=="yijing-force") continue;     	
if (sname[i]=="mingyu-shengong") continue;	
if( SKILL_D(sname[i])->valid_enable("force") )	
/*
	if ( me->query_skill("bibo-shengong",1)
	|| me->query_skill("bahuang-gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("zixia-shengong",1) )
*/
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧڤ���񹦣���\n");
}

	return 1;
}

int practice_skill(object me)
{
    return notify_fail("ڤ����ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
    return __DIR__"mingyu-shengong/" + func;
}
