inherit NPC;
#define Husband "fyue"
string Husband_name = "����";
#define Wife "shenxue"
#define Wife_name "��ѩ"
#include <ansi.h>

varargs void drool(string msg, string who);
void create()
{
        set_name(Wife_name, ({Wife}));
        set("long", HIC "\n�����ü�������������˫�۾����ĵ�ֱ���Թ��˻��ǡ�\n"+
        "����ɫ��Ө����ӳ���ں�����֮�£��������ɷ��\n"+
        "������ȻһЦ�����������·����۲���ת֮�䣬\n"+
        "���һ����������飬�������м����ľ��硣\n" NOR);
        set("gender", "Ů��");
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
        set("nickname",HIM+Husband_name+"������"+NOR);
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
                BOLD+Wife_name+"��Ȼ���˸�������Ц��: �������ȥ������\n"+NOR,
                BOLD+Wife_name+"���ĵ������־̾��: ����һ���ˣ���û��˼��\n"+NOR,
                BOLD+Wife_name+"���������һ���С�֣������°�˵: ˭�����˵˵��?\n"+NOR,
                BOLD+Wife_name+"ն��������˵: �ţ�˭Ҫ���۸��ң��Ҿ���������\n"+NOR,
                BOLD+Wife_name+"���˸���Ƿ������������סӣ��С�ڣ��������������ˡ�\n"+NOR,
                (: drool :),
                (: command("sleep2") :),
        }) );
        set("combat_exp", 3000000);
        set("score", 5000000);
        set("chat_chance_combat", 20);  
        set("chat_msg_combat", ({
                Wife_name+"����̾���������������Ǻο���?\n",
                (: command("!!!") :),
                (: command("xixi") :),
                (: command("chat ���кλ����������? ����ͳ�ȫ����ɡ�\n") :),
                (: command("chat ����" + RANK_D->query_rude(this_player())+"��������˵�ִ�Բ���?\n") :),
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/quanzhou/obj/xiuhua")->wield();
}
int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "Ү", "");
        msg = replace_string(msg, "��", "");

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
        if ( (string) ob -> query ("gender") == "����"||(string) ob -> query ("gender") == "����" ){
                command("say ��Ӵ��˭��õ���" + RANK_D->query_rude(ob)+"����Ҳ��һ����ɫ֮ͽ ��");
        }else{
                message_vision(CYN+"$N��$nЦ����������ͬΪŮ��������ôϲ��Ҳ��Ҫ����������\n"+NOR, this_object(),ob);
                command("giggle");
                command("say �벻��"+ ob->query("name") +"��" + RANK_D->query_rude(ob)+"����Ȼ��һ����̬��");
        }
        message_vision(CYN+"$Nҡ��ҡͷ����$n����̾���������������Ǻο���?\n"+NOR,this_object(),this_player());
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
                                        command ("chat "+Husband_name+"��������"+ ob->query("name") + "��Ҫ�����ң�\n") ;
                                        command("chat ��Ӵ��˭��õ���" + RANK_D->query_rude(ob)+"����Ҳ��һ����̬��\n");
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
        if( (strsrch(msg, "kiss") >= 0)|| (strsrch(msg, "love") >= 0)|| (strsrch(msg, "��") >= 0)
                || (strsrch(msg, "mo") >= 0)|| (strsrch(msg, "��") >= 0)|| (strsrch(msg, "hug") >= 0))
                {
                if( sscanf(msg, "%*skiss%s", msg) == 2 ) msg = "kiss" + msg;
                if( sscanf(msg, "%*smo%s", msg) == 2 ) msg = "mo" + msg;
                if( sscanf(msg, "%*shug%s", msg) == 2 ) msg = "hug" + msg;
                if( sscanf(msg, "%*slove%s", msg) == 2 ) msg = "love" + msg;
                if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
                if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
                if( sscanf(msg, "%*s��", msg) == 2 ) msg = "��"+ msg;
                switch(random(20)) {
                case 4:command("chat* cry\n"); break;
                case 6:command("chat ���񰡷���"+who+"��С��å��������\n"); break;
                case 7:command ("chat "+Husband_name+"��������"+ who + "��Ҫ�����ң�\n") ;
                case 11:command("say ���Ů��������������\n"); break;
                case 13:command("chat* ��ȻһЦ��˵�����˹���!\n"); break;
                case 14:command("chat* �����͵�ͨ�죬�������㡣���� ��\n"); break;
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
       message_vision("$N��$n��ȻһЦ.\n\n",this_object(),ob );
       if (this_object()->query("startroom")==base_name(environment())){
            if(ob->query("id")== Husband){
               Husband_name=ob->query("name");
               set("nickname",MAG+ob->query("name")+"������"+NOR);
                command("say �ޣ�"+ob->query("name")+"���ӻ����ˡ�");
                command("say ���ӣ����ҳ�ȥ�����ɣ�һ���ˣ�������Ү��");
                command("follow "+Husband);
            }else
                command("say ��λ" + RANK_D->query_respect(ob)+ "����Ե����СŮ�ӷ��У�\n");
                }
       if (this_object()->query("startroom")!=base_name(environment())){
           if(ob->query("id")== Husband){
          if (this_object()->query_leader() != ob){
                command("say �ޣ�"+ob->query("name")+"���ӣ��ҵ���Ѱ�㲻���������һؼҰɡ�");
                command("follow "+Husband);
              }
               Husband_name=ob->query("name");
               set("nickname",MAG+ob->query("name")+"������"+NOR);
           }else{
                if (!present(Husband,environment()))
                command("say ��λ" + RANK_D->query_respect(ob)+ "������������๫ô��\n");
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
                  command("chat ��������"+ob->query("name")+"��"
                + RANK_D->query_rude(ob)+"��Ȼ�뵱�����ң�\n");
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
                command("chat ��ѽ��"+ob->query("name")+"��"
                + RANK_D->query_rude(ob)+"��Ȼ�����Ҿ�����ˮ������ģ�\n");
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
                command("chat ��������"+ob->query("name")+"��"+ RANK_D->query_rude(ob)+"��Ȼ�뵱�����ң�\n");
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
                command("chat ��������"+ob->query("name")+"��ͷ"+ RANK_D->query_rude(ob)+"��Ȼ�뵱�����ң�\n");
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
                command("chat ��������"+ob->query("name")+"��"+ RANK_D->query_rude(ob)+"��Ȼ�뵱�ڱ��ң�\n");
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
        message_vision("\n$N����һ������˵����"+Husband_name+"��Ϊ�ұ���ġ�\n", this_object());
        message_vision("$N˵�꣬����һ������ȥ��\n", this_object());
        destruct(this_object());
}
void defeated_enemy(object victim)
{
        command("nomatch");
}
int accept_fight(object who)
{
        message_vision("\n$Nҡ��ҡͷ����$n����̾���������������Ǻο���?\n",this_object(),who);
        command("nomatch "+who->query("id"));
}
