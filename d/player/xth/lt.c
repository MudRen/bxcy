// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "冷月堂大堂");
	set("long", "这儿是啸天会冷月堂大堂，一进来就会看到墙上墙上一弯
新月，手持兵器的武士威风凛凛的站在两旁。冷月堂堂主就在
这儿接待天下英雄豪杰，从大堂四周还不时听到帮中弟子在练
武时发出的呐喊声。从这儿往南北两边是帮中弟子的练功房。\n");

	set("exits", ([
                "north" : __DIR__"lgt1",
		"south" : __DIR__"lgt2",
                "west" : __DIR__"lt1",
                "northeast" : __DIR__"sclk1",

	]));
	setup();
	replace_program(ROOM);
}

