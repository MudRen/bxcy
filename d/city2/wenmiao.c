
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
����������������п׷����������ʵ۶������������˼��������
�Լ��Ľ�ɽ��𢣬�����ʵ���ȻҲ�����⡣���ۺ��˵��ˣ����Ϲ��Ͼ�����
����ݡ�
LONG
	);
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("objects", ([
		"/d/city/obj/box" : 1,
		"/d/taishan/npc/shu-sheng" : 1,
"/d/city2/npc/lwshizhe" : 1,       	
	]));
	set("exits", ([
		"west" : __DIR__"xisi",
	]));
	setup();
	replace_program(ROOM);
}
