// ITEM: shiquanwan.c
// Date: Qianyu 99/11/08

#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name(HIC"十全大补丸"NOR, ({"jiuhuayulu wan", "jiuhua wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗晶莹幽蓝的十全大补丸，经天神千羽精心练制而成，
服用后，周身通泰，似有无穷能量。\n");
                set("value", 1400000);
        }
        setup();
}

int do_eat(string arg)
{
        int fw;
        object me = this_player();

	if (!id(arg))  return notify_fail("你要吃什么？\n");
	if (me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");
	if(arg=="wan") 
	{
                     
	 	me->set("eff_jing",me->query("max_jing"));
		me->set("jing",me->query("max_jing"));
		me->set("eff_qi",me->query("max_qi"));
		me->set("qi",me->query("max_qi"));
		me->set("neili",me->query("max_neili"));
message_vision(HIC"$N吃下一颗十全大补丸，一股清新凉爽自丹田猛地升起，向全身扩散！\n"NOR,me);
		me->start_busy(1);
        	destruct(this_object());
	}
	return 1;
}

int query_autoload() { return 1; }