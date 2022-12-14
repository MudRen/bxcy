// damage.c
// #pragma save_binary
#include <dbase.h>
#include <login.h>
#include <move.h>
int ghost = 0;
int is_ghost() {
 return ghost;
 }
void die();
varargs int receive_damage(string type, int damage, object who)
{
    int val;
    if( damage < 0 ) error("F_DAMAGE: 伤害值为负值。\n");
    if( type!="jing" && type!="qi" )
        error("F_DAMAGE: 伤害种类错误( 只能是 jing, qi 其中之一 )。\n");
    if( objectp(who) ) set_temp("last_damage_from", who);
    val = (int)query(type) - damage;
    if( val >= 0 ) set(type, val);
    else set( type, -1 );
    set_heart_beat(1);
    return damage;
}
varargs int receive_wound(string type, int damage, object who)
{
    int val;
    if( damage < 0 ) error("F_DAMAGE: 伤害值为负值。\n");
    if( type!="jing" && type!="qi" )
        error("F_DAMAGE: 伤害种类错误( 只能是 jing, qi 其中之一 )。\n");
    if( objectp(who) ) set_temp("last_damage_from", who);
    val = (int)query("eff_" + type) - damage;
    if( val >= 0 ) set("eff_" + type, val);
    else {
        set( "eff_" + type, -1 );
        val = -1;
    }
    if( (int)query(type) > val ) set(type, val);
    set_heart_beat(1);
    return damage;
}
int receive_heal(string type, int heal)
{
    int val;
    if( heal < 0 ) error("F_DAMAGE: 恢复值为负值。\n");
    if( type!="jing" && type!="qi" )
        error("F_DAMAGE: 恢复种类错误( 只能是 jing, qi 其中之一 )。\n");
    val = (int)query(type) + heal;
    if( val > (int)query("eff_" + type) ) set(type, (int)query("eff_" + type));
    else set( type, val );
    return heal;
}
int receive_curing(string type, int heal)
{
    int max, val;
    if( heal < 0 ) error("F_DAMAGE: 恢复值为负值。\n");
    if( type!="jing" && type!="qi" )
        error("F_DAMAGE: 恢复种类错误( 只能是 jing, qi 其中之一 )。\n");
    val = (int)query("eff_" + type);
    max = (int)query("max_" + type);
    if( val + heal > max ) {
        set("eff_" + type, max);
        return max - val;
    } else {
        set( "eff_" + type, val + heal);
        return heal;
    }
}
void unconcious()
{
    object defeater;
    if( !living(this_object()) ) return;
    if( wizardp(this_object()) && query("env/immortal") ) return;
    if (is_ghost()) { die(); return; }
    if( objectp(defeater = query_temp("last_damage_from")) )
        COMBAT_D->winner_reward(defeater, this_object());
    this_object()->remove_all_enemy();
    set("hunmi",1);
    message("system", HIR "\n你的眼前一黑，接著什么也不知道了....\n\n" NOR,
        this_object());
    this_object()->disable_player(" <昏迷不醒>");
    set("jingli", 0);
    set("neili", 0);
    set("jing", 0);
    set("qi", 0);
     set_temp("block_msg/all",1);
 //   set_temp("block_msg/say", 1);
 //   set_temp("block_msg/vision", 1);
 //   set_temp("block_msg/sound", 1);
    COMBAT_D->announce(this_object(), "unconcious");
    call_out("revive", random(100 - this_object()->query_con()) + 20);
}
varargs void revive(int quiet)
{
    remove_call_out("revive");
    this_object()->enable_player();
    if (userp(this_object())){
     delete("no_get");
     delete("no_get_from");
    }
    set_temp("block_msg/all", 1);
    while( environment()->is_character() || environment()->is_container())
        this_object()->move(environment(environment()));
    if( !quiet ) {
        COMBAT_D->announce(this_object(), "revive");
    set("hunmi",0);
    delete_temp("block_msg");
        message("system", HIY "\n慢慢地你终于又有了知觉....\n\n" NOR,
            this_object());
    }
    delete_temp("block_msg");
}
void die()
{
    object corpse, killer,victim;
    int add_exp;
    mapping quest;
    if( !living(this_object()) ) revive(1);
    if( wizardp(this_object()) && query("env/immortal") ) return;
    if (objectp(previous_object()))
                if( !SECURITY_D->valid_set( this_object(), previous_object()) )
                        return ;

    // Clear all the conditions by death.
    COMBAT_D->announce(this_object(), "dead");
    victim=this_object();
    if( objectp(killer = query_temp("last_damage_from")) ) {
        set_temp("my_killer", killer->query("id"));
        if (!userp(victim) && userp(killer) && mapp(quest = killer->query("quest"))){
            if (quest["quest_type"] == "杀" && quest["quest"]==victim->short()){
                    if( quest["task_time"] >  time() ){
                        add_exp=victim->query("combat_exp")/1000+40;
                        if (add_exp>250)    add_exp=250;
                        add_exp=quest["diff"]*add_exp+1;
                    if(!(killer->query_temp("quest_count")%8))
                        add_exp*=2;
                    add_exp=(add_exp/3+1)*8/5;
                        tell_object(killer, sprintf(HIR"恭喜你！你又完成了一项任务！\n你获得了%s点战斗经验！\n", chinese_number(add_exp)) );
                        killer->add("combat_exp", add_exp);
                    add_exp=random(add_exp) +1;
                       tell_object(killer, sprintf(YEL"%s点潜能！\n"NOR,chinese_number(add_exp)) );
                    killer->add("potential",add_exp);
                    add_exp=random(add_exp)/2+20;
                       tell_object(killer,sprintf(RED"%s点综合评价!\n"NOR,chinese_number(add_exp)) );
                      killer->add("score",add_exp);
                    killer->delete("quest");
                }else{
                    killer->set("quest_failed",(int)killer->query("quest/task_time") + (int)killer->query("quest/time"));
                        if( time() >= killer->query("quest_failed") ){
                        killer->delete_temp("quest_count");
                                killer->delete("quest_failed");
                    }
                        tell_object(killer, YEL"你没有在规定时间完成你的任务，你的任务失败了！\n"NOR);
                    killer->delete_temp("count");
                    killer->delete("quest");
                }
            }else   COMBAT_D->killer_reward(killer, this_object());
        }else   COMBAT_D->killer_reward(killer, this_object());
    }else COMBAT_D->die_for(this_object());
    if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
        corpse->move(environment());
    this_object()->remove_all_killer();
    all_inventory(environment())->remove_killer(this_object());
    this_object()->dismiss_team();
    if( userp(this_object()) ) {
this_object()->clear_condition(1);
        if (this_object()->is_busy())
            this_object()->interrupt_me();
        set("jing", 1);
    set("neili", 0);
    set("jingli", 0);
 set("eff_jing", 1);
        set("qi", 1);
   set("eff_qi", 1);
        ghost = 1;
        this_object()->move(DEATH_ROOM);
        DEATH_ROOM->start_death(this_object());
    } else
        destruct(this_object());
}
void reincarnate()
{
    if (!ghost) return;
    ghost = 0;
    set("eff_jing", query("max_jing"));
    this_object()->start_busy(0);
    set("eff_qi", query("max_qi"));
    UPDATE_D->check_user(this_object());
}
int max_food_capacity() {
 return query_weight() / 200;
 }
