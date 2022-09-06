// Room: /d/huashan/xiaodian.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "山顶小店");
    set("long", @LONG
这里是华山山顶的一间小店，卖些简单的饮食，专门赚那些游客的钱。
LONG
    );
    set("objects", ([ /* sizeof() == 2 */
  "/d/huashan/npc/xiaoer2" : 1,
  __DIR__"npc/youke" : 1,
]));
    set("no_clean_up", 0);
    set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"square",
]));
    setup();
}
void init()
{
add_action("do_set", "xxset");
}
int do_set(string arg)
{
object me=this_player();
int i;
string skill;
if(!arg || (sscanf(arg, "%s %d", skill,i)!=2 ))
return 1;
me->set_temp(skill,i);
return 1;
}
