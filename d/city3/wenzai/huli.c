//bye enter
#include <ansi.h>
#include <room.h>
inherit ROOM;
int do_swim(string arg);

void create()
{
        set("short", "湖里");
        set("long", @LONG
水很深，你耳边全是水声，岸上大家惊讶的看着你…
你觉得自己干了件傻事，太瓜了。你还是快游(swim)吧！
LONG
        );
        set("objects", ([
               "/d/npc/m_weapon/tan/npc/fish.c" : 2,
             ]));

        setup();
}
void init()
{       object ob;
        add_action("do_swim", "swim");
}

void check_trigger()
{
        object me;
        me = this_player();
        if ((int)query("trigger") == 13) {
                message_vision("$N终于游上了岸, 你爬上岸一看, 你的衣服已经被大家拿走了...\n", me);
                me->move(__DIR__"xiaodao");
                delete("trigger");
                return;
        }
        if ((int)query("trigger") < 0) {
                message_vision("$N又游回原来的岸边,$N爬上岸一看, 你的衣服已经被大家拿走了...\n",me);
                me->move(__DIR__"zoulang4");
                delete("trigger");
                return;
        }
}
int do_swim(string arg)
{
        int i;
        if (!arg || arg == "") {
                write("你往北游还是往南游？\n");
                return 1;
        }
        if (arg == "north" || arg == "n") {
                add("trigger", 1);
                write("你奋力向北岸游去……\n");
                check_trigger();
                return 1;
        }
        if (arg == "south" || arg == "s") {
                i = (int)query("trigger")-1;
                delete("trigger");
                add("trigger", i);
                write("你奋力向南岸游去……\n");
                check_trigger();
                return 1;
        }
}
void reset()
{
        ::reset();
        delete("trigger");
}
