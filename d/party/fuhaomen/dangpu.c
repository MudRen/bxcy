// Room: /city/dangpu.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
	����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������ǰ����̨
�ϰ���һ������(paizi)����̨���������ϰ壬һ˫�������۾��������´������㡣
LONG
	);
	set("no_beg",1);
	set("item_desc", ([
		"paizi": @TEXT
    �����̲����ۺ�ͯ�����ۣ���ӭ�ݹˣ����Ա��ܡ����Ŀ���������
����(list)������(buy)����ѯ�ѵ䵱����(check)������(value)���䵱(pawn)�����(redeem)������(sell)���ֻ��	
TEXT
	]) );
	set("objects", ([
"/d/city/npc/tang" : 1,	
	]));
	set("exits", ([
		"west" : __DIR__"nandajie1",
	]));
	setup();
	replace_program(ROOM);
}
