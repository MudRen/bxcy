// Room: /chengdu/ruin2.c
// oooc: 1998/06/26

inherit ROOM;

void create()
{
        set("short", "ؤ��ֶ�");
	set("long", @LONG
������һ���ƾɴ�լ�������������ǽ�ڸ��ݶ��Ѿ�����̮��
�ˣ����쬵����ӱ��ߵ�ȱ��ֱ��������������������ǣ���
����ɨ���൱���࣬������Ǭ���������������һ������
LONG
	);

	set("exits", ([
                "west": __DIR__"ruin1"
	]));
        set("objects", ([
              __DIR__"npc/chen" : 1,
              __DIR__"npc/obj/jitui" : 1,
              __DIR__"npc/obj/jiudai": 1,
        ]));


	setup();
}
