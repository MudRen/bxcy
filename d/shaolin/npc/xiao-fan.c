// seller.c
inherit NPC;
inherit F_VENDOR;
void create()
{
    set_name("小贩", ({ "xiao fan", "seller", "fan" }) );
    set("gender", "男性" );
    set("age", 32);
    set("long",
        "这是个小贩，别看他长的老老实实，可你别想从他那儿掏便宜。\n");
    set("shen_type", 1);
    set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
    set("attitude", "peaceful");
    set("vendor_goods", ({
        "/d/shaolin/obj/map",
        "/d/shaolin/obj/guide",
        "/d/city/obj/bo",
        "/d/village/npc/obj/stick",
        "/d/village/npc/obj/shoes",
                "/d/village/npc/obj/bottle",
    }) );
    setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("coin", 100);
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
int do_buy(string arg)
{
    int amount,once;
    string items,targ;
        if(sscanf(arg, "%d %s %d from %s",amount,items,once, targ)!=4 )
            if(sscanf(arg, "%d %s from %s",amount,items, targ)!=3 )
            if(sscanf(arg, "%s %d from %s", items,once,targ)!=3 )
        if( sscanf(arg, "%d %s %d",amount,items,once)!=3 )
                if(sscanf(arg, "%s from %s", items, targ)!=2 )
            if( sscanf(arg, "%d %s",amount,items)!=2 )
            if( sscanf(arg, "%s %d",items,once)!=2 )
                items=arg;
     if (items=="suger" && is_vendor_good(items,once) )
       {
         if (amount>1 ) { command("say sorry,我只有一根。");  return 1; }
              if ( ::do_buy(arg) ) {
               set("vendor_goods",({
        "/d/shaolin/obj/map",
        "/d/shaolin/obj/guide",
        "/d/village/npc/obj/stick",
        "/d/village/npc/obj/stick",
        "/d/village/npc/obj/shoes",
        "/d/village/npc/obj/bottle",
         }));
         return 1;
        }
    }
    else return ::do_buy(arg);
}
