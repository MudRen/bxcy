inherit NPC;
string inquiry_dao();
void create()
{
    set_name("老材", ({ "lao cai","cai" }) );
    set("gender", "男性" );
    set("nickname","老财");
    set("age", 40);
    set("long", "一个有名的吝啬鬼，好象他整日看守着柴房也能发财似的。\n");
    set("shen_type",-1);
    set("combat_exp", 10000);
    set("str", 17);
    set("dex", 18);
    set("con", 18);
    set("int", 18);
    set("attitude", "friendly");
    set("inquiry" , ([
    "柴刀" : (: inquiry_dao :),
    ]));
    setup();
    carry_object("/clone/misc/cloth")->wear();
}
string inquiry_dao()
{
 object me=this_player();
 object ob;
 object *obj;
 int i;
 if (time()-me->query_temp("cai_dao")<60)
        return "老材瞪着眼说：你刚才不是拿了吗？还想要！\n";
 obj=deep_inventory(me);
 if (sizeof(obj))
 for (i=0;i<sizeof(obj);i++)
    if (obj[i]->id("cai dao"))
        return "老材瞪着眼说：你身上带着一把，还想要！\n";
 ob=new("/d/baituo/obj/chaidao");
 ob->move(me);
 me->set_temp("cai_dao",time());
  return "老材递给你一把柴刀，嘱咐道说：小心保管！\n";
}
