// This is a room made by roommaker.

inherit ROOM;

void create()
{
    set("short", "城墙");
    set("long", "这是一间什麽也没有的空房间。\n");
    setup();
    replace_program(ROOM);
}
