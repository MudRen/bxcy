// Room: /u/wyz/jingzhou/room5.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��ǽ");
	set("long", @LONG
�����ĳ�ǽ�ָ��ֺ񣬸���һ�ְ�ȫ�ĸо���ң�����⣬��ɫ����Ұһ������
һ����СС��ũ�����ǵ��ĵ�׺�ſ�����Ұ������ʱ������������Ϧ��б�գ���
��ʤ�ա�Զ�������Ⱥɽ�������˸е�����׳�ۡ�
LONG
);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room25",
  "north" : __DIR__"room6",
  "down" : __DIR__"room1",
]));
	set("channel_id", "��ǽ");

	setup();
	replace_program(ROOM);
}
