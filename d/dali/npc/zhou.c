// zhou.c 周老板 
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
int redeem(string arg);
void create()
{
        set_name("周亮", ({ "zhou liang", "zhou" }));
        set("title", "当铺老板");
        set("shen_type", 0);
        set("gender", "男性");
        set_max_encumbrance(100000000);
        set("age", 35);
        set("long",
                "周亮的身份十分神秘,据说他的后台是官府的人。\n");
        set("no_get_from", 1);
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/attack", 30);
        set_temp("apply/damage", 15);
        set("combat_exp", 50000);
set("no_get",1);	
        set("attitude", "friendly");
       set_weight(50000000);
       set("no_put",1);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
    if (base_name(environment())!=this_object()->query("startroom")) return;
        add_action("do_list", "list");
        add_action("do_buy", "buy");
        add_action("do_sell", "sell");
        add_action("do_value", "value");
        add_action("do_redeem", "redeem");
        add_action("do_pawn", "pawn");
        add_action("do_check", "check");
}
void die()
{
        message_vision("\n$N死了。\n", this_object());
        destruct(this_object());
}
