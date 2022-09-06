// Room: /d/shaolin/duchuan.c
// Date: YZC 96/01/19
inherit ROOM;


void create()
{
        set("short", "羊皮小筏");
        set("long", @LONG
一只小羊皮筏子，最多也就能载三、四个人。一名六十多岁的老艄公
手持长竹篙，正在吃力地撑着筏子。
LONG
        );

        setup();
}
int do_check()
{
	object *obj;
	int	i;
	obj=all_inventory(this_object());
	if (!sizeof(obj))	return 1;
	for (i=0;i<sizeof(obj);i++)
		if (userp(obj[i]))	return 0;
	return 1;
}
