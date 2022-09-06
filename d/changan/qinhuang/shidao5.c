// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "石道");
    set("long", @LONG
这是一条阴森的道路，四周是一个个的俑坑，还有无数的骸骨，
看来秦始皇建好这座陵墓后，把全部的施工者都杀死在这里了，脚下
到处是森森白骨,想来都是些人物遗骨.你只觉得有点毛骨悚然。  
LONG
);
        set("exits", ([
           "south":__DIR__"shidao4",
           "north":__DIR__"outroom",
           "west":__DIR__"clubroom",
           "east":__DIR__"axeroom",
]));
        set("objects", ([
             __DIR__"obj/skeleton" : 1+random(10),
]));
    setup();
}
void init()
{
add_action("do_search","search");
add_action("do_train","rain");
}
int do_search(string arg)
{
object me=this_player();
object ob; 
if( (!arg) ||!((arg == "bone") || (arg == "遗骨")))
return notify_fail("你要搜索什么？\n");
if( !(ob = me->query_temp("weapon")) || ( (string)ob->query("skill_type")!="staff" && (string)ob->query("skill_type")!="blade" && (string)ob->query("skill_type")!="sword" ) )
return notify_fail("没有工具怎么干活？\n");
message_vision(HIR "\n$N轻轻拨动脚下白骨。\n\n" NOR, me);	
if(query("not_jianpu")) {
message("vission", HIR "只听呼啦一声，从里面窜出来几只大老鼠。\n"NOR, me);	
return 1;
}
ob=new("/clone/book/wuming.c");
ob->move(me);	
me->set("qinhuang",1);
message_vision(HIR "只听“哗啦..”一声，从里面掉出一本"HIM+"紫绢秘籍"+NOR"。\n\n\n"NOR, me);    	
set("not_jianpu", 1);
//call_out("regenerate", 86400);
return 1;
}
int regenerate()
{
set("not_jianpu", 0);
return 1;
}
