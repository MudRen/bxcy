// Room: /u/aplio/ltsh/taizi.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "̫������");
	set("long", @LONG
�ഫ̫����������������ʱ���ѣ��������񲻱䡣
����̫���쳣��������������λ�����صؽ������ᣬ
����̫������Ū���¡�����һ˫¹���ϼ���һ�ѵ���̫��
���𽭺����Ϲ�������������¡�������ǽ��һ��������
       ������ɣԶ�����Ķ�������
       ������Ե������ȥ�����С�
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lxg",
]));

	setup();
	replace_program(ROOM);
}
