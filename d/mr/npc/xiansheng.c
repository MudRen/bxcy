// teacher.c 私塾先生
// CLEANSWORD 1999/9/7
inherit NPC;
#include <ansi.h>
string * degree_desc = ({
       BLU "文盲" NOR,
       BLU "童生" NOR,
       BLU "秀才" NOR,
       CYN "举人" NOR,
       CYN "解元" NOR,
       CYN "贡士" NOR,
       CYN "会元" NOR,
       GRN "进士" NOR,
       GRN "探花" NOR,
       GRN "榜眼" NOR,
       GRN "状元" NOR,
       HIY "翰林院士" NOR,
       HIY "翰林硕士" NOR,
       HIY "翰林博士" NOR,
       HIY "翰林院编修" NOR,
       HIR "庶吉士" NOR,
       HIR "学士" NOR,
       HIR "内阁大学士" NOR,
       HIR "内阁首辅" NOR,
       MAG "文学大宗师" NOR,
       HIW "圣人" NOR,
});
int ask_degree();
void create()
{
        set_name("私塾先生", ({ "xiansheng", "teacher" }));
        set("long", "这就是慕容家重金礼聘来的私塾先生，他是当代大儒朱熹的学生，?
　　　他经过老师朱熹的许可，可以为当代的文人墨客授予学位\n");
        set("gender", "男性");
        set("age", 65); 
        set_weight(30000000);
        set_skill("literate", 300);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 400000);
        set("shen_type", 1);
        set("inquiry", ([
            "学位" : (:ask_degree:),
            "书"   : "唉!书到用时方恨少。",
            "借书" : "借？你不还我到哪里找你？哼!",
        ]));
        setup();

        set("chat_chance", 3);
        set("chat_msg", ({
                "私塾先生说道：普天之下，莫非王土；率土之滨，莫非王臣。\n",
                "私塾先生说道：出家人，小过损益焉；无妄大过，未济咸困之。\n",
                "私塾先生说道：大学之道，在明明德。在亲民，在止于至善。 \n",
                "私塾先生说道：格物致知，诚意正心，修身齐家，治国平天下。\n",
        }) );
     this_player()->carry_object("/clone/misc/cloth")->wear();
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/朱"))
                return 0; 
        ob->add_temp("mark/朱", -1);
        return 1;
}

int accept_object(object who, object ob)
{
        if (!(int)who->query_temp("mark/朱"))
                who->set_temp("mark/朱", 0);
        if (ob->query("money_id") && ob->value() >= 5000) {
                message_vision("私塾先生同意指点$N一些问题。\n", who);
                who->add_temp("mark/朱", ob->value() / 250);
                return 1;
        }
        return 0;
}
int ask_degree()
{
        int lv;
        object ob = this_player();
        lv = (ob->query_skill("literate") / 5);
        if (lv >= sizeof(degree_desc)) lv = sizeof(degree_desc)-1; 
        if (lv < 3) 
        {
               command("say "+ob->query("name")+"，你那点墨水也好意思问? 随便给你个学位就算了! \n");
               ob->set("degree",degree_desc[lv]);
               return 1;
        }
        if (lv < 10) 
        {
               command("say "+ob->query("name")+"，呃，不错，有前途，很高兴授予学位给你，继续好好努力! \n");
               ob->set("degree",degree_desc[lv]);
               return 1;
        }
        else
        {
               command("say 果然是长江后浪逐前浪啊，"+ob->query("name")+"，我非常荣幸能有机会为你授学位! \n");
               ob->set("degree",degree_desc[lv]);
               return 1;
        }
}

