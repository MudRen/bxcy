// Room: /d/quanzhen/mengjin/duchuan.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "渡船");
	set("long", @LONG
你正处在渡船之中，耳边只有船夫的吆喝声和水流声。
LONG
);

	setup();
}
int do_check()
{
        object *obj;
        int     i;
        obj=all_inventory(this_object());
        if (!sizeof(obj))       return 1;
        for (i=0;i<sizeof(obj);i++)
                if (userp(obj[i]))      return 0;
        return 1;
}
