// Room: /u/cass/hg/quqiao.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������ʯ���ɣ������ð������ˣ��Ŷ��Ƿ���������ߣ����Ƴ�ͤ��
�ɱܷ��ꡣʯ�ŵĹ����ر��������֮���ν����ˣ��Ե�ʮ�����㡣�岨��
�գ��ſ�Բ����£��븡ˮ�ϣ����ˮ�£������Ӱ������ˮ�У�εΪ׳�ۡ�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"longtan",
  "north" : __DIR__"yanyuhu",
]));

	setup();
	replace_program(ROOM);
}
