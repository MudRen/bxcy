// Room: /city/cangku.c
inherit ROOM;
void init();
void create()
{
    set("short", "仓库");
    set("long", @LONG
这里是一间黑黝黝的仓库，堆满了各种杂物，塞了满满一仓库。看来
你是被人拐卖到这里来的。
LONG
    );
    set("valid_startroom", 1);
    set("no_fight", 1);
    set("objects", ([
        __DIR__"obj/jitui" : 3,
        __DIR__"obj/jiudai" : 1,
    ]));
    setup();
}
void init()
{
    object ob;
    ob = this_player();
    ob->set("startroom","/d/city/cangku");
}
object do_check(string arg)
{
    object *obj;
    int i;
    if (!arg)   return 0;
    obj=deep_inventory(this_object());
    if (!sizeof(obj))   return 0;
    for (i=0;i<sizeof(obj);i++)
        if (obj[i]->id(arg) && obj[i]->is_character() && !obj[i]->is_corpse())    return obj[i];
    return 0;
}
