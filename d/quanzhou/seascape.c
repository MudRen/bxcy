  // Room: /d/player/seascape.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
����ĺ��磬�ḧ��������ӣ��������������ġ�������Թ��Ѫ�ȳ�ɱ
ͨͨ�����Ժ󡣱̺���ɳ���������������𺣱ߵĶ���С�ݣ�һ����ҵĸо�
��Ȼ����·�ߵ���ʯ�Ͽ��š������´�һ·����
LONG
);
        set("shout", "�������");
        set("exits", ([ /* sizeof() == 1 */
//  "west" : "/d/quanzhou/yucun1",
]));

        setup();
        replace_program(ROOM);
}

