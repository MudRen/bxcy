// Room: /u/cass/hg/ningshougong.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "���ٹ�");
	set("long", @LONG
ֻ��ǽ���ϡ������ϣ����ǵ���Ƥ��֮��ı����������Ǹ����˵ľ��ң�
�������ǽ�֦��Ҷ�Ĺ����޹���
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huangjidian",
]));

	setup();
	replace_program(ROOM);
}