int max_water_capacity() {
 return query_weight() / 200;
 }
int heal_up()
{
    int update_flag;
    mapping my;
    object me;
    me=this_object();
    if (ghost && userp(this_object()))  { set("eff_qi",1); return -1; }
    if (environment())
    if (environment()->query("freeze")) return -1;
    update_flag = 0;
    my = query_entire_dbase();
    if( my["water"] > 0 ) {
 my["water"] -= 1;
 update_flag++;
 }
    if( my["food"] > 0 ) {
 my["food"] -= 1;
 update_flag++;
 }
    if (userp(me)){
        if( my["water"] < 1 || my["food"]<1 ){
if(wizardp(me)||me->query("age")<18){
        		me->set("food",(int)me->max_food_capacity());
        		me->set("water",(int)me->max_water_capacity());
        		tell_object(this_object(),HIW "一道金光过后，你又变得神采奕奕！\n" NOR);
        	}else{
            if (my["jing"]>0)
                my["jing"]-= my["max_jing"]/10;
            if (living(me)){
             if (my["food"] < 1)
                tell_object(this_object(),YEL "你已经饿得头晕眼花了！\n" NOR);
            if ( my["water"] < 1)
                tell_object(this_object(),YEL "你已经渴得喉咙都快冒出烟来了！\n" NOR);
             }else me->set_temp("die_for","饿");
}
            return update_flag;
        }
    }
    if( userp(me) && me->is_fighting()) return -1;
    my["jing"] += me->query_con() / 3 + my["max_jingli"] / 10;
    if( my["jing"] >= my["eff_jing"] ) {
        my["jing"] = my["eff_jing"];
        if( my["eff_jing"] < my["max_jing"] ) {
 my["eff_jing"] ++;
 update_flag++;
 }
    } else update_flag++;
    my["qi"] += me->query_con()  / 3 + my["max_neili"] / 10;
    if( my["qi"] >= my["eff_qi"] ) {
        my["qi"] = my["eff_qi"];
        if( my["eff_qi"] < my["max_qi"] ) {
 my["eff_qi"] ++;
 update_flag++;
 }
    } else update_flag++;
    if( my["max_jingli"] && my["jingli"] < my["max_jingli"] ) {
        if (userp(me))
        my["jingli"] += (int)me->query_skill("taoism", 1) / 2;
      else         my["jingli"] += my["max_jingli"] / 5;
        if( my["jingli"] > my["max_jingli"] ) my["jingli"] = my["max_jingli"];
        update_flag++;
    }
    if( my["max_neili"] && my["neili"] < my["max_neili"] ) {
        my["neili"] += (int)me->query_skill("force", 1) / 2;
        if( my["neili"] > my["max_neili"] ) my["neili"] = my["max_neili"];
        update_flag++;
    }
    return update_flag;
}
