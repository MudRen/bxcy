// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
set_name("��³�ϰ�", ({"aldebaran", "jin niu"}));
set("long", "��ţ�����������׺��Ļƽ�ʥ��ʿ������������ʽ����Ķ��ִ�ܣ�ڤ��֮ս�У���ذ�����±�ͬ���ھ���\n");
set("gender","����");	
set("title", "��"+HIY"�ƽ�ʥ��ʿ"+NOR"��");
        set("no_get",1);
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
set("no_suck",1);	
set("combat_exp",80000000);	
        set("chat_chance",20);
        set("chat_msg", ({
"��³�ϰ�˵������֪��ʱ���ټ����ŵ��ȣ�\n"   	
        }));
        set_skill("dodge", 310);
        set("attitude", "friendly");
        set_skill("force", 310);
        set_skill("parry", 310);
        set_skill("unarmed", 310);
        set_skill("sword", 310);
        set_skill("westsword",310);
        set_skill("boxing",310);
        set_skill("balei",310);
        set_skill("spells",310);
        set_skill("jinniu", 310);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","jinniu");
        map_skill("dodge","balei");
set("neili", 5000000);	
set("max_neili",1000000);   	
set("max_jingli",1000000);   	
set("jingli",2000000);   	
set("max_jing", 500000);	
set("max_qi", 1000000);	

        setup();
        carry_object(__DIR__"obj/jn_cloth")->wear();
        carry_object(__DIR__"obj/westsword")->wield();
}
 
void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
        if( ! me ) return ;
   if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }                               

if (me->query("combat_exp")>1000000)set("combat_exp",(me->query("combat_exp")/5)*6);if (me->query("str")>25) set("str",me->query("str"));if (me->query("con")>25) set("str",me->query("con"));if (me->query("dex")>25) set("str",me->query("dex"));if (me->query("int")>25) set("str",me->query("int"));	
set("neili",me->query("neili")*3);
set("jiali",me->query("jiali")*5);
     switch(random(6))
     {        
        case 0:
        {
        message_vision(YEL"$N�ӻ����䣬������$n��������\n",ob,me);


       if(random(3)==0)
                {
              message_vision(YEL"$N�������Ļ�����û��˫�ۣ�\n"NOR,me);
              me->add("eff_qi",-me->query("max_qi")/10);
              me->add("eff_jing",-me->query("max_jing")/10);
                }
        else
        message_vision(YEL"$NҲ������ͣ��ѷ����Ļ����׷״����ڵأ�\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(YEL"$N�����дʣ�һֻ��ţ��$n������\n",ob,me);

                if(random(3)==0)

                {
              message_vision(YEL"$N����ţ�ļ��ת�˸��������\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        }
        break;

        case 2:
        {

        message_vision(HIR"$N��$n����˰���֮����\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIR"$N��������ܣ�����ӭ����ȥ��\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        else
        message_vision(HIR"$N��׼���򣬶㿪��$n�İ���֮����\n"NOR,me,ob);
        }
        break;

  }
        if( random(30) == 5 )

        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{

        object ob = query_temp("my_killer");

        if((ob&&ob->query("12gong/baiyang")=="done") && (ob&&ob->query("12gong/jinniu")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"���ƽ�ʮ�������ŵ���(Ya dian na):"+ob->name()+
        "�����˵ڶ�������ţ��!\n"NOR,users());
        ob->set("12gong/jinniu","done");
        ob->add("12gong/number",1);
ob->add("combat_exp", 500000);	
tell_object(ob,"��Ӯ����500000����");	

        }
       ::die();
}
