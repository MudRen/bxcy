//room: party/xxshi.c
//restroom
inherit ROOM;
void create()
{
  set("short","��Ϣ��");
  set("long",
      "�����Ǽ���Ϣ�ң��������Ŵ󴲡�������˯���ǳ������û����\n"
  "���š�\n"
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
		return notify_fail("���Ǳ��˵ĵ��̣���������\n");
	if(!me->query("guild")||
	((int)me->query("guild/generation")>2 && dir == "north"))
		return notify_fail("���ǳ�������Ϣ�ĵط������ȥ�����ˡ���\n");
	}
	return ::valid_leave(me, dir);
}