//suicong.c 随从
inherit NPC;

void create()
{
        set_name("王府随从", ({ "sui cong", "sui" }));
        set("gender", "男性");
        set("age", 30);

        set("combat_exp", 40000);
        set_skill("dodge", 70);
        set_skill("unarmed", 70);
        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);
        set("shen_type", 1);
        setup();

        add_money("silver",10);
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        ::init();
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}