// Room: /d/huashan/xiaodian.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "ɽ��С��");
    set("long", @LONG
�����ǻ�ɽɽ����һ��С�꣬��Щ�򵥵���ʳ��ר��׬��Щ�ο͵�Ǯ��
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
