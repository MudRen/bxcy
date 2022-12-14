//NPC: /d/lingshedao/npc/xiexue.c
//Creat by Yjss on Sep.1999
#include "ansi.h"
inherit NPC;
inherit F_UNIQUE;
int ask_wuji();
int ask_tulong();
void create()
{
        set_name("谢逊", ({"xie xun", "xie", "xun", }));
        set("long",
        "\n他是一位身材魁伟异常的的老者,满头黄发，威风凛凛.\n"
        "可是,他的两只眼睛并不睁开,好象是瞎了.\n"
        "他捧着一把宝刀,正在苦苦冥思着什么.\n"
        );
        set("nickname",HIY "金毛狮王" NOR);
        set("gender", "男性");
        set("attitude", "peaceful");

        set("age", 53);
        set("shen_type", 1);
        set("per", 20);
        set("str", 40);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 3000);
        set("max_jing", 1300);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 200);
        set("combat_exp", 950000);
        set("score", 700000);
        set("max_qi", 5500);
        set("max_jing", 5500);
        set("neili", 15000);
        set("max_neili", 15000);
        set("jiali", 250);

        set("combat_exp", 8000000);
        set("score", 800000);

        set_skill("force", 260);
        set_skill("dodge", 240);
        set_skill("sword", 240);
        set_skill("blade", 240);
        set_skill("parry", 240);
        set_skill("cuff", 200);
        set_skill("blade", 250);
        set_skill("jinwu-daofa", 250);
        set_skill("jiuyang-shengong", 250);
        set_skill("lingxu-bu", 250);
        set_skill("damo-jian", 250);
        set_skill("qishang-quan", 250);
        set_skill("hunyuan-zhang", 250);
        set_skill("literate", 100);

        map_skill("force", "jiuyang-shengong");
        map_skill("dodge", "lingxu-bu");
        map_skill("cuff", "qishang-quan");
        map_skill("parry", "hunyuan-zhang");
        map_skill("sword", "damo-jian");
        map_skill("blade", "jinwu-daofa");

        set_temp("apply/attack", 700);
        set_temp("apply/defense", 500);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        prepare_skill("cuff","qishang-quan");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: command("perform hunpofeiyang") :),
                (: command("perform youyouhunduan") :),
        }) );
       
        set("inquiry",([
            "无忌" :    ( :ask_wuji: ),
            "屠龙刀" :  ( :ask_tulong: ),
            "wuji" :    ( :ask_wuji: ),
            "tulong" :  ( :ask_tulong: ),
        ]) );

        set("chat_chance",4);
        set("chat_msg",({
           "谢逊抚刀沉思道:屠龙刀啊屠龙刀,你到底有什么秘密呢?\n",
           "谢逊恨恨的说道:成昆老贼,你害我家破人亡,我不亲手杀了你,死不瞑目!\n",
           "谢逊喃喃的说道:也不知道我那无忌孩儿过得怎样.\n",
           "谢逊轻轻的叹道:不知道韩夫人带我到这儿是为了什么.\n",
        }) );
        setup();
        carry_object("/d/city/obj/cloth")->wear();
}


int accept_fight(object ob)
{
        say("谢逊昂然道: 你要恃强夺刀，是不是？谢逊有屠龙刀在手，抵得过坏了一对招子..\n");
        say("谢逊怒吼一声: 要取宝刀，先取了我这条性命!\n");
        kill_ob(ob);
        return 1;
}

