// Room: /u/cass/hg/wenyuange.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��Ԩ��");
	set("long", @LONG
�����ܻ��Ի��ȣ�24�����������������ı�Ϊ�񻨴�������Ϊ������
���ڵ�ͼ��ݣ���������Ҳ�ǻ��ӡ������������顢�徭֮����
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shangshufang",
  "west" : __DIR__"taihedian",
]));

	setup();
	replace_program(ROOM);
}
