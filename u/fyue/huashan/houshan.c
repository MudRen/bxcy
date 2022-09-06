// houshan.c
// By Hop, 97.04.30
inherit ROOM;
void create()
{
    set("short", "后山");
    set("long", @LONG
这里是玉女峰后山的一个小山谷，长年人迹罕至。谷中古树参天，绿
荫森森。偶尔从远处传来几声悠扬的鸟语，伴随着阵阵花香，简直让人疑
心自己到了世外桃源。
你远远的看见谷中有两间小屋，不过看来已经好久每住过人了。你心里不
禁发起愁来，该怎么办呢？
LONG
    );
    set("exits", ([ /* sizeof() == 2 */
        "out" : __DIR__"siguoya",
    ]));
        set("objects", ([
                CLASS_D("huashan")+"/feng" : 1,
        ]));
    set("outdoors", "huashan" );
    set("no_magic",1);
    setup();
}
int valid_leave(object me, string dir)
{
    if ((me->query("family/family_name") == "华山派") && (me->query("family/master_id") == "feng qingyang"))
    {
        me->move("/d/huashan/square");
        me->delete_temp("mark/steps");
        tell_object(me,"你循着风清扬指点你的捷径一下子就来到了华山练武场。\n");
        return 1;
    }
    return 1;
}
