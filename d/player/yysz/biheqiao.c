
inherit ROOM;

void create()
{
        set("short", "�ն���");
        set("long",@LONG
�����͵�ˮ���ϣ�һ���������۵�С��ͨ��ˮ�е�һƬС�ޣ�
���ϻ������̣��ƺ����ж��졣
LONG );
        set("outdoors", "yusz");
        set("exits", ([
            "west" : __DIR__"huayuan",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

