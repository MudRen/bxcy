// yitian-jian 倚天剑
// Modifyied by Uranus

#include <weapon.h>
#include <ansi.h>
int do_hukan();
inherit SWORD;

void create()
{
        set_name(HIY HIW "倚天剑" NOR,({ "yitian jian", "yitian", "sword", "jian" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
            set("value",50000);
//             set("no_drop", "这样东西不能离开你。\n");	
		set("no_put",1);
                set("material", "steel");
                set("long", "这是一柄四尺来长的古剑，剑鞘上金丝镶着两个字“倚天”。
整个剑身隐隐发出一层青气，剑未出鞘，已可见其不凡。\n");
                set("wield_msg", HIY "$N“唰”的一声抽出$n" + HIY + "挽了个剑花，但见寒芒吞吐，
电闪星飞。 ....$N不由得从心底升起一股凌云豪气。\n" NOR);
                set("unwield_msg", HIW "倚天剑"HIY"幻作一道白光，「唰」地飞入剑鞘。\n" NOR);
                set("unequip_msg", HIW "倚天剑"HIY"幻作一道白光，「唰」地飞入剑鞘。\n" NOR);
        }
init_sword(400,2);	
        setup();
}

// Add by Uranus

void init()
{
        add_action("do_hukan", "hukan");
}

int do_hukan()
{
	object me,dao,jian,book;
	string own;
	me = this_player();
	jian = this_object();

	if ( !present("tulong dao", me) )
		return notify_fail(HIW"你还没有拿到屠龙刀呢，拿什么跟倚天剑互砍？\n"NOR);

	dao=present("tulong dao", me);

	if ( dao->query("name") != HIW HIY "屠龙刀" NOR )
	{
		dao->unequip();
		dao->set("name", "断掉的" + dao->query("name"));
		dao->set("value", 0);
		dao->set("weapon_prop", 0);
		message_vision(HIC"$N大喝一声，拿起屠龙刀向倚天剑砍去。\n结果屠龙刀啪地一声断成两截。\n"NOR,me);
		return notify_fail(HIW"你这把屠龙刀只怕是假的吧！\n"NOR);
	}

	if ( me->query("neili") <2000 )
		return notify_fail(HIW"你的内力太低了，只怕砍不断吧！\n"NOR);

else if ( jian->query("name") == HIY HIW "倚天剑" NOR )	
	{
		jian->unequip();
		jian->set("name", "断掉的" + jian->query("name"));
		jian->set("value", 10000);
		jian->set("weapon_prop", 0);
		dao->unequip();
		dao->set("name", "断掉的" + dao->query("name"));
		dao->set("value", 10000);
		dao->set("weapon_prop", 0);
		message_vision(HIC"$N大喝一声，拿起屠龙刀向倚天剑砍去。\n"+
				"只听一声金铁相击之音，倚天剑和屠龙刀双双断成两截。\n"NOR,me);
book = new("/clone/misc/wumu-yishu");	
		own = me->query("id");
		book->set("master",own);
		book->move(me);
		message_vision(HIC"$N从断掉的屠龙刀中拿出一本书。\n"NOR,me);
		return 1;
	}
}

/* --- End of Modify --- */



int query_autoload() { return 1; }
