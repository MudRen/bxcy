// taoism.c

inherit SKILL;

void create() { seteuid(getuid()); }
string type() { return "knowledge"; }
int valid_learn(object me) 
{
	int lvl;
	
       lvl = (int)me->query_skill("yugalism",1);
	
          if(me->query("gender") == "无性" && lvl > 30)
             return notify_fail("你刚听一会儿，便觉心智迷糊，原来你的阴柔之气不足，无法领会里面的阴阳变化之道。\n");
           if(me->query("gender") == "男性" && lvl > 30)
             return notify_fail("你刚听一会儿，便觉心智迷糊，原来你的阴柔之气不足，无法领会里面的阴阳变化之道。\n");
		
        if(me->query("class") == "taoism")
		return notify_fail("哈哈！"+RANK_D->query_respect(me)
                +"即入道家，怎么却来学佛门心法？\n");
        if ( me->query_skill("taoism",1))
         return notify_fail("你不先散了「道学心法」，怎能学「大乘涅磐心法」？！\n");
	return 1;
}

int practice_skill(object me)
{	
        return notify_fail("大乘涅磐心法只能靠学(learn)来提高。\n");
}
