// Room: /u/aplio/ltsh/jyt.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
set("short", "����");	
	set("long", @LONG
�����ǰ������´���,������һ��Ƥ��ߴ��ι������������֮��,Ҳ�ǰ�������Ȩ��������.���߸�����һ�����������ң�		
���������������������ƣ�����񺿡�
�����������������Ƹ��꣬Ψ�Ҷ���
�Ա߱��ǻ���ľ���Σ������к�Ⱥ�ۻ���ڻ㱨��С�������Ϣ�ط���
LONG
);
set("no_fight",1);
	set("exits", ([ /* sizeof() == 2 */
"east" : __DIR__"beidajie3",
"north" : __DIR__"xxshi",
]));

	setup();
}
int valid_leave(object me, string dir)
{
	if (!wizardp(me)){
	if (file_name(environment(me))!="/d/party/"+me->query("guild/id")+"/dating"
		&& dir == "north")
		return notify_fail("���Ǳ��˵ĵ��̣���������\n");
	if(!me->query("guild")||
	((int)me->query("guild/generation")>2 && dir == "north"))
		return notify_fail("���ǳ�������Ϣ�ĵط������ȥ�����ˡ���\n");
	}
	return ::valid_leave(me, dir);
}