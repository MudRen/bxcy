//gift.c

#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");  
}
void create()
{
        set_name(HIC"新手丹"NOR, ({"dan"}));          
        set("unit", "颗");
        set("value", 0);
        set("long", "这是一颗isle送给五一期间进入碧血残阳的新手的礼物。\n");
        setup();

}
int do_eat(string arg)
{
        object me=this_player();
        if (!id(arg))  return notify_fail("你要吃什么？\n");
        if (me->is_busy() )
                return notify_fail("别急，慢慢吃，小心别噎着了。\n");
        if (me->query("combat_exp")>500000)
              return notify_fail("搞什么啊，你都不是新手了还想吃？！\n");
        if (me->query("max_neili")>1000)
              return notify_fail("看来你想用新手丹作弊,你可小心了！\n");
     else
        {
        me->set("combat_exp", 200000);                    
        me->add("potential", 5000);
        me->set("max_neili",2000);
        me->set("max_jingli",300);
        message_vision(HIW"$N吃下一颗新手丹，一股热流从丹田升起，顿时全身充满力量！\n"NOR,me);
              me->start_busy(2);
        destruct(this_object());
        return 1;
}
}
