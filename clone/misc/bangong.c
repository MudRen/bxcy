// bangong.c
// WENWU 2003/8/1	
inherit ITEM;
#include <ansi.h>
#define LAST_PAR "xin"
#define THIS_PAR "xinsf"
void create()
{
set_name("办公桌", ({ "bangong zhuo","zhuo","table"}));
set_weight(5000000);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "张");
set("no_get",1);
set("long","一张普普通通的桌子，上面好象搁着一封信。是否(pick xin)拿下来看看呢?");	
set("value", 0);
set("material", "stone");
}       	
}	
void init()
{
add_action("do_pick", "pick");
}
int do_pick(string arg)
{
object me,obj;
me = this_player();
if( !arg || arg!="xin" ) return notify_fail("你要拿什么？\n");
if (me->query("id")!="lisa") {	
tell_object(me,CYN "对不起,这封信你不能拿。\n" NOR)	;
return 1;	
}	
if (me->query(THIS_PAR + "_pick")) {
tell_object(me,CYN "你从办公桌上拿起一封信。\n"NOR)	;
return 1;
}
message_vision("$N从办公桌上拿起一封信。\n",me );
obj = new ("/clone/misc/xin");
obj->move(me);
return 1;
}
