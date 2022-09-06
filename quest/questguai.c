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

//���³������ֵ�����
   guaikeysa=keys(guainame);
   s1=random(sizeof(guaikeysa));
   if (s1==0 || s1==sizeof(guaikeysa)) s1=0; 
   guaikeysb=keys(guainame[guaikeysa[s1]]);
   s2=random(sizeof(guaikeysb));
   if (s2==0 || s2==sizeof(guaikeysa)) s2=0;
   guaiobname=guaikeysb[s2];
   guaiobid=guainame[guaikeysa[s1]][guaikeysb[s2]];
   set_name(guaiobname,guaiobid); 

//�����������,

   set("gender","����");
   set("env/wimpy", 30);
   set("per",10);
   set("age",60);
   set("attitude", "friendly");
   set("no_suck",1);
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
//����ôҲ������?
void heart_beat()
{
   
   int qi,effqi,maxqi;
   maxqi=(int)this_object()->query_temp("maxqi");   
   effqi=(int)this_object()->query("eff_qi");
qi=(int)this_object()->query("qi");
if(!me->is_fighting())
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
   message_vision(MAG"$N�ۼ����������һ�������ˡ�\n"NOR,
          this_object());
   destruct (this_object());
}


void die ()
{
   int pot,exp,turnd;
    object killerob,me,baoshi;
    mixed questob;
    string username;
    me=this_object();
    killerob=me->query_temp("last_damage_from");             
    questob=(object)me->query_temp("player"); 
username=me->query_temp("killername");
if(find_player(username))
	questob->delete_temp("kill");   	
    if (!killerob) 
    {   
        message_vision("$N�ҽ�һ�������ˡ�\n",this_object());
         tell_object(questob,"��õ�����㾭������Ǳ�ܣ�\n"NOR);
        destruct(me);
        return;    
    }
    else if (killertemp)
     {
        if (killertemp!=killerob)
          {
             message_vision("$N�ҽ�һ�������ˡ�\n",this_object());
             tell_object(questob,"��õ�����㾭������Ǳ�ܣ�\n"NOR);
             destruct(me);
             return;    
          }
     } 
else if(!questob)
{
message_vision("$N�ҽ�һ�������ˡ�\n",this_object());	
destruct(me);	
return; 	
}
    if (killerob->query("id")!=questob->query("id"))
    {  
       message_vision("$N�ҽ�һ�������ˡ�\n",this_object());
        tell_object(questob,"��õ�����㾭������Ǳ�ܣ�\n"NOR);
       destruct(me);
       return; 
    }
/*
    switch(random(4))
     {
       case 1: message_vision("$N�ҽ�һ�������ˡ�\n",this_object());break;
       case 2: message_vision("$N�ҽ�һ�������ˡ�\n"
               questob,this_object());break;
       case 3: message_vision("$N�ҽ�һ�������ˡ�\n"
               questob,this_object());break;
       default :message_vision("$N�ҽ�һ�������ˡ�\n",questob,this_object());
     }
*/
    message_vision("$N�ҽ�һ�������ˡ�\n",this_object());
     pot=me->query_temp("killrewardpot")/4;
    exp=me->query_temp("killrewardexp");
    turnd=questob->query_temp("turn");
if (exp>10000)
exp = 10000;
if(questob->query_temp("baoshi")){
exp +=exp;
	if(turnd==10)
		if(random(30)<1){
		switch (random(5))
		{
			case 0:baoshi=new("/clone/baoshi/bs_b1"); break;
			case 1:baoshi=new("/clone/baoshi/bs_g1"); break;
			case 2:baoshi=new("/clone/baoshi/bs_r1"); break;
			case 3:baoshi=new("/clone/baoshi/bs_y1"); break;
			default:baoshi=new("/clone/baoshi/bs_z1");
			}
		tell_object(questob,"��õ���һ"+baoshi->query("unit")+baoshi->query("name")+"!\n");
		baoshi->move(questob);
		}
		if(turnd>0&&turnd<10)
			if(random(10)<1){
		switch (random(5))
		{
			case 0:baoshi=new("/clone/weapon/yuenv"); break;
			case 1:baoshi=new("/d/binghuodao/npc/obj/killdragon"); break;
			case 2:baoshi=new("/d/mingjiao/obj/heiyu"); break;
			case 3:baoshi=new("/d/city/obj/yangjing"); break;
			default:baoshi=new("/d/city/obj/jinchuang");
			}
		tell_object(questob,"��õ���һ"+baoshi->query("unit")+baoshi->query("name")+"!\n");
		baoshi->move(questob);
		}
		questob->delete_temp("baoshi");
	}
    questob->add("potential",pot);
    questob->add("combat_exp",exp);
    tell_object(questob,"��õ���"+HIW+
     chinese_number(exp)+NOR"�㾭���"+HIW+chinese_number(pot)+NOR"��Ǳ��\n");
    destruct(me);
   return;
}
//�����ñ��˰�æ���ι�   
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
         {  if(random(40)>20){     
         message_vision(HIR"$N��ݺݵض���$n�����һ������Ȼ���������ˣ����첻����������������\n"NOR
         ,this_object(),this_player());
          this_object()->kill_ob(this_player());  
          command("follow "+this_player()->query("id"));}
         else this_object()->command("? "+this_player()->query("id"));
          set_temp("firstsee",1);
          
          }
         set_heart_beat(1);
         if(random(40)<20) this_object()->kill_ob(this_player());
       
        
         
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



