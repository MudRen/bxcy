// m_jia.c

#include <ansi.h>

#include <armor.h>

inherit S_ROBE;


int duanlian(string arg);
int do_hui(object armor);




void init()
{
        add_action("do_duanlian","duanlian");
	add_action("do_hui","hui");
	add_action("do_levelup","jijia");
}


void create()
{	
	object me;
	string w_name,w_id,w_or,w_time;
	string result1,result2,result3,result4,result;
	int w_lv;
	me = this_player();
//读入数据
	w_name=me->query("jia/name");
	w_id = me->query("jia/id");
	w_or = me->query("jia/or");
	w_lv = me->query("jia/lv");
	w_time=me->query("jia/time");
        if (!me->query("jia/name"))
        {
	w_name="自制的甲衣";
        }	
        if (!me->query("jia/id"))
        {
	w_id="jia";
        }	
        if (!me->query("jia/or"))
        {
	w_or="千年神木";
        }	
        if (!me->query("jia/lv"))
        {
	w_lv=1;
        }	
        set("material", "fur");
	set_name(w_name, ({w_id,"armor","jia"}));
	set("unit", "件");   
	set("value",0);
	set("no_get",1);
	set("no_drop",1);
	set("no_give",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
	set("material", "fur");
	switch(w_or)
		{
		case "千年神木" :
			set_weight(500);
set("material", "fur");
			break;
		case "海底金母" :
			set_weight(1000);
set("material", "fur");
			break;
		case "寒丝羽竹" :
			set_weight(30);
set("material", "fur");
			break;
		default :
		} 
	set("unit", "件");   
	if( me->query("jia/wear_msg"))
		set("wear_msg", me->query("jia/wear_msg")+"\n");
	else
		set("wear_msg", "$N穿上"+w_name+"在身上。\n");
	if( me->query("jia/unequip_msg"))
		set("unequip_msg", me->query("jia/unequip_msg")+"\n");
	else
		set("unequip_msg", "$N身上的"+w_name+"脱了下来，眨眼间已然不见影踪。\n");
                set("armor_prop/armor", w_lv * 10);
	set("armor_type","cloth");
	set("material", "fur");
	
	result1="   这是一件用"+w_or+"打造而成的"+w_name+"。";
	switch(w_or) {
		case "千年神木":
			result2="看起来黑中透红，似乎十分坚硬。\n";
			break;
		case "海底金母":
			result2="看起来紫澄澄的，似乎十分沉重。\n";
			break;
		case "寒丝羽竹":
			result2="看起来晶莹碧绿，透着丝丝的寒意。\n";
			break;
		default:
			break;
		}
	switch(w_lv) {
		case 1:
			result3="但似乎威力还没有开发出来，是习武之人常用的铠甲。\n";
			break;
		case 2:
			result3="但似乎威力并不很大，象是江湖人常用的护身铠甲。\n";
			break;
		case 3:
			result3="隐隐的散发着一丝令人不安的气息.\n";
			break;
		case 4:
			result3="散发着一丝令人不安的气息, 显然普通铠甲已不能和他相比了。\n";
			break;
		case 5:
			result3="向外散发着一丝迷蒙的雾气，竟有一种霸气散发了出来。\n";
			break;
		case 6:
			result3="一股霸气直冲霄汉，直叫神惊鬼泣.\n";
			break;
		case 7:
			result3="霸气似乎有所收敛，但更多的是有了一股骇人的戾气。\n";
			break;
		case 8:
			result3="冲天的戾气叫人看了不由心惊胆战，不愿再看第二眼。\n";
			break;
		case 9:
			result3="戾气似乎削减了不少，一股温和的王者之气透了出来。\n";
			break;
		case 10:
			result3="一股温和的王者之气悠悠的散发了出来.\n";
			break;
		default:
			result3="一种庄严，温和，凛然而不可侵犯的气息让人不敢有一丝亵渎之意, 它已经返朴归真，成为真正的上古神兵. \n";
		}

	result4="上面用小篆刻着一行小字："+me->query("name")+"造于"+w_time+"\n";
	result=result1+result2+result3+result4;
	set("long",result);
	
	
	setup();
}	



int do_duanlian(string arg)
{
	object me,armor;
	int w_zhi, w_level;
	string w_or;

	me=this_player();
	

	if( !arg||arg!="armor" )
	{	return notify_fail("你要锻炼什么?\n");
	}
	else
	{
		armor=this_object();
	}

	if(armor->query("equipped") ) 
	return notify_fail("甲你正穿着呢!\n");

	if( (int)me->query("max_neili") < 10 )
		return notify_fail("你的内力不够，无法锻炼甲气！\n");

	if( (int)me->query("qi") < 150 )
		return notify_fail("你的气不够，无法锻炼甲气！\n");

	if( (int)me->query("eff_qi") < 30 )
		return notify_fail("你现在的体力太弱，无法锻炼甲气！\n");

	if( (int)me->query("eff_jing") < 10 )
		return notify_fail("你现在的精力无法集中，不能锻炼甲气！\n");

	if((int)me->query("jia/lv")>39)
		 return notify_fail("你的铠甲已经到极限了，不能再升级了！\n");
		 
if( ((int)me->query("potential") - (int)me->query("learned_points"))< 2 )
		return notify_fail("你的潜能不够，无法锻炼甲气！\n");

	message_vision(HIR "$N手指甲脊，一股内力丝丝的传了进去。\n" NOR, me);

	me->add("max_neili",-2);
	me->set("neili", (int)me->query("max_neili"));
	me->add("qi",-150);
	me->add("eff_qi",-30);
	me->add("jing",-30);
	me->add("eff_jing",-30);
	me->add("potential", -2);

	w_zhi = (int)me->query("jia/value");
	w_zhi++;
	me->set("jia/value", w_zhi);
	w_or = (string)me->query("jia/or");
	w_level = (int)me->query("jia/lv");
	if( w_zhi >= ((w_level + 1) * (w_level + 1)))
	{
		w_level++;
		me->set("jia/lv", w_level);
		message_vision(CYN "甲身忽的一闪，一道银光隐入$N的甲中，不见了！\n" NOR,me);
		message_vision(HIG "$N的甲的等级提高了！\n" NOR, me);
		armor=this_object();
		if(armor->query("equipped") ) 
			armor->unequip();
		reload_object( armor );
		me->set("jia/value",0);
		return 1;
	}
	message_vision(RED "$N的甲气提升了!\n" NOR, me);
	return 1;
}


int do_hui(string arg)
{	
	string w_name;
	object me,ob;
	me=this_player();
	
	w_name=me->query("jia/name");
	if( !arg||arg!="armor" )
		return notify_fail("你要摧毁什么?\n");
	message_vision(HIR "$N大喝一声，一掌擎甲，一掌猛力击下。结果轰隆一声巨响"
			+w_name+HIR"毁的粉碎!\n" NOR,me);
	
	me->delete("jia");
	destruct( this_object() );
	
	me->save();

	return 1;
}

