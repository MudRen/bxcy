inherit ROOM;

void create()
{
	set("short", "��ٵ�");
	set("long", @LONG
����һ��������ֱ�Ĺٵ�����������������û�������ˡ����������ݵ����ţ�
������ֱ������ɽɽ�š�
LONG
);
	set("no_clean_up", 0);
	set("outdoors", "changan");
	set("exits", ([ /* sizeof() == 1 */
           "west" : __DIR__"shijie1",
           "east" : __DIR__"ximen",
]));

	setup();
	replace_program(ROOM);
}
