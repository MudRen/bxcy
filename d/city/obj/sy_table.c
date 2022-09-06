#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("赏月台", ({ "table"}));
    set_weight(5000000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "张");
        set("long","一张小巧玲珑的赏月台，专供玩家赏月聊天用的。上面放着几个小月饼，你可以拿（pick cake）一个月饼来吃。");
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
       if( !arg || arg!="cake" ) return notify_fail("你要拿什么？\n");
       if (me->query("get_cake")) return notify_fail("吃那么多干啥？很腻的！\n");

      obj = new (__DIR__"yuebing");
       obj->move(me);
       message_vision("$N从石桌上拿起一个小月饼。\n",me );
       me->set("get_cake",1);
       return 1;
}

int query_autoload() { return 1; }