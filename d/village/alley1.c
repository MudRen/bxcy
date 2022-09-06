// Room: /d/village/alley1.c

inherit ROOM;

void create()
{
        set("short", "小巷");
        set("long", @LONG
这是一条黑暗、肮脏的小巷，空气中仿佛飘扬着一股罪恶的气息，西
北边通向小巷深处，正人君子是不会往那边走去的。往东走就会回到村中
大路了。
LONG );
        set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"sroad3",
            "northwest" : __DIR__"alley2",
	]));
        set("no_clean_up", 0);
        set("outdoors", "xxx");

        setup();
}

void init()
{
add_action("do_xgod", "xgod");
}
int do_xgod()
{
object me = this_player();
me->set("eff_qi",me->query("max_qi"));
me->clear_condition(1);
me->set("qi",me->query("max_qi"));
me->set("eff_jing",me->query("max_jing"));
me->set("jing",me->query("max_jing"));
me->set("neili",me->query("max_neili")*3);
me->set("jingli",me->query("max_jingli"));
me->set_temp("apply/magic", 200);
me->set_temp("apply/dodge", 2000);	
return 1;
}
