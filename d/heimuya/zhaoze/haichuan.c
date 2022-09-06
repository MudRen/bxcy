// Room: /d/heimuya/zhaoze/haichuan.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "海船");
	set("long", @LONG
一条渔船，最多也就能载二三十个人。一名六十多岁的老艄公
指挥着几个年轻力壮的水手，鼓足了风帆，在海浪中挣扎。
LONG
);

	setup();
}
void init()
{
    if (userp(this_player())){
       remove_call_out("drive_boat");
       call_out("drive_boat",10,this_player(),1);
    }
}
void drive_boat(object me,int i)
{
    object room;
    if (!me && environment(me)!=this_object()) return;

    if (i<22)
    {
     i++;
       remove_call_out("drive_boat");
       message("vision",BLU+"你在海上航行了很久...很久.....\n"+NOR,this_object());
       call_out("drive_boat",10,this_player(),i);
        return;
    }
}
