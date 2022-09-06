// robber1 for dart

#include <ansi.h>
inherit NPC;
#include "mgb2.h"
void create()
{ 
        set_name("�ɹŽ���",({"menggu jiangling"}));
        set("long","����һλ�ַ���ԭ���ɹŽ��졣\n");
        set("gender", "����" );
        set("age", random(30)+14);
        
        set("vendetta/authority", 1);
        set("attitude", "peaceful");    
        set("bellicosity", 100000);
         set("max_qi", 2000);
         set("eff_qi", 2000);
         set("qi", 2000);
        set("max_jing", 1200);
        set("jing", 1200);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);
        set("shen_type", -10);
        set("combat_exp", 600000);

        set_skill("force", 180); 
        set_skill("unarmed", 180);
        set_skill("dodge", 180);
        set_skill("parry", 180);
	set("chat_chance_combat", 60);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.duan" :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.leiting" :),                

	}) );

     
        setup();
        carry_object(__DIR__"wandao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void do_change(object ob)
{
      object me;
      mapping hp_status, skill_status;
      string *sname;
      int i, temp;
      me = this_object();
//      ob = this_player(); 

      
      if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname  = keys(skill_status);
                temp = sizeof(skill_status);
                for(i=0; i<temp; i++) {
                        me->delete_skill(sname[i]);
                }
      }

      if ( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
                sname  = keys(skill_status);
                temp = skill_status[0];
                for(i=0; i<sizeof(skill_status); i++) {
		  if(sname[i]=="force")i++;
if (i>0 && i <sizeof(skill_status))
{

                  if (skill_status[sname[i]] >= temp)
                  { temp = skill_status[sname[i]];}
              }
        }
} else temp=(int)ob->query("force",1);

/*if (!ob->query_skill("force",1))
{
temp=10;
}else
temp=ob->query_skill("force",1);
*/        me->set_skill("wuhu-duanmendao", temp-random(50));
        me->set_skill("unarmed",temp-random(50));
        me->set_skill("xianglong-zhang",temp-random(50));
        me->set_skill("dodge", temp-random(50));
        me->set_skill("blade", temp-random(50));
        me->set_skill("parry", temp-random(50));

        me->map_skill("blade","wuhu-duanmendao");
        me->map_skill("parry","wuhu-duanmendao");
        me->map_skill("unarmed","xianglong-zhang");
        prepare_skill("unarmed", "xianglong-zhang");



/* copy hp */

me->set("qi",(ob->query("max_qi")*3/4));
me->set("eff_qi",(ob->query("max_qi")*3/4));
me->set("max_qi",(ob->query("max_qi")*3/4));
me->set("max_jing",(ob->query("max_jing")*3/4));
me->set("eff_jing",(ob->query("max_jing")*3/4));        
me->set("jing",(ob->query("max_jing")*3/4));
me->set("max_neili",(ob->query("max_neili")*3/4));
me->set("neili",(ob->query("max_neili")*3/4));

        hp_status = ob->query_entire_dbase();
if (!ob->query_skill_mapped("force"))
{
me->set("qi",(ob->query("max_qi")*2));
me->set("eff_qi",(ob->query("max_qi")*2));
me->set("max_qi",(ob->query("max_qi")*2));
me->set("max_jing",(ob->query("max_jing")*2));
me->set("eff_jing",(ob->query("max_jing")*2));        
me->set("jing",(ob->query("max_jing")*2));
}        me->set("str", hp_status["str"]+random(2));
        me->set("int", hp_status["int"]);
        me->set("con", hp_status["con"]+random(2));
        me->set("dex", hp_status["dex"]+random(10));
        me->set("combat_exp",hp_status["combat_exp"]*5/4);
            me->set("ygjg",ob);

}

void die()
{
            object ob;
              object robber;
              object room;
             ob=query_temp("last_damage_from");
if (!ob) return;
if (ob)
{
               room = environment(ob);   

                  if(ob->query_temp("start_job")==1)
                  {
                        ob->add_temp("killed_mgb",1);
                  }
                  else
                        ob->add_temp("help_killed",1);
            if( !ob->query_temp("job_over"))
{
                 switch( random(3) ) {
                        case 0:
                        message_vision(HIR"������������һ���ɹű�ʿ��\n" NOR,ob); 
                        robber=new(__DIR__"robber1");
                robber->do_change(ob);
                        robber->move(room);
                        robber->kill_ob(ob);
            ob->kill_ob(robber);
                        break;
                        case 1:
                        message_vision(HIR"������������һ���ɹŽ��졣\n" NOR,ob); 
                        robber=new(__DIR__"robber2");
                robber->do_change(ob);
                        robber->move(room);
                        robber->kill_ob(ob);
            ob->kill_ob(robber);
                        break;
                        case 2:
                        message_vision(HIR"������������һ���ɹŸ��֡�\n" NOR,ob); 
                        robber=new(__DIR__"robber3");
        if( (int)ob->query_skill("shenzhao-jing",1)>100)
{
robber=new(__DIR__"robber4");
}
        if( (int)ob->query("jiuyin-zhengong",1)>3500000)
{
robber=new(__DIR__"robber4");
}

        if( (int)ob->query_skill("anranxiaohun-zhang",1)>100)
{
robber=new(__DIR__"robber4");
}
        if( (int)ob->query("combat_exp",1)>3500000)
{
robber=new(__DIR__"robber4");
}
        if( (int)ob->query_skill("anranxiaohun-zhang",1)>100)
{
robber=new(__DIR__"robber4");
}
        if( (int)ob->query("combat_exp",1)>3500000)
{
robber=new(__DIR__"robber4");
}

                robber->do_change(ob);
                        robber->move(room);
                        robber->kill_ob(ob);
            ob->kill_ob(robber);
                        break;
                        }       
}
}
              message_vision("$N���ڵ��������˼��£������������"HIR"��Ѫ"NOR"�����ˣ�\n",this_object());
                   destruct(this_object());
            return;
}
