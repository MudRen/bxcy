//room: /u/chen/shashou/postport.c
inherit ROOM;

void init();

void create()
{
	set("short","皇家驿站");
	set("long", @LONG
这里是皇家驿站，专门负责处理全国各地来往的信件，一个年轻的信差站在
一堆信中，一副焦头烂额的样子。
LONG
	   );
	set("exits",([
           "south" : "/d/shaolin/xingbudatang",
	   ]));
	set("objects",([
//                         "/u/quest1/npc.c":1,
		]));

	set("no_fight", 1);
	set("no_yun", 1);
	set("no_steal", 1);
	setup();
}

