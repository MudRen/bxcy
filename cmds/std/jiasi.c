// TIE@FY3
#include <ansi.h>
inherit F_SSERVER;
 int main(object me, object target)
{
        int wimpy;
        seteuid(getuid());
        if( !me->is_fighting() )
                return notify_fail("你不在战斗中，不需要假装死。\n");
    if(me->query("shen") > 5000)
   return notify_fail("你一片侠骨丹心，理应奋勇杀敌，何需假死！？\n");
   target = offensive_target(me);
   if (target->query("combat_exp") > me->query("combat_exp"))
     {
if(random(20)>8) { write("你企图装死，结果被"+target->query("nname")+"看破企图！\n"); 
      me->start_busy(1);
      return 1;
}
     }
else if (random(20)>15) {write("你企图装死，结果被"+target->query("name")+"看破企图！\n"); 
      me->start_busy(2);
      return 1; }
        wimpy = (int)me->query("env/wimpy");
        message_vision("$N惨叫一声，一头栽倒在地下。\n$N死了。\n",me);
      me->set_temp("disable_inputs",1);
      me->set_temp("block_msg/all",1);
      me->set("disable_type",HIG "<假死中>" NOR);
        me->set("no_get",1);
        me->remove_all_killer();
        me->remove_all_enemy();
        me->delete("env/wimpy");
        me->start_call_out( (: call_other, __FILE__, "remove_dazuo", me, wimpy :), 
30+random(50 - (int) me->query_con()));
        return 1;
}

void remove_dazuo(object me, int wimpy)
{
   me->delete_temp("disable_inputs");
   me->delete("disable_type");
 me->set("no_get",0);
   me->delete_temp("block_msg/all");
        me->set("env/wimpy",wimpy);
        message_vision("$N在地上悄悄地翻了个身，小心翼翼地睁开了眼。\n",me);
        me->move(environment(me),1);

}

int help(object me)
{
        write(@HELP
指令格式 : jiasi
让你在战斗中装死，创造逃生的机会。
正神高者不可以装死。

HELP
        );
        return 1;
}

