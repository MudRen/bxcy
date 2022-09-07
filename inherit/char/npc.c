// npc.c
// #pragma save_binary
#include <command.h>
inherit CHARACTER;
inherit F_CLEAN_UP;

void scan();
int  heal_self();
int  chat();
int  exert_function(string func);
object carry_object(string file)
{
    object ob,obj;
    if( !objectp(ob = new(file)) ) return 0;
    if (obj=present(ob->query("id"), this_object())){
        destruct(ob);
        return obj;
    }
    ob->move(this_object());
    return ob;
}
object add_money(string type, int amount)
{
    object ob;
    ob = carry_object("/clone/money/" + type);
    if( !ob ) return 0;
    ob->set_amount(amount);
}
int accept_fight(object who)
{
    string att;
    att = query("attitude");
    if( is_fighting() ) switch(att) {
        case "heroism":
            command("say �ߣ����аɣ�\n");
            break;
        default:
            command("say ���ж�Ϊʤ���ⲻ������̫����\n");
            return 0;
    }
    if( (int)query("jing") * 100 / (int)query("max_jing") >= 90
    &&  (int)query("qi") * 100 / (int)query("max_qi") >= 90 ) {
        switch(att) {
            case "friendly":
                command("say " + RANK_D->query_self(this_object())
                    + "��ô������" + RANK_D->query_respect(who)
                    + "�Ķ��֣�\n");
                return 0;
            case "aggressive":
            case "killer":
                command("say �ߣ����аɣ�\n");
                break;
            default:
                if( !is_fighting() )
                    command("say ��Ȼ" + RANK_D->query_respect(who)
                        + "�ͽ̣�" + RANK_D->query_self(this_object())
                        + "ֻ�÷��㡣\n");
        }
        return 1;
    } else
        return 0;
}
// This function is called by the reset() of the room that creates this
// npc. When this function is called, it means the room demand the npc
// to return its startroom.
int return_home(object home)
{
    object ob=this_object();
    mapping exits;
    // Are we at home already?
    if( !environment() )
        return 1;
    exits=environment()->query("exits");
    // Are we able to leave?
    if( !living(ob)
    ||  is_fighting()
    ||  !mapp(exits) || !sizeof(exits) ) {
            remove_call_out("return_home");
            call_out("return_home",20,home);
            return 1;
    }
    ob->set("water",ob->max_water_capacity());
    ob->set("food",ob->max_food_capacity());
    ob->create();
    // Leave for home now.
    if ( environment()!=home ){
        message("vision", ob->name() + "����ææ���뿪�ˡ�\n",
        environment(), this_object());
        message("vision", ob->name() + "���˹�����\n",
        home, ob);
      return move(home);
    }
    return 1;
}
void scan()
{
        object me;

        me = this_object();

        if (! environment() || ! living(me)) return;

        if (me->is_coagent() && me->is_helping() && ! me->is_fighting())
        {
                // finish helping
                me->finish_help();
        }

        if (heal_self()) return;

        chat();
}

// Here, the NPC will process the heal/recover.
int heal_self()
{
        mapping my;
        int cost;

        if (is_busy() || is_fighting())
                // ��æ��
                return 0;

        if (query("not_living"))
                // ������
                return 0;

        if (! query_skill_mapped("force"))
                // û�м����ڹ�
                return 0;

        if (query_temp("no_exert"))
                // ���������ֹʹ���ڹ�
                return 0;

        my = query_entire_dbase();
        if (my["neili"] < 50)
                return 0;

        if (my["jing"] < my["eff_jing"] * 8 / 10)
        {
                // ����̫��
                exert_function("regenerate");
                return 1;
        }

        if (my["qi"] < my["eff_qi"] * 8 / 10 &&
            query_skill("force") >= 150 &&
            my["eff_qi"] > my["max_qi"]/2 )
        {
                // ��Ѫ�������沢���ڹ��ȼ���
                exert_function("recover");
                return 1;
        }

        if (my["eff_qi"] < my["max_qi"])
        {
                // ������
                exert_function("heal");
                return 1;
        }

        if (my["eff_jing"] < my["max_jing"] &&
        	my["eff_qi"] > my["max_qi"]/2 )
        {
                // ���ܵ�����ʧ
                exert_function("jingheal");
                return 1;
        }

        if (my["neili"] < my["max_neili"] - 10)
        {
                // �����������棬�����ָ�
                cost = my["max_neili"] - my["neili"];
                if (cost > my["qi"] / 2) cost = my["qi"] / 2;
                command(sprintf("dazuo1 %d", cost));
                return 1;
        }

        return 0;
}

// This is the chat function dispatcher. If you use function type chat
// message, you can either define your own functions or use the default
// ones.
int chat()
{
    string *msg;
    int chance, rnd;
    if( !environment() || !living(this_object()) ) return 0;
    if( !chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance") )
        return 0;
    if( arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))) {
        if( random(100) < chance ) {
            rnd = random(sizeof(msg));
            if( stringp(msg[rnd]) )
                say(msg[rnd]);
            else if( functionp(msg[rnd]) )
                return evaluate(msg[rnd]);
        }
        return 1;
    }
}
// Default chat function: Let the npc random move to another room.
int random_move()
{
    mapping exits;
    string *dirs;
    if( !environment() || !living(this_object()) ) return 0;
    if( !mapp(exits = environment()->query("exits")) ) return 0;
    dirs = keys(exits);
    if (!sizeof(dirs)) return 0;
    command("go " + dirs[random(sizeof(dirs))]);
    return 1;
}
// Default chat function: Let the npc cast his/her enabled spells
void cast_spell(string spell)
{
    string spell_skill;
    if( !environment() || !living(this_object()) ) return;
    if( stringp(spell_skill = query_skill_mapped("spells")))
        SKILL_D(spell_skill)->cast_spell(this_object(), spell);
}
// Default chat function: Let the npc exert his/her enabled force
int exert_function(string func)
{
        string force_skill;

        if (! stringp(force_skill = query_skill_mapped("force")))
                return 0;

        // ���������ֹʹ���ڹ�
        if (this_object()->query_condition("no_exert"))
                return 0;

        if (SKILL_D(force_skill)->exert_function(this_object(), func))
                return 1;

        return SKILL_D("force")->exert_function(this_object(), func);
}
// Default chat function: Let the npc perform special action with
// his/her enabled martial art
int perform_action(string action)
{
    string martial_skill, act;
    if( !environment() || !living(this_object()) ) return 0;
    if (!stringp(action))   return 0;
    if( sscanf(action, "%s.%s", martial_skill, act) != 2 )
        return 0;
    martial_skill = query_skill_mapped(martial_skill);
    if( stringp(martial_skill) )
        return SKILL_D(martial_skill)->perform_action(this_object(), act);
}
void attempt_apprentice(object ob)
{
    command("sigh "+ob->query("id"));
    command("say "+RANK_D->query_self(this_object())+"����ѧǳ�����������ӵܣ���λ"+RANK_D->query_respect(ob)+"��ı�߾Ͱɣ�");
}
