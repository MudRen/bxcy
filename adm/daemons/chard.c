// chard.c
// From ES2
// Modified by Xiang@XKX
#define HUMAN_RACE "/adm/daemons/race/human"
#define BEAST_RACE "/adm/daemons/race/beast"
#define MONSTER_RACE "/adm/daemons/race/monster"
void create() { seteuid(getuid()); }
void setup_char(object ob)
{
	string race;
	mapping my;
        if( !stringp(race = ob->query("race")) ) {
                race = "人类";
                ob->set("race", "人类");
        }
        switch(race) {
                case "人类":
                        HUMAN_RACE->setup_human(ob);
                        break;
                case "妖魔":
                        MONSTER_RACE->setup_monster(ob);
                        break;
                case "野兽":
                        BEAST_RACE->setup_beast(ob);
                        break;
                default:
                        error("Chard: undefined race " + race + ".\n");
        }
	my = ob->query_entire_dbase();
	if( undefinedp(my["pighead"]) ) my["pighead"] = 0;
	if( undefinedp(my["jing"]) ) my["jing"] = my["max_jing"];
	if( undefinedp(my["qi"]) ) my["qi"] = my["max_qi"];
	if( undefinedp(my["eff_jing"]) ) my["eff_jing"] = my["max_jing"];
	if( undefinedp(my["eff_qi"]) || my["eff_qi"] > my["max_qi"]) my["eff_qi"] = my["max_qi"];
	
	if( undefinedp(my["shen"]) ) {
		if (userp(ob))
			my["shen"] = 0;
		else{
			if( undefinedp(my["shen_type"]) ) my["shen_type"] = 0;
			my["shen"] = my["shen_type"] * my["combat_exp"] / 10;
		}
	}
	if( !ob->query_max_encumbrance() )
		ob->set_max_encumbrance( (ob->query_str()-ob->query("jiali")) * 5000 );
	ob->reset_action();
}
varargs object make_corpse(object victim, object killer)
{
	int i;
        object corpse, *inv,room;
        room=environment(victim);
        while (room->is_character() || room->is_container() )
            room=environment(room);
	if( victim->is_ghost() ) {
		inv = all_inventory(victim);
		inv->owner_is_killed(killer);
		inv -= ({ 0 });
		i = sizeof(inv);
                while(i--) inv[i]->move(room);
		return 0;
	}
	corpse = new(CORPSE_OB);
	corpse->set_name( victim->name(1) + "的尸体", ({ "corpse" }) );
	corpse->set("long", victim->long()
		+ "然而，" + gender_pronoun(victim->query("gender")) 
		+ "已经死了，只剩下一具尸体静静地躺在这里。\n");
        corpse->set("age", victim->query("age"));
        corpse->set("gender", victim->query("gender"));
        corpse->set("victim_name", victim->name(1));
        corpse->set_weight( victim->query_weight() );
        corpse->set_max_encumbrance( victim->query_max_encumbrance() );
        corpse->move(room);
        // Don't let wizard left illegal items in their corpses.
        if( !wizardp(victim) ) {
                inv = all_inventory(victim);
                inv->owner_is_killed(killer);
                inv -= ({ 0 });
                foreach (object obj in inv){
                    if (!obj->move(corpse)) obj->move(room);
                    if(obj->is_character())
                    	obj->move(room);
              }
        }
        return corpse;
}
