// Room: /u/cass/hg/pubu.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�ٲ�");
	set("long", @LONG
�ٲ���ɽ�������ն��£����걼к��Ϣ������ϸ����˿���ٲ��Ӱ��
���ƺ�����׹��ʱ�������ɴ秣�ʱ���ֻ�Ϊ���̣�ʢ�������籼��������
�裬��Ȼ��к�����Ư�����ﶬ���������´���ˮ���ѩ�����ת�ƣ�����
���£�����ʤ�ա�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"longtan",
  "northwest" : __DIR__"shidong",
]));

	setup();
	replace_program(ROOM);
}
