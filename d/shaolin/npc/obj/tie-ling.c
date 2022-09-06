inherit ITEM;
void create()
{
    set_name( "少林英雄令", ({ "yingxiong ling", "ling", "iron" }) );
    set_weight(800);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "块");
             set("long", "这是一块用于通行少林寺的铁铸令牌。 由方丈签发，邀各路英雄入寺观礼。\n");
            set("shaolin",1);
             set("no_drop","这东西不能随便丢弃！");
             set("no_get",1);
            set("no_put",1);
        set("material", "iron");
    }
    setup();
        call_out("dest", 1800);
}
void dest()
{
    object ob=environment(this_object());
    if (ob)
    if (userp(ob) && domain_file(base_name(environment(ob)))=="shaolin" ){
       if (ob->query_condition("bonze_jail")){
               destruct(this_object());
               return;
        }
            tell_object(ob, HIY "几个僧兵对你喝道：时辰已过，施主为何还逗留寺中？\n"+"只觉一阵腾云驾雾般，你昏昏沉沉地被扔出了少林寺！\n" NOR);
            ob->move("/d/nanyang/shanmen");
            message("vision",
                HIY "只听乒地一声，你吓了一跳，定睛一看，\n"
                "原来是一个昏昏沉沉的家伙从大门里被扔了出来！\n" NOR, environment(ob), ob);
    }
    destruct(this_object());
}
int query_autoload() { return 1; }