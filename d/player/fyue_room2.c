inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
�����ǰ������һ�������Ļ�԰����԰������һЩ�滨����������Լ��
��һЩ��Ů������ˣ����԰������һ����ɽ����ɽ����һ��������ˮ�ء�
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"fyue_room",
]));

	setup();
	replace_program(ROOM);
}
