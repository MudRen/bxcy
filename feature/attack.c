// attack.c
// From ES2
// Modified by Xiang for XKX (12/15/95)
#pragma save_binary
#include <dbase.h>
#include <origin.h>
#include <skill.h>
#define MAX_OPPONENT    4
nosave object *enemy = ({});
nosave object *killer = ({});
nosave object *att_killer = ({});
        // ���������ĵ���
// prototypes
object *query_enemy() {    return enemy;}
object *query_killer() { return killer; }
// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_fighting(object ob)
{
    if( !ob ) return sizeof(enemy) > 0;
    return member_array(ob, enemy)!=-1;
}
// �ж��Ƿ���������ĳ��ob
varargs int is_att_killing(object ob)
{
    if( !ob ) return 0;
    return member_array(ob, att_killer)!=-1;
}
// ��������,����Ҳ���Ч
void att_kill_ob(object ob)
{
    if(!ob || ob==this_object()) return;
    if (!living(this_object()))  return;
    if (environment()->query("no_fight") ) return;
    if (!userp(ob) || !userp(this_object()) )       return;
    if( member_array(ob, att_killer)==-1 )
        att_killer += ({ ob });
}
// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_killing(object ob)
{
    if( !ob ) return sizeof(killer) > 0;
    return member_array(ob, killer)!=-1;
}
//This function starts fight between this_object() and ob
void fight_ob(object ob)
{
    if(!ob || ob==this_object()) return;
    set_heart_beat(1);
    if( member_array(ob, enemy)==-1 ) 
        enemy += ({ ob });
}
// This function starts killing between this_object() and ob
void kill_ob(object ob)
{
    if(!ob || ob==this_object()) return;
    if (!living(this_object()))  return;
    if (environment()->query("no_fight") && !this_object()->query("demogorgon") ) return;
    if( member_array(ob, killer)==-1 )
        killer += ({ ob });
    if (environment()==environment(ob))
    tell_object(ob, HIR "������" + this_object()->name() + HIR + "��ɱ���㣡\n" NOR);
    fight_ob(ob);
}
void clean_up_enemy()
{
    if( sizeof(enemy) > 0 ) {
        for(int i=0; i<sizeof(enemy); i++) {
            if( !objectp(enemy[i])
            ||  environment(enemy[i])!=environment()
            ||  (!living(enemy[i]) && !is_killing(enemy[i])) )
                enemy[i] = 0;
        }
        enemy -= ({ 0 });
    }
}
// This function checks if the current opponent is available or
// select a new one.
object select_opponent()
{
    int which;
    if( !sizeof(enemy) ) return 0;
    which = random(MAX_OPPONENT);
    return which < sizeof(enemy) ? enemy[which] : enemy[0];
}
// Stop fighting ob.
int remove_enemy(object ob)
{
    if (!ob)    return 0;
    if( is_killing(ob) ) return 0;
    enemy -= ({ ob });
    return 1;
}
// Stop killing ob.
int remove_killer(object ob)
{
    if( is_killing(ob) ) {
        killer -= ({ ob });
        remove_enemy(ob);
        return 1;
    }
    return remove_enemy(ob);
}
// Stop all fighting, but killer remains.
void remove_all_enemy()
{
    for(int i=0; i<sizeof(enemy); i++) {
        // We ask our enemy to stop fight, but not nessessary to confirm
        // if the fight is succeffully stopped, bcz the fight will start
        // again if our enemy keeping call COMBAT_D->fight() on us.
        if( objectp(enemy[i]) )
            enemy[i]->remove_enemy(this_object());
            enemy[i] = 0;
    }
    enemy = ({});
}
// Stop all fighting and killing.
void remove_all_killer()
{
    killer = ({});
    
    att_killer = ({});
    
    enemy -= ({ 0 });
    for(int i=0; i<sizeof(enemy); i++){
        if (enemy[i]->query_leader()==this_object())
            enemy[i]->set_leader(0);
        if( enemy[i]->remove_killer(this_object()) )
            enemy[i] = 0;
    }
    enemy -= ({ 0 });
}
// reset_action()
//
// This function serves as a interface of F_ATTACK and wielded, worn objects.
// When the living's fighting action need update, call this function.
//
void reset_action()
{
    object me,ob;
    string type, skill;
        me = this_object();
    
    if ( me->query_temp("secondly_weapon") ){
        if( ob=me->query_temp("secondary_weapon") ) type = ob->query("skill_type");
        else type = "unarmed";
    }else{
        if( ob=me->query_temp("weapon") ) type = ob->query("skill_type");
        else type = "unarmed";
    }
    
    if( stringp(skill = query_skill_mapped(type)) ) {
        // If using a mapped skill, call the skill daemon.
                if ( ob )
                        set("actions", (: call_other, SKILL_D(skill), "query_action", me, ob :) );
                else
                        set("actions", (: call_other, SKILL_D(skill), "query_action" :) );
    } else {
        // Else, let weapon handle it.
        if( ob ) set("actions", ob->query("actions",1) );
        else set("actions", query("default_actions",1) );
    }
}
// This is called in heart_beat() to perform attack action.
int attack()
{
    object opponent;
    clean_up_enemy();
    opponent = select_opponent();
    if( objectp(opponent) ) {
        set_temp("last_opponent", opponent);
        COMBAT_D->fight(this_object(), opponent);
        return 1;
    } else
        return 0;
}
//
// init() - called by MudOS when another object is moved to us.
//
void init()
{
    object ob;
    string vendetta_mark;
    int shen,sb_shen;
    // We check these conditions here prior to handle auto fights. Although
    // most of these conditions are checked again in COMBAT_D's auto_fight()
    // function, these check reduces lots of possible failure in the call_out
    // launched by auto_fight() and saves some overhead.
    if( is_fighting()
    ||  !living(this_object())
    ||  !(ob = this_player()) 
    ||  environment(ob)!=environment()
    ||  !living(ob)
    ||  ob->query("linkdead") )
        return;
    sb_shen=ob->query("shen");
    shen=this_object()->query("shen");
    // Now start check the auto fight cases.
    if( is_killing(ob) ) {
        COMBAT_D->auto_fight(this_object(), ob, "hatred");
        return;
    } else if( stringp(vendetta_mark = query("vendetta_mark"))
    && ob->query("vendetta/" + vendetta_mark) ) {
        COMBAT_D->auto_fight(this_object(), ob, "vendetta");
        return;
    } else if( userp(ob) && (string)query("attitude")=="aggressive" ) {
        COMBAT_D->auto_fight(this_object(), ob, "aggressive");
        return;
    } else if ((shen<-5000 && sb_shen>5000 ) || (shen>5000 && sb_shen<-5000 ) ){
        COMBAT_D->auto_fight(this_object(), ob, "berserk");
        return;
    }
}

