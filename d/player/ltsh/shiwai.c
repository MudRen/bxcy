// Room: /u/aplio/ltsh/shiwai.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
�����ٲ���ֱк��ǧ����ɽ���������֪����һ������С·��ɽ���ơ�
��˵����ͨ�ˣ������������Ṧ����Ҳ������η����ϡ����һ�����ư����
��������������ŷ�ɥ���������ĺ���̳���ڡ�
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "enter" : __DIR__"jyt",
]));
	set("outdoors", "����ɽӰ");

	setup();
	replace_program(ROOM);
}
