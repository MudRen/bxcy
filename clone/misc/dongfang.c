// This is a room made by roommaker.

inherit ROOM;

void create()
{
    set("short", "�շ���");
    set("long", "����һ��ʲ��Ҳû�еĿշ��䡣\n");
    setup();
    replace_program(ROOM);
}
int query_autoload() { return 1; }