// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "�᳤����");
	set("long", "�����ǻ᳤�����ң������������һ�ֺ���ܰ�ĸо���ʹ
�˸���˯�⡣\n");
        set("no_fight",1);
        set("no_steal",1);
        set("sleep_room",1);

	set("exits", ([
                "east" : __DIR__"hks",
                "west" : __DIR__"szl",
	]));
	setup();
	replace_program(ROOM);
}

