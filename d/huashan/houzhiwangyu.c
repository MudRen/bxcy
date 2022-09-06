// ----/d/huashan/houzhiwangyu.c ----
// Room: /inherit/room/houzhiwangyu.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
        set("short", "猴子望月");
        set("long", @LONG
此处原是一仞高耸入云的峭壁，不知何年由人从峭壁的半腰硬是开出一条栈
道来，栈道旁有一粗十余丈的擎天石柱，石柱顶生一松，松旁有一天生奇石，宛
如翘首望月的猴子。 
LONG
);
        set("exits", ([ /* sizeof() == 3 */
  "southdown" : __DIR__"liyubei",
  "west" : __DIR__"cunyangdaoguan",
//        "northup" : __DIR__"huashanjueding.c",	
    "1" : __DIR__"biwu1.c",
    "2" : __DIR__"biwu2.c",
    "3" : __DIR__"biwu3.c",
    "4" : __DIR__"biwu4.c",
]));

  set("no_fight",1);
        setup();
}
int valid_leave(object me, string dir)
{
    int age=(int)me->query("mud_age") / 86400 + 14;
    if (wizardp(me)
      || dir == "1" && age < 25 
      || dir == "2" && ( age >=25 && age <60 )
      || dir == "3" && ( age >= 60 && age <90 )
      || dir == "4" && age >= 90 )
      return 1;
   if (dir == "southdown" || dir == "west" || dir == "northup") return 1;
    return notify_fail("你不可以到那边比武！！\n");
}

