// biyun-xinfa.c 碧云心法
// cleansword

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
	int lvl = (int)me->query_skill("biyun-xinfa", 1);

	if ( (me->query("family/family_name") != "唐门"))
		return notify_fail("碧云心法乃唐门独门神功, 非唐门弟子不传!\n");
				    
	if ( me->query("gender") == "无性" && lvl > 49)
		return notify_fail("唐门不要你这种无根无性的人，你无法领会高深的碧云心法。\n");

	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("你的基本内功火候还不够，无法领会碧云心法。\n");
skl = this_player()->query_skills();	
sname  = keys(skl);	
for (i=0;i<sizeof(skl);i++){	
if (sname[i]=="yijing-force") continue;	
if (sname[i]=="biyun-xinfa") continue;	
if( SKILL_D(sname[i])->valid_enable("force") )	
return notify_fail("你不先散了别派内功，怎能学碧云心法？！\n");	
}
	return 1;
}

string exert_function_file(string func)
{
	return __DIR__"biyun-xinfa/" + func;
}
