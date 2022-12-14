// daoshi.c  护山道士
// modified by snow@jhfy
#include <ansi.h> 
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("护山道士", ({"dao shi"}));
        set("gender", "男性");
        set("age", 25);
        set("long",
             "他是全真教的护山道士，专门守护山门。 \n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 17);
        set("int", 14);
        set("con", 17);
        set("dex", 14);

        set("chat_chance", 1);
        set("chat_msg", ({
          "护山道士说道：“我全真教乃名门正教，可不能让江湖中人小看了。”\n",          "护山道士说道：“活死人墓千万别乱闯，会有生命危险的。”\n",
       "护山道士说道：“要说我全真教长春真人的武功，嘿嘿，弟子可钦佩得很呀。”\n",
        (: random_move :),
        }));

        set("qi", 450);
        set("max_qi", 450);
        set("jing", 350);
        set("max_jing", 350);
        set("neili", 200);
        set("max_neili", 200);
        set("jiali", 20);
        
        set("combat_exp", 100000);
        set("score", 3000);
 
        set_skill("force", 90);             // 基本内功
        set_skill("tiangang-zhengqi", 90);    //天罡正气
        set_skill("unarmed", 90);           // 基本拳脚
        set_skill("kongming-quan", 90);    //空明拳 
        set_skill("dodge",90);               // 基本躲闪
        set_skill("qixing-huanwei", 80);        //七星换位
        set_skill("parry",90);             // 基本招架
        set_skill("sword", 90);             // 基本剑法
        set_skill("quanzhen-jianfa", 90);        //全真剑法
        set_skill("literate",30);           //读书写字  
  
        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "kongming-quan");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");
        
        create_family("全真教",4, "第子");
        setup();
        
        carry_object("/d/quanzhen/npc/obj/changjian")->wield();
       carry_object("/d/quanzhen/npc/obj/yellowrobe")->wear();
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
 void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say(CYN"护山道士问道：这位" + RANK_D->query_respect(ob)
                                + "是来拜师的吗？\n"NOR);
                        break;
                case 1:
                        say(CYN"护山道士说道：这位" + RANK_D->query_respect(ob)
                                + "欢迎你到全真来。\n"NOR);
                        break;
        }
}

