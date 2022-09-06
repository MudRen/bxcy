// Room: /u/aplio/ltsh/jyt.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
set("short", "大厅");	
	set("long", @LONG
这里是帮派议事大厅,上首有一虎皮金边大椅供帮主休憩议事之用,也是帮内至上权威的象征.两边各竖着一块黑漆金字牌匾：		
　　　　　　　乱世风云，鬼哭神嚎。
　　　　　　　翻云覆雨，唯我独尊。
旁边便是花梨木几椅，用来招呼群雄或帮众汇报大小事务的休息地方。
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
		return notify_fail("那是别人的地盘，你想干嘛。”\n");
	if(!me->query("guild")||
	((int)me->query("guild/generation")>2 && dir == "north"))
		return notify_fail("那是长老们休息的地方，你别去打扰了。”\n");
	}
	return ::valid_leave(me, dir);
}