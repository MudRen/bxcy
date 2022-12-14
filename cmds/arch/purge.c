// purge.c
#include <ansi.h>
int help(object me);
inherit F_CLEAN_UP;
int help(object me);
protected int do_purge_players(int day,object me);
int main(object me, string arg)
{
        string name, reason;
        int day;
        if( !arg ) return help(me);
        if( sscanf(arg, "%d", day) && day >= 0) return do_purge_players(day,me);
        if( sscanf(arg, "%s because %s", name, reason)!=2 )
                return help(me);
        if( me!=this_player(1)
        && wiz_level(me) < wiz_level(SECURITY_D->get_status(arg)) )
                return notify_fail("你没有权力使用这个指令。\n");
        seteuid(getuid());
        if( file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__)<0 )
                return notify_fail("没有这位使用者。\n");
        rm(DATA_DIR + "login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        rm(DATA_DIR + "user/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        rm(DATA_DIR + "mail/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        write( "使用者 " + capitalize(name) + " 删除掉了。\n");
        log_file("static/PURGE", sprintf("[%s] %s purged %s because %s.\n",
                ctime(time())[0..15], geteuid(this_player(1)), name, reason));
        return 1;
}
protected int do_purge_players(int day,object me)
{
        int i, j, ppl_cnt, count;
        string *dir, *ppls, name;
        object ob;

        if( me!=this_player(1)
        && wiz_level(me) < wiz_level("(arch)") )
                return notify_fail("你的巫师等级太低，没有使用这个指令的权力。\n");
        if (day<60)     day=60;
        seteuid(getuid());
        message("system", RED"\n 整理玩家储存档中，请稍候....\n", users());
        write("处理中：\n");
        count = 0;
        ppl_cnt = 0;
        dir = get_dir(DATA_DIR + "login/");
        for(i=0; i<sizeof(dir); i++) {
                reset_eval_cost();
                write(HIY+"----------------"+dir[i]+"-------------\n"+NOR);
                ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
                ppl_cnt += sizeof(ppls);
                for(j=0; j<sizeof(ppls); j++) {
                        if( sscanf(ppls[j], "%s.o", name)==1 ){
                                if( (string)SECURITY_D->get_status(name)!="(player)" ){
                                    write(BOLD+"排除巫师"+name+"\n"+NOR);
                                        continue;
                                 }
                                if (ob=FINGER_D->acquire_login_ob(name)){
                                    if ( (time()-ob->query("last_on"))/86400<day){
                                        destruct(ob);
                                        continue; 
                                     }
                                    if (ob->query("combat_exp")>200000){
                                        printf("排除老玩家\t%-20s经验:%10d\t%d天未上线。\n",ob->query("name")+"("+name+"):",ob->query("combat_exp"),(time()-ob->query("last_on"))/86400);
                                        destruct(ob);
                                        continue; 
                                      }
                                    destruct(ob);
                                 }
                                    rm(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
                                    rm(DATA_DIR + "user/" + dir[i] + "/" + ppls[j]);
                                    rm(DATA_DIR + "mail/" + dir[i] + "/" + ppls[j]);
                                    count ++;
                         }
                }
        }
        write("\n\n原来总共有 " + ppl_cnt + " 位使用者。\n");
        write( count + " 个超过 " + day + " 天未上线的使用者被清除掉了。\n");
        write("现在总共有 " + (ppl_cnt - count) + " 位使用者。\n");
        log_file("static/PURGE", sprintf("[%s] %s cleaned up %d characters who didn't login for more than %d days\n"
                "\t\tResulting statistics: %d characters remaining.\n",
                ctime(time())[0..15], geteuid(this_player(1)), count, day, ppl_cnt - count));
        return 1;
}
int help(object me)
{
write(@HELP
指令格式：purge [<未上线天数>] | <使用者姓名> because <原因>
清除一个使用者或清除超过一定天数不曾上线地使用者。
HELP
        );
    return 1;
}


