// /d/city/obj/gift.c
#include <ansi.h>
#define LAST_PAR "sorry"
#define THIS_PAR "sorrysf"
#define GIFT_NAME "幸运包"	
inherit ITEM;
void create()
{
    set_name(HIR + GIFT_NAME + NOR, ({"gift","liwu"}));
    set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "件");
        set("long", @LONG
┌──────────────────────┐	
│                                            │ 	
│  碧血残阳，所有巫师。                      │ 	
│                                            │ 	
│       向侠客们衷心祝福，WANFU ALL          │                	
│                                            │ 	
│            希望我们的明天更美好!           │        	
│                                            │ 	
│                                            │ 	
│                  AKAI，sigh, addoil!       │ 	
│                                            │ 	
└──────────────────────┘	
FYZQ 巫师的一点小心意，请打开(chai)来看看是什么？	
LONG
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


  if (!id(arg))  return notify_fail("你要拆什么？\n");
  if (me->query(THIS_PAR + "_chai",1)) 
	{
	  destruct(this_object());
	  return notify_fail("一个漂亮的人影突然在一阵烟雾中出现,一把抓过你手中的礼包,歪歪头看了半天：“呀~你该已经拿过了吧~别想偷懒哦~!!”说完转身跑了.\n");
		
		
	}
  
       me->add("max_neili", 5000);
       me->add("max_jingli",1000);
       me->add("potential",50000);
     if (me->query("combat_exp")<200000)
       me->add("combat_exp",200000) ;
	   if (me->query_skill("literate",1)<300)
	   {
		   me->set_skill("literate",300);
	   }
		if (me->query_skill("unarmed",1)<100)
	   {
		   me->set_skill("unarmed",100);
	   }
	   if (me->query_skill("dodge",1)<100)
	   {
		   me->set_skill("dodge",100);
	   }
	   if (me->query_skill("parry",1)<100)
	   {
		   me->set_skill("parry",100);
	   }
		if (me->query_skill("sword",1)<100)
	   {
		   me->set_skill("sword",100);
	   }
	   if (me->query_skill("force",1)<100)
	   {
		   me->set_skill("force",100);
	   }
	


      tell_object(me,HIC "你小心翼翼的拆开礼物包，只见一阵烟雾过后，你顿时隐隐约约感到自己身体有了一些变化。\n" NOR);

//删除上次派礼物生成的参数，增加本次参数，确保每位玩家只能用一次。
      me->delete(LAST_PAR + "_chai");
      me->set(THIS_PAR + "_chai",1);
     destruct(this_object());
	 return 1;
}
void owner_is_killed() { destruct(this_object()); }
int query_autoload() { return 1; }
