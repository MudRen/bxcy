// Room: /u/cass/hg/jiashan.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
ֻ��ӭ��һ�����ֵ���ǰ�棬��ʯ�����������֣�����Ұ�ޣ��ݺṰ
��������̦޺�ɰߣ�������ӳ������΢¶һ����С�����ƺ���ͨ��ʯ����
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yuhuayuan",
  "north" : __DIR__"shidong",
]));

	setup();
	replace_program(ROOM);
}
