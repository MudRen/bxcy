// Room: /d/gaibang/undertree.c
// Date: Haa 96/03/22

inherit ROOM;

void create()
{
       set("short", "裂缝下");
	set("long", @LONG
走进这里，你发现这里居然别有洞天。
LONG
	);

	set("exits", ([
                "south":__DIR__"/d/tianlongsi/dadao1",
	]));

	setup();
	replace_program(ROOM);
}
