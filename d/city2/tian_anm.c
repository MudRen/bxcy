// Room: /city2/tiananmen.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "�찲��");
	set("long", @LONG
��������찲�Ź㳡����ɫ�ĳ�ǽ������ׯ������֮�У�����
�����ǻʹ��ˡ��ʹ�����ǰ����С�ţ�һ�����Ǻ��ƳǶ�����Խ��
С������ȥ���Ͻ��ǵ������淢�Ե���ΰ�ߴ�һ����ֱ�Ĵ��
��ᶫ���������Ƕ������֣��������������֡��ϱ���һ��������
���������������һ�����ţ���˵���˺ܶࡣ
LONG
	);
set("no_fight", "1"); 
set("no_steal", "1");
set("no_beg", "1");
set("no_sleep_room", "1");
set("no_clean_up", 0);
	set("exits", ([
		"south" : "/d/city2/nandaj1",
		"north" : "/d/city2/bridge",
		"west" : "/d/city2/xichang1",
		"east" : "/d/city2/dongcha1",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
// "/d/npc/kuangfeng" : 1,     
"/quest/fyue":1,
	]));
	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}
