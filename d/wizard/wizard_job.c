// Room: /d/wizard/wizard_room.c
inherit ROOM;
void create()
{
    set("short", "��ʦ������");
    set("long", @LONG
������ǡ���Ѫ����֮������衹��ʦ�Ļ����ң�������	
�߰���ذ��ż��ŵ��ӡ��м����ӵİ�̨��ѹ��һ����ʦ������
����
LONG );
    set("exits", ([ /* sizeof() == 1 */
    "down" : __DIR__"wizard_room" ]));
    set("valid_startroom", 1);
	set("objects", ([
    "/clone/misc/player":1,
	]));
    set("no_fight", "1");
    set("no_clean_up", 0);
    setup();
        call_other("/d/board/wizard_j", "???");
    replace_program(ROOM);
}
