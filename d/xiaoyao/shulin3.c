// Room: /d/xiaoyao/shulin3.c
inherit ROOM;
void create()
{
    set("short", "����");
    set("long", @LONG
����һƬï�ܵ����֡��ܶ�ü�ʮ�ɸߵĴ�������һ�飬��һ�Ѱ�����
��ɡ�������¶����ڱεð�Ȼ�޹⡣�����л���ʱ������������Ȼ���������졣�����Ǹ�����da���ĺû��ᡣ
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
             return notify_fail("�㻹�ǵȹ�װ���˼��ٴ���ɣ�\n");

        if(me->query("qi")<10)
             return notify_fail(HIR"�㻹������Ϣһ�°ɣ����ҲҪ������Ӵ����\n"NOR);

                           me->start_busy(3);
        message_vision("$N�����ʱ��ˣ�õ�С��С������׼���ϵ�Сȸ��ȥ......\n", me);

               message_vision("$Nֻ������һ�����������\n",me);
        kar = me->query("kar");
        
        if (random(kar)>15) {
                message_vision("$N��һֻ"HIW"������\n"NOR, me);
                    if (me->query("combat_exp")>=10000000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                else {
                        bb=(int)me->query("combat_exp");
                        me->set("combat_exp",150+bb);
                        tell_object(me,"��õ���150�㾭��\n");
                }
       me->receive_damage("qi", 10);
                bb=(int)me->query("potential");
                    if (me->query("combat_exp")>=10000000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                else {
                        me->set("potential",12+bb);
                        tell_object(me,"��õ���12��Ǳ��\n");
                }

                return 1;
        
        if (random(kar)>10) 
                message_vision("$N��һֻ"HIY"��˿ȸ��\n"NOR, me);
                    if (me->query("combat_exp")>=10000000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                else {
                        bb=(int)me->query("combat_exp");
                        me->set("combat_exp",130+bb);
                        tell_object(me,"��õ���130�㾭��\n");
                }
       me->receive_damage("qi", 10);
                bb=(int)me->query("potential");
                    if (me->query("combat_exp")>=10000000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                else {
                        me->set("potential",bb+10);
                        tell_object(me,"��õ���10��Ǳ��\n");
                }

                return 1;
        }
        
        if (random(kar)>8) 
            {
               message_vision("$N��һֻ"HIG"���ġ�\n"NOR, me);
                bb=(int)me->query("combat_exp");
                    if (me->query("combat_exp")>=10000000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                        else {
                        tell_object(me,"��õ���110�㾭��\n");
                        me->set("combat_exp",110+bb);
                }
            me->receive_damage("qi", 10);  
                
                bb=(int)me->query("potential");
                    if (me->query("combat_exp")>=10000000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                else {
                        me->set("potential",bb+8);
                       tell_object(me,"��õ���8��Ǳ��\n");
               }

               return 1;
       }
        if (random(kar)>5)
            {
               message_vision("$N��һֻ"YEL"��ȸ��\n"NOR, me);
                bb=(int)me->query("combat_exp");
                    if (me->query("combat_exp")>=10000000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                        else {
                        tell_object(me,"��õ���90�㾭��\n");
                        me->set("combat_exp",90+bb);
                }
            me->receive_damage("qi", 10);  
                
                bb=(int)me->query("potential");
                    if (me->query("combat_exp")>=2000000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                else {
                        me->set("potential",bb+6);
                       tell_object(me,"��õ���6��Ǳ��\n");
               }

               return 1;
       }
        else 
           {
                me->receive_damage("qi", 10);  
                message_vision("$NʲôҲû�򵽡�\n",me );
     }

        return 1;
}

