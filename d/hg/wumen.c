// Room: /u/cass/hg/wumen.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ͻ��г�¥�������׳����¥���ϲ�������Ъɽʽ���������߶���
Ρ���¥����¥������Χ�к�����ʯ���ˡ����壬�����������ƿͼ������
¥���м�ʮ���ľ������������е��������룬���������微�����ʣ�����
��������ʻ�������ͼ���������̵��ǽ�ש���²������ɫ��̨�����ܻ���
�������߷ⶥ�İ�ǽ���²����е�̾����ĺ�����������̨������¥������
���ӹ�ͤ��
LONG
);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"gulou",
  "west" : __DIR__"zhonglou",
  "north" : __DIR__"jinshuiqiao",
"south" : "/d/huanggon/houyuan",	
]));

	setup();
	replace_program(ROOM);
}
