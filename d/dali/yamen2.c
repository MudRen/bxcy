// Room: /d/dali/yamen2.c

inherit ROOM;

void create()
{
	set("short", "衙门正厅");
	set("long", @LONG
堂上东西有两根楹住，挂着一幅对联，但是你无心细看。正墙上悬挂一个横匾，
上书“[1;33m正大光明[2;37;0m”四个金光闪闪的大字。知府正坐在文案后批阅文书，师爷随侍在后。
凡大理官员都可以来这里缉拿（ｊｉｎａ）想要的疑犯。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yamen",
]));

                 set("objects", ([
                __DIR__"npc/cheng" : 1,
                __DIR__"npc/shiye" : 1,
        ]));

         
	setup();
}

void init()
{
	add_action("do_jina","jina");
}

void gethim(object target,object me)
{
	if(!target || !me ) return;

	if(environment(me) == this_object()){
        message("vision","几个官兵冲了进来，二话不说，架起"+target->name()+"，匆匆忙忙往外离去。\n",environment(target));
        target->move(this_object());
        message_vision("$N被官兵押了进来。\n$n大喝一声，"+target->name(1)+"，你这杀人犯，纳命来！\n",target,me);
        me->kill_ob(target);
        target->kill_ob(me);
	}
}

int do_jina(string arg)
{
	object me, target;
	
	if(!arg)
	    return notify_fail("你要下令缉拿谁？\n");

	me = this_player();

	if((string) me->query("class") != "officer" )
	    return notify_fail("你不是大理官员，不可缉拿疑犯！\n");
if( me->query("combat_exp",1) <=100000000 )
return notify_fail("只有大理国御令贴身侍卫以上官级才可以缉拿疑犯！\n");	
	if((int) me->query("jing") < 100 )
	    return notify_fail("你的心神不够！\n");	
	me->add("jing",-100);
	if(!objectp(target = find_living(arg)))
	    return notify_fail("找不到你想要的疑犯！\n");
        if(!environment(target) || wizardp(target))
	    return notify_fail("找不到你想要的疑犯！\n");
if(target->is_ghost())
return notify_fail("找不到你想要的疑犯！\n");   	
	if (!(int)target->query_condition("killer"))
	    return notify_fail(target->name(1)+"好象并没有作奸犯科，你无权缉拿"+gender_pronoun(target->query("gender"))+"。\n");
        message_vision("$N大声令下：来人那．．把"+target->name(1)+"给我拿来！！\n",me);
	call_out("gethim",5,target,me);
	return 1;
}
int valid_leave(object me, string dir)
{
	if(me->is_fighting() && dir=="east")
	return notify_fail("你现在不可离开！\n");
	return 1;
}
