// wu-shi1.c 盟主卫士
#include <ansi.h>
inherit NPC;


#define MZ "/d/taishan/npc/meng-zhu"
#define FAE "/d/taishan/npc/fa-e"
#define SS "/d/taishan/npc/shang-shan"

void create()
{
    set_name("白衣武士", ({ "wei shi", "shi", "guard" }) );
    set("gender", "男性");
    set("age", 35);
    set("long",
        "这是位白衣武士，身披钢甲，手执长剑，双目精光炯炯，警惕地巡视着四周的情形。\n");
    set("combat_exp", 100000);
    set("attitude", "heroism");
    set("str", 30);
    set("con", 25);
    set("int", 20);
    set("dex", 30);
    set("max_qi", 500);
    set("eff_qi", 500);
    set("qi", 500);
    set("max_jing", 200);
    set("jing", 200);
    set("neili", 500);
    set("max_neili", 500);
    set("jiali", 30);
    set("shen_type", 0);
    set_temp("apply/attack",  50);
    set_temp("apply/defense", 50);
    set_skill("sword", 100);
    set_skill("unarmed", 80);
    set_skill("parry", 100);
    set_skill("dodge", 100);
    setup();
        carry_object("/d/city/obj/gangjian")->wield();
        carry_object("/d/city/obj/tiejia")->wear();
}
void init()
{
    object ob1, ob2, ob3;
    string mengzhu, shangshan, fae;
    
    if(!( ob1 = find_living("wuling mengzhu")) ){
        ob1 = load_object(MZ);
        mengzhu = ob1->query("winner");
    }
    if(!( ob2 = find_living("shangshan shizhe")) ){
        ob2 = load_object(SS);
        shangshan = ob2->query("winner");
    }
    if(!( ob3 = find_living("fae shizhe")) ){
        ob3 = load_object(FAE);
       if (ob3)
        fae = ob3->query("winner");
    }
    if( this_player()->query("id") == mengzhu ) {
        message_vision(HIY "白衣武士举起长剑，向$N齐声大喊：盟主万岁，万岁，万万岁！\n" NOR, 
        this_player());
    }   
    else if( this_player()->query("id") == shangshan ) {
        message_vision(HIY "白衣武士举起长剑，向$N齐声大喊：赏善使者好！\n" NOR, 
        this_player());
    }   
    else if( this_player()->query("id") == fae ) {
        message_vision(HIY "白衣武士举起长剑，向$N齐声大喊：罚恶使者好！\n" NOR, 
        this_player());
    }   
}

