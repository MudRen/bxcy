// #include <room.h>

inherit ROOM;

void create()
{
        set("short", "�Խ���");
        set("long", @LONG
����������֮�����������һ����ɱ֮��ʹ�����һ����������
���󲢲����Ž��֣��ƺ����ڴ�ʲô��һ�Եļ����ϰ��ż�����ϰ��
���񽣡���������һ���Ҷ�(sign)��
LONG
        );
        set("no_die", 1);
     set("no_fight_npc",1);
        set("no_get", 1);
        set("exits", ([
                 "south": __DIR__"wumiao",
"up": __DIR__"mingren",	
]));
set("objects", ([	
"/clone/misc/milestone" : 1,	
"/clone/misc/swordjia" : 1,                        	
]));	
set("item_desc", ([
                "sign": @TEXT
   ��̨�۽�
���¹���
TEXT
        ]) );

/*
set("objects", ([
                __DIR__"bamboo_s":4,   //��4����

        ]) );
*/


        setup();
        replace_program(ROOM);
}
