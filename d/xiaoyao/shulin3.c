// Room: /d/xiaoyao/shulin3.c
inherit ROOM;
void create()
{
    set("short", "树林");
    set("long", @LONG
这是一片茂密的树林。很多棵几十丈高的大树聚在一块，象一把把琼天
大伞，连日月都被遮蔽得暗然无光。树林中还不时可以听到大自然发出的声响。这正是个打鸟（da）的好机会。
LONG
    );
set("no_fight", 1);
    set("objects", ([ ]));
    set("outdoors", "xiaoyao");
    set("exits", ([ /* sizeof() == 4 */
    "west" : "/d/wudang/wdroad4",
  "south" : __DIR__"shulin3",
  "north" : __DIR__"shulin3",
  "east" : __DIR__"shulin2",
]));
    set("no_clean_up", 0);
    setup();
}
void init()
{
        add_action("do_da", "da");
}
int do_da()
{
        object me;
        int i, kar, cps, bb,mm;
        me = this_player();

        if(me->is_busy())
             return notify_fail("你还是等弓装好了箭再打鸟吧！\n");

        if(me->query("qi")<10)
             return notify_fail(HIR"你还是先休息一下吧，射箭也要用力气哟。。\n"NOR);

                           me->start_busy(3);
        message_vision("$N拿起儿时玩耍用的小弓小箭，瞄准树上的小雀射去......\n", me);

               message_vision("$N只听树上一阵鸟儿急鸣…\n",me);
        kar = me->query("kar");
        
        if (random(kar)>15) {
                message_vision("$N打到一只"HIW"百灵鸟。\n"NOR, me);
                    if (me->query("combat_exp")>=10000000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                else {
                        bb=(int)me->query("combat_exp");
                        me->set("combat_exp",150+bb);
                        tell_object(me,"你得到了150点经验\n");
                }
       me->receive_damage("qi", 10);
                bb=(int)me->query("potential");
                    if (me->query("combat_exp")>=10000000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                else {
                        me->set("potential",12+bb);
                        tell_object(me,"你得到了12点潜能\n");
                }

                return 1;
        
        if (random(kar)>10) 
                message_vision("$N打到一只"HIY"金丝雀。\n"NOR, me);
                    if (me->query("combat_exp")>=10000000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                else {
                        bb=(int)me->query("combat_exp");
                        me->set("combat_exp",130+bb);
                        tell_object(me,"你得到了130点经验\n");
                }
       me->receive_damage("qi", 10);
                bb=(int)me->query("potential");
                    if (me->query("combat_exp")>=10000000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                else {
                        me->set("potential",bb+10);
                        tell_object(me,"你得到了10点潜能\n");
                }

                return 1;
        }
        
        if (random(kar)>8) 
            {
               message_vision("$N打到一只"HIG"鹦鹉。\n"NOR, me);
                bb=(int)me->query("combat_exp");
                    if (me->query("combat_exp")>=10000000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                        else {
                        tell_object(me,"你得到了110点经验\n");
                        me->set("combat_exp",110+bb);
                }
            me->receive_damage("qi", 10);  
                
                bb=(int)me->query("potential");
                    if (me->query("combat_exp")>=10000000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                else {
                        me->set("potential",bb+8);
                       tell_object(me,"你得到了8点潜能\n");
               }

               return 1;
       }
        if (random(kar)>5)
            {
               message_vision("$N打到一只"YEL"麻雀。\n"NOR, me);
                bb=(int)me->query("combat_exp");
                    if (me->query("combat_exp")>=10000000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                        else {
                        tell_object(me,"你得到了90点经验\n");
                        me->set("combat_exp",90+bb);
                }
            me->receive_damage("qi", 10);  
                
                bb=(int)me->query("potential");
                    if (me->query("combat_exp")>=2000000)
                        tell_object(me,"你已经不能用打鸟来锻炼了。\n");
                else {
                        me->set("potential",bb+6);
                       tell_object(me,"你得到了6点潜能\n");
               }

               return 1;
       }
        else 
           {
                me->receive_damage("qi", 10);  
                message_vision("$N什么也没打到。\n",me );
     }

        return 1;
}

