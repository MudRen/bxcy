// ----/cmds/usr/quit.c ----
#include <command.h>
#include <ansi.h>
#define HTTP_D "/adm/daemons/httpd"

inherit F_DBASE;
inherit F_CLEAN_UP;
void create() 
{
        seteuid(getuid());
    set("channel_id", "����ָ��");
}
string online_time(int t)
{
    int h, m, s;

        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t ;
        
        return sprintf("��������ʱ��%d:%d",m,s);
}

int main(object me, string arg)
{
   int exp,online;
    object link_ob,*users;
object sb = me->query_temp("armor/finger");
    string ip_num,msg;
    
    if( me->query_busy() && !me->query_temp("netdead") )
    if(! me->query_temp("suicide") )
            return notify_fail("��һ������δ��ɣ�\n");
    else{
            CHANNEL_D->do_channel(this_object(),"rumor",me->name() + "������ͨ�ˣ�������ɱ�ˡ� :)");
            tell_object( me,MAG "\n\n�����Ҫ������ɱ��̫���ˣ����´������ɣ�\n\n\n" NOR);
    }
//   if(environment(me)->query("fight_room")) return notify_fail("��̨�ϲ����˳���\n");
    if (me->is_fighting())  return notify_fail("ս����ֻ�����ܣ������˳���Ϸ��\n");
    // We might be called on a link_dead player, so check this.
    link_ob = me->query_temp("link_ob");
    if( link_ob ) {
        // Are we possessing in others body ?
        if( link_ob->is_character() ) {
                write("��Ļ��ǻص�" + link_ob->name(1) + "�����ϡ�\n");
                exec(link_ob, me);
                link_ob->setup();
                return 1;
        }
        if(!living(me) ){
                write("ʲ�᣿\n");
                return 0;
        }
        if( !wizardp(me) ) {
            if ((me->query_temp("pker_starttime")+3600*me->query_temp("pker_time")) > me->query("mud_age"))
                return notify_fail("�����ڲ����˳���Ϸ��\n");
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
    write("��ӭ�´�������\n");
    message("system", me->name() + "�뿪��Ϸ��\n", environment(me), me);
    ip_num = query_ip_number(me);
    if (!ip_num)
        msg=me->query("name")+"("+me->query("id")+")"+HIR+"����ʱ�����"+HIW+",�Զ��뿪��Ϸ�ˡ�";
    else
        msg=me->query("name")+"("+me->query("id")+")("+query_ip_number(me)+")�뿪��Ϸ�ˡ�";
    msg+=online_time(online);
    if (exp!=0)
        msg+=sprintf("����������"+HIR+"%d"+NOR+WHT+"�㡣",exp);
    else
        msg+="��";
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
ָ���ʽ : quit
��������ʱ�뿪ʱ, �����ô�һָ�
HELP
    );
    return 1;
}

