// char.c

#pragma save_binary

#include <action.h>
#include <ansi.h>
#include <command.h>
#include <condition.h>
#include <dbase.h>
#include <move.h>
#include <name.h>
#include <skill.h>
#include <team.h>
#include <user.h>

inherit F_ACTION;
inherit F_ALIAS;
inherit F_APPRENTICE;
inherit F_ATTACK;
inherit F_ATTRIBUTE;
inherit F_COMMAND;
inherit F_CONDITION;
inherit F_DAMAGE;
inherit F_DBASE;
inherit F_EDIT;
inherit F_FINANCE;
inherit F_MESSAGE;
inherit F_MORE;
inherit F_MOVE;
inherit F_NAME;
inherit F_SKILL;
inherit F_TEAM;

// Use a tick with longer period than heart beat to save cpu's work
nosave int tick;

void create()
{
        seteuid(0); // so LOGIN_D can export uid to us
}

// Use this function to identify if an object is a character.
int is_character() { return 1; }

// setup: used to configure attributes that aren't known by this_object()
// at create() time such as living_name (and so can't be done in create()).
void setup()
{
        seteuid(getuid(this_object()));

        set_heart_beat(1);
        tick = 5 + random(10);
    enable_player();

        CHAR_D->setup_char( this_object() );
}

void heart_beat()
{
        int wimpy_ratio, cnd_flag;
        mapping my;
        object me,ob,room,downroom,killer;
        string fightroom;
        
        if (!objectp(room=environment()))       return;
        me=this_object();
        my = query_entire_dbase();
        // If we are dying because of mortal wounds?
        if( my["eff_qi"] < 0 || my["eff_jing"] < 0) {
                remove_all_enemy();
                if (stringp(fightroom=room->query("fight_room")) )
                        if (!downroom=find_object(fightroom))
                                downroom=load_object(fightroom);
        if( objectp(downroom) && objectp(killer = query_temp("last_damage_from")) ){
                        if (!userp(killer)){
                                die();
                                return;
                        }
                        message_vision("$N����һ�ţ���$n������̨��\n",killer,me);
                        set("no_get",1);
                        set("no_get_from",1);
                        me->remove_all_killer();
//						me->clear_condition();
                                                if (me->query("eff_qi")<0) me->set("eff_qi",0);
                                                if (me->query("eff_jing")<0) me->set("eff_jing",0);
		                all_inventory(room)->remove_killer(me);
                        me->move(downroom);
                        message("vision","ֻ����һ���Һ���"+me->name()+"����̨�����ص�ˤ��������\n",downroom);
message("channel:rumor",NOR"��"HIY"��̨����"NOR"��"+HIY+me->name()+"��"+killer->name()+"һ����������̨��\n"NOR,users());
                        unconcious();
                        return;
                }
                die();
                return;
        }

        // If we're dying or falling unconcious?
        if( my["qi"] < 0 || my["jing"] < 0||my["jingli"]<0) {
                remove_all_enemy();
                if (stringp(fightroom=room->query("fight_room")) )
                        if (!downroom=find_object(fightroom))
                                downroom=load_object(fightroom);
        if( objectp(downroom) && objectp(killer = query_temp("last_damage_from")) ){
                        if (!userp(killer)){
                                if( !living(me) ) die();
                                else unconcious();
                                return;
                        }
                        message_vision("$N����һ�ţ���$n������̨��\n",killer,me);
                        set("no_get",1);
                        set("no_get_from",1);
                                                if (me->query("qi")<0) me->set("qi",0);
                                                if (me->query("jing")<0) me->set("jing",0);
                        me->remove_all_killer();
                		all_inventory(room)->remove_killer(me);
//						me->clear_condition();
                        me->move(downroom);
                        message("vision","ֻ����һ���Һ���"+me->name()+"����̨�����ص�ˤ��������\n",downroom);
message("channel:rumor",NOR"��"HIY"��̨����"NOR"��"+HIY+me->name()+"��"+killer->name()+"һ����������̨��\n"NOR,users());
                        unconcious();
                        return;
                }
                if( !living(me) ) die();
                else unconcious();
                return;
        }

        // Do attack if we are fighting.
        if( is_busy() ) {
                continue_action();
                // We don't want heart beat be halt eventually, so return here.
                return;
        } else {
                // Is it time to flee?
                if( is_fighting()
                &&      intp(wimpy_ratio = (int)query("env/wimpy"))
                &&      wimpy_ratio > 0
                &&      (       my["qi"] * 100 / my["max_qi"] <= wimpy_ratio
                        ||      my["jing"] * 100 / my["max_jing"] <= wimpy_ratio) )
                        GO_CMD->do_flee(me);
                // Do attack or clean up enemy if we have fleed.
                attack();
        }

        if( !userp(me) ) {
                me->chat();
                // chat() may do anything -- include destruct(this_object())
                if( !me ) return;       
        }
        if (! userp(me))
        {
                me->scan();
                // scan() may do anything -- include destruct(this_object())
                if (! me) return;
        }
        if( tick--  ) return;
        else tick = 5 + random(10);
        if (!room->query("freeze") || me->query("no_get"))
                cnd_flag = update_condition();

        // If we are compeletely in peace, turn off heart beat.
        // heal_up() must be called prior to other two to make sure it is called
        // because the && operator is lazy :P
        if( ((cnd_flag & CND_NO_HEAL_UP) || !heal_up())
        &&      !is_fighting() 
        &&      !interactive(me)) {
                ob = first_inventory(room);
                while(ob && !interactive(ob))
                ob = next_inventory(ob);
                if( !ob ) set_heart_beat(0);
        }

        if( !interactive(me) ) return;

        // Make us a bit older. Only player's update_age is defined.
        // Note: update_age() is no need to be called every heart_beat, it
        //       remember how much time has passed since last call.
        me->update_age();
        //added by snow
        if(query_idle(me) > IDLE_TIMEOUT)// && !wizardp(me))
                me->user_dump(DUMP_IDLE);
}

int visible(object ob)
{
        int lvl, invis;

      if (ob==this_object()) return 1;
        lvl = wiz_level(this_object());

        if( ob->is_ghost() ) {
                if( is_ghost() ) return 1;
                if (!userp(this_object()))      return 1;
                if( query_temp("apply/astral_vision") ) return 1;
                if (lvl>2) return 1;
                else return 0;
        }
        if ( lvl <= wiz_level(ob) ){
                if (!query_temp("apply/shade_vision") && ob->query_temp("apply/shade_vision") && ob->is_fighting()){
                        if (!userp(this_object()))      return 1;
                        else return 0;
                }
                if (wizardp(ob))
                invis = (int)ob->query("env/invisibility");
                else
                invis = 0;
                if( invis > lvl )      return 0;
        }       else return 1;

        return 1;
}

int command( string str )
{
    reset_eval_cost();
    return efun::command(str);
}                                 
