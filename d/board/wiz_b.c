// /clone/board/wiz_b.c
inherit BULLETIN_BOARD;
void create()
{
        set_name("��ʦ���Բ�", ({ "board","thousand-gold" }) );
	set("location", "/d/wizard/wizard_room");
	set("board_id", "wiz_b");
	set("long", "����һ��ר����ʦʹ�õ����԰塣\n" );
	setup();
	set("capacity", 300);
//        replace_program(BULLETIN_BOARD);
}
string short()
{
    if (!wizardp(this_player())&&this_player()->query("id")!="snow") return "һ��"+HIY+"һǧ���Ľ�Ʊ"+NOR+"(Thousand-gold)";
    return ::short();
}

string long()
{
    if (!wizardp(this_player())&&this_player()->query("id")!="snow") return "һ�����ֵһǧ�����ӵĽ�Ʊ��\n";
    return ::long();
}
int do_post(string arg)
{
    if (!wizardp(this_player())&&this_player()->query("id")!="snow") return 0;
    return ::do_post(arg);
}
int do_read(string arg)
{
    if (!wizardp(this_player())&&this_player()->query("id")!="snow") return 0;
    return ::do_read(arg);
}
int do_discard(string arg)
{
    if (!wizardp(this_player())&&this_player()->query("id")!="snow") return 0;
    return ::do_discard(arg);
}
