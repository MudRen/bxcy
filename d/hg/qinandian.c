// Room: /u/cass/hg/qinandian.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�հ���");
	set("long", @LONG
��������ȫ��������Ļƻ���ľ��ֱ�����۲ʻ�������64��������Ϊ��
���帡���̽���������ǽĥש�������ڱڵ�ש�����м����帣���ٵȵ�ש
ͼ�������������ʡ��微��ש��λȫ���ó����Ҷ����ӳ�յý�̻Իͣ���
�ʶ�Ŀ�������������������ۣ���໹����������һ�ڡ���ǰ����������
�Ǵ��氮���������
LONG
);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"wanchunting",
  "southwest" : __DIR__"qianqiuting",
  "north" : __DIR__"shenwumen",
]));

	setup();
	replace_program(ROOM);
}
