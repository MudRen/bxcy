// linji-zhuang.c �ټ�ʮ��ׯ
// create by host nov,27

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
mapping skl;	
string *sname;	
int i;	

        if ( (me->query("family/family_name") != "������"))
          return notify_fail("�㲻�Ƕ��ҵ��ӣ�������ϰ�ټ�ʮ��ׯ��\n");
				    
        if ( me->query("gender") == "����" )
         return notify_fail("���޸����ԣ�����������������ᴿ��������ķ����ڹ��ķ���\n");

        if ((int)me->query_skill("force", 1) < 20)
           return notify_fail("��Ļ����ڹ���򻹲������޷�����ټ�ʮ��ׯ��\n");
/*

        if ( me->query_skill("bahuang-gong",1)
        || me->query_skill("beiming-shengong",1)
        || me->query_skill("bibo-shengong",1)
        || me->query_skill("hamagong",1)
        || me->query_skill("huagong-dafa",1)
        || me->query_skill("huntian-qigong",1)
        || me->query_skill("hunyuan-yiqi",1)
        || me->query_skill("jiuyang-shengong",1)
        || me->query_skill("kurong-changong",1)
//      || me->query_skill("linji-zhuang",1)
        || me->query_skill("longxiang",1)
//      || me->query_skill("taiji-shengong",1)
        || me->query_skill("wuzheng-xinfa",1)
        || me->query_skill("xiantian-qigong",1)
        || me->query_skill("xiaowuxiang",1)
        || me->query_skill("yunlong-shengong",1)
        || me->query_skill("yunv-xinfa",1)
        || me->query_skill("zixia-shengong",1) )
*/
skl = this_player()->query_skills();	
sname  = keys(skl);	
for (i=0;i<sizeof(skl);i++){	
if (sname[i]=="yijing-force") continue;	
if (sname[i]=="linji-zhuang") continue;	
if( SKILL_D(sname[i])->valid_enable("force") )	
	         return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�ټ�ʮ��ׯ����\n");
}
	return 1;
}

string exert_function_file(string func)
{
        return __DIR__"linji-zhuang/" + func;
}
