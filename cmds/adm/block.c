// function:    block player to /clone/misc/block.c
// creator:     ken@xajh.chinesemud.net
// creat time:  1998/04/27
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
inherit F_DBASE;
 
void auto_post(string title,string arg);
 
void create() 
{
        seteuid(getuid());
        set("channel_id","游戏精灵(block)");
}
 
int main(object me, string arg)
{
        object ob;
        int day;
        string who,why;
 
        if (!arg) return notify_fail("<Syntax>: block <player id> <day> because <why>.\n");

        if( sscanf(arg,"%s %d because %s",who,day,why) != 3 )
                return notify_fail("<Syntax>: block <player id> <day> because <why>.\n");

        if( day < 1 || day > 100 )
                return notify_fail("block player must up to 1~100 day.\n");

        ob = LOGIN_D->find_body(who);
        if (!ob) return notify_fail("No suck player online now ...\n");

        // moving

        if( wiz_level(me) < wiz_level("(arch)") && wizardp(ob) )
                return notify_fail("OOp！你不能 block 巫师。\n");

        if ( ob->query("block") )
                        return notify_fail(
                                sprintf("%s(%s)将在沧海呆到 %s 释放，到时候再说吧。\n",
                                        ob->name(),ob->query("id"),
                                        ctime((int)ob->query("block/time")) )
                                );
        tell_object(ob,RED"\n\n一阵大风刮来, 你眼前一阵黑....\n\n"NOR);

        ob->set("block/time",time()+day*24*60*60);
        ob->move("/clone/misc/block");

        tell_object(me, "你把"+(string)ob->query("name")+"关进了沧海.\n");

        tell_object(ob,YEL"\n.... 醒来时发现是"+(string)me->query("name")+
                        "把你关进了沧海.\n\n"NOR);

        auto_post(
                sprintf("公告：%s被关进了沧海.",ob->name() ),

                sprintf("%s(%s) 因为 %s 的缘故，\n"
                        "现在将其放逐到沧海 %d 天，将于 %s 后自动释放。\n\n",
                        ob->name(),ob->query("id"),why,
                        day,ctime((int)ob->query("block/time"))
        ) );

        if( !wizardp(ob) )
                CHANNEL_D->do_channel(this_object(),"rumor",ob->query("name")+"被关进了沧海。");
        // ok ..
        return 1;
}

void auto_post(string title,string body) {
        mapping note;
        object POSTER;
        if( objectp(POSTER=load_object("/clone/board/towiz_b")) )
        {
                note=([]);
                note["title"] = title;;
                note["author"] = sprintf("%s(%s)",this_player()->query("name"),this_player()->query("id"));
                note["time"] = time();
                POSTER->done_post(this_player(),note,body);
        }
        return;
}

int help(object me)
{
write(@HELP
指令格式 : block <某人> <天数> because <原因>

此指令可让你(你)将某人关到沧海。
HELP
    );
    return 1;
}
