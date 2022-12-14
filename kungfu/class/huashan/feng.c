// feng.c 风清扬
inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
    set_name("风清扬", ({ "feng qingyang", "feng", "qingyang" }));
    set("nickname", "剑宗祖师");
    set("long", 
"他就是华山剑宗的长老风清扬。他身材瘦长，眉宇间一直笼罩着一股淡淡的忧伤\n"
"神色，显然对当年的剑宗气宗之争一直难以忘怀。\n");
    set("gender", "男性");
    set("age", 68);
    set("attitude", "peaceful");
    set("shen_type", 1);
    set("str", 60);
    set("int", 80);
    set("con", 80);
    set("dex", 230);
    
    set("qi", 5800);
    set("max_qi", 5800);
    set("jing", 5600);
    set("max_jing", 5600);
    set("neili", 50000);
    set("max_neili", 20000);
    set("jiali", 300);
    set("combat_exp", 11059200);
    set_skill("force", 400);
    set_skill("blade", 400);
    set_skill("dodge", 480);
    set_skill("parry", 400);
    set_skill("sword", 400);
    set_skill("unarmed", 400);
    set_skill("zixia-shengong", 450);
    set_skill("poyu-quan", 470);
    set_skill("fanliangyi-dao", 480);
    set_skill("huashan-jianfa", 400);
    set_skill("hunyuan-zhang", 470);
    set_skill("dugu-jiujian", 400);
    set_skill("huashan-shenfa",460);
    set_skill("literate", 200);
    map_skill("force", "zixia-shengong");
    map_skill("dodge", "huashan-shenfa");
    map_skill("parry", "dugu-jiujian");
    map_skill("sword", "dugu-jiujian");
    map_skill("blade", "fanliangyi-dao");
    map_skill("unarmed", "hunyuan-zhang");
    create_family("华山派", 12, "弟子");
    set("chat_chance_combat", 60);
    set("chat_msg_combat", ({
        (: perform_action, "sword.poqi" :),
        (: perform_action, "sword.pozhang" :),
        (: perform_action, "sword.pojian" :),
        (: exert_function, "recover" :),
    }) );
    set("inquiry", ([
     "独孤九剑":(:ask_me:),
     ]) );;
    setup();
    carry_object("/clone/misc/cloth")->wear();
    carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{
    if (mapp(ob->query("family"))  &&   (string)ob->query("family/family_name") != "华山派")
    {
        command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜老朽呢？");
        return;
    }
    if (((int)ob->query_skill("sword",1) < 150) || ((int)ob->query_skill("huashan-jianfa",1) < 150))
    {
        command("say 我看" + RANK_D->query_respect(ob) + "的华山剑法还没学到家吧。");
        return;
    }
    if (((int)ob->query_skill("force",1) < 150) || ((int)ob->query_skill("zixia-shengong",1) < 130))
    {
        command("say 我看" + RANK_D->query_respect(ob) + "的紫霞神功还没学到家吧。");
        return;
    }
    if (((int)ob->query_skill("dodge",1) < 150) || ((int)ob->query_skill("huashan-shenfa",1) < 150))
    {
        command("say 我看" + RANK_D->query_respect(ob) + "的华山身法还没学到家吧。");
        return;
    }
    if ( (int)ob->query_skill("literate",1) < 160)
    {
        command("say 我看" + RANK_D->query_respect(ob) + "的读书识字还没学到家吧。");
        return;
    }
    if ((int)ob->query("shen") < 100000)
    {
        command("say 我华山派乃是堂堂名门正派，对弟子要求极严。");
        command("say 在德行方面，" + RANK_D->query_respect(ob) +
            "是否还做得不够？");
        return;
    }
    if ((int)ob->query_int() < 41) {
        command("say 依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合学我独孤九剑？");
        return;
    }
    command("say 好吧，我就收下你了。");
    command("recruit " + ob->query("id"));
    if((string)ob->query("class") != "swordsman")
        ob->set("class", "swordsman");
}
string ask_me()
{
    object me,ob;

    me = this_player();
    if ((string)me->query("family/master_id")==(string)this_object()->query("id"))
    {
         if (me->query("fengset")) 
         	return "你竟然能领悟独孤九剑的精华,今后武林正义就要靠你了。";
         if (!me->query_temp("marks/fengseto"))
         	return "「独孤九剑」？这套剑法博大精深,你要好好领悟。";
         switch (random(10))
         {
              case 0:
              		 me->delete_temp("marks/fengseto");
                   me->set_temp("marks/fengsett",1);
                   return "当年独孤大侠在剑冢留下了些秘密,你不防去瞧瞧。";
              default:
                   return "「独孤九剑」？这套剑法博大精深,你要好好领悟。";
         }
    }
    else return RANK_D->query_respect(this_player()) + "不是我的徒弟吧？";
}
