// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "啸天楼");
	set("long", "这里就是啸天会最机密的地方之一，上楼的木阶上隐隐
约约的，不知道隐藏了多少的机关。平时只有会长，长老和四
个堂主才可以进来。\n");

	set("exits", ([
                "north" : __DIR__"zly",
                   "up" : __DIR__"jing",

	]));
	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        if (dir=="up"){
if ((string)me->query("id")=="wenwu"||(string)me->query("id")=="lisa") return 1;	
  else    return notify_fail("大胆，那里是你去的地方吗？!\n");
}
       else return 1;
}

