// Room: /u/mei/zhaoze/room10.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "é��");
	set("long", @LONG
ֻ����ǰһ�ų��������������յ�͵ƣ��ų������֮�Ρ���
�¶���һ��ͷ�����׵�Ů�ӣ�������������Ŀ���ŵ���һ����������
��Ƭ����Ȼ����Ǳ��˼�������������˽�����ȴ��̧ͷ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room9",
]));
        set("objects", ([ 
        __DIR__"npc/yinggu" : 1,
]));


	setup();
}
