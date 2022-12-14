// ----/cmds/usr/quit.c ----
#include <command.h>
#include <ansi.h>
#define HTTP_D "/adm/daemons/httpd"

inherit F_DBASE;
inherit F_CLEAN_UP;
void create() 
{
        seteuid(getuid());
    set("channel_id", "离线指令");
}
string online_time(int t)
{
    int h, m, s;

        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t ;
        
        return sprintf("本次联线时间%d:%d",m,s);
}

int main(object me, string arg)
{
   int exp,online;
    object link_ob,*users;
object sb = me->query_temp("armor/finger");
    string ip_num,msg;
    
    if( me->query_busy() && !me->query_temp("netdead") )
    if(! me->query_temp("suicide") )
            return notify_fail("上一个动作未完成！\n");
    else{
            CHANNEL_D->do_channel(this_object(),"rumor",me->name() + "终于想通了，放弃自杀了。 :)");
            tell_object( me,MAG "\n\n你决定要放弃自杀，太好了，那下次再来吧！\n\n\n" NOR);
    }
//   if(environment(me)->query("fight_room")) return notify_fail("擂台上不能退出！\n");
    if (me->is_fighting())  return notify_fail("战斗中只能逃跑，不能退出游戏！\n");
    // We might be called on a link_dead player, so check this.
    link_ob = me->query_temp("link_ob");
    if( link_ob ) {
        // Are we possessing in others body ?
        if( link_ob->is_character() ) {
                write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
                exec(link_ob, me);
                link_ob->setup();
                return 1;
        }
        if(!living(me) ){
                write("什麽？\n");
                return 0;
        }
        if( !wizardp(me) ) {
            if ((me->query_temp("pker_starttime")+3600*me->query_temp("pker_time")) > me->query("mud_age"))
                return notify_fail("你现在不能退出游戏！\n");
            foreach (object ob in all_inventory(me))
                if(ob && !ob->query_autoload() )
                        DROP_CMD->do_drop(me, ob,1);
        }
        
            online=time()-link_ob->query("online_time");
        link_ob->set("last_on", time());
        link_ob->set("last_from", query_ip_name(me));
        exp=me->query("combat_exp")-link_ob->query("combat_exp");
        link_ob->set("combat_exp", me->query("combat_exp"));
        if (wizardp(me) && me->query("env/invisibility") )
            ;
        else
            link_ob->save();
        destruct(link_ob);
    }
    users = filter_array(users(), (: $1->query_temp("tomud") :));
    message("system",REM2(me),users);
    write("欢迎下次再来！\n");
    message("system", me->name() + "离开游戏。\n", environment(me), me);
    ip_num = query_ip_number(me);
    if (!ip_num)
        msg=me->query("name")+"("+me->query("id")+")"+HIR+"断线时间过长"+HIW+",自动离开游戏了。";
    else
        msg=me->query("name")+"("+me->query("id")+")("+query_ip_number(me)+")离开游戏了。";
    msg+=online_time(online);
    if (exp!=0)
        msg+=sprintf("，经验增加"+HIR+"%d"+NOR+WHT+"点。",exp);
    else
        msg+="。";
    CHANNEL_D->do_channel(this_object(), "sys",msg);

    reclaim_objects();
if(objectp(sb))
if(sb->query("id") == "magic ring")
sb->unequip();
    me->save();
    me->set("startroom", base_name(environment(me)));
    destruct(me);
//    HTTP_D->make_who();
    return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : quit
当你想暂时离开时, 可利用此一指令。
HELP
    );
    return 1;
}

