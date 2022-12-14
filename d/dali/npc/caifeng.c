#include <ansi.h>
inherit NPC;
void create()
{
        set_name("老裁缝", ({ "waiter" }) );
        set("gender", "男性" );
        set("age", 60);
        set("long",
                "这位老裁缝正笑咪咪地忙著，还不时的擦一擦自己的老花眼。\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 30);
        set("shen_type", 0);
        set("max_neli",5000);
        set("jiali",50);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("jiuyin-baiguzhao",200);
        set_skill("force",150);
        set_skill("sword",150);
        set_skill("bibo-shengong",100);
        set_skill("luoying-shenjian",100);
        set_skill("parry",90);
        set_skill("anying-fuxiang",100);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage",50);
        set("combat_exp", 800000);
    
        map_skill("force","bibo-shengong");
        map_skill("parry","luoying-shenjian");
        map_skill("sword","luoying-shenjian");
        map_skill("unarmed","jiuyin-baiguzhao");
        map_skill("dodge","anying-fuxiang");
    
        set("attitude", "peaceful");
        
        set("inquiry", ([
        "订做衣服"  : "订做衣服可是件十分艰苦的事，要消耗人的精气和内力，不过，只要有钱...\n",
        "cloth": "订做衣服可是件十分艰苦的事，要消耗人的精气和内力，不过，只要有钱...\n",
       ]) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_answer","answer");
        add_action("do_ding","ding");
}
void complete(object me)
{
    object ob;
    string w_name,armor;
    
    if( !me || environment(me) != environment() ) return;
    if ((int)me->query("make_wear/time") < time() ){
        w_name=me->query("make_wear/name");
        switch (me->query("make_wear/armor")){
           case "wrists": armor=__DIR__"obj/m_wear/m_wrists";    break;
           case "scarf": armor=__DIR__"obj/m_wear/m_scarf";    break;
           case "finger": armor=__DIR__"obj/m_wear/m_finger";    break;
           case "waist": armor=__DIR__"obj/m_wear/m_waist";    break;
           case "hands": armor=__DIR__"obj/m_wear/m_hands";    break;
           case "coif": armor=__DIR__"obj/m_wear/m_coif";    break;
           case "boots": armor=__DIR__"obj/m_wear/m_boots";    break;
           case "cloth": armor=__DIR__"obj/m_wear/m_cloth";    break;
           default: me->delete("make_wear");   return;
        }
        write("老裁缝告诉你：已经做好了，客官请过目。\n");
        ob=new(armor);
        ob->set("name",w_name);
        ob->move(me);
        me->delete("make_wear");
        message_vision("$N递给$n一"+ob->query("unit")+w_name+"。\n",this_object(),me);
    }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "老裁缝笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来订身衣服吧。\n");
                        break;
                case 1:
                        say( "老裁缝愁眉苦脸说道：这位" + RANK_D->query_respect(ob)
                                + "，你又胖又矮，这帮不了你。\n");
                        break;
        }
        call_out("complete",1,ob);
}

void dest(object ob)
{
    if (ob)     destruct(ob);
}
int accept_object(object who, object ob)
{   
    if (who->query("make_wear")){
        command("say 你上次订做的"+who->query("make_wear/name")+"还未完成呢，请下次再来吧。\n");
        return 0;
    }
    if (ob->query("money_id") && ob->value() >= 10000 ){
        call_out("dest",1,ob);
        who->set_temp("get_wear",1);
        message("vision","老裁缝连忙一哈腰：\n",who);
        command("say 我这儿可以定做以下服饰：\n"+
          "     腰带(waist)\n"+
          "     护腕(wrists)\n"+
          "     指套(finger)\n"+
          "     手套(hands)\n"+
          "     围巾(scarf)\n"+
          "     头巾(coif)\n"+
          "     靴子(boots)\n"+
          "     衣服(cloth)\n");       
        command("say 这位"+RANK_D->query_respect(who)+"要定做什么服饰？决定了告诉我(answer)。\n");
        return 1;
    }
    command("say 订做服饰至少要一两黄金。");
    return 0;
}

int do_answer(string arg)
{
    object me,ob;
    string str;
    
    me = this_player();
    if (me->query("make_wear"))        return 0;
    if(!(me->query_temp("get_wear") ) ){
        write("你得先付钱呀。\n");
        return 1;
    }
    
    if(!arg){
       write("你要造什么服饰？\n");
       return 1;
    }
    message("vision",me->name()+"对老裁缝轻声说了几句。\n",environment(me), ({me}) );

    switch (arg) {
      case "waist"  :
         ob=present("my waist",me);
         str="腰带";
         break;
      case "wrists"   :        
         ob=present("my wrists",me);
         str="护腕";        
         break;
      case "finger" :   
         ob=present("my finger",me);
         str="指套";    
         break;
      case "hands" :
         ob=present("my hands",me);
         str="手套";
         break;
      case "scarf" :
         ob=present("my scarf",me);
         str="围巾";
         break;
      case "coif" :
         ob=present("my coif",me);
         str="头巾";
         break;
      case "boots" :
         ob=present("my boots",me);
         str="靴子";
         break;         
      case "cloth" :
         ob=present("my cloth",me);
         str="衣服";
         break;
      default :
        message_vision(HIC "$N一脸狐疑地看着$n：什么服饰？\n" NOR,this_object(),me);
        return notify_fail("此事不可儿戏，请慎重!!\n");
    }
    if (ob){
        say("老裁缝一脸茫然：您已经有"+str+"了，还来干什么？难到不称心吗？\n");
        return 1;
    }
    command("say 请这位"+RANK_D->query_respect(me)+"给"+str+"起名字吧！(ding "+str+"的中文名字(使用颜色请参考help nick))\n");
    me->set_temp("wear",arg);
    me->delete_temp("get_wear");
    return 1;
}

int do_ding(string w_name)
{
    object me,ob;
    string armor;

    if( !w_name )
        return notify_fail("老裁缝认真的说：想好了中文的名称后再告诉我。\n");
    me = this_player();
    armor = me->query_temp("wear");
    me->delete_temp("wear");
    w_name = replace_string(w_name, "$BLK$", BLK);
    w_name = replace_string(w_name, "$RED$", RED);
    w_name = replace_string(w_name, "$GRN$", GRN);
    w_name = replace_string(w_name, "$YEL$", YEL);
    w_name = replace_string(w_name, "$BLU$", BLU);
    w_name = replace_string(w_name, "$MAG$", MAG);
    w_name = replace_string(w_name, "$CYN$", CYN);
    w_name = replace_string(w_name, "$WHT$", WHT);
    w_name = replace_string(w_name, "$HIR$", HIR);
    w_name = replace_string(w_name, "$HIG$", HIG);
    w_name = replace_string(w_name, "$HIY$", HIY);
    w_name = replace_string(w_name, "$HIB$", HIB);
    w_name = replace_string(w_name, "$HIM$", HIM);
    w_name = replace_string(w_name, "$HIC$", HIC);
    w_name = replace_string(w_name, "$HIW$", HIW);
    w_name = replace_string(w_name, "$NOR$", NOR);
    w_name += NOR;
    me->set("make_wear/name",w_name);
    me->set("make_wear/armor",armor);
    me->set("make_wear/time",time()+7200);
    command("say 这位"+RANK_D->query_respect(me)+"订做"+w_name+CYN+"，请一个月后来取罢。\n");
    return 1;
}


