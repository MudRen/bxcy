// migong lev1

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name("野猪", ({ "ye zhu", "pig" , "zhu" }));
      
          set("race", "野兽");
       set("long",
"一头凶猛长着棕毛的野猪。\n");
               set("attitude", "aggressive");
            
    set("vendetta/authority",1);

set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
set("max_qi",50000+random(5000));	
set("max_jing",50000+random(5000));	
  set("max_sen",500+random(500));
  set("max_mana",500+random(500));
  
      set("dex",30);
     set("str" ,30);
       
    set("age", 5);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

set("combat_exp", 50000000);	
                  
        set_temp("apply/attack", 40);
        set_temp("apply/damage", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/defence",50);

   setup();

        

}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        call_out("hunting",1);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",1);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
if (!me) return;
        message_vision(WHT"$N一声悲鸣,躺倒在地。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
if((int)me->query("combat_exp") < 50000000)   {	
message("vision", me->name() + "成功打死猎物增加了1380经验和20潜能。\n", me);	
me->add("combat_exp",1380);	
        me->add("potential",20);
        destruct(ob);
        }
              me->add("score",1);
               destruct(ob);
        return;
}
