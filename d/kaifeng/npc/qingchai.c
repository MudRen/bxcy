// unix 1998,10
// modified by wind
// modified by snow

#include <ansi.h>
inherit NPC;
inherit F_CLEAN_UP;
void del_gaoed(object me);

void init()
{
add_action("do_gao","gao");
add_action("xiao_li","dangguan");
}
void create()
{
        set_name("钦差〖包龙星〗",
        ({"qin chai", "qin"}));
        set("title", HIY"八省总巡捕"NOR);
        set("nick_name", "钦差大人");
        set("gender", "男性");
        set("age", 54);
        set("long",
                "他是京城皇上派来的钦差大臣，手中掌管着兵马大权，\n");
        set("attitude", "peaceful");
        set("str", 27);
        set("int", 25);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 50);
        set("max_jing", 2000);
        set("eff_jing", 2000);
        set("jing", 2000);
        set("max_qi", 5000);
        set("eff_qi", 5000);
        set("qi", 5000);
        set("combat_exp", 400000);
        set_skill("blade", 70);
        set_skill("force", 80);
        set_skill("parry", 50);
        set_skill("dodge", 60);
        set("chat_chance", 5);
        set("chat_msg", ({
       HIM "包龙星看看你说:想必你也有冤情?\n" NOR,
       HIM "包龙星目视前方说:当年我为戚秦氏翻案差点丢了脑袋\n" NOR,
        }));

         set("inquiry", ([
        "当官": HIC "包龙星想了想说:想当官那要看你有无这分才能啊!\n" NOR,
        "告状": HIC "你想告谁,喝喝我可是很清廉的好官哦!\n" NOR,
        "升官": HIC "想升官就让我来考考你(dangguan)\n" NOR,
        ]));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
      carry_object("/clone/weapon/gangjian")->wield();
        }

int accept_object(object who, object ob)
{
if (ob->query("money_id") && ob->value() <10000000000+random((50-who->query("kar")))*10000)        {	
        tell_object(who, HIM "钦差大人勃然大怒，说道：什么?竟敢对本官行贿？\n" NOR);
        message_vision(HIY"包龙星大喝道:大胆狂徒,胆敢行贿，来人给我托下去打!!\n"+
                        "几个身强力壮的衙役一佣而上,将$N往外一扔,接着板子\n"+
                        "像雨点般打在$N身上,打的$N哭爹喊娘\n"NOR,who);
        message_vision(HIR"突然$N不动了,一个衙役来到包龙星身边耳语了几句\n"+
                        "只听包龙星说:这次盏且放过你下次再犯决不轻饶,退堂!!\n"NOR,who);
        who->move("/d/city/jianyu");
        who->unconcious();
        return 0;
       }
        else {
        message_vision(HIY"包龙星对$N嘿嘿地笑了几声。\n"NOR,who);
        who->set_temp("gao_paid",1);
        }
        return 1;
}


void beating(object ob)
{
        message_vision(HIY"包龙星大喝道:大胆狂徒,胆敢诬告,来人,给我托下去打!!\n"+
                        "几个身强力壮的衙役一佣而上,将$N往外一扔,接着板子\n"+
                        "像雨点般打在$N身上,打的$N哭爹喊娘\n"NOR,ob);
        message_vision(HIR"突然$N不动了,一个衙役来到包龙星身边耳语了几句\n"+
                        "只听包龙星说:这次盏且放过你下次再犯决不轻饶,退堂!!\n"NOR,ob);
        ob->move("/d/city/jianyu");
        ob->unconcious();
}


void beating2(object ob)
{
        message_vision(HIY"包龙星大喝道:大胆狂徒, 就算你犯了案吧！来人,给我托下去打!!\n"+
                        "几个身强力壮的衙役一佣而上,将$N往外一扔,接着板子\n"+
                        "像雨点般打在$N身上,打的$N哭爹喊娘\n"NOR,ob);
        message_vision(HIR"突然$N不动了,一个衙役来到包龙星身边耳语了几句\n"+
                        "只听包龙星说:这次盏且放过你下次再犯决不轻饶,退堂!!\n"NOR,ob);
        ob->move("/d/city/jianyu");
        ob->unconcious();
}

void dzj(object ob)
{
int j;
message_vision(HIY"两旁衙役高呼:威~~呜~~~!!\n"NOR,ob);
j=random(3);
if (j == 0){remove_call_out("beating");
call_out("beating", 3, ob);
return ;
}
call_out("dzj",j--, ob);
}

void dzj2(object ob)
{
int j;
message_vision(HIY"两旁衙役高呼:威~~呜~~~!!\n"NOR,ob);
j=random(3);
if (j == 0)
{
remove_call_out("beating2");
call_out("beating2", 3, ob);
return ;
}
call_out("dzj2",j--, ob);
}

void del_gaoed(object me)
{
        if (objectp(me) &&  me->query("gaoed"))
           me->delete("gaoed");
}

