// Room: /u/cass/hg/shidong.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����ʯ����ֻ����ľ�״У��滨���ƣ�һ����䣬�ӻ�ľ�����к��
ʯ϶֮�¡����е�����������ƽ̹������߷�����գ����������������
ɽ������֮�䣬������֮������Ϫкѩ��ʯ�㴩�ƣ���ʯΪ�����������ء�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jiashan",
  "southeast" : __DIR__"pubu",
]));

	setup();
	replace_program(ROOM);
}
