// /clone/board/towiz_b.c
inherit BULLETIN_BOARD;
void create()
{
    set_name("巫师反馈意见板", ({ "board" }) );
    set("location", "/d/wizard/guest_room");
    set("board_id", "towiz_b");
    set("no_get",1);
    set("long", "这是一个供玩家和巫师交留的留言板。\n" );
    setup();
    set("capacity", 30);
    set("unit","块");
//  replace_program(BULLETIN_BOARD);
}
string long()
{
    string long_msg= ::long();
    if (!wizardp(this_player())) return long_msg+"\nopen netclub  打开你所在网吧的ip\n";
    long_msg+=BAN_D->list_sites();
    long_msg+=BAN_D->list_welcome_users();
    long_msg+="\n\nadd ban <ip地址>        加封一个ip\ndel ban <ip地址>        解封一个ip\nadd welcome <用户id>     增加一个受欢迎的玩家\ndel welcome <用户id>     删除一个受欢迎的玩家\n";
    return long_msg;
}
void init()
{
    object me=this_player();
    ::init();
    if (wizardp(me)){
        add_action("do_add","add");
        add_action("do_del","del");
    }
    add_action("do_open","open");
}
int do_add(string arg)
{
    string str;
    if (!arg) return 0;
    if (sscanf(arg,"welcome %s",str)){
        BAN_D->add_welcome_user(str);
        return 1;
    }
    if (sscanf(arg,"ban %s",str)){
        BAN_D->add_site(str);
        return 1;
    }
    return 0;
}
int do_del(string arg)
{
    string str;
    if (!arg) return 0;
    if (sscanf(arg,"welcome %s",str)){
        BAN_D->remove_welcome_user(str);
        return 1;
    }
    if (sscanf(arg,"ban %s",str)){
        BAN_D->remove_site(str);
        return 1;
    }
    return 0;
}
int do_open(string arg)
{
     if (arg && arg=="netclub"){
        BAN_D->open_club_line(this_player());
        return 1;
     }
     return 0;
}
int do_post(string arg)
{
    if (!wizardp(this_player())) return 0;
    return ::do_post(arg);
}

