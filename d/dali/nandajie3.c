// Room: /d/dali/nandajie3.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��19�գ�����ʱ�䣺23ʱ42��49�롣

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "�ϳ���");
	set("long", @LONG
�������Ÿ����ɣ���Լ�������࣬�����ĳ�����������ȭͷ���С��
�������Ŷ���Լ���ɣ���Լÿ������ʱ���ͻ��ٱ����ء���������������׽
��֮��Ĺٸ�ͨ��(gaoshi)��
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"nandajie2",
  "south" : "/d/tianlongsi/dadao1",
]));

        set("item_desc", ([
                "gaoshi" : (: look_gaoshi :),
        ]));

        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));

	setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n����֪��\n������\n";
}

