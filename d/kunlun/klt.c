// Room: /d/kunlun/klt.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "昆仑台");
        set("long", @LONG
这里便是昆仑台了，寒风迎面扑来，你开始觉得冷了。只见满峰是雪，昆
仑山在骄阳下看来亮如纯银，到了夕阳西下时又变得灿烂如黄金。身当此境，
顿觉心旷神怡。
LONG
        );
        set("outdoors", "klt");
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"klsj2",
  "northup" : __DIR__"zwf",
]));

        setup();
}
int valid_leave(object me, string dir)
{
    object boot;
    int damage=80-me->query_skill("dodge",1)/10;
    boot=me->query_temp("armor/boots");
    if (dir=="northup" && (!boot || boot->query("id")!="sandals")){
        if (damage<20){
            tell_object(me,HIW+"你脚下一滑，你晃了两晃，总算没摔着！\n"+NOR);
            return 1;
        }else
        me->receive_damage("qi",damage);
        me->receive_damage("jing",damage);
        return notify_fail(HIW+"你脚下一滑，摔了个四脚朝天！\n"+NOR);
   }
   return 1;
}

