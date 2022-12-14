// m_sword.c
#include <ansi.h>
#include <weapon.h>
//inherit M_WEAPON;	
inherit S_WEAPON;    	
int do_hui(object weapon);
int do_rename(string arg);
void init()
{
   if (!mapp(this_player()->query("weapon"))){
     this_object()->owner_is_killed();
     return;
   }

     if (this_player()!=environment()) return;
        add_action("do_duanlian","duanlian");
    add_action("do_hui","hui");
    add_action("do_rename","rename");
}
void create()
{   
    object me;
    string w_name,w_id,w_or;
    int w_lv;
    me = this_player();
//读入数据
    w_name=me->query("weapon/name");
    w_id = me->query("weapon/id");
    w_or = me->query("weapon/or");
    w_lv = me->query("weapon/lv");
    set_name(w_name, ({w_id,"whip"}));
    set("unit", "柄");   
    set("no_get",1);
    set("no_drop",1);
    set("no_give",1);
set("no_put",1);
set("bianren",w_lv);         //  龙云梦增加于2003年12月17日		
    set_desc(w_lv,w_or,w_name);
    switch(w_or)
        {
        case "千年神木" :
            set_weight(6000+w_lv*450);
            set("material", "iron");
            break;
        case "海底金母" :
            set_weight(8000+w_lv*450);
            set("material", "steel");
            break;
        case "寒丝羽竹" :
            set_weight(4000+w_lv*450);
            set("material", "bamboo");
            break;
        default :
        } 
    set("wield_msg", "$N往腰中一摸，刷的抖出了一把"+w_name+"\n");
    set("unwield_msg", "$N手中"+w_name+"一抖，眨眼间卷回腰间不见了影踪。\n");
    init_whip(w_lv * 10 + 2,2);
    setup();
}   
int do_duanlian(string arg)
{
    object me;
    object weapon;
    string w_name;
    int w_zhi, w_level;
    string w_or;
    me=this_player();
    w_name=me->query("weapon/name");
    if( !arg || !id(arg) )
        return notify_fail("你要锻炼什么?\n");
    if( (int)me->query("max_neili") < 1000 )
        return notify_fail("你的内力不够，无法锻炼兵器！\n");
    if( (int)me->query("qi") < 150 )
        return notify_fail("你的气不够，无法锻炼兵器！\n");
    if( (int)me->query("eff_qi") < 50 )
        return notify_fail("你现在的体力太弱，无法锻炼兵器！\n");
    if( (int)me->query("eff_jing") < 50 )
        return notify_fail("你现在的精力无法集中，不能锻炼兵器！\n");
    if( ((int)me->query("potential") - (int)me->query("learned_points"))< 2 )
        return notify_fail("你的潜能不够，无法锻炼兵器！\n");
    message_vision(HIR "$N手捏鞭稍，一股内力丝丝的传了进去。\n" NOR, me);
    me->add("max_neili",-10);
    me->set("neili", (int)me->query("max_neili"));
    me->add("qi",-150);
    me->add("eff_qi",-30);
    me->add("eff_jing",-30);
me->add("potential",-2);
    w_zhi = (int)me->query("weapon/value");
    w_zhi++;
    me->set("weapon/value", w_zhi);
    w_or = (string)me->query("weapon/or");
    w_level = (int)me->query("weapon/lv");
    if( w_zhi >= ((w_level + 1) * (w_level + 1)))
    {
        w_level++;
        me->set("weapon/lv", w_level);
        message_vision(HIY "鞭身忽的一亮，一道金光隐入$N的"+w_name+"，不见了！\n" NOR,me);
        message_vision(HIG "$N的"+w_name+"的等级提高了！\n" NOR, me);
        weapon=this_object();
        if(weapon->query("equipped") ) 
            weapon->unequip();
        reload_object( weapon );
        me->set("weapon/value",0);
        return 1;
    }
    message_vision(RED "$N的"+w_name+"的质地改善了!\n" NOR, me);
    return 1;
}
int do_hui(string weapon)
{   
    string w_name;
    object me;
    me=this_player();
    w_name=me->query("weapon/id");
    if( !weapon || w_name!=weapon)
        return notify_fail("你要摧毁什么?\n");
    message_vision(HIR "你大喝一声，一手擎鞭，一手猛的一扯。结果啪的一声爆响"
            +this_object()->name()+HIR+"断为两截!\n" NOR,me);
    me->delete("weapon");   
    me->save();
    destruct( this_object() );
    return 1;
}
int do_rename(string arg)
{
    object me;
    me=this_player();
    if( !arg )
        return notify_fail("你改什么的名字?\n");
if (this_object()->query("bianren") > me->query("weapon/lv"))    	
return notify_fail("你只能改自己剑的名字!\n");		
if( strlen(arg) > 30 )          		
return notify_fail("你的兵器名称最多只能设置十五个字符。\n");     	
    arg = replace_string(arg, "$BLK$", BLK);
    arg = replace_string(arg, "$RED$", RED);
    arg = replace_string(arg, "$GRN$", GRN);
    arg = replace_string(arg, "$YEL$", YEL);
    arg = replace_string(arg, "$BLU$", BLU);
    arg = replace_string(arg, "$MAG$", MAG);
    arg = replace_string(arg, "$CYN$", CYN);
    arg = replace_string(arg, "$WHT$", WHT);
    arg = replace_string(arg, "$HIR$", HIR);
    arg = replace_string(arg, "$HIG$", HIG);
    arg = replace_string(arg, "$HIY$", HIY);
    arg = replace_string(arg, "$HIB$", HIB);
    arg = replace_string(arg, "$HIM$", HIM);
    arg = replace_string(arg, "$HIC$", HIC);
    arg = replace_string(arg, "$HIW$", HIW);
    arg = replace_string(arg, "$NOR$", NOR);
    me->set("weapon/name",arg+NOR);
    set("name",arg+NOR);
    write("ok!\n");
    this_object()->create();
    return 1;
}
