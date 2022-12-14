// longnv.c 小龙女
#include <ansi.h>
inherit NPC;
string ask_yunv();
string ask_me();

void create()
{
        set_name("小龙女", ({"long nv", "long"}));
        set("gender", "女性");
        set("age", 18);
        set("long",
                "她一生爱穿白衣，当真如风拂玉树，雪裹琼苞，兼之生性清冷，\n"
                "实当得起“冷浸溶溶月”的形容。\n");
        set("attitude", "friendly");

        set("per", 30);
        set("str", 30);
        set("int", 37);
        set("con", 36);
        set("dex", 38);

        set("chat_chance_combat", 9);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
        }) );
        set("chat_chance", 1);
        set("chat_msg", ({
                "小龙女幽幽地道：“不知过儿现在在哪里？可有看到我刺在玉蜂翅上的字？”\n", 
                "小龙女喃喃道：“玉女剑与全真剑合壁，是可天下无敌。可是...哪里去找这一个人呢？”\n",
                "小龙女深深地叹了口气，转过头去。\n",
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.suxin" :),
        }));

        set("qi", 35000);
        set("max_qi", 35000);
        set("jing", 16000);
        set("max_jing", 16000);
        set("neili", 140000);
        set("max_neili", 140000);
        set("jiali", 100);
        set("combat_exp", 12000000);

        set_skill("force", 350);
        set_skill("yunv-xinfa", 350);    //玉女心法
        set_skill("sword", 350);
        set_skill("yunv-jian", 350);     //玉女剑
        set_skill("quanzhen-jianfa",350);  //全真剑
        set_skill("dodge", 350);
        set_skill("yunv-shenfa", 350);   //玉女身法
        set_skill("parry", 350);
        set_skill("hubo", 500);          //双手互搏
        set_skill("unarmed",350);
        set_skill("meinv-quan", 350);    //美女拳法
        set_skill("literate",520);
        set_skill("qufeng",250);         //驱蜂之术

        map_skill("force", "yunv-xinfa");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("unarmed", "meinv-quan");

        create_family("古墓派", 3, "弟子");
        set("book_count", 1);
        set("count",1);

        set("inquiry", ([
                "过儿" : (: ask_me :),
                "杨过" :  "你知道我过儿的下落？\n",
                "玉女剑法" : "玉女剑法和全真剑法合壁，天下无敌！\n",
                "古墓派" : "我的林祖师爷爷本来和重阳先师是一对璧人，可是...\n",
                "玉女心经" : (: ask_yunv :),
        ]) );

        set("env/wimpy", 40);
        setup();

        carry_object(__DIR__"obj/shunvjian")->wield();
        carry_object(__DIR__"obj/baipao")->wear();

}

void attempt_apprentice(object ob)
{       
   if (((string)ob->query("gender")!="女性") || (ob->query("per") < 20))
	{
        	command("say 我古墓向来不和你这样的人打交道,阁下还是请回吧。\n");
	}
	else
	{
	        command("say 好吧，我就收下你这个徒弟了。\n");
        	command("recruit " + ob->query("id"));
	}
}

string ask_yunv()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "古墓派")
                return RANK_D->query_respect(this_player()) +
                "与本派毫无瓜葛，何以问起本派的心经？";
        if (query("book_count") < 1)
                return "你来晚了，本派的玉女心经已经被人取走了。";
        add("book_count", -1);
        ob = new("/clone/book/yunvjing1");
        ob->move(this_player());
        return "好吧，这本「玉女心经」你拿回去好好研读。";
}
string ask_me()
{
        object ob;

        if(query("count") < 1)
                return "你知道过儿的下落？";

        add("count", -1);
        ob=new(__DIR__"obj/junzijian");
        ob->move(this_player());
        return "这柄君子剑送给你做个信物，见到过儿的时候请交给他。";
}
