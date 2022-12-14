// salt seller
#include <dbase.h>
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
void create()
{
    set_name("盐枭", ({"salt seller","seller"}));
    set("long",
    "这是一个身材高大的江湖人，两臂粗壮，膀阔腰圆。\n"
    );
    set("gender", "男性");
set("no_get", 1);	
    set("attitude", "friend");
    set("class", "swordman");
    set("age", 20+random(30));
    set("str", 25+random(10));
    set("dex", 25+random(10));
    set("int", 25+random(10));
    set("con", 25+random(10));
    set("qi", 1500);
    set("max_qi", 1500);
     set("jing", 10000);
    set("max_jing", 1000);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiaji", 50+random(100));
    set("combat_exp", 10000+random(100000));
    set_skill("force", 20+random(80));
    set_skill("dodge", 20+random(60));
    set_skill("unarmed", 20+random(150));
    set_skill("parry", 20+random(80));
    
    setup();
    carry_object("/clone/misc/blk_cloth")->wear();
    
}
void init()
{
    ::init();
    remove_call_out("greeting");
    call_out("greeting", 1, this_player());
    add_action("do_buy", "buy");
}
void greeting(object ob)
{
    object me;
    me = this_object();
        if( !ob || environment(ob) != environment() ) return;
    if (interactive(ob))
            command("whisper "+ob->query("id")+" 这位"+RANK_D->query_respect(ob)+"要买盐(salt)么，这可是一本万利的生意耶！");
}
int pay_player(object who, int amount)
{
    object ob;
    int total;
    if( amount < 1 ) amount = 1;
        if( amount/10000 ) {
        if (!ob=present("gold_money", who)){
                    ob = new(GOLD_OB);
            if (!ob->move(who)) ob->move(environment(who));
        }else total=ob->query_amount();
                ob->set_amount(amount/10000+total);
                amount %= 10000;
    }
    if( amount/100 ) {
        if (!ob=present("silver_money", who)){
                    ob = new(SILVER_OB);
            if (!ob->move(who)) ob->move(environment(who));
        }else total=ob->query_amount();
                ob->set_amount(amount/100+total);
        amount %= 100;
    }
    if( amount ) {
        if (!ob=present("coin_money", who)){
            ob = new(COIN_OB);
            if (!ob->move(who)) ob->move(environment(who));
        }else total=ob->query_amount();
                ob->set_amount(amount+total);
    }
    return 1;
}
int do_buy(string arg)
{
    string items,targ;
    object *env,me,ob,obj,room;
    int i,amount=1;
    ob=this_player();
    me=this_object();
    if (! room=find_object(me->query("startroom")))
        room=load_object(me->query("startroom"));
    if (room!=environment()){
        command("say 这里没货，等我回去再说吧！");
        return 1;
    }
    env=all_inventory(room);
    for (i=0;i<sizeof(env);i++){
        if (env[i]==me || env[i]==ob)   continue;
        if (env[i]->is_character() && !env[i]->is_corpse() ){
            command("whisper "+ob->query("id")+" 这里耳目众多，这位"+RANK_D->query_respect(ob)+"呆会再来吧！");
            command("say 走开！走开！谁说我这里有什么盐卖的？"+RANK_D->query_self_rude(me)+"从来不干这勾当！");
            return 1;
        }
    }
    targ="";
    if ( !arg )
        return notify_fail("你要买什么东西？\n");
    if(sscanf(arg, "%d %s from %s",amount,items, targ)!=3 )
        if(sscanf(arg, "%s from %s", items, targ)!=2 )
            if( sscanf(arg, "%d %s",amount,items)!=2 )
                items=arg;
    if(targ!="")
        if (!me->id(targ))
            return notify_fail("你要跟谁买东西？\n");
    if (items == "")
        return notify_fail(items+"你想买什么？ \n");
    if ( items!="salt")
        return notify_fail(items+"你想买什么？ \n");
    if(amount<1) return notify_fail("至少得买一斤吧？\n");
//   if(time()-(int)ob->query_temp("salt_got")<=20) return notify_fail("刚才不是卖给你了么？等会再来吧!\n");
    if(amount>1000) return notify_fail("现在没这么多现货！\n");
    if( ob->can_afford(100*amount) ) {
        if (!obj=present("illicit salt",ob)){
            obj=new("/clone/misc/salt");
            if (!obj->move(ob)) obj->move(environment(ob));
            obj->set_amount(amount);
        }else
            obj->add_amount(amount);
        ob->pay_money(100*amount);
        ob->set_temp("salt_got",time());
        message_vision("$N向$n买下" +CHINESE_D->chinese_number(amount)+"斤盐。\n",ob, me );
        return 1;
    } else
        return notify_fail("你的钱不够。\n");
}
