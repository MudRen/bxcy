// Room: /u/aplio/ltsh/jyt.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��Ӣ��");
	set("long", @LONG
һ��ȥ������ӳ���������Ǻ���һ�����������ң�
���������������������ƣ�����񺿡�
�����������������Ƹ��꣬Ψ�Ҷ���
�Ա߱��ǻ���ľ���Σ������к�Ⱥ�ۻ���ڻ㱨��С�������Ϣ�ط���
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"tst",
  "out" : __DIR__"shiwai",
]));

	setup();
	replace_program(ROOM);
}
