inherit NPC;
#include "star.h"
void get_date();
 
void create()
{
set_name("������", ({"mu","bai yang"}));   	
set("long", "��˵�еİ��򹬻ƽ�սʿ���ػ��Ű�����,�����������ǻ۵Ļƽ�ʥ��ʿ�����ó�����ʥ�¡�	��ʮ����֮ս�У�������ʸ����������߸С�ڤ��֮ս�У�������ǿ��ڤ��ʿ֮һ������	�ǵİͱ�¡�� \n");	
        set("gender","����");
set("title", "��"+HIY"�ƽ�ʥ��ʿ"+NOR"��");	
        set("no_get",1);
        set("age",37);
        set("attitude", "friendly");
        set("con",30);
        set("per",30);
        set("str",25);
set("no_suck",1);	
set("jingli", 2000000);  	
        set("int",35);
set("combat_exp",200000000);     	
        set("chat_chance",20);
        set("chat_msg", ({
"������˵������֪��ʱ���ټ����ŵ��ȣ�\n"   	
        }));
set("max_neili", 1000000);  	
set("max_jingli", 1000000);  	
set("neili", 2100000);  	
set("max_qi", 1000000); 	
set("max_jing", 500000);       	
set_skill("dodge", 2000);
          set_skill("force", 300);
          set_skill("parry", 300);
          set_skill("unarmed", 300);
          set_skill("sword", 300);
         set_skill("westsword",300);
          set_skill("boxing",300);
         set_skill("baiyang", 300);
        set_skill("baiyang", 300);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","baiyang");

        setup();
        carry_object(__DIR__"obj/by_cloth")->wear();
        carry_object(__DIR__"obj/westsword")->wield();
}
 
void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
    
     if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }
     if( me->is_ghost() )
     {
     remove_call_out("check");
     return;
     }
if (me->query("combat_exp")>1000000)set("combat_exp",(me->query("combat_exp")/5)*6);        	
set("neili",me->query("neili")*3);	
set("jiali",me->query("jiali")*3);              	
if (me->query("str")>25) set("str",me->query("str"));
if (me->query("con")>25) set("con",me->query("con"));
if (me->query("int")>25) set("int",me->query("int"));
if (me->query("dex")>25) set("dex",me->query("dex"));
     switch(random(6))
     {        
        case 0:
        {
        message_vision(HIR"$N˫��һ�ӣ�һ���һ�ֱ��$n��ȥ��\n",ob,me);

        if(random(2))
        
                {
              message_vision(HIR"$N��$n���һ��ո���ͷ������\n"NOR,me,ob);
              me->add("eff_qi",-me->query("eff_qi")/10);
              me->add("eff_jing",-me->query("eff_jing")/10);
                }
        else
        message_vision(HIR"$N����׾ٵĶ����$n�Ĺ�����\n"NOR,me,ob);
        }
        break;


        case 1:
        {

        message_vision(HIR"$N�������ѣ���ʱһֻ������$nֱ���ȥ��\n",ob,me);

        if(random(2))

                {
              message_vision(HIR"$N������ײ�˸���������\n"NOR,me);
              me->add("eff_qi",-2*me->query("eff_qi")/10);
              me->add("eff_jing",-2*me->query("eff_jing")/10);
                }
        else
        message_vision(HIR"$N���Ű�����һ����ͣ������ԹԴ��Ա��￪�ˣ�\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIR"$N���г������˶���ޱȣ�ֱ��$n����\n",ob,me);

        if(random(2))

                {
              message_vision(HIR"$N��ʱѪ����ע�����Ⱦ����ȫ��\n"NOR,me);
              me->add("eff_qi",-3*me->query("eff_qi")/10);
me->add("jing",-3*me->query("eff_jing")/10);    	
                }
        else
        message_vision(HIR"$N˳�Ž��ķ�������Ծ�𣬶��������һ����\n"NOR,me);
        }
        break;

  }
 //       if( present(me,environment()) )  return ;

        if( random(30) == 5 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{

        object ob = query_temp("my_killer");

        if(ob&&ob->query("12gong/baiyang")!="done")
        {
        ob->start_busy(3);
        message("chat",HIY+"���ƽ�ʮ�������ŵ���(Ya dian na):"+ob->name()+
        "������"+environment(ob)->query("short")+"\n"NOR,users());
        ob->set("12gong/baiyang","done");
        ob->add("12gong/number",1);
ob->add("combat_exp", 500000);	
tell_object(ob,"��Ӯ����500000����");	
       
        }
       ::die();
}
