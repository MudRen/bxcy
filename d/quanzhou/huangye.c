// Room: /d/quanzhou/huangye.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "��Ұ");
    set("long", @LONG
������Ȫ�ݽ���Ļ�Ұ�ϣ���ʱ��һ���󺣷�����洵��������ͨ��
�Ϸ���һ��Ȫ�ݣ�������һ��С��塣
LONG
    );
    set("outdoors", "quanzhou");
    set("no_clean_up", 0);
    set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"nanmen",
  "south" : __DIR__"yucun",
]));
    setup();
    replace_program(ROOM);
}
