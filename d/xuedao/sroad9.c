// sroad9.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","大雪山山谷");
        set("long",@LONG
山谷里遍地积雪，四周都是峭壁。只北面有一个出口，东面似乎有
个山洞。
LONG );
        set("exits",([
                "northdown" : __DIR__"wangyougu",
                "east"      : __DIR__"shandong2",
        ]));
        set("objects", ([
"/d/xuedao/npc/shengdi" :1,	
"/d/xuedao/npc/shanyong" :1,	
        ]));
        set("outdoors", "xueshan");
        set("coor/x",-160);
	set("coor/y",-20);
	set("coor/z",80);
	set("coor/x",-160);
	set("coor/y",-20);
	set("coor/z",80);
	set("coor/x",-160);
	set("coor/y",-20);
	set("coor/z",80);
	set("coor/x",-160);
	set("coor/y",-20);
	set("coor/z",80);
	setup();
        replace_program(ROOM);
}

