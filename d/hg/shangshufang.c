// Room: /u/cass/hg/shangshufang.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "���鷿");
	set("long", @LONG
��������һ���Ŷ�����ܣ����϶��������飬Ҳ��֪�м�ǧ���򱾡�
���а��ŵ�������̴ľ�������������������Ƕ������̯��һ���飬
���׷��ŵ���̨��ͲҲ����̾��¡����������˽��У���������һ����
��������������һֻ��ͭ�Ŷ�������̴�㣬���ǵ���ͷ���������³�һ
�������̣��Ա߻����˸���ͭ��¯��
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wenyuange",
]));
	set("no_new_clean_up", 0);

	setup();
	replace_program(ROOM);
}
