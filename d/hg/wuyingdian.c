// Room: /u/cass/hg/wuyingdian.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��Ӣ��");
	set("long", @LONG
�������ʡ����������ܵ����ϣ������ŷ��졢�ɻ���ĵ���Ȳʻ���ʮ
������Щ�ʻ治���ʷ�ϸ�壬����������������������Ϊʯ�죬�����ܵ�
��ĵ����������ͼ����
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"taihemen",
]));

	setup();
	replace_program(ROOM);
}
