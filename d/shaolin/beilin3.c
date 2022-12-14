// Room: /d/shaolin/beilin3.c
// Date: YZC 96/01/19
inherit ROOM;
int do_study(string arg);
void create()
{
    set("short", "地下室");
    set("long", @LONG
这里是佛塔底下的地下密室。密室虽小，却也五脏俱全，
石桌(table)石椅，石几石床，连室内放的几件器皿,也都是石
制的。看来似乎很久以前有人在这里住过。正中的石桌上平放
着一块薄薄的石板，上面好象刻着些什么。
LONG
    );
    set("objects",([
        "d/shaolin/obj/book-stone" : 1,
    ]));
    set("item_desc", ([
        "table" : "这是一整块巨石雕成的石桌，上面刻了些奇怪的图形。\n",
    ]));
    setup();
}
void init()
{
    add_action("do_study", "study");
}
int do_study(string arg)
{
    object me;
    int    jing_cost;
    me = this_player();
    if ( !arg || ( arg != "table" ) )
        return 0;
    if ( (int)me->query_skill("literate", 1) < 1){
        write("你是个文盲，先学点文化(literate)吧。\n");
        return 1;
    }
    if ( (int)me->query_int() < 30){
        write("你的悟性不够，先学点文化(literate)吧。\n");
        return 1;
    }
    jing_cost = (-1) * random(20);
/*if((int)me->query("jing") < jing_cost){
        write("你现在过于疲倦，无法专心下来研读新知。\n");
        return 1;
}*/
     me->add("jing", jing_cost);
    me->delete_temp("stone_learned");
    message_vision("$N正专心研读石桌上的古怪图形。\n", me);
    switch( random(7) )
    {
        case 0:
        if ( (int)me->query_skill("parry", 1) < 200)
        {
            me->improve_skill("parry", me->query_int());
            write("你对着石桌琢磨了一回儿，似乎对拆招卸力之技有点心得。\n");
    break;}else {me->set_temp("stone_learned",1);break;
        }
        case 1:
        if ( (int)me->query_skill("unarmed", 1) < 200)
        {
            me->improve_skill("unarmed", me->query_int());
            write("你对着石桌琢磨了一回儿，似乎对拳脚之道有点心得。\n");
        break;} else {me->set_temp("stone_learned",1);break;
        }
        case 2:
        if ( (int)me->query_skill("sword", 1) < 200)
        {
            me->improve_skill("sword", me->query_int());
            write("你对着石桌琢磨了一回儿，似乎对基本剑术有点心得。\n");
    break;} else {me->set_temp("stone_learned",1);break;
        }

        case 3:
        if ( (int)me->query_skill("club", 1) < 200)
        {
            me->improve_skill("club", me->query_int());
            write("你对着石桌琢磨了一回儿，似乎对棍法有点心得。\n");
 break;} else {me->set_temp("stone_learned",1);break;
        }

        case 4:
        if ( (int)me->query_skill("whip", 1) < 200)
        {
            me->improve_skill("whip", me->query_int());
            write("你对着石桌琢磨了一回儿，似乎对鞭法有点心得。\n");
 break;} else {me->set_temp("stone_learned",1);break;
        }
        default :
            write("你对着石桌琢磨了一回儿,陷入了沉思之中!\n");break;
    }
    if ( me->query_temp("stone_learned") )
    {
        write("你对着石桌琢磨了一回儿，发现上面所说的太过浅显，对你来说已毫无意义了。\n");
    }
    return 1;
}
