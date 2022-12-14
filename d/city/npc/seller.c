inherit NPC;
void create()
{
    set_name("王八", ({ "wang ba", "wang", "ba" }));
    set("long", "一个满脸横肉的家伙，一看他诡秘的神情，就知道不是个好人。\n");
    set("nickname", "人贩子");
    set("rank_info/respect", "大佬");
    set("gender", "男性");
    set("age", 35);
    set("shen_type",-1);
    set("combat_exp", 5000);
    set("per",10);
    set_skill("unarmed", 100);
    set_skill("blade", 100);
    set_skill("parry", 100);
    set_skill("dodge", 100);
    
    set_temp("apply/attack", 15);
    set_temp("apply/defense", 15);
    set_temp("apply/damage", 20);
    setup();
    carry_object("/clone/misc/blk_cloth")->wear();
}
    
void init()
{
    add_action("do_sell","sell");
    add_action("do_redeem","redeem");
}
int do_sell(string arg)
{
    object obj,room;
    if (!arg)    return notify_fail("你要卖什么？\n");
    if( !(obj = present(arg, this_player())) )
        return notify_fail("你身上没有这东东。\n");
    if (!obj->is_character() || obj->is_corpse() )
        return notify_fail(this_object()->name()+"摇了摇头：我对这东西没兴趣！\n");
    if (obj->query("combat_exp") <1000 )
        return notify_fail(obj->name()+"不值钱！\n");
}
int do_redeem(string arg)
{
    object obj,room;
    if (!arg)   return notify_fail("你想赎谁？\n");
    if (! room=find_object("/d/city/cangku") )
        room=load_object("/d/city/cangku");
    if (!room->do_check(arg))
        return notify_fail("谁？没听说过！\n");
    
}