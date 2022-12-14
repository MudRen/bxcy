// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
set_name("亚鲁迪巴", ({"aldebaran", "jin niu"}));
set("long", "金牛座。最勇猛凶悍的黄金圣斗士，但经常被招式诡异的对手打败，冥界之战中，与地暗星尼奥比同归于尽。\n");
set("gender","男性");	
set("title", "【"+HIY"黄金圣斗士"+NOR"】");
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
"亚鲁迪巴说道：不知何时能再见到雅典娜！\n"   	
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
        message_vision(YEL"$N挥挥衣袖，黄土向$n卷卷而来！\n",ob,me);


       if(random(3)==0)
                {
              message_vision(YEL"$N被飞来的黄土淹没了双眼！\n"NOR,me);
              me->add("eff_qi",-me->query("max_qi")/10);
              me->add("eff_jing",-me->query("max_jing")/10);
                }
        else
        message_vision(YEL"$N也鼓起嘴巴，把飞来的黄土纷纷吹落在地！\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(YEL"$N念念有词，一只斗牛向$n冲来！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(YEL"$N被斗牛的尖角转了个大窟窿！\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        }
        break;

        case 2:
        {

        message_vision(HIR"$N向$n射出了爱情之箭。\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIR"$N不但不躲避，反而迎了上去！\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        else
        message_vision(HIR"$N看准方向，躲开了$n的爱情之箭！\n"NOR,me,ob);
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
        message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第二宫：金牛宫!\n"NOR,users());
        ob->set("12gong/jinniu","done");
        ob->add("12gong/number",1);
ob->add("combat_exp", 500000);	
tell_object(ob,"你赢得了500000经验");	

        }
       ::die();
}
