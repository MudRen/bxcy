// meng-zhu.c 武林盟主
// colored the title of 武林盟主(player) ,   ReyGod, 1/15/1997
#include <ansi.h>
#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif
#define MENGZHU NPCDATA + "meng-zhu"
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
inherit F_SAVE;
string query_save_file()
{
    return MENGZHU;
}
void create()
{
    seteuid(getuid());
    if (!restore()) {
    set_name("魏无双", ({ "wulin mengzhu", "mengzhu", "zhu" }) );
    set("title", "武林盟主" );
    set("gender", "男性" );
    set("age", 40);
      set("long","他就是雄踞武林，号召天下，威风赫赫的当今武林盟主。\n");
    set("attitude", "heroism");
    set("generation",0);
    set("winner","NONE");
    set("str", 25);
    set("con", 25);
    set("int", 25);
    set("dex", 25);
    set("max_qi", 500);
    set("eff_qi", 500);
    set("qi", 500);
    set("max_jing", 300);
    set("jing", 300);
    set("neili", 500);
    set("max_neili", 500);
    set("jiali", 40);
    set("shen_type", 0);
    set("no_clean_up",1);
    set("combat_exp", 800000);
    set_skill("force",  200); 
    set_skill("unarmed",200);
    set_skill("sword",  200);
    set_skill("dodge",  200);
    set_skill("parry",  200);
    set("my_weapon", "/d/shaolin/obj/changjian");
    set("my_armor", "/d/city/obj/cloth");
    setup();
    carry_object("/d/shaolin/obj/changjian")->wield();
    carry_object("/d/city/obj/cloth")->wear();        
    }
    else {
        set("id", "mengzhu");
if(!query("name"))
set_name("魏无双", ({  "wulin mengzhu", "mengzhu", "zhu" }));	
else
        set_name(query("name"), ({  "wulin mengzhu", "mengzhu", "zhu" }));
        setup();
        if( this_object()->query("my_weapon") ) carry_object(this_object()->query("my_weapon"))->wield();
        if( this_object()->query("my_armor") )  carry_object(this_object()->query("my_armor"))->wear();        
      UPDATE_D->check_user(this_object());
    }
    set("no_suck",1);

}
void init()
{
    object me = this_object();
    object ob = this_player();
    if (base_name(environment())!=me->query("startroom")) return;
    if ( me->query("winner") == ob->query("id")
      && me->query("age") <= ob->query("age")
      && time()-me->query("recover")>60){
        ob->set("eff_jing",ob->query("max_jing"));
        ob->set("jing",ob->query("max_jing"));
        ob->set("eff_qi",ob->query("max_qi"));
        ob->set("qi",ob->query("max_qi"));
        if (ob->query("neili")<ob->query("max_neili"))
            ob->set("neili",ob->query("max_neili"));
        if (ob->query("jingli")<ob->query("max_jingli"))
            ob->set("jingli",ob->query("max_jingli"));
        me->set("recover",time());
    }
add_action("do_recopy",  "recopy");       	
add_action("do_recover", "recover");      	
    add_action("do_kill", "kill");
}
int do_kill(string arg)
{
    object ob;
    int i;
    if (!this_object()->id(arg)) return 0;
    command("say 你想谋害本盟主，当真是吃了熊心豹子胆了！！");
    command("say 座下白衣武士何在！");
    
    message_vision("四周的白衣武士群起对$N发动攻击！\n", this_player());
    for(i=0; i<4; i++) {
        if( objectp( ob = present("wei shi " + (i+1), environment(this_object())) ) )
                 ob->kill_ob(this_player());    
        else    this_object()->kill_ob(this_player());      
    }
    return 1;
}
int accept_fight(object ob)
{
object home;	
    object me  = this_object();
        
    if ( me->query("winner") == ob->query("id") ) {
        command("say 你跟你自己打什么架？！\n");
        return 0;
    }
    if (wizardp(this_player())){
        command("say 巫师不能抢盟主之位！\n");
        return 0;
    }
if(!home = find_object(me->query("startroom")) )	
home = load_object(me->query("startroom"));	
if (environment(me)!=home){     	
command("say 我现在正忙着呢！等我回去再说吧！\n");	
return 0;	
}
    if ( me->is_fighting() || me->query("fighting") ) {
        command("say 已经有人正在挑战武林盟主！\n");
        return 0;
    }
    me->set("eff_qi", me->query("max_qi"));
    me->set("qi",     me->query("max_qi"));
    me->set("jing",   me->query("max_jing"));
    me->set("neili",  me->query("max_neili"));
    remove_call_out("checking");
    call_out("checking", 1, me, ob);
    
    return 1;
}
int checking(object me, object ob)
{
    int my_max_qi, his_max_qi;
    object *enemy=me->query_enemy();
    if (sizeof(enemy)>1)    return 1;
    if (!ob)    return 1;
    my_max_qi  = me->query("max_qi");
    his_max_qi = ob->query("max_qi");
    if (me->is_fighting()) {
        if ( (me->query("qi")*100 / my_max_qi) <= 80 )
            command("exert recover");
        call_out("checking", 1, me, ob);
        return 1;
    }
    if ( !present(ob, environment()) ) return 1; 
    if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) {
        if (!living(me))    me->revive();
        command("say 果然厉害，恭喜你成为当今武林盟主！\n");
        command("chat 哈哈哈，到底是长江後浪推前浪，一代新人换旧人！\n");
        command("chat 恭喜" + ob->query("name") + "被推举为当今武林盟主！\n");
        me->set("fighting",1);
        remove_call_out("do_copy");
        call_out("do_copy", 1, me, ob);
        return 1;
    }
    if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) {
        command("say 看来" + RANK_D->query_respect(ob) + 
            "还得多加练习，方能在当今武林中出人头地 !\n");
        return 1;
    }
    return 1;  
}
int do_copy(object me, object ob)
{
object shizhe,room;        	
    string name;
    if(!( shizhe = find_living("shangshan shizhe")) )
    shizhe = load_object("/d/taishan/npc/shang-shan");
    name = shizhe->query("winner");
    if( ob->query("id") == name ){
        shizhe->rm_file();
      if (!room=find_object("/d/taishan/xiayi"))
      room=load_object("/d/taishan/xiayi");
      room->reset();
     }
    if(!( shizhe = find_living("fae shizhe")) )
    shizhe = load_object("/d/taishan/npc/fa_e");
    name = shizhe->query("winner");
    if( ob->query("id") == name ){
        shizhe->rm_file();
      if (!room=find_object("/d/taishan/zhengqi"))
      room=load_object("/d/taishan/zhengqi");
      room->reset();
     }
    seteuid(getuid());
    if (!living(me))    me->revive();
    me->set("winner", ob->query("id"));
    me->add("generation", 1);   
    me->set("name",  ob->query("name") );
    
    ob->delete("party");
    ob->set("party/party_name",YEL+"第" + chinese_number(me->query("generation")) + "代"+ NOR );
    ob->set("party/rank",YEL+"武林盟主"+NOR);
    
    me->set("short", YEL+"第" + chinese_number(me->query("generation")) + "代武林盟主" + NOR+" " + me->query("name") + "(Wulin mengzhu)");
    me->delete("title");
    remove_call_out("do_clone");
    call_out("do_clone", 0, me, ob);
    return 1;
}
int do_recopy(object me, object ob)
{
object home;	
    me = this_object();
    ob = this_player();
    if (me->is_fighting() || ob->is_fighting() || me->query("fighting"))
        return notify_fail("现在这里正打的不亦乐乎！等会吧！\n");
    if ( me->query("winner") != ob->query("id") ) 
        return notify_fail("你不是现任武林盟主！\n");;
if(!home = find_object(me->query("startroom")) )	
home = load_object(me->query("startroom"));	
if (environment(me)!=home)
return notify_fail("什么？\n");	
     me->set("name",  ob->query("name") );
    ob->delete("party");
    ob->set("party/party_name",YEL+"第" + chinese_number(me->query("generation")) + "代"+ NOR );
    ob->set("party/rank",YEL+"武林盟主"+NOR);

    me->set("short", YEL+"第" + chinese_number(me->query("generation")) + "代武林盟主" + NOR+" " + me->query("name") + "(Wulin mengzhu)");
    me->delete("title");
    remove_call_out("do_clone");
    call_out("do_clone", 0, me, ob);
    return 1;
}
int do_clone(object me, object ob)
{
    object *inv, newob,weapon;
    mapping hp_status, skill_status, map_status;
    string *sname, *mname;
    int i, temp;
    string skill1,skill2;
    seteuid( geteuid(me) );
    if (!living(me))    me->revive();
/* delete and copy skills */
    if (mapp(skill_status=ob->query("weapon")))
        me->set("weapon",skill_status);
    else    me->delete("weapon");
    if ( mapp(skill_status = me->query_skills()) ) {
        skill_status = me->query_skills();
        sname  = keys(skill_status);
        temp = sizeof(skill_status);
        for(i=0; i<temp; i++) {
            me->delete_skill(sname[i]);
        }
    }
    if ( mapp(skill_status = ob->query_skills()) ) {
        skill_status = ob->query_skills();
        sname  = keys(skill_status);
        for(i=0; i<sizeof(skill_status); i++) {
            me->set_skill(sname[i], skill_status[sname[i]]);
        }
    }
    
/* delete and copy skill maps */
    if ( mapp(map_status = me->query_skill_map()) ) {
        mname  = keys(map_status);
        temp = sizeof(map_status);
        for(i=0; i<temp; i++) {
            me->map_skill(mname[i]);
        }
    }
    if ( mapp(map_status = ob->query_skill_map()) ) {
        mname  = keys(map_status);
        for(i=0; i<sizeof(map_status); i++) {
            me->map_skill(mname[i], map_status[mname[i]]);
        }
    }
    
/* unwield and remove weapon & armor */
    inv = all_inventory(me);
    for(i=0; i<sizeof(inv); i++) {
        destruct(inv[i]);
    }
    set("my_weapon", 0);
    set("my_armor", 0);
/* wield and wear weapon & armor */
    inv = all_inventory(ob);
    for(i=0; i<sizeof(inv); i++) {
        if( inv[i]->query("weapon_prop/damage") > 100 
        ||  inv[i]->query("armor_prop/armor") > 100
        ||  inv[i]->query("shaolin")
                ||  inv[i]->query("value")>100000 ) continue;
        if( inv[i]->query("weapon_prop") &&  inv[i]->query("equipped") ) {
            if (!inv[i]->id(query("weapon/id"))){
//            carry_object(base_name(inv[i]))->wield();
            me->set("my_weapon", base_name(inv[i]));
                        }
        }
        else if( inv[i]->query("armor_prop") &&  inv[i]->query("equipped") ) {
//            carry_object(base_name(inv[i]))->wear();
            me->set("my_armor", base_name(inv[i]));
        }
    }

/* copy entire dbase values */
    hp_status = ob->query_entire_dbase();
        me->set("str", hp_status["str"]);
        me->set("int", hp_status["int"]);
        me->set("con", hp_status["con"]);
        me->set("dex", hp_status["dex"]);
        me->set("age", hp_status["age"]);
        me->set("max_qi",    hp_status["max_qi"]);
        me->set("eff_qi",    hp_status["eff_qi"]);
        me->set("qi",        hp_status["qi"]);
        me->set("max_jing",  hp_status["max_jing"]);
        me->set("eff_jing",  hp_status["eff_jing"]);
        me->set("jing",      hp_status["jing"]);
        me->set("max_neili", hp_status["max_neili"]);
        me->set("neili",     2*hp_status["max_neili"]);
        me->set("max_jingli",hp_status["max_jingli"]);
        me->set("jingli",    hp_status["jingli"]);
        me->set("jiali",     hp_status["jiali"]);
        me->set("gender",    hp_status["gender"]);
        me->set("combat_exp",hp_status["combat_exp"]);
me->set("birthday",  hp_status["birthday"]);    	
    
    me->delete("fighting");
    if (objectp(weapon=me->query_temp("weapon"))){
            skill1=weapon->query("skill_type");
            if (objectp(weapon=me->query_temp("secondaly_weapon")))
                    skill2=weapon->query("skill_type");
        }
    if ( mapp(skill_status = me->query_skills()) ) {
        sname  = keys(skill_status);
        for(i=0; i<sizeof(skill_status); i++) {
            command("enable unarmed "+sname[i]);
            command("enable force "+sname[i]);
            command("enable parry "+sname[i]);
            command("enable dodge "+sname[i]);
                        if (stringp(skill1))
            command("enable "+skill1+" "+sname[i]);
                        if (stringp(skill2))
            command("enable "+skill2+" "+sname[i]);
        }
    }

    command("enforce max");
    command("enable unarmed liumai-shenjian");
    save();
    tell_object(ob, "状态储存完毕。\n");
    newob = new("/d/taishan/npc/meng-zhu");
    newob->move("/d/taishan/fengchan");
    destruct(me);
    return 1;
}
int do_recover()
{
object me, ob,home;	
    mapping skill_status, map_status;
    string *sname, *mname;
int i,temp;	
    me = this_object();
    ob = this_player();
    if (me->is_fighting() || ob->is_fighting() || me->query("fighting"))
        return notify_fail("现在这里正打的不亦乐乎！等会吧！\n");
if ( me->query("winner") != ob->query("id") || (me->query("age")-1)>ob->query("age") || me->query("birthday")!=ob->query("birthday")) 
        return notify_fail("你不是现任武林盟主！\n");;
if(!home = find_object(me->query("startroom")) )	
home = load_object(me->query("startroom"));	
if (environment(me)!=home)
return notify_fail("什么？\n");	
    if (time()-me->query("recover")<60)
        return notify_fail("状态暂时不能复元。\n");
/* delete and copy skills */
    if ( mapp(skill_status = ob->query_skills()) ) {
        sname  = keys(skill_status);
temp = sizeof(skill_status);	
//   for(i=0; i<(sizeof(skill_status)); i++) {       	
for(i=0; i<temp; i++) {
            ob->delete_skill(sname[i]);
        }
    }
    if ( mapp(skill_status = me->query_skills()) ) {
        sname  = keys(skill_status);
        for(i=0; i<sizeof(skill_status); i++) {
            ob->set_skill(sname[i], skill_status[sname[i]]);
        }
    }
    
/* delete and copy skill maps */
    if ( mapp(map_status = ob->query_skill_map()) ) {
        mname  = keys(map_status);
        for(i=0; i<sizeof(map_status); i++) {
            ob->map_skill(mname[i]);
        }
    }
    if ( mapp(map_status = me->query_skill_map()) ) {
        mname  = keys(map_status);
        for(i=0; i<sizeof(map_status); i++) {
            ob->map_skill(mname[i], map_status[mname[i]]);
        }
    }
    
/* copy combat exp values */
    ob->set("combat_exp", me->query("combat_exp"));
    write("状态复元完毕。\n");
    me->set("recover",time());
    return 1;
}
