// by dubei

#include <ansi.h>
#include <room.h>

inherit ROOM;

string jianzhong(object);

void create()
{
    set("short", BLU "平台"NOR);
    set("long", @LONG
只见许多石块堆著一个大坟。这坟背向山谷，俯仰空阔。大石上剑
冢(jianzhong)两个大字之旁，尚有两行字体较小的石刻：
    剑魔独孤求败既无敌於天下，乃埋剑於斯。
　　呜呼！群雄束手，长剑空利，不亦悲夫！
LONG
    );

    set("item_desc", ([
        "jianzhong" : (: jianzhong :),
    ]));

    set("outdoors", "xiangyang");
        set("no_clean_up", 1);

    setup();
}

string jianzhong(object me)
{
    object where = environment(me);
	if(where->query_temp("temp/ban")<1)
    {
        return  "你心中一动：「独孤前辈身具绝世武功，说不定留下甚麽剑经剑谱之类。」\n";
    }

    return "搬开冢上石块后，露出并列著的三柄长剑，在第一、第二两把剑之\n"+
"间，另有一块长条石片。三柄剑和石片并列於一块大青石之上。\n"+
"石上刻字：\n\n"+
"        弱 凌       误 紫       四 重       渐 草 四\n"+
"        冠 厉       伤 薇       十 剑       进 木 十\n"+
"        前 刚       义 软       岁 无       于 竹 岁\n"+
"        以 猛       不 剑       前 锋       无 石 後\n"+
"        之          祥          恃          剑 均\n"+
"        与 无          三       之 大       胜 可 不\n"+
"        河 坚       乃 十       横 巧       有 为 滞\n"+
"        朔 不       弃 岁       行 不       剑 剑 于\n"+
"        群 摧       之 前       天 工       之    物\n"+
"        雄          深 所       下          境 自\n"+
"        争          谷 用                      此\n"+
"        锋                                     精\n"+
"                                               修\n";

}


void init()
{
        add_action("do_move", "move");
        add_action("do_jump", "jump");
        add_action("do_bihua", "bihua");
}

int do_move(string arg)
{
    object me = this_player(), ob_jian, ob_xtj,where = environment(me);
         if((!arg) || (arg != "stone"))
        return notify_fail("你要搬什么？\n");
    if ( where->query_temp("temp/ban", 1) || me->query("max_neili")<500)
    {
       message_vision("这里什么也没有了，$N深深叹了口气。\n",me);
       return 1;
    }

    where->set_temp("temp/ban", 1);

    message_vision("但见$N双手起落不停，不多时便搬开冢上石块。\n", me);
		if (me->query_temp("marks/fengsett"))
		{
				message_vision("$N仔细一看，大青石上似乎有些图案。\n",me);
				me->delete_temp("marks/fengsett");
				me->set_temp("marks/bihua",1);
			}
    ob_jian = new(__DIR__"obj/wuming-jian");
    if(!clonep(ob_jian)){ 
              return 1;
          }  
    ob_jian->move(where);
    ob_xtj = new(__DIR__"obj/xuantie-jian");
    if(!clonep(ob_xtj)){ 
              return 1;
          } 
    ob_xtj->move(where);
    return 1;
}
int do_jump(string arg)
{
	object me = this_player();

	if (me->is_busy()) return notify_fail("你正忙着呢！\n");
        
        if (arg != "down")
           return notify_fail("你要往哪里跳？\n");
        me->move(__DIR__"qiaobi");
	message_vision("$N纵身跃到了峭壁上。\n", me);
	
	return 1;
}
int do_bihua(string arg)
{
	object me = this_player();

	if (me->is_busy()) return notify_fail("你正忙着呢！\n");
  if (!me->query_temp("marks/bihua")) 
  	return notify_fail("你想干什么\n");     
        if (arg != "qingshi")
           return notify_fail("你乱比划什么？\n");
    if (me->query("fengset")) 
    	return notify_fail("大青石上的内容对你来说已经太肤浅了！\n");
    if (((int)me->query_skill("lonely-sword",1) < 400) || 
    	((int)me->query_skill("dugu-jiujian",1) < 500))
    	{
    		me->receive_damage("qi", 30);
    	 return notify_fail("你独孤九剑不够娴熟，结果累了一身臭汗！\n");
    	}
		if (random(me->query("kar")) > 28 && me->query("kar") >= 30)
			{
				message_vision("$N手捻剑诀，对着青石若有所思。\n", me);
				if(random((int)me->query_skill("literate",1)) > 2000 &&
					(int)me->query_skill("sword",1) > 1500){
						me->add_temp("bihua",1);
						tell_object(me, "你从中领悟了一些独孤九剑的窍门！\n");
					}else{
						tell_object(me, "你费了半天劲，可是什么也没有学到。\n");
				}
}
		if (me->query_temp("bihua")>100)
			me->set("fengset",1); 		
	me->receive_damage("qi", 30);
	return 1;
}
