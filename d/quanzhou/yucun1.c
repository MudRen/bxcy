// Room: /d/quanzhou/yucun.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "С���");
    set("long", @LONG
һ����ľ����ǳ�����㼸ʮ��Զ�ĺ�̲�ϣ���ˮ������Ĵ��ź�����
��ֻ��Ÿ����������Χ���㼫ĿԶ����������ȴ������һ���洬��
LONG
    );
    set("no_clean_up", 0);
    set("exits", ([ /* sizeof() == 1 */
    "west":"/d/quanzhou/yucun.c",
    "east":"/d/player/sgsy_room.c",
 ]));
    set("outdoors", "quanzhou");
    setup();
    replace_program(ROOM);
}

