// By Jungu

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
mapping skl;	
string *sname;	
int i;	
         if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ���򻹲������޷������Ԫ����\n");
/*
        if ( me->query_skill("bibo-shengong",1)
        || me->query_skill("beiming-shengong",1)
        || me->query_skill("bahuang-gong",1)
        || me->query_skill("hamagong",1)
        || me->query_skill("huagong-dafa",1)
        || me->query_skill("huntian-qigong",1)
        || me->query_skill("hunyuan-yiqi",1)
        || me->query_skill("longxiang",1)
        || me->query_skill("jiuyang-shengong",1)
        || me->query_skill("jiuyang-force",1)
        || me->query_skill("taiji-shengong",1)
        || me->query_skill("xiaowuxiang",1)
        || me->query_skill("zixia-shengong",1) 
        || me->query_skill("yunlong-shengong",1)
        || me->query_skill("wuji-shengong",1)
        || me->query_skill("guiyuan-dafa",1)
        || me->query_skill("xiantian-wuji",1)
        || me->query_skill("yunu-xinjing",1)
          || me->query_skill("tiangang-zhangqi",1))
*/
skl = this_player()->query_skills();	
sname  = keys(skl);	
for (i=0;i<sizeof(skl);i++){	
if (sname[i]=="yijing-force") continue;	
if (sname[i]=="shenyuan-gong") continue;	
if( SKILL_D(sname[i])->valid_enable("force") )	
                return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��Ԫ������\n");
}
                
        return 1;
}

int practice_skill(object me)
{
    return notify_fail("��Ԫ��ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
    return __DIR__"shenyuan-gong/" + func;
}

