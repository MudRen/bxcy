// Room: /d/player/garden.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
        set("short", "��ϼ��·");
	set("long", @LONG
��������ϼ����Ҵ���ڣ���ڵ��ұ�����һ���ð������ɵ�ʯ��
(stela)�����һ��С���ӣ����ӵ�������ż������֡���ϼ��Ҵ��ΰ�
ͤ����
LONG
);

    set("item_desc", ([
        "stela" : "�������˰һ�����ƽ���ִ�����߲������ڡ�\n",


    ]));

	setup();
	replace_program(ROOM);
}
