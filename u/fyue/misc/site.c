
inherit ITEM;

mapping places=([
"bt":"/d/baituo/dating.c",
"tam":"/d/city2/tian_anm.c",
"gc":"/d/city/guangchang.c",
"lj":"/d/lingjiu/damen.c",
"sl":"/d/shaolin/guangchang1.c",
"wd":"/d/wudang/sanqingdian.c",
"xy":"/d/xiaoyao/qingcaop.c",
"xx":"/d/xingxiu/xxh2.c",
"hs":"/d/huashan/square.c",
"xs":"/d/xueshan/dadian.c",
"kl":"/d/gaochang/room63.c",
"ny":"/d/nanyang/nanyang.c",
"qz":"/d/quanzhou/zhongxin.c",
"cd":"/d/city3/guangchang.c",
"ca":"/d/changan/ca.c",
"dl":"/d/dali/guangchang.c",
]);

void create()
{
       set_name("魔法传送帖", ({ "trans site","site"}) );
    set_weight(500);
    if (clonep())
        set_default_object(__FILE__);
    else {
            set("long",
        "\n这是一张魔法传送帖，以它的法力可以到达(trans)的地方：\n\n"
        "   gc : 扬州广场     tam : 天安门     bt : 白驼山\n"
        "   lj : 灵鹫宫       sl  : 少林寺     wd : 武当山\n"
        "   xy : 逍遥派       xx  : 星宿海     xs : 雪山寺\n"
        "   hs : 华山         ny  : 南阳       qz : 泉州\n"
        "   kl : 昆仑         cd  : 成都       dl : 大理   ca  : 长安\n\n"

"set msg_min <anything>        设定当使用魔法传送帖到达某处时, 别人所看到的讯息。\n"
"set msg_mout <anything>       设定当使用魔法传送帖离开时, 原来房间里的人所看到的讯息。\n\n"

        );
            set("unit", "张");
    }
    setup();
}
void init()
{
    if ( !this_player()->is_ghost() )
    add_action("do_trans","trans");
}
int do_trans(string arg)
{
        object me,room,ob,*obj;
    string msg;
        int i;
    me=this_player();

    if( ! environment()->is_character() ) return 0;
    if (me->query("age")>17)     return notify_fail("这奶嘴只适合小孩子使用。\n");
    if( !arg ) return notify_fail("你要去哪里？\n");
    if (me->is_fighting())
         return notify_fail("战斗中无法使用魔法传送！\n");
    if  (!environment(me)->query("outdoors"))
         return notify_fail("在房间里面无法使用魔法传送！\n");
    if (!stringp(places[arg]))  return notify_fail("你要去哪里？\n");
    if (present("biao yin",me)) return notify_fail("你身上带着镖银，无法使用魔法传送！\n");

     obj=deep_inventory(me);
     for (i=0;i<sizeof(obj);i++)
           if (obj[i]->id("illicit salt"))
         return notify_fail("你身上带着私盐，无法使用魔法传送！\n");

    ob=first_inventory(me);
    while(ob){
        if (ob->is_character() && !ob->is_corpse() )
            return notify_fail(ob->name()+"不能和你一起穿越时空之门！\n");
        ob=next_inventory(ob);
    }
    if( stringp(msg = me->query("env/msg_mout")) )
       {if (msg!="") message_vision(msg+"\n", me);}
    else
        message_vision("只见一阵烟雾过後，$N的身影已经不见了。\n", me);
    if (!room=find_object(places[arg]) )
        room=load_object(places[arg]);
    me->move(room);
    if( stringp(msg = me->query("env/msg_min")) )
       {if (msg!="") message_vision(msg+"\n", me);}
    else
        message_vision("$N的身影突然出现在一阵烟雾之中。\n", me);
    me->receive_damage("jing", 10);
    return 1;
}
void owner_is_killed() { destruct(this_object()); }
