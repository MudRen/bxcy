//叶枫修改于 13/10/2001
// abandon.c


#include <ansi.h>
inherit F_CLEAN_UP;
mapping valid_types = ([
	"unarmed":      "拳脚",
	"sword":        "剑法",
	"blade":        "刀法",
	"stick":        "棒法",
	"staff":        "杖法",
	"club" :        "棍法",
	"force":        "内功",
	"parry":        "招架",
	"dodge":        "轻功",
	"taoism":       "法术",

]);
int main(object me, string arg)
{
	mapping skills, skillmap, pmap;
	string *skill, skillname, name;
	object ob;
	int i, level;

	if( !arg || arg=="" ) 
		return notify_fail("你要放弃哪一项技能？\n");

        level = me->query_skill(arg, 1);
        
/*	if( !me->delete_skill(arg) )
		return notify_fail("你并没有学过这项技能。\n");
*/
	if( arg =="all" ) {
		skills = me->query_skills();
		if( !mapp(skills) || sizeof(skills)==0 )
	                return notify_fail("你并没有学习任何的技能。\n");

		if( me != this_player(1) ) return 0;
	
		ob = me->query_temp("link_ob");
		if( !ob ) return 0;
		while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

		write(HIR"你是否决定放弃继续学习所有的技能，放弃后就连神仙也不能再帮你恢复！\n"NOR"如果你决定放弃继续学习所有的技能，请输入你的"HIG"管理密码："NOR);
                input_to("delete_all", ob);
	} else {		 
		name = arg;
		skillname = to_chinese(name);
//	      	if( !mapp(skillmap) || sizeof(skillmap)==0 ) return 1;              
		if (!me->query_skill(name))
  {
     write("ok。\n");
     me->delete_skill(name);
     return 1;
  }
		if( me != this_player(1) ) return 0;
	
		ob = me->query_temp("link_ob");
		if( !ob ) return 0;
		while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");
		write(HIR"你决定放弃继续学习" + HIG +skillname+ HIR + "，放弃后就连神仙也不能再帮你恢复！\n"NOR"如果你决定放弃继续学习" + HIG +skillname+ NOR + "，请输入你的"HIG"管理密码："NOR); 
                input_to("delete_skill", ob, arg, skillname, name);
	}
	return 1;
}

private void delete_all(string pass, object ob, string *skill)
{
	mapping skills, pmap, skillmap;
	int i;
	object me = this_player();
	string old_pass;

	write("\n");
	old_pass = ob->query("wizpwd");
	if( crypt(pass, old_pass)!=old_pass ) {
		write("密码错误，你不能放弃他的武功！\n");
		return;
	}
	skills = me->query_skills();
        pmap = me->query_skill_prepare();
	skillmap = me->query_skill_map();
	write(HIC"你决定放弃继续学习所有的技能。\n"NOR);
	skill = keys(valid_types);
	if ( !(!mapp(skillmap) || sizeof(skillmap)==0 )){
		for (i=0; i<sizeof(skill); i++) 
		{
                        if( undefinedp(valid_types[skill[i]]))
			{
				map_delete(skillmap, skill[i]);
	                        map_delete(pmap, skill[i]);
				continue;
			}
			if( !me->query_skill(skill[i]) ) continue;
			if(skillmap[skill[i]])
			{
				write("去除激发："+to_chinese(skill[i])+" => "+to_chinese(skillmap[skill[i]])+"。\n");
				me->map_skill(skill[i]);
			}
		}
	}
	skill = keys(skills);
	for (i=0; i<sizeof(skill); i++) {
		me->delete_skill(skill[i]);
	}
}

private void delete_skill(string pass, object ob, string *skill, string skillname, string name)
{
	mapping skillmap, pmap, skills;
	int i;
	object me = this_player();
	string old_pass,*skill2;

	write("\n");
	old_pass = ob->query("wizpwd");
	if( crypt(pass, old_pass)!=old_pass ) {
		write("密码错误，你不能放弃" + HIG +skillname+ NOR + "！\n");
		return;
	}
	skills = me->query_skills();
        pmap = me->query_skill_prepare();
	skillmap = me->query_skill_map();
	if( !(!mapp(skillmap) || sizeof(skillmap)==0 ))
	{
		skill = keys(valid_types);
		for (i=0; i<sizeof(skill); i++) 
		{
                        if( undefinedp(valid_types[skill[i]])) 
			{
				map_delete(skillmap, skill[i]);
	                        map_delete(pmap, skill[i]);
				continue;
			}
			if( !me->query_skill(skill[i]) ) continue;
			if(skillmap[skill[i]]==name)
			{
				write("去除激发："+to_chinese(skill[i])+" => "+to_chinese(skillmap[skill[i]])+"。\n");
				me->map_skill(skill[i]);
			}
		}
	}
	if(!me->delete_skill(name)) return;
	write(HIC"你决定放弃继续学习" + HIG +skillname+ HIC + "。\n"NOR);
	skill = keys(skills);
	for (i=0; i<sizeof(skill); i++) {
		if( skills[skill[i]] == name ) me->map_skill(skill[i]);
		}
}
int help()
{
	write(@TEXT
指令格式：abandon|fangqi <技能名称>

放弃一项你所学过的技能，注意这里所说的「放弃」是指将这项技能从你人物
的资料中删除，如果你以后还要练，必须从０开始重练，请务必考虑清楚。

这个指令使用的场合通常是用来删除一些「不小心」练出来的技能，由于每个
人有着不同的天赋，所修习的武功也不会相同。如果样样都学，到头来只会样
样不精。
TEXT
	);
	return 1;
}
