inherit NPC;
#define Husband "fyue"
string Husband_name = "风月";
#define Wife "shenxue"
#define Wife_name "深雪"
#include <ansi.h>

varargs void drool(string msg, string who);
void create()
{
        set_name(Wife_name, ({Wife}));
        set("long", HIC "\n她长得极美，尤其是那双眼睛，媚得直可以勾人魂魄。\n"+
        "其容色晶莹如玉，映照于红红烛光之下，娇美不可方物。\n"+
        "回眸嫣然一笑，雅如仙子下凡。眼波流转之间，\n"+
        "便把一个少年的心灵，推向梦中极美的境界。\n" NOR);
        set("gender", "女性");
        set("age", 18);
        set("per", 30);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("qi", 2000);
        set("max_qi", 2000);
         set("max_jing", 2000);
         set("jing", 2000);
          set("jingli", 60000);
          set("max_jingli", 60000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("combat_exp", 1000000);
        set("score", 1000);
        set("jiali",10);
        set("marry",Husband);
        set("nickname",HIM+Husband_name+"的妻子"+NOR);
        set_skill("force", 100);
        set_skill("dodge", 800);
        set_skill("sword", 100);
        set_skill("pixie-jian", 300); 
        set_skill("tiyunzong", 800);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("kuihua-xinfa", 100);

        map_skill("sword","pixie-jian");        
        map_skill("dodge","tiyunzong");
        map_skill("force","kuihua-xinfa");
        map_skill("unarmed","taiji-quan");
        map_skill("parry","pixie-jian");


        set("env/wimpy", 90);
        set("chat_chance", 3);
        set("chat_msg", ({
                BOLD+Wife_name+"忽然做了个鬼脸，笑道: 真想溜出去玩会儿。\n"+NOR,
                BOLD+Wife_name+"无聊地绕着手绢，叹道: 唉，一个人，真没意思。\n"+NOR,
                BOLD+Wife_name+"伸出白玉雕成一般的小手，托着下巴说: 谁想和我说说话?\n"+NOR,
                BOLD+Wife_name+"斩钉截铁地说: 嗯，谁要敢欺负我，我就宰了他！\n"+NOR,
                BOLD+Wife_name+"打了个呵欠，左手轻轻掩住樱桃小口，柔声道：我困了。\n"+NOR,
                (: drool :),
                (: command("sleep2") :),
        }) );
        set("combat_exp", 3000000);
        set("score", 5000000);
        set("chat_chance_combat", 20);  
        set("chat_msg_combat", ({
                Wife_name+"幽幽叹道：唉，你这又是何苦呢?\n",
                (: command("!!!") :),
                (: command("xixi") :),
                (: command("chat 生有何欢，死亦何忧? 不如就成全了你吧。\n") :),
                (: command("chat 你这" + RANK_D->query_rude(this_player())+"此生怎如此的执迷不悟?\n") :),
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/quanzhou/obj/xiuhua")->wield();
}
int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "？", "");
        msg = replace_string(msg, "？", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "！", "");
        msg = replace_string(msg, "啊", "");
        msg = replace_string(msg, "吗", "");
        msg = replace_string(msg, "耶", "");
        msg = replace_string(msg, "吧", "");

        if( msg!="" ) {
                add("memory/" + who, ({ msg }));
                return 1;
        } else return 0;
}
void relay_channel(object ob, string channel, string msg)
{
        string who, phrase;

        if( !userp(ob) || (channel != "chat") ) return;
        who = ob->query("name");

        if( ob==this_object() ) return;

        if( add_phrase(who, msg) &&     random(10) > 3 )
                drool(msg, ob->query("name"));
}
void relay_say(object ob, string msg)
{
        string who, phrase;

        if( !userp(ob) ) return;
        who = ob->query("name");

        if( ob==this_object() ) return;

        if( add_phrase(who, msg) &&     random(10) > 3 )
                drool(msg, ob->query("name"));
}
void relay_emote(object ob, string verb)
{
       if( !userp(ob) ) return;
        switch(verb) {
        case "mo":
                command("puke "+ob->query("id"));
        case "fang":
        case "hug":
        case "kiss":
        case "18mo":
        if (ob->query("id")==Husband){
                if (random(10)>5)
                        command("xixi");
                else
                        command("blush");
                return;
        }
        if ( (string) ob -> query ("gender") == "男性"||(string) ob -> query ("gender") == "无性" ){
                command("say 哎哟，谁想得到这" + RANK_D->query_rude(ob)+"，竟也是一个好色之徒 。");
        }else{
                message_vision(CYN+"$N对$n笑道：“你我同为女儿身，再怎么喜欢也不要这样啊。”\n"+NOR, this_object(),ob);
                command("giggle");
                command("say 想不到"+ ob->query("name") +"这" + RANK_D->query_rude(ob)+"，竟然是一个变态！");
        }
        message_vision(CYN+"$N摇了摇头，对$n幽幽叹道：唉，你这又是何苦呢?\n"+NOR,this_object(),this_player());
        if(wizardp(ob)){
                ob->set("immortal",0);
                command("kick "+ob->query("id"));
                command("shout "+ob->query("id"));
        }
        this_object()->kill_ob(ob);
        return;
        default:
            if( random(10)<2 ){
                command(verb + " " + ob->query("id"));
                return;
            }else{
                switch(verb){
                        case  "kick":
                        case  "kok":
                        case  "slap":
                        switch(random(2)){
                                case 0:
                                command ("kick "+ ob->query("id"));
                                command ("xixi");
                                break;
                                case 1:
                                command ("slap "+ ob->query("id"));
                                command ("xixi");
                                break;
                                default:
                                if( random(10)<3 ){
                                        command(verb + " " + ob->query("id"));
                                        return;
                                }else{ 
                                        command ("chat "+Husband_name+"快来啊，"+ ob->query("name") + "想要羞辱我！\n") ;
                                        command("chat 哎哟，谁想得到这" + RANK_D->query_rude(ob)+"，竟也是一个变态狂！\n");
                                        command("cry");
                                        command("faint "+ob->query("id"));
                                }
                                return;
                        }
                }
                }
        }
        return;
}
varargs void drool(string msg, string who)
{
        mapping mem;
        string *ob;

        mem = query("memory");
       if (!sizeof(mem)) return;
        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }
        if( (strsrch(msg, "kiss") >= 0)|| (strsrch(msg, "love") >= 0)|| (strsrch(msg, "吻") >= 0)
                || (strsrch(msg, "mo") >= 0)|| (strsrch(msg, "抱") >= 0)|| (strsrch(msg, "hug") >= 0))
                {
                if( sscanf(msg, "%*skiss%s", msg) == 2 ) msg = "kiss" + msg;
                if( sscanf(msg, "%*smo%s", msg) == 2 ) msg = "mo" + msg;
                if( sscanf(msg, "%*shug%s", msg) == 2 ) msg = "hug" + msg;
                if( sscanf(msg, "%*slove%s", msg) == 2 ) msg = "love" + msg;
                if( sscanf(msg, "%*s吻%s", msg) == 2 ) msg = "吻" + msg;
                if( sscanf(msg, "%*s抱%s", msg) == 2 ) msg = "抱" + msg;
                if( sscanf(msg, "%*s摸", msg) == 2 ) msg = "摸"+ msg;
                switch(random(20)) {
                case 4:command("chat* cry\n"); break;
                case 6:command("chat 非礼啊非礼！"+who+"这小流氓又来啦！\n"); break;
                case 7:command ("chat "+Husband_name+"快来啊，"+ who + "想要羞辱我！\n") ;
                case 11:command("say 你对女孩子总是这样吗？\n"); break;
                case 13:command("chat* 嫣然一笑，说：够了够了!\n"); break;
                case 14:command("chat* 满脸胀得通红，急道：你。。。 。\n"); break;
                }
                return;
            if (random(10)<3) command("chat* angry\n"); 
            else if(random(10)<3) command("chat* xixi\n");
        return;
        } 
}
void reset()
{
        delete("memory");
}       
void init()
{       
    object ob;
    ob = this_player();
    ::init();
    if (userp(ob)){
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
}
void greeting(object ob)
{
       if( !ob || environment(ob) != environment() ) return;
       if(!userp(ob)) return;
       message_vision("$N对$n嫣然一笑.\n\n",this_object(),ob );
       if (this_object()->query("startroom")==base_name(environment())){
            if(ob->query("id")== Husband){
               Husband_name=ob->query("name");
               set("nickname",MAG+ob->query("name")+"的妻子"+NOR);
                command("say 噢，"+ob->query("name")+"公子回来了。");
                command("say 公子，带我出去玩会儿吧，一个人，好无聊耶！");
                command("follow "+Husband);
            }else
                command("say 这位" + RANK_D->query_respect(ob)+ "，何缘来到小女子房中？\n");
                }
       if (this_object()->query("startroom")!=base_name(environment())){
           if(ob->query("id")== Husband){
          if (this_object()->query_leader() != ob){
                command("say 噢，"+ob->query("name")+"公子，我到处寻你不见，你快带我回家吧。");
                command("follow "+Husband);
              }
               Husband_name=ob->query("name");
               set("nickname",MAG+ob->query("name")+"的妻子"+NOR);
           }else{
                if (!present(Husband,environment()))
                command("say 这位" + RANK_D->query_respect(ob)+ "，你可曾见我相公么？\n");
                }
       }
}
int do_chat( string arg )
{
   object ob ;
   string dir;
   ob = this_player() ;
   if( !arg || arg=="" ) return 0;
   if( sscanf(arg, "*kiss %s", dir)==1 ) {
        if( dir==Wife) {
                if(ob->query("id")==Husband)
                  command("chat* blush "+Husband);
                else{
                  command("chat 救命啊！"+ob->query("name")+"这"
                + RANK_D->query_rude(ob)+"居然想当众吻我！\n");
                  command("xixi");
                        if(wizardp(ob)){ 
                                ob->set("immortal",0);
                                command("kick "+ob->query("id"));
                                command("shout "+ob->query("id"));
                        }
                        this_object()->kill_ob(ob);
                  }
                return 1;
        }
   }
   if( sscanf(arg, "*taste %s", dir)==1 ) {
                if( dir==Wife) {
                if(ob->query("id")==Husband) return 0;
                else
                {
                command("chat 哎呀！"+ob->query("name")+"这"
                + RANK_D->query_rude(ob)+"居然看着我就流口水，真恶心！\n");
                command("xixi");
                        if(wizardp(ob))         
                        { 
                        ob->set("immortal",0);
                        command("kick "+ob->query("id"));
                        command("shout "+ob->query("id"));
                        }
                        this_object()->kill_ob(ob);
                }
                return 1;
                }
        }
   if( sscanf(arg, "*mo %s", dir)==1 ) {
                if( dir==Wife) {
                if(ob->query("id")==Husband) return 0;
                else
                {
                command("chat 救命啊！"+ob->query("name")+"这"+ RANK_D->query_rude(ob)+"居然想当众摸我！\n");
                command("xixi");
                        if(wizardp(ob))         
                        { 
                        ob->set("immortal",0);
                        command("kick "+ob->query("id"));
                        command("shout "+ob->query("id"));
                        }
                        this_object()->kill_ob(ob);
                }
                return 1;
                }
        }
   if( sscanf(arg, "*18mo %s", dir)==1 ) {
                if( dir==Wife) {
                if(ob->query("id")==Husband) return 0;
                else {
                command("chat 救命啊！"+ob->query("name")+"这头"+ RANK_D->query_rude(ob)+"居然想当众摸我！\n");
                command("xixi");
                        if(wizardp(ob))         
                        { 
                        ob->set("immortal",0);
                        command("kick "+ob->query("id"));
                        command("shout "+ob->query("id"));
                        }
                        this_object()->kill_ob(ob);
                }
                return 1;
                }
        }
   if( sscanf(arg, "*hug %s", dir)==1 ) {
                if( dir==Wife) {
                if(ob->query("id")==Husband) return 0;
                else
                {
                command("chat 救命啊！"+ob->query("name")+"这"+ RANK_D->query_rude(ob)+"居然想当众抱我！\n");
                command("xixi");
                        if(wizardp(ob))         
                        { 
                        ob->set("immortal",0);
                        command("kick "+ob->query("id"));
                        command("shout "+ob->query("id"));
                        }
                        this_object()->kill_ob(ob);
                }
                return 1;
                }
        }
       return 0 ;
}
void die()
{
        object ob;
        command("cry");
        message_vision("\n$N娇喘一口气，说道："+Husband_name+"会为我报仇的。\n", this_object());
        message_vision("$N说完，化作一缕清风而去。\n", this_object());
        destruct(this_object());
}
void defeated_enemy(object victim)
{
        command("nomatch");
}
int accept_fight(object who)
{
        message_vision("\n$N摇了摇头，对$n幽幽叹道：唉，你这又是何苦呢?\n",this_object(),who);
        command("nomatch "+who->query("id"));
}
