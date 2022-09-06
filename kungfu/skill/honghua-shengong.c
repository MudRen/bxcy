// honghua-shengong.c 红花神功
// By Xiang
// Modified by Hop

inherit FORCE;
inherit F_DBASE;
public string query_type() {
       return "yang";
}

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
mapping skl;	
string *sname;	
int i;	
	int lvl = (int)me->query_skill("honghua-shengong", 1);
	int t = 1, j;
	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;

	

	

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");

	if(lvl<=100)
	{
		if (lvl > 10 && (int)me->query("shen") < t * 120) 
			return notify_fail("你的侠义正气太低了。\n");
	}
	else
	{
		if ((int)me->query("shen") < (51200 + (lvl - 100) * 1000)) 
			return notify_fail("你的侠义正气太低了。\n");
	}
/*

	if ( me->query_skill("bibo-shengong",1)
|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bahuang-gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
//	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("longxiang",1)
//	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("zixia-shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学红花神功？！\n");
*/

if ( me->query("gender") == "无性" && me->query_skill("honghua-shengong",1) > 49)	
return notify_fail("你无根无性，阴阳不调，难以领会高深的红花神功。\n");	
skl = this_player()->query_skills();	
sname  = keys(skl);	
for (i=0;i<sizeof(skl);i++){	
if (sname[i]=="yijing-force") continue;	
if (sname[i]=="honghua-shengong") continue;	
if( SKILL_D(sname[i])->valid_enable("force") )	
return notify_fail("你不先散了别派内功，怎能学红花神功？！\n");	
}
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("红花神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"honghua-shengong/" + func;
}

