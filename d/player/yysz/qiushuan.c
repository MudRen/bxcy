

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long",@LONG
��ᣵʹ����豸���أ��ٴ������϶������ᣬһ��Ͱë����ʾ����
��ѧʶԨ����һֻ���λ�ƿ���ż����绨�������������µ���Ϣ��
LONG );
        set("exits", ([
"east" : __DIR__"canheje",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

