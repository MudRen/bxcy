// work.c modified by snow

inherit ROOM;

int cot;
void create()
{
        set("short", "谷物加工厂");
        set("long", @LONG
这是一间谷物加工厂，这里是谷子脱壳成米的地方。米厂老板是一
个一看就知道是十分精明的干瘦的中年人，老是带着一脸奸笑。你可以
看到许多人正在忙忙碌碌的工作着，门口挂著一块牌子(sign)。
LONG
        );
        set("no_sleep_room",1);
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dongmen",
]));
        set("item_desc", ([
                "sign": @TEXT
现在正紧缺人手，急需雇佣一批短工来干活。
work     开始工作。
TEXT
        ]) );
    set("no_magic", 1);
        setup();
}
void init()
{
        add_action("do_work", "work");
        if (!wizardp(this_user()))
        add_action("discmds",({"duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","learn","sleep","kill","steal","cast","conjure","expell","fight","hit","perform","prcatice","scribe","surrender"}));
}
 int discmds()
{
    tell_object(this_player(),"还是老老实实工作吧？！\n");
    return 1;
}
int do_work(string arg)
{
        int time;
        object me;
        me = this_player();
        time = 300/(int)me->query("str");
        if (time <15) time = 15;
        if ((int)me->query("jing")<random(30) || (int)me->query("qi")<random(30))
        {
        	message_vision("$N开始辛苦地工作......\n", me);
        	write("你突然感到头晕眼花。。。。。。\n");
        	tell_room(environment(me), RED+me->name() +"脸色看起来不大对头，斗大的汗珠从脸上滑了下来。\n哎,又是一个要钱不要命的..!\n"NOR, ({me}));
                me->unconcious();
                return 1;
         }
        if ((int)me->query("jing")<30 || (int)me->query("qi")<30) return notify_fail("你快累死了，要钱不要命了吗？\n");
        if (me->query_temp("working")) return notify_fail("加油呀！谁叫你穷呀！\n");
         if ((cot>2)||me->query("combat_exp")>3000000) {
        	write("老板嘿嘿一笑：我这里人手已经够了，做义工可没工钱的哟！\n");
        	me->start_busy(5);
        	return 1;
        	}
        message_vision("$N开始辛苦地工作......\n", me);
       cot++;
        me->set_temp("working",1);
        me->add_temp("work_times",1);
        call_out("working",10+random(time),me);
        return 1;
}
int working(object me)
{
        object ob;
        if (!me)        return 1;
        
        me->add("jing",-30);
        me->add("qi",-30);
        if((string)environment(me)->query("short")!="谷物加工厂"||me->query_temp("work_out"))
        {
        write("你工作的时候开小差，结果累了半天什么都没得到!\n");
        me->set_temp("working",0);
        me->delete_temp("work_out");
        cot--;
        return 1;
}
        if(random((int)me->query_temp("work_times"))>60+random(100))
        {
        	if((int)me->query("kar")>20)
      message("vision",HIY"〖谷物加工厂〗"NOR+":"+YEL" 由于"HIW+me->name()+NOR YEL"工作勤劳，获得了老板的嘉奖!\n"NOR,users());
        	else message_vision("老板对$N说：嗯，做的不错，这是给你的奖励！\n",me);
        	ob = new("/clone/money/gold");
        	
               ob->set_amount(1);
               ob->move(me);
               me->add("potential",30);
               me->delete_temp("work_times");
               me->set_temp("working",0);
                cot--;
               return 1;
        }
        message_vision("$N辛苦的工作终于结束了，可人也累的半死。\n", me);
        ob = new("/clone/money/silver");
          ob->set_amount(10+random(20));
            me->add("combat_exp",random(10));
             me->add("potential",random(10));
        ob->move(me);
        message_vision("老板冷冷地对$N说：这是你的工钱。\n", me);
        me->set_temp("working",0);
       cot--;
        return 1;
}
int valid_leave(object me, string dir)
{
       if(dir=="north")
       me->set_temp("work_out",1);
        
        return ::valid_leave(me, dir);
}
void reset()
{
        cot=0;
        ::reset();
}

