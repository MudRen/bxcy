// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "白云涧");
	set("long", "这是一段极窄极险的山崖，天机山最高峰，遥遥望去可以
隐隐约约的看到泰山的山峰，下面渊深无底 。如 不小心一失
足掉下去，只怕连骨头都找不到。这里就是啸天长老白云的住
处，四周云雾缭绕，寒风飕飕有几个石有几只孤鹰飞来飞去。
桌、石椅放在中间 ，石桌上放了盘棋(qi)好象还没下完，主
人就匆匆忙忙的走了。\n");
        set("no_fight",1);
        set("no_steal",1);

	set("exits", ([
                "west" : __DIR__"zly",
	]));
	setup();
	replace_program(ROOM);
}

