// Room: /u/xdd/gumu/gmqiecuo.c
// Modify by csy 98/12/29
#include <ansi.h>
inherit ROOM;

void delete_qiecuo(object me, object arg);

void create()
{
          set("short",HIR"切磋室"NOR);
          set("long", @LONG
这是古墓派弟子切磋武技的地方，空旷的一间石室，没有任何摆设。四周
点亮不少火把，倒也灯火通明，石壁上留有几个骇人的掌印，入石数分，显见
是高手相交所为。
LONG        );

          set("exits", ([
               "north" : __DIR__"gmqt",
          ]));
          set("no_fight", 1);
          setup();
}

void init()
{
        add_action("do_qiecuo", "qiecuo");
        add_action("do_qiecuo", "chaizhao");
}

int do_qiecuo(object arg)
{
        object me = this_player();
        object ob;
        mapping fam;

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢。\n");
//      if (ob->is_busy() || ob->is_fighting())
//                    return notify_fail("你没看见对方正忙着吗？\n");
        if (!arg)
            return notify_fail("你要和谁切磋武艺？\n");
        if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
            return notify_fail("你不是古墓派传人。\n");
        if (!(ob = present(arg, this_object())))
            return notify_fail("这人现在不在这里！\n");
        if (me == ob)
            return notify_fail("你想玩双手互搏吗？\n");
        if (!living(ob))
            return notify_fail("你必须先把" + arg->name() + "弄醒。\n");
        if (!userp(ob))
            return notify_fail("你只能和玩家切磋武艺！\n");
        if (me->query("combat_exp") > 150000)
            return notify_fail("你功夫过高，已经不能从切磋中得到帮助了！\n"); 
        if (ob->query("combat_exp") < me->query("combat_exp")/2 )
            return notify_fail("这人功夫与你相差太远，无法助你练功！\n");
        if (me->query("jing") < 40 || me->query("qi") < 40)
            return notify_fail("你太累了，还是先休息一会儿吧！\n");
        if (me->query_temp("gumu_qiecuo") >= 1)
            return notify_fail("你现在正在和别人拆招！\n");
         me->set_temp("gumu_qiecuo", 1);
         if (ob->query_temp("gumu_qiecuo") < 1)
         return notify_fail("对方似乎并没有要和你切磋武艺的意思！\n");
         message_vision("$N和$n拉开架式，拆起招来。\n", me, ob);
         me->start_busy(10);
         ob->start_busy(10);
         call_out("delete_qiecuo",15, me, ob);
         return 1;
}

void delete_qiecuo(object me, object ob)
{
        mapping my;
        if (!me || !ob) return;
        my = me->query_entire_dbase();

        me->delete_temp("gumu_qiecuo");
        ob->delete_temp("gumu_qiecuo");
        message_vision("$N和$n你攻我守，身形变幻，转眼便已拆了十余招.....\n",me, ob);
        if (my["potential"] < 1) {
         tell_object(me, "你什么也没有学到。\n");
         return;
         }
        my["potential"]--;
        tell_object(me, "你只觉得此番练习，收获颇丰，功夫掌握的更加娴熟了！\n");
        me->receive_damage("jing", 20+random(my["max_jing"]/10) );
        me->receive_damage("qi",  20+random(my["max_qi"]/10) );
        me->add("combat_exp", 1+random((my["max_pot"]-100)/3) );
        return;
}

