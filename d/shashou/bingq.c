
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ɱ��¥�ı����ң����ܷ��⼸�������ܣ�
������ɱ��¥������ƽʱ�����õ��񽣡�
LONG
	);
	set("exits", ([
		"west" : __DIR__"jiaoch",
	]));
	set("objects", ([
                "/d/village/obj/zhujian" : 2,
            "/d/taohua/npc/jiguan" : 2]));

//           set("no_fight", 1);
	
	setup();
	replace_program(ROOM);
}
// bingqi.c ������
