// Room: /d/quanzhen/mengjin/hulao.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "���ι�");
	set("long", @LONG
���ﱾ�����Թ��������չأ��ؿ�λ��������ɽ֮���Ͽ���У�
���������ʧ�ޣ���ǽ�ѱ�����ò�������͢Ҳ�����ɱ�פ�����
��Χ�İ���ȫ�������ˣ�ֻʣ��һƬ��ש���ߺͷ��̾Ϣ��
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shanlu",
  "east" : __DIR__"guandao4",
]));
	set("outdoors", "mengjin");

	setup();
	replace_program(ROOM);
}
