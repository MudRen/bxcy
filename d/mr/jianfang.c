#include <room.h>
inherit ROOM;

void create()
{
        set("short", "武器库");
        set("long", @LONG
这里是慕容家族的武器库，慕容家为了兴复大燕，早已从各个方面
做好了准备。
LONG
        );
        set("no_sleep_room","1");

        set("exits",([
            "west" : __DIR__"wuchang",
]));
        set("objects",([
                "/d/huashan/obj/changjian":3,
                "/d/city/obj/gangdao":3,
                "/d/city/obj/junfu":3,
            ]));
       setup();

}
 
int valid_leave(object me, string dir)
{
        if ( present("jian 2",me) || present("blade 2",me) || present("junfu 2",me) || (present("jian",me) && present("blade",me)))
        {
        write("带这么多兵器出去，不太好吧？\n");
        return notify_fail("");
        }
        if (me->query_temp("mark/bingqi") && (present("jian",me) || present("blade",me) || present("junfu",me)))
        {
          return notify_fail("你刚拿了一把兵器出去，怎么又拿一把，太贪心了吧。\n");
        }
        me->set_temp("mark/bingqi",1);
        call_out("del_tmp",1800,me);
        return ::valid_leave(me, dir);
}

void del_tmp(object me)
{
        if ( objectp(me) ) me->delete_temp("mark/bingqi");
}