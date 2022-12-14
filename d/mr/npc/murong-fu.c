inherit NPC;
inherit F_MASTER;
string ask_bo();
string ask_skill();
string ask_wang();
string ask_dan();
string ask_dan1();
string ask_ge();
string ask_sword(); 
string ask_book();
string ask_book2();
object ob = this_object();

void create()
{
        set_name("慕容复",({"murong fu","murong","fu"}));
        set("title","姑苏慕容公子");
        set("nick","以彼之道 还施彼身");
        set("long", 
              "他就是天下号称以彼之道，还彼之身的姑苏慕容复。\n"
              "他脸上带着不可一世的笑容。\n");
        set("age", 27);
         set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 3500);
        set("max_jing", 3000);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 0);
        set("combat_exp", 5000000);
        set("score", 50000);                
        set("chat_msg_combat", ({
          (: perform_action, "parry.xingyi" :)
}));

        set_skill("dodge",280);
        set_skill("unarmed",280);
        set_skill("force", 270);
        set_skill("canhe-zhi", 260);
        set_skill("murong-jianfa",260);       
        set_skill("shenyuan-gong", 260);
        set_skill("yanling-shenfa", 260);   
        set_skill("xingyi-zhang",270);
        set_skill("douzhuan-xingyi", 280);
        set_skill("parry", 280);
        set_skill("sword", 160);
        set_skill("literate", 170);
        set_skill("murong-daofa", 160);
        set_skill("blade",160);
        
        map_skill("blade", "murong-daofa");
        map_skill("force", "shenyuan-gong");
        map_skill("dodge", "yanling-shenfa");
        map_skill("unarmed", "xingyi-zhang");
        map_skill("parry", "douzhuan-xingyi");
        map_skill("sword", "murong-jianfa");

        prepare_skill("finger","canhe-zhi");
        prepare_skill("strike","xingyi-zhang");
        
        create_family("姑苏慕容",2,"弟子");

        set("inquiry", 
                ([
                        "name" : "我就是以彼之道，还施彼身的姑苏慕容复。\n",
                        "here" : "这里是大名鼎鼎的燕子坞，难道你没有听说过？\n",
                        "rumors" : "家父突染恶疾，我连他老人家最后一面都没见到，此事顶有蹊跷！\n",
                        "姑妈" : "我的姑妈住在曼佗罗山庄，那里有闻名天下的娘缳玉洞。\n",
                        "还施水阁" : (: ask_ge :),
                        "慕容博" : (: ask_bo :),
                        "领悟" : (: ask_book :),
                        "王语嫣" : (: ask_wang :),
                        "宝剑" : (: ask_sword :),
                        "斗转星移"  : (: ask_skill :),
                        "归元丹" : (: ask_dan :),
                        "玉露清新散" : (: ask_dan1 :),
                        "图解" : (: ask_book2 :)
                ]));
        set("dan_count", 2);
        set("book_count",1);
        set("book2_count" ,1);
        set("dan1_count", 5);
        setup();
        
    carry_object("/d/city/obj/gangjian")->wield();
}

void attempt_apprentice(object ob)
{
        if (ob->query_skill("parry", 1) < 120) {
                command("say 我姑苏慕容以彼之道、还施彼身对招架要求甚高，小兄弟似乎不宜学习。");
    command("say " + RANK_D->query_respect(ob) + "的功力不够，还是请回吧。");
                return;
        }

        if (ob->query_skill("shenyuan-gong", 1) < 100) {
                command("say 我姑苏慕容以彼之道、还施彼身对内功心法要求甚高，小兄弟似乎不宜学习。");
    command("say " + RANK_D->query_respect(ob) + "的功力不够，还是请回吧。");
                return;
        }

  command("say 嗯，看你还是个学武的料，我就收下你吧！");
        command("say 苍天在上，让我姑苏慕容又得一良材，为复兴我大燕多了一份力量。");
        command("chat* 朗声说道：公子我又收一良材，大燕兴复指日可待啦！");
        command("chat* haha"); 
        command("recruit " + ob->query("id"));
        ob->set("title","姑苏慕容第三代弟子");
}

string ask_bo()
{
        mapping fam; 
        if (!(fam = this_player()->query("family")) 
           || fam["family_name"] != "姑苏慕容")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
                return "先父前些日子突染恶疾，已经仙逝了。\n";
         }

string ask_wang()
{
mapping fam;
        if (!fam = this_player()->query("family") || fam["family_name"] !="姑苏慕容")
        return RANK_D->query_respect(this_player()) +
        "与本派素无来往，不知此话从何谈起？";
        return "语嫣是我表妹，一直被姑妈管的很严，连我都很长时间没有见到她了。\n";
}

