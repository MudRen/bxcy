
inherit ROOM;

void create()
{
        set("short", "������");
        set("long",@LONG
һ������ĵ񻨴��ţ�һ����Ŀ�����ӹ������ϣ����Ժ�ɫС׭д
�� "���һ�����δ�������" �������֣�����һ��ׯ������ĸо���
�������������������Ϣ�ĵط�����������Ľ�ݼ����÷����Ŵ����
LONG );
        set("exits", ([
"west"  : __DIR__"qinfeng1",
            "east"  : __DIR__"dannuo",
            "north" : __DIR__"longfeng",
//   "south" : __DIR__"canheju",

        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

