// /clone/misc/gift.c	
#include <ansi.h>
#define GIFT_NAME "礼物包"	
inherit ITEM;
void create()
{
    set_name(HIR + GIFT_NAME + NOR, ({"gift","liwu"}));
    set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "件");
set("long",
HIG"※豪侠晚歌※" + HIC" 巫师的一点小心意，请打开(chai)来看看是什么？\n"NOR	
);
    set("value", 0);
    set("no_give",1);
    set("no_get",1);
    set("no_put",1);
    set("no_drop",1);
  }
    setup();
}
void init()
{
    add_action("do_chai", "chai");
}
int do_chai(string arg)
{
     object me = this_player();
     object cloth,weapon,leather;
		 cloth = new("/clone/cloth/zixuan");
		 leather=new("/clone/cloth/lingyun");
		 weapon=new("/d/binghuodao/npc/obj/killdragon");

  if (!id(arg))  return notify_fail("你要拆什么？\n");
if (me->query("五一",1))
	{
	  destruct(this_object());
	  return notify_fail("一个漂亮的人影突然在一阵烟雾中出现,一把抓过你手中的礼包,歪歪头看了半天：“呀~你该已经拿过了吧~别想偷懒哦~!!”说完转身跑了.\n");
		
		
	}
  
//          me->add("max_neili", 5000);	
//           me->add("max_jingli",500);	
me->add("potential",600000);
//if(me->query("combat_exp",1) < 10000000)
//{
me->add("combat_exp",600000) ;
//}
/*
cloth->move(me);
weapon->move(me);
leather->move(me);
*/
tell_object(me,HIC "你小心翼翼的拆开礼物包，只见一阵烟雾过后，你顿觉如浴春风,似乎又变厉害了些。\n" NOR);     	

//删除上次派礼物生成的参数，增加本次参数，确保每位玩家只能用一次。
me->delete("元旦",1);              	
me->delete("国庆节",1);  
me->delete("新春",1);
me->set("五一",1);
     destruct(this_object());
	 return 1;
}
void owner_is_killed() { destruct(this_object()); }
int query_autoload() { return 1; }
