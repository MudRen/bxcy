
inherit ROOM;
void create()
{
    set("short", "����");
    set("long", @LONG
������һ��С�ݣ�һ��̫��������Ϣ��
LONG
    );
    set("exits", ([
        "north" : __DIR__"zoulang1",
    ]));
    set("objects", ([
        "/d/huanggon/npc/taijian":1,
    ]));
    setup();
    replace_program(ROOM);
}

