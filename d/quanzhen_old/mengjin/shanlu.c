// Room: /d/quanzhen/mengjin/shanlu.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��;ȷ��ʤ������ʴ���������֮�ʣ��������١�Ұ�����ޡ�
��ɫ������������۪ɽ����ɽ�ȴ�ɽ����Զ�����ǻ�ɽ�����ƿ�ʼ��
����ƽ��
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hulao",
  "south" : __DIR__"qiandao",
]));
	set("outdoors", "mengjin");

	setup();
	replace_program(ROOM);
}
