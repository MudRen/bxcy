// shizhe1.c

inherit NPC;

void create()
{
        set_name("侍者", ({ "waiter","zhe"}) );
        set("gender", "男性" );
        set("age", 14);
        set("long", "一个身着黄衣的汉子。\n");
        set("shen_type", 1);
        set("combat_exp", 300000);
        set("str", 200);
        set("dex", 25);
        set("con", 20);
        set("int", 250);
   
        create_family("侠客岛", 2, "弟子");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}


