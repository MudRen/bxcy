
inherit ROOM;
void create()
{
    set("short", "�ܵ�");
    set("long", @LONG
�����ǰ��һ���ú������̳ɵ�̨�ף�һֱ�������죬���ߵ�ǽ�ڶ�
�ǻ����ң�ǽ�ϸ�ʮ��������һյ�͵ƣ�ʹ���ܿ�����Χ��
LONG
    );
    set("exits", ([
        "southup" : __DIR__"midao1",
        "northdown": __DIR__"midao3",
    ]));
    setup();
        replace_program(ROOM);
}