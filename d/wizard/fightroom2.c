// Room: /city/dangpu.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
        set("short", "武林大会广场");
    set("long", @LONG
这是一个方圆数十丈的大广场，一个用白玉汉石砌成数丈高的擂台耸立在广
场中央，从上面不时传来吆喝声和惨叫声，擂台的四个边角竖着四根十多丈高的
旗杆，分别用金线绣着豪侠晚歌四个大字，广场的正北方用同样的石料砌了一	
个小台。台上竖着一根大旗杆，一张大旗(flag)迎风招展。
LONG
    );
    set("no_new_clean_up", 0);
        set("no_fight",1);
        set("no_magic",1);
    set("item_desc", ([
                "flag": @TEXT
              以武会友！
TEXT
    ]) );
    set("exits", ([ /* sizeof() == 2 */
                "west" : __DIR__"fightroom1",
                "up" : __DIR__"fightroom3",
        ]));
    setup();
}
void init()
{
       object me=this_player();
    add_action("discmds",({"respitate","exert","array","duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","learn","sleep","kill","steal","cast","conjure","expell","fight","hit","perform","prcatice","scribe","surrender"}));
       if (userp(me) && me->query("no_get") )
           call_out("do_recover",15,me);
}
void do_recover(object me)
{
    if( !me || environment(me) != this_object() ) return;
       me->delete("no_get");
me->delete_temp("last_damage_from");
       if (!living(me)) me->revive();
    me->set("eff_jing",me->query("max_jing"));
    me->set("jing",me->query("max_jing"));
    me->set("eff_qi",me->query("max_qi"));
        me->set("qi",me->query("max_qi"));
    if (me->query("neili")<me->query("max_neili"))
        me->set("neili",me->query("max_neili"));
    if (me->query("jingli")<me->query("max_jingli"))
        me->set("jingli",me->query("max_jingli"));
        me->start_busy(0);
    tell_object(me,HIW "广场似乎有一种神秘的力量，你活动了一下经骨，发现并没有受伤！\n"NOR);
}
int discmds()
{
        tell_object(this_player(),"现在你还是专心看比武吧！\n");

     return 1;
}
