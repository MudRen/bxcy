// liangongfang.c ������
// by Xiang

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������������ҵط��ż�������,��λɱ��¥��������ϥ������
�������
LONG
	);
	set("exits", ([
                "west" : __DIR__"jiaochang",
	]));
	set("objects", ([
                "/d/village/obj/zhujian" : 2,
            "/d/taohua/npc/jiguan" : 2]));

	
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
