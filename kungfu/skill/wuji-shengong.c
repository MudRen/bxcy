// wuji-shengong.c �޼���

inherit FORCE;
inherit F_DBASE;
public string query_type() {
       return "yin";
}

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
mapping skl;	
string *sname;	
int z;          	
      int i = (int)me->query_skill("wuji-shengong", 1);
	int t = 1, j;
	for (j = 1; j < i / 10; j++) t *= 2;

	if ((int)me->query_skill("force", 1) < 10)
              return notify_fail("��Ļ����ڹ���򻹲�����\n");
/*

	   if ( me->query_skill("bibo-shengong",1)     
          || me->query_skill("bahuang-gong",1)     
|| me->query_skill("beiming-shengong",1)
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
                return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�޼��񹦣���\n");
*/
if ( me->query("gender") == "����" && me->query_skill("wuji-shengong",1) > 49)	
return notify_fail("���޸����ԣ�����������������������޼��񹦡�\n");	
skl = this_player()->query_skills();	
sname  = keys(skl);	
for (z=0;z<sizeof(skl);z++){            	
if (sname[z]=="yijing-force") continue;         	
if (sname[z]=="wuji-shengong") continue;                	
if( SKILL_D(sname[z])->valid_enable("force") )          	
return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�޼��񹦣���\n");	
}
        return 1;
}

int practice_skill(object me)
{
       return notify_fail("�޼���ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
       return __DIR__"wuji-shengong/" + func;
}
