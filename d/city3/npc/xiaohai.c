// xiao-hai.c

inherit NPC;

void create()
{
        set_name("小孩",({ "xiao hai", "hai" }) );
        set("gender", "男性" );
        set("age", 11);
        set("long", "小孩子有什么好看的。\n");
//	set("shen_type", 1);
        set("combat_exp", 50);
        set("shen", 50);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
        set("attitude", "heroism");
        setup();
	carry_object("clone/misc/cloth")->wear();
}