string ask_skill()
{
mapping fam; 
        if (!(fam = this_player()->query("family"))
           || fam["family_name"] != "姑苏慕容")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
                return "斗转星移是我慕容家的绝学，最是注重招架和身法。\n";

}

string ask_ge()
{
mapping fam; 
        if (!(fam = this_player()->query("family"))
           || fam["family_name"] != "姑苏慕容")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
                return "还施水阁是我慕容收藏天下秘籍之所在，在我的书.....\n";
}

string ask_sword()
{
mapping fam; 
        if (!(fam = this_player()->query("family"))
           || fam["family_name"] != "姑苏慕容")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
                return "碧玉剑是老爷子仙逝后的遗物，我让阿朱姑娘收起来好好保管！\n";
}

string ask_book()
{
        object ob;
        mapping fam; 
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "姑苏慕容")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
        if (!(fam = this_player()->query("family")) || fam["master_name"] != "慕容复")
        return RANK_D->query_respect(this_player()) + 
                "功力不够，何以谈及领悟？";

        if (  present("douzhuan xingyi", this_player()) )
                return RANK_D->query_respect(this_player()) + 
                "你现在身上不是有斗转星移的武籍了嘛，怎么又来要了？ 真是贪得无餍！";

        if (query("book_count") < 1) return "对不起，斗转星移的武籍已经被别人要走了。";

        ob = new(__DIR__"obj/shu1");
        ob->move(this_player());

        add("book_count", -1);

        message_vision("$N得到一本斗转星移的武功秘籍。\n",this_player());
        return "好吧，看你为慕容家忠心耿耿，这本书就赐于你吧。";

}

string ask_book2()
{
        object ob;
        mapping fam; 
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "姑苏慕容")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
        if (!(fam = this_player()->query("family")) || fam["master_name"] != "慕容复")
        return RANK_D->query_respect(this_player()) + 
                "功力不够，何以谈及领悟？";
        if ( (int)this_player()->query_skill("douzhuan-xingyi",1)<50)
             return RANK_D->query_respect(this_player()) + 
                "功力不够，何以谈及领取图解？";
        if (  present("douzhuan xingyi", this_player()) )
                return RANK_D->query_respect(this_player()) + 
                "你现在身上不是有斗转星移的武籍了嘛，怎么又来要了？ 真是贪得无餍！";

        if (query("book2_count") < 1) return "对不起，斗转星移的武籍已经被别人要走了。";

        ob = new(__DIR__"obj/shu2");
        ob->move(this_player());

        add("book2_count", -1);

        message_vision("$N得到一本斗转星移的武功秘籍。\n",this_player());
        return "好吧，看你为慕容家忠心耿耿，这本书就赐于你吧。";

}
 
string ask_dan()
{
        mapping fam; 
        object ob;
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "姑苏慕容")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";

      if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
                return RANK_D->query_respect(this_player()) + 
                "你是不是刚吃过药，怎么又来要了？ 灵药多吃有害无宜，过段时间再来吧。";

      if ( (int)this_player()->query("max_neili" ) < 400)
                return RANK_D->query_respect(this_player()) + 
                "功力不够，灵药多吃有害无宜，过段时间再来吧。";

        if (  present("guiyuan dan", this_player()) )
                return RANK_D->query_respect(this_player()) + 
                "你现在身上不是有颗药丸吗，怎么又来要了？ 真是贪得无餍！";

        if (query("dan_count") < 1) return "对不起，归元丹已经被别人要走了。";

ob = new("/d/mr/obj/guiyuan-dan");	
        ob->move(this_player());

        add("dan_count", -1);

        message_vision("$N获得一颗归元丹。\n",this_player());
        return "好吧，此丹集天下灵气于一身，你服后会功力大增，我就赐于你吧。";

}

string ask_dan1()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "姑苏慕容")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";

        if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
                return RANK_D->query_respect(this_player()) + 
                "你是不是刚吃过药，怎么又来要了？ 灵药多吃有害无宜，过段时间再来吧。";

        if ( (int)this_player()->query("max_neili" ) < 100)
                return RANK_D->query_respect(this_player()) + 
                "功力不够，灵药多吃有害无宜，过段时间再来吧。";

        if (  present("qingxin san", this_player()) )
                return RANK_D->query_respect(this_player()) + 
                "你现在身上不是有颗药丸吗，怎么又来要了？ 真是贪得无餍！";
        if (query("dan1_count") < 1) return "对不起，玉露清新散已经发完了";

        ob = new(__DIR__"obj/qingxin-san");
        ob->move(this_player());

        add("dan1_count", -1);

        message_vision("$N获得一颗玉露清新散。\n",this_player());
        return "好吧，此药集天下灵气于一身，你服后会功力大增，我就赐于你吧。";

}
