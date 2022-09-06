//shenshe.c
inherit ITEM;
void create()
{
	set_name("引路神蛇", ({ "shenshe"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一条有识路能力的神蛇，可以把主人带到白
		      驼山。(玩家键入home即可)\n");
		set("unit", "条");
		set("value", 0);
	}
}
void init()
{
    if ( !this_player()->is_ghost() )
 add_action("do_home","home");
}
int do_home()
{
    object me = this_player();
object ob;	
   if(me->query("family/family_name") != "白驼山派")
	  return notify_fail("你不是白驼山派弟子，「引路神蛇」不听你使唤。\n");
        if( me->over_encumbranced() )
                return notify_fail("你的负荷过重，动弹不得。\n");
        if( me->is_busy() )
                return notify_fail("你的动作还没有完成，不能移动。\n");
if (file_name(environment(me))=="/d/city/jianyu")
return notify_fail("监狱里你还是老实点吧！\n");
        if (me->is_fighting()) return 0;
ob=first_inventory(me);	
if (ob->is_character() && !ob->is_corpse() )	
return 0;	
ob=next_inventory(ob);

   message_vision("$N从怀中掏出「引路神蛇」，口里不知念了些什么，\n
   就见「引路神蛇」吐吐芯子，摇头摆尾地把$N往白驼山带去￣￣￣\n",me);
   me->move("/d/baituo/damen");
   return 1;
}
