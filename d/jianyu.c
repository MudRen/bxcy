// ----/d/jianyu.c ----
#include <ansi.h>
inherit ROOM;
nosave string *verbs=({"look","say","help","quit"});
void create()
{
        set("short", "海盗船");
        set("long", @LONG
一条没有舵手的破旧木船，桅杆上绑着一面烂旗子，上面画着一个
骷髅头，几条被海水泡得有点霉烂的缆绳吃力地扯起风帆，这里是江湖
风云里被遗忘的角落，你永远也不知道，这船到底要驶向那里。
LONG
        );
        set("no_fight",1);
        set("freeze",1);
        set("no_magic",1);
        setup();
}
void init()
{
   object me=this_player();
    if (me->query("id") == "demogorgon"){
     me->move(VOID_OB);
     call_out("dest",1,me);
     return;
    }
    if (!userp(me)) return;
    if (wizardp(me)){
        me->delete("shen");
        add_action("do_summon","summon");
        add_action("kick_out","kickout");
        return;
        }
    me->set("startroom",base_name(this_object()));
    me->set("block",time());
    if(me->is_ghost()) me->reincarnate();
    me->save();
    add_action("discmds","",1);

   remove_call_out("do_rumor");
   call_out("do_rumor",300);
}
int dest(object me)
{
    if (!me) return 0;
            message("vision",me->name()+"哈哈一笑，看来你在这里比死还难受，算了，老夫饶你一死，bye！\n",this_object());
    destruct(me);
    return 1;
}

int discmds(string arg)
{
    string verb=query_verb();
    if( EMOTE_D->do_emote( this_player(), verb, arg ) )
      return 1;
    if (member_array(verb,verbs)==-1)
        tell_object(this_player(),"你违反了游戏规则, 请好好的反省一下你的所作所为。\n");
    else
        return 0;
    return 1;
}
void do_rumor()
{
    object ob;

   if (!sizeof(ob)) return;
   foreach (ob in all_inventory(this_object()) )
   if (userp(ob) && !wizardp(ob) ) {
        if (time()-ob->query("block")>86400*2){
            ob->delete("block");
            ob->set("startroom","/d/city/wumiao");
            ob->move("/d/city/wumiao");
            message("vison",ob->name()+"从半空中划了一道美妙的弧线，惨嚎着滚到你脚边！\n",environment(ob),({ob}));
            continue;
        }
        CHANNEL_D->do_channel(this_object(),"sys",HIR+ob->name(1)+"在船仓里抓老鼠呀！"+NOR);
   }
   tell_room(this_object(),
    "从远处的江湖隐约传来断断续续的歌声：\n\n"+
"            沧海一声笑，滔滔两岸潮，\n"+
"            浮沉随浪只记今朝。\n"+
"            苍天笑，纷纷世上潮，\n"+
"            谁负谁胜天知晓。\n"+
"            江山笑，烟雨遥，\n"+
"            浪涛淘尽俗世几多娇。\n"+
"            清风笑，竟惹寂寥，\n"+
"            豪情仍在痴痴笑笑！\n"+
"            苍天笑，不再寂寥，\n"+
"            豪情仍在痴痴笑笑！\n");
    call_out("do_rumor",300);
}

int do_summon(string str)
{
    object me=this_player();
    object ob;
    if (!str || !wizardp(me)) return 0;
    ob = LOGIN_D->find_body(str);
    if (!ob) ob=find_player(str);
    if (!ob|| !me->visible(ob)) return notify_fail("咦... 有这个人吗?\n");
    if (ob==me) return notify_fail("哈哈哈... 你能把自己提起来吗？\n");
    if (environment(ob)==environment(me))   return notify_fail(ob->name(1)+"已经在你身边了。\n");
    tell_object(ob,"你眼前一阵黑....,心里一阵紧张?:那里做错了?\n");
    ob->move(environment(me));
    tell_object(me, "你把"+(string)ob->query("name")+"抓到你的面前.\n");
    return 1;
}
int kick_out(string str)
{
    object me=this_player();
    object ob;
    if (!str || !wizardp(me)) return 0;
    if (!ob=present(str,this_object()))
        return 0;
    if (!userp(ob))      return 0;
    ob->set("startroom","/d/city/wumiao");
    message_vision("$N飞起左脚把$n撩了起来，紧跟着右脚把$n踢了出去！\n",me,ob);
    ob->move("/d/city/wumiao");
    message("vison",ob->name()+"从半空中划了一道美妙的弧线，惨嚎着滚到你脚边！\n",environment(ob),({ob}));
    return 1;
}