int do_gao(string str)
{
        object ob,me;
      
          me=this_player();
       if (!me->query_temp("gao_paid")) return notify_fail(HIY"再怎么也得交点手续费嘛！\n" NOR);
       if (!str) return notify_fail("<Syntax>: gao <player id>\n");
                   ob=find_player(str);
       if (!ob) ob= find_living(str);
      if (!ob) return notify_fail(HIM "找不到你要的疑犯！\n" NOR);
         me->set("gaoed",1);
      if (me->query("pks")>random(10)||me->query("combat_exp")<random(1000)||random(10)>7)
        {call_out("dzj", 5, me);}
             else {
        call_out("del_gaoed", 3000, me);
        me->delete_temp("gao_paid");
        tell_room(environment(ob),"一群衙役一拥而上，把"+
        (string)ob->query("name")+"抓了起来, 然後绑走了.\n", ob);
        tell_object(ob,"一群衙役一拥而上，对你说：有人告你了，跟我们走一趟\n");
        ob->move(environment(me));
        tell_object(me, (string)ob->query("name")+"被抓到了衙门.\n");
        tell_object(ob,"你发现是"+(string)me->query("name")+
                "告你的.\n");
        tell_room(environment(ob),(string)ob->query("name")+"突然被抓"+
        "到衙门来了\n",({me,ob}));
          message_vision("\n$N看到$n站在大堂上暗笑不止,不由心火上升"
                +(string)me->query("name")+ "咂们等着瞧!\n",ob,me);
        if (random(10)<7) call_out("dzj2", 5, ob);

        else
        message_vision(HIY"包龙星大声喝道: 这次算你走运，既然没有犯案，就快滚吧!\n" NOR,ob);
         }
       return 1;
}

int xiao_li()
 {
  object ob;
  string old_title;
   ob=this_player();
   old_title = this_player()->query("title");
        if(ob->query("combat_exp")<3000||ob->query("meili")<50){
        command(HIY "say 我主万岁,需要的是有用之人,你算什么东西。\n" NOR);
        return 1;
   }
   else if(ob->query("class")=="bonze")
   {command("say 和尚也想当官？还是先去还俗吧！\n");
    command("sigh2");
    return 1;} else {
           command("smile");
        command(BLU "say 很好,朝庭正是用人之季！" + ob->query("name") +
        "大侠肯为朝庭效力，我正求之不得！\n" NOR);
ob->set("class", "guanfu");	
        ob->set("weiwang", 0);
       if ((ob->query("combat_exp")<5000)&&(ob->query("combat_exp")>=3000)) ob->set("title", "翰林院编修");
 else if (ob->query("combat_exp")<6000) ob->set("title","乔阴县师爷");
else if (ob->query("combat_exp")<7000) ob->set("title","乔阴县令");
else if (ob->query("combat_exp")<8000) ob->set("title","雪亭镇县令");
 else if (ob->query("combat_exp")<9000) ob->set("title", "平杨县令");
else if (ob->query("combat_exp")<10000) ob->set("title", "大同县令");
else if (ob->query("combat_exp")<11000) ob->set("title", "凤祥县令");
else if (ob->query("combat_exp")<12000) ob->set("title", "晋阳县令");
else if (ob->query("combat_exp")<13000) ob->set("title", "桐城县令");
else if (ob->query("combat_exp")<14000) ob->set("title", "杭州令");
else if (ob->query("combat_exp")<15000) ob->set("title", "杭州知府");
else if (ob->query("combat_exp")<18000) ob->set("title", "开封知府");
else if (ob->query("combat_exp")<20000) ob->set("title", "广州知府");
else if (ob->query("combat_exp")<25000) ob->set("title", "南京知府");
else if (ob->query("combat_exp")<30000) ob->set("title", "九门提督");
else if (ob->query("combat_exp")<40000) ob->set("title", "云贵总督");
else if (ob->query("combat_exp")<60000) ob->set("title", "两广总督");
else if (ob->query("combat_exp")<80000) ob->set("title", "两江总督");
else if (ob->query("combat_exp")<100000) ob->set("title", "礼部尚书员外郎");
else if (ob->query("combat_exp")<200000) ob->set("title", "礼部尚书");
else if (ob->query("combat_exp")<400000) ob->set("title", "户部尚书");
else if (ob->query("combat_exp")<600000) ob->set("title", "钦赐龙图阁大学士");
else if (ob->query("combat_exp")<800000) ob->set("title", "左丞相");
else if (ob->query("combat_exp")<1000000) ob->set("title", "右丞相");
else if (ob->query("combat_exp")<1500000) ob->set("title", "钦赐一等千里伯");
else if (ob->query("combat_exp")<2000000) ob->set("title", "钦赐二等万户侯");
else if (ob->query("combat_exp")<3000000) ob->set("title", "钦赐一等定北侯");
else if (ob->query("combat_exp")<5000000) ob->set("title", "钦赐二等护国公");
else if (ob->query("combat_exp")<8000000) ob->set("title", "钦赐一等鹿鼎公");
else if (ob->query("combat_exp")<10000000) ob->set("title", "钦赐特等平西王");
else if (ob->query("combat_exp")<30000000) ob->set("title", "钦赐镇南王");
else if (ob->query("combat_exp")<50000000) ob->set("title", "钦赐西北大将军");
else if (ob->query("combat_exp")<80000000) ob->set("title", "钦赐礼部尚书");
else if (ob->query("combat_exp")<100000000) ob->set("title", "钦赐户部尚书");
else if (ob->query("combat_exp")<200000000) ob->set("title", "钦赐兵部尚书");
else if (ob->query("combat_exp")<300000000) ob->set("title", "钦赐朝廷宰相");
else ob->set("title", "当今皇上");
if (old_title==(string)ob->query("title")) 
command("say "+RANK_D->query_respect(ob)+"如果能够继续努力的话，将来一定会加官进爵，钱途不可限量!\n");
else if((string)ob->query("title") == "普通百姓") 
write("包龙星疑惑的看了看你，说道：嗯，你还是继续做你的普通百姓吧！\n");
else {
tell_object(ob,"你现在的官衔是[["+ob->query("title")+"]]\n");
message("system", HIY"圣旨：
由于"+ob->query("name")+"执政有方，特为嘉奖从即日起荣升为『"+ob->query("title")+"』！
望"+ob->query("name")+"能继续为朝庭效忠！
            钦此\n"NOR,users());
        }
       return 1;
       }
}
