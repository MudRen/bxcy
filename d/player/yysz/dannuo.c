
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long",@LONG
����һ�����µĴ��������ϰ��ż�����̴ľ�������������Ʋ;�һ
Ӧ��ȫ������һ���绨ľ�Ρ�ÿ������ɽׯ�ܶ��˶��ڴ��ò͡���
Ѫ������������������أ����ǿ��߰ɡ�
LONG );
        set("exits", ([
            "west" : __DIR__"yimen",
            "east" : __DIR__"huayuan",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

