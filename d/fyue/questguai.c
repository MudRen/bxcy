#include <ansi.h>;
inherit "/quest/npcskill";	
#include <command.h>;
#include "/quest/name.h";	

//1,moon,2,fangcun,3,putuo,4,hell,5,longgong,6,xueshan
//7,wudidong

object me=this_object(),questob,killertemp;
string username;
string guaiobname,*guaikeysa,*guaikeysb,*guaiobid;
int s1,s2;

void create()
{  
   int level,chooseguai;
   object guai;   
   guai=this_object();

//以下程序分配怪的名字
   guaikeysa=keys(guainame);
   s1=random(sizeof(guaikeysa));
   if (s1==0 || s1==sizeof(guaikeysa)) s1=0; 
   guaikeysb=keys(guainame[guaikeysa[s1]]);
   s2=random(sizeof(guaikeysb));
   if (s2==0 || s2==sizeof(guaikeysa)) s2=0;
   guaiobname=guaikeysb[s2];
   guaiobid=guainame[guaikeysa[s1]][guaikeysb[s2]];
   set_name(guaiobname,guaiobid); 

//分配名字完成,

   set("gender","男性");
   set("env/wimpy", 30);
   set("per",10);
   set("age",60);
   set("attitude", "friendly");
   set_temp("apply/armor",600);
   set("chat_chance",10);
   set("chat_msg",({
   (:random_move:)}));
   set("chat_chance_combat",random(90));
   setup();
   
}
int setguaiskill(int chooseguai,int level,object guai)
{  
   set_std_skills(level,guai);
   switch (chooseguai)
    {
      case 1:set_moon_guai(level,guai);carry_moon_weapon();break;
      case 2:set_fangcun_guai(level,guai);carry_fangcun_weapon();break;
      case 3:set_putuo_guai(level,guai);carry_putuo_weapon();break;
      case 4:set_hell_guai(level,guai);carry_hell_weapon();break;
      case 5:set_longgong_guai(level,guai);carry_longgong_weapon();break;
      case 6:set_xueshan_guai(level,guai);carry_xueshan_weapon();break;
      default:set_wudidong_guai(level,guai);carry_wudidong_weapon();break;
    }
}
//怪怎么也会疗伤?
void heart_beat()
{
   
   int qi,effqi,maxqi;
   maxqi=(int)this_object()->query_temp("maxqi");   
   effqi=(int)this_object()->query("eff_qi");
   qi=query("qi");
   if (effqi<maxqi) command("exert heal");
   if (qi<(int)(effqi*2/3)) command("exert recover");
   ::heart_beat();
}

int check_time()
{
   if (!query_temp("appear")) 
     {
       set_temp("appear",1);
       call_out("check_time",900);
       return 1;
     }
   if (me->is_fighting()) 
     {
       call_out("check_time",600);
       return 1;
     }
   remove_call_out("check_time");
   message_vision(MAG"$N窜了几窜，化成一道青烟消失了。\n"NOR,
          this_object());
   destruct (this_object());
}


void die ()
{
    int pot,exp;
    object killerob,me;
    mixed questob;
    me=this_object();
    killerob=me->query_temp("last_damage_from");
                    
    questob=(object)me->query_temp("player"); 
    questob->set_temp("kill",0); 
    if (!killerob) 
    {   
        message_vision("$N惨叫一声，死了。\n",this_object());
        tell_object(questob,HIY"你得到了零点潜能和零点经验！\n"NOR);
        destruct(me);
        return;    
    }
    else if (killertemp)
     {
        if (killertemp!=killerob)
          {
             message_vision("$N惨叫一声，死了。\n",this_object());
             tell_object(questob,HIY"你得到了零点潜能和零点经验！\n"NOR);
             destruct(me);
             return;    
          }
     } 
    if (killerob->query("id")!=questob->query("id"))
    {  
       message_vision("$N惨叫一声，死了。\n",this_object());
       tell_object(questob,HIY"你得到了零点潜能和零点经验！\n"NOR);
       destruct(me);
       return; 
    }
/*
    switch(random(4))
     {
       case 1: message_vision("$N惨叫一声，死了。\n",this_object());break;
       case 2: message_vision("$N惨叫一声，死了。\n"
               questob,this_object());break;
       case 3: message_vision("$N惨叫一声，死了。\n"
               questob,this_object());break;
       default :message_vision("$N惨叫一声，死了。\n",questob,this_object());
     }
*/
    message_vision("$N惨叫一声，死了。\n",this_object());
    pot=me->query_temp("killrewardpot");
    exp=me->query_temp("killrewardexp");
exp=exp*4;
pot=pot*4;
    questob->add("potential",pot);
    questob->add("combat_exp",exp);
    tell_object(questob,HIW"你得到了"+chinese_number(pot)+"点潜能和"+
     chinese_number(exp)+"点经验。\n"NOR);
    destruct(me);
   
}
//不能让别人帮忙打晕怪   
void unconcious()
{
  killertemp=query_temp("last_damage_from");
  ::unconcious();
}
void init()
{
    if (is_busy()) return;
    add_action("do_drive","drive");
    username=query_temp("killername");
    if ((int)environment(me)->query("no_fight")) return; 
    if (this_player()->query("id")==username)
     { 
       if (query_temp("firstsee")==0||!query_temp("firstsee"))
         {       
          message_vision(HIR"$N恶狠狠地盯着$n，赫然叫一声：「好大的胆子，竟敢奉老贼的命令来杀我！」\n"NOR
         ,this_object(),this_player());
          set_temp("firstsee",1);
          command("follow "+this_player()->query("id"));
          }
         set_heart_beat(1);
         this_object()->kill_ob(this_player());   
         
     }   
}

int do_drive(string arg)
{
    mapping exits;
    string *dirs;
    int size;
    if (arg==(string)this_object()->query("id"))
      {
        if (environment()->query("no_fight"))
         {
           exits=environment()->query("exits");      
           dirs=keys(exits);
           size=sizeof(dirs);
           if (size>0)
             { 
              this_player()->command("follow "+this_object()->query("id"));
              command("go "+dirs[random(size)]);
              return 1;
             }
          }
       }
     return 0;
}



