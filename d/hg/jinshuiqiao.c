// Room: /u/cass/hg/jinshuiqiao.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��ˮ��");
	set("long", @LONG
һ���ú�����ʯ�����ʯ�ţ�����ͨ���ף��ŵ������ж��ٶ��
��������ͷ����������������Ϊ��Ҷ�գ������м�Ƕ�кܶ����壬����
�ڲ��������������б�ƿ�����Ƶ�ͼ����ÿ�������ϻ�����˺ö�ǧ
�˰�̬�����������ʯʨ��
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"wumen",
  "north" : __DIR__"taihemen",
]));
	set("no_new_clean_up", 0);

	setup();
	replace_program(ROOM);
}
