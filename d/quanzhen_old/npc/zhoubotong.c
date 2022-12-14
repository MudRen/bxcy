inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("周伯通", ({"master zhou","zhou botong", "zhou", "botong"}));
        set("nickname", "老顽童");
        set("gender", "男性");
        set("age", 70);
        set("long",
             "他白发白须，满脸红光，笑容可掬。\n"
                "他就是闻名天下，玩世不恭的老顽童。\n"
                "听说他被困在了桃花岛，不知怎么到\n"
                "这里来了,也许你在做梦吧。\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 35);
        set("int", 30);
        set("con", 35);
        set("dex", 30);

        set("chat_chance", 1);
        set("chat_msg", ({
                "周伯通说道：“黄老邪这混蛋为了《九阴真经》，关了我十五年了。”\n",
                "周伯通叹了口气道：“我答应师兄不练《九阴真经》的，但不学又打不过黄老邪。”\n",
             "周伯通喃喃道：“我一定要把《九阴真经》的武功给忘了。” \n",
//              (: random_move :),
        }));
//      set("inquiry", ([
//              "九阴真经":"师兄死后，就有我保管，下卷以毁，只剩上卷了。\n",
//              "。\n",
//      ]));

        set("qi", 5500);
        set("max_qi", 5500);
        set("jing",2500);
        set("max_jing",2500);
        set("neili", 5500);
        set("max_neili", 5500);
        set("jiali", 200);
        
        set("combat_exp", 20000000);
        set("score", 300000);
         
        set_skill("force", 500);             // 基本内功
        set_skill("tiangang-zhengqi", 500);    //天罡正气
        set_skill("unarmed", 500);           // 基本拳脚
        set_skill("kongming-quan", 500);       //空明拳 
        set_skill("dodge", 500);             // 基本躲闪
        set_skill("qixing-huanwei",500);        //七星换位
        set_skill("parry", 500);             // 基本招架
        set_skill("sword", 500);             // 基本剑法
        set_skill("quanzhen-jianfa", 500);        //天罡剑法 
        set_skill("taoism",500);           //道学心法  
        set_skill("literate",500);           //读书写字
       
        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "kongming-quan");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");
        
        create_family("全真教", 1, "元老");
        setup();
        
        carry_object("/d/quanzhen/obj/changjian")->wield();
        carry_object("/d/quanzhen/obj/greyrobe")->wear();
}
void attempt_apprentice(object ob)
{
        if ((int)ob->query_str() < 35 || (int)ob->query_con() < 20) {
                command("say 当道士需要能吃苦耐劳，六根清静依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合当道士？");
                return;
        }
        if ((string)ob->query("family/family_name") != "" &&
            (string)ob->query("family/family_name") != "全真教") {
                command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜本真人呢？");
                return;
        }
       if ((int)ob->query_skill("tiangang-zhengqi", 1) < 180) {
                command("say 我全真教乃内家武功，最重视内功心法。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在天罡正气上多下点功夫？");
                return;
       }
       if ((int)ob->query_skill("quanzhen-jianfa", 1) < 220) {
                command("say 我全真教剑法扬名天下，天下无双。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在全真剑法上多下点功夫？");
                return;
       }
       command("chat 哈哈哈哈！！！！");
       command("say 想不到我老顽童还能遇到如此智质的徒弟，一生绝学也不至于失传。");
        command("recruit " + ob->query("id"));
        
}





















