int accept_object(object who, object ob)
{
        object tlblade;
        object shi1,shi2,shi3;
        object room;
        if ((string)ob->query("id")=="blade")
           {
            if(!who->query("blade_get"))
            {
              if(who->query_temp("marks/wuji")&&who->query_temp("marks/tulong"))
               {
     say("谢逊把"+ ob->query("name") + "放在手里抚摸了一会,突然
哽咽道:是的,这是无忌孩儿的东西\n");
                if(who->query("party/party_name")== HIG "明教" NOR)
               {
                tlblade= new("/d/lingshedao/obj/tlblade");
               message_vision("谢逊紧紧握住$N的手说道：谢谢你带来了无忌的讯息，我已经年老体迈
经不起海上的风浪,这把屠龙刀,就请你转交给无忌吧!\n
说罢谢逊把"+ tlblade->query("name") + "交给了" + who->query("name") + "。\n",who);
              tlblade->move(who);
                command("rumor "+who->query("name")+"拿到屠龙刀了。\n");
                add("blade_count",-1);
                who->set("blade_get",1);
                who->delete_temp("marks/wuji",1);
                who->delete_temp("marks/tulong",1);
                message_vision(HIC" 便在此时，忽听得身后传来两下玎玎异声，三个人疾奔而至,
那三人都身穿宽大白袍，其中两人身形甚高，左首一人是个女子。
每人的白袍角上赫然都绣着一个火焰之形，竟是明教中人。\n\n"NOR,who);
                if(!(room=find_object("/d/lingshedao/chuan")) )
                room=load_object("/d/lingshedao/chuan");
                shi1=present("liu yun",room);
                shi2=present("miao feng",room);
                shi3=present("hui yue",room);
                shi1->move("d/lingshedao/xiaowu");
                shi2->move("d/lingshedao/xiaowu");
                shi3->move("d/lingshedao/xiaowu");
                return 1;
               }
              say("谢逊沉默了一阵,说道:本来想请你把这把屠龙刀转交给无忌,可惜 
你非我明教中人,我实在放心不下.唉!\n\n");
              say("谢逊又说道:岛东有一条小船,这样吧,我送你到那儿,回中土后千万不要泄露我的行踪.唉.\n\n");
              call_out("go_back",4,ob);
              return 1;
               }
              say("谢逊冷笑一声:这是什么东西?你最好离我远点!\n");
              return 0;
            }
        say("谢逊说道:我不是让你把屠龙刀转交给无忌吗?\n");  
        command("heng");
        command("give " + ob->query("id") + " to " + who->query("id"));
        return 1;
         }
           return 0;
}


int ask_wuji()
{
        object ob;
        ob=this_player();
        message_vision(MAG"\n谢逊一愣,放下手中的宝刀,颤声问道:无忌,无忌,你知道\n
我无忌孩儿的消息么?快告诉我,无忌孩儿在哪?\n"NOR,ob);
        ob->set_temp("marks/wuji","1");
        return 1;
}


int ask_tulong()
{
        object ob;
        ob=this_player();
        if((int)ob->query("combat_exp")<200000)
        {
        say("谢逊哼的一声,说道:就你这点微末道行,也配来问屠龙刀?\n");
        message_vision("说完谢逊飞起一脚,把$N踢出了小屋\n",ob);
        ob->move("/d/lingshedao/xiaowuout");
        return 1;
        }
        if(!query("blade_count")<1) 
       { command("nod");
        say(HIW"谢逊说道: 武林至尊，宝刀屠龙，号令天下，莫敢不从！\n"NOR);
        ob->set_temp("marks/tulong","1");
        return 1;
       }
        command("say 已经有人把屠龙刀带走了.\n");
        return 1;
}


int go_back(object ob)
{
        message_vision("谢逊将$N送到了一个海滩上.\n",ob);
        ob->move("/d/lingshedao/haitan2");
        return 1;
} 
void die()
{
        message("vision","\n谢逊仰天长笑道:想不到我谢逊纵横江湖数十年,今日竟败在一
个无名小卒手下.只可惜这把屠龙刀,不能亲手交给我的无忌孩儿了!\n","/d/lingshedao/xiaowu");
        message("vision","谢逊长叹一声:就算我死了,屠龙刀也不能落入奸人之手!说罢,谢逊
将屠龙刀奋力往窗外一扔,屠龙刀落入山中密林,再也没了踪影.\n","/d/lingshedao/xiaowu");
        message_vision("只见$N缓缓的倒了下去,死了.\n",this_object());
        ::die();
}
