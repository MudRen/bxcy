// migong lev1

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name("狐狸", ({ "fox", "huli" }));
      
          set("race", "野兽");
       set("long",
"一只狡猾的狐狸。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "头部", "身体", "前爪", "后抓", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
set("max_qi",50000+random(5000));	
set("max_jing",50000+random(5000));	
  set("max_sen",500+random(500));
  set("max_mana",500+random(500));
  
      set("dex",30);
     set("str" ,20);
       
    set("age", 5);

        set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

set("combat_exp", 50000000);	
                  
        set_temp("apply/attack", 50);
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
        
        message_vision(WHT"$N一声惨叫,倒在地上，翻了个跟头就不动弹了。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
if((int)me->query("combat_exp") < 50000000)   {	
message("vision", me->name() + "成功打死猎物增加了400经验和20潜能。\n", me);	
me->add("combat_exp",400);	
me->add("potential",20);	
        destruct(ob);
        }
              me->add("score",1);
               destruct(ob);
        return;
}
