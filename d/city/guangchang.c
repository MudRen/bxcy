// Room: /city/guangchang.c
// YZC 1995/12/04 
inherit ROOM;

string look_notice();

void create()
{
    set("short", "中央广场");
    set("long", @LONG
    这里是城市的正中心，一个很宽阔的广场，铺着青石地面。一些游手好闲
的人在这里溜溜达达，经常有艺人在这里表演。中央有一棵大榕树，盘根错节，据
传已有千年的树龄，是这座城市的历史见证。树干底部有一个很大的洞(shudong)。
你可以看到北边有来自各地的行人来来往往，南面人声鼎沸，一派繁华景象，东边
不时地传来朗朗的读书声，西边则见不到几个行人，一片肃静。大树上挂一块大牌
（NOTICE）。
LONG
    );
        set("no_sleep_room",1);
        set("outdoors", "city");
    set("item_desc", ([
        "shudong" : "这是一个黑不溜湫的大洞，里面不知道有些什么古怪。\n",
        "榕树"  :   "一棵枝叶茂盛的大榕树，看来似乎可以爬(climb)上去。\n",
        "大榕树":   "一棵枝叶茂盛的大榕树，看来似乎可以爬(climb)上去。\n",
        "树"    :   "一棵枝叶茂盛的大榕树，看来似乎可以爬(climb)上去。\n",
        "tree"  :   "一棵枝叶茂盛的大榕树，看来似乎可以爬(climb)上去。\n",

                "notice" : (: look_notice :),

    ]));
    set("exits", ([
        "east" : __DIR__"dongdajie1",
        "south" : __DIR__"nandajie1",
        "west" : __DIR__"xidajie1",
        "north" : __DIR__"beidajie1",
"northwest" : __DIR__"mianju_r",	
"down" : __DIR__"drop",  	
    ]));
    set("objects", ([
        __DIR__"npc/liumang" : 2,
        __DIR__"npc/liumangtou" : 1,
//      __DIR__"obj/table" : 1,后卫2003-7-13修改，换到武庙去
"d/city/npc/scavenger":2,
        "/clone/npc/halfgod":1,
        "/d/npc/xunbu":1,
    ]));
    setup();
}
void do_rumor(object me)
{
    if (!me)    return;
   if (!userp(me)) return;
//   CHANNEL_D->do_channel(this_object(),"rumor",me->name()+"在街上裸奔呀！");
else return;
}
void init()
{
    object me;
    me=this_player();
    if (!me->query_temp("armor/cloth") && me->query("race")=="人类" ){
            if (time()-me->query_temp("rumor/nocloth")>10){
                me->set_temp("rumor/nocloth",time());
                call_out("do_rumor",random(5),me);
            }
        }
    if(me->is_ghost()){		
		write(BLU"突然间阴风阵阵，你耳边响起一阵空洞而又阴森的声音:‘回来哟，回来哟!’\n"NOR);
		write(HIW"一阵白雾将你裹了起来，你又回到了鬼门关\n"NOR);
	
		me->move("/d/death/gate");
		      }    
        
        add_action("do_enter", "enter");
        add_action("do_climb", "climb");
}
int do_enter(string arg)
{
    object me;
    me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="shudong" ) 
    {
        message("vision",
            me->name() + "一弯腰往洞里走了进去。\n",
            environment(me), ({me}) );
                me->move("/d/gaibang/inhole");
                message("vision",
            me->name() + "从洞里走了进来。\n",
                    environment(me), ({me}) );
        return 1;
    }
}   
int do_climb(string arg)
{
    object me;
    mixed *local;
    local=localtime(time());
    me=this_player();
        if(local[6]==6&&!environment(me)->query("ok"))
    return notify_fail("树干上布满了青苔,看样子是没法爬上的!\n");
        if( !arg || arg!="up") return notify_fail("你要往哪个方向爬？\n");
    if(me->query_condition("killer"))
    {
       message("vision",
        me->name() + "战战兢兢地拉着大榕树的盘根，屁股一扭一扭地往上爬，突然一声惨叫，又掉了下来。\n",
        environment(me), ({me}) );
        write("你战战兢兢地拉着大榕树的盘根往上爬，一不小心摔了个狗吃屎。\n");
        return 1;
     }
    if (me->query("gender")!="女性")
    message("vision",
        me->name() + "战战兢兢地拉着大榕树的盘根，屁股一扭一扭地往上爬。\n",
        environment(me), ({me}) );
    else if(me->query("age")<40&&me->query("per")>24)
    message("vision",
        me->name() + "轻轻一跳，衣裙飘飘，象仙子般飞上大榕树。\n",
        environment(me), ({me}) );
    else message("vision",
        me->name() + "战战兢兢的抓住树干往上爬去。\n", environment(me), ({me}) );
                me->move(__DIR__"chatroom");
    if (me->query("gender")!="女性")
        message("vision",
        me->name() + "气喘嘘嘘地爬了上来。\n",
                environment(me), ({me}) );
    else if(me->query("age")<40&&me->query("per")>24)
    message("vision","一阵清香飞来，你定眼一看，"+
        me->name() + "已经婷婷玉立在你眼前。\n",
        environment(me), ({me}) );
    else  message("vision", me->name() + "战战兢兢地从下面爬了上来。\n", environment(me), ({me}) );   
    return 1;
}   
string look_notice()
{
        object who;
        string *name_list, file;
        int i, j=0, k;
        who=this_player();
        file=read_file("/log/lunjian");
        if(!file)
                return "目前没有任何比武记录。\n";
        name_list = explode(file,"\n");
        for(i=0;i<sizeof(name_list);i++) {
                if(name_list[i] == "seperator" ) {
                        j++;
                        k=0;
                        printf("\n第"+chinese_number(j)+"届华山论剑结果：\n");
                        continue;
                }
                k++;
                printf(GRN "第"+chinese_number(k)+"名：%-50s\n" NOR, name_list[i]);
        }
        return "\n";
}

