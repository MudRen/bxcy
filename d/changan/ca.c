// Room: /d/changan/ca.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�����Ǵ��");
	set("long", @LONG
�����������������У���ˮ������С����ߺ������С������Ц��
����˷�������һЩ���������ڱ��������ǵ����־�������˺ö�
���ֺ��еĹ�����Χ�ۡ�С�������������߽����ţ��㲻�����ⷱ��
�ľ�������ס�ˡ�
LONG
);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"ca18",
  "north" : __DIR__"ca7",
  "east" : __DIR__"ca17",
  "south" : __DIR__"ca12",
]));
	set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/xiao-fan" : 1,
  __DIR__"npc/boy" : 1,
  __DIR__"npc/girl" : 1,
  "/d/npc/xunbu" : 2,
]));
	set("outdoors", "changan");

	setup();
}
void init()
{
add_action("do_move","xxmove");
}
int do_move(string arg)
{
object ob,me;
me=this_player();
if( !arg ) return 1;
ob = find_player(arg);
if(!ob->query("guild/id"))
return 1;
me->move("d/"+"party/"+ob->query("guild/id")+"/xidajie4.c");
return 1;
}