// sroad1.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","山路");
        set("long",@LONG
川西多是崇山峻岭，交通不便。一条山路蜿蜒在山间，连接着
藏边和中原。
LONG );
        set("exits",([
                "north"  : "/d/xueshan/caoyuan",
"northwest"  : "/d/lingxiao/boot",	
                "westup" : __DIR__"sroad2",
        ]));
        set("outdoors", "xueshan");
        set("no_clean_up", 0);
        set("coor/x",-110);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-110);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

