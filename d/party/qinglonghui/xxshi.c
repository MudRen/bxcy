//room: party/xxshi.c
//restroom
inherit ROOM;
void create()
{
  set("short","休息室");
  set("long",
      "这里是间休息室，里面有张大床。在这里睡觉非常舒服，没人能\n"
  "打扰。\n"
     );
  set("exits",([
      "north" : __DIR__"biguan",
      "south" : __DIR__"dating",
     ]));
  set("sleep_room", 1);
  set("no_fight",1);
  set("no_steal",1);
 setup();
}
int valid_leave(object me, string dir)
{
	if (!wizardp(me)){
	if (file_name(environment(me))!="/d/party/"+me->query("guild/id")+"/xxshi"
		&& dir == "north")
		return notify_fail("那是别人的地盘，你想干嘛。”\n");
	if(!me->query("guild")||
	((int)me->query("guild/generation")>2 && dir == "north"))
		return notify_fail("那是长老们休息的地方，你别去打扰了。”\n");
	}
	return ::valid_leave(me, dir);
}