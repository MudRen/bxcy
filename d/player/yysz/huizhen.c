
inherit ROOM;

void create()
{
        set("short", "����԰");
        set("long",@LONG
��������ɽװ�����Ļ�԰����ֲ���ϵ��滨��ݣ�����Ũ����һȺ
�۷��ڻ������ѷ��裬�㲻�ɵĳ��ˣ��е��ֶ�������
LONG );
         set("outdoors", "yysz");
        set("exits", ([
            "west"  : __DIR__"changlang",
        ]));
        set("objects",([
// __DIR__"npc/mifeng" : 3,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

