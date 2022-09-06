//Room of wizard that haven't modify own workroom.
//Modify by Super 1998.1.2

inherit ROOM;

void create()
{
set("short","巫师工作室");


        set("long",@LONG
这是没有建造工作室的巫师的临时住处，这里的设备非常简单，
只有一些常用物品。
LONG );
        set("exits",([ /* sizeof() == 1 */
                "gc":"/d/city/guangchang",
                "test" : "none",
                "north":"/d/wizard/wizard_room" ]));
        set("valid_startroom", 1);
         set("freeze",1);
        set("no_fight", "1");
        set("no_clean_up", 0);
        setup();
}
void init()
 {
      add_action("do_kill","kill");
 }
int do_kill()
    {
       message_vision("$N脸色一沉，全身散发出一股浓烈的杀气，\n",this_player());
       return 0;
    }
int valid_leave(object me, string dir)
{
        if( dir=="north" && !wizardp(me) )
                return notify_fail("那里只有巫师才能进去。\n");
        return ::valid_leave(me, dir);
}

