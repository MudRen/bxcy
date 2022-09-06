// Room: /d/snow/chatroom.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "大榕树上");
        set("long", @LONG
这棵大榕树真不愧为千年神木，这树上竟可盖上几层棚子，这里是第二层，据
说这里的时间也是冻结的，因此一些觉得下面太吵的人也会跑上来独自一个清静。
这里摆着几张用榕树根做的椅子，中间用几根榕树枝搭在一起，算是一个茶几了。
当你抬头往上看的时候似乎有个影在树梢之间移动，不过也许是风吹动所造成的
错觉。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
        "down": __DIR__"chatroom",
"up"  : __DIR__"tianti",
        "east"  : "/u/fyue/mjroom",
        ]));
        set("no_fight",1);
        set("no_magic",1);
      set("valid_startroom","1");
        set("freeze",1);
        set("objects", ([
        ]));
        setup();
        call_other("/d/board/comm_b", "???");
}
void init()
{
    if (wizardp(this_player())) return;
    add_action("do_jump","tiao");
    add_action("discmds",({"sleep","respitate","exert","array","duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","learn","kill","steal","conjure","fight","hit","perform","prcatice","scribe","surrender"}));
    add_action("do_climb", "climb");
}
int discmds()
{
        tell_object(this_player(),"现在你还是专心聊天吧！\n");
        return 1;
}
int do_climb(string arg)
{
    object me;
    me=this_player();
        if( !arg || arg!="down") return notify_fail("你要往哪个方向爬？\n");

    if (me->query("gender")!="女性")
    message("vision",
        me->name() + "气喘嘘嘘的抓住树干，屁股一扭一扭地往下爬去。\n",
        environment(me), ({me}) );
   else if(me->query("age")<40&&me->query("per")>24)
    message("vision",
        me->name() + "象仙子般继续向下飘去，转瞬即逝。\n",
        environment(me), ({me}) );
   else message("vision",
        me->name() + "战战兢兢的抓住树干往下爬去。\n",    environment(me), ({me}) );
     me->move(__DIR__"chatroom");
     
     if (me->query("gender")!="女性")
        message("vision",
        me->name() + "气喘嘘嘘地从上面爬了下来。\n",
                environment(me), ({me}) );
 else if(me->query("age")<40&&me->query("per")>24)
        message("vision","一阵清香飞来，你定眼一看，"+
        me->name() + "已经婷婷玉立在你眼前。\n",
        environment(me), ({me}) );   
          
   else 
        message("vision", me->name() + "战战兢兢地从上面爬了下来。\n", environment(me), ({me}) );   
        
    
    return 1;
}   
int valid_leave(object me, string dir)
{
//           if (dir=="up"){	
if (dir=="hereup"){	
if (wizardp(me)) return 1;
else    return notify_fail("爬这么高， 小心掉下来摔死!\n");
        }
         if ( dir=="down" && !wizardp(me))
        return notify_fail("这里没法直接走，看来你只能爬(climb)下去！\n");

        else return 1;
}
