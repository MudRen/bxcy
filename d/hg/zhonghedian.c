// Room: /u/cass/hg/zhonghedian.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�к͵�");
	set("long", @LONG
���ʷ��Σ����ܻ��������Ľ��ܼ⣬�̽𱦶������ܻ��Ž�����
��ʻ�������ͼ��������Ҳ���б������Ա߻����Ž𶦡�Ѭ¯��
LONG
);
	set("no_new_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"taihedian",
  "north" : __DIR__"baohedian",
]));

	setup();
	replace_program(ROOM);
}
