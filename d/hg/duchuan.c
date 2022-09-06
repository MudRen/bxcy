inherit ROOM;


void create()
{
        set("short", "小画舫");
        set("long", @LONG
一叶漂亮的小舟，船仓内散发着一股淡淡的清香，船头一个风铃轻轻摇曳，
发出清脆动听的音响，几个太监在船尾慢慢地撑着船。
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

