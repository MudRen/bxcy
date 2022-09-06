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
//��������
	w_name=me->query("jia/name");
	w_id = me->query("jia/id");
	w_or = me->query("jia/or");
	w_lv = me->query("jia/lv");
	w_time=me->query("jia/time");
        if (!me->query("jia/name"))
        {
	w_name="���Ƶļ���";
        }	
        if (!me->query("jia/id"))
        {
	w_id="jia";
        }	
        if (!me->query("jia/or"))
        {
	w_or="ǧ����ľ";
        }	
        if (!me->query("jia/lv"))
        {
	w_lv=1;
        }	
        set("material", "fur");
	set_name(w_name, ({w_id,"armor","jia"}));
	set("unit", "��");   
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
		case "ǧ����ľ" :
			set_weight(500);
set("material", "fur");
			break;
		case "���׽�ĸ" :
			set_weight(1000);
set("material", "fur");
			break;
		case "��˿����" :
			set_weight(30);
set("material", "fur");
			break;
		default :
		} 
	set("unit", "��");   
	if( me->query("jia/wear_msg"))
		set("wear_msg", me->query("jia/wear_msg")+"\n");
	else
		set("wear_msg", "$N����"+w_name+"�����ϡ�\n");
	if( me->query("jia/unequip_msg"))
		set("unequip_msg", me->query("jia/unequip_msg")+"\n");
	else
		set("unequip_msg", "$N���ϵ�"+w_name+"����������գ�ۼ���Ȼ����Ӱ�١�\n");
                set("armor_prop/armor", w_lv * 10);
	set("armor_type","cloth");
	set("material", "fur");
	
	result1="   ����һ����"+w_or+"������ɵ�"+w_name+"��";
	switch(w_or) {
		case "ǧ����ľ":
			result2="����������͸�죬�ƺ�ʮ�ּ�Ӳ��\n";
			break;
		case "���׽�ĸ":
			result2="�������ϳγεģ��ƺ�ʮ�ֳ��ء�\n";
			break;
		case "��˿����":
			result2="��������Ө���̣�͸��˿˿�ĺ��⡣\n";
			break;
		default:
			break;
		}
	switch(w_lv) {
		case 1:
			result3="���ƺ�������û�п�����������ϰ��֮�˳��õ����ס�\n";
			break;
		case 2:
			result3="���ƺ����������ܴ����ǽ����˳��õĻ������ס�\n";
			break;
		case 3:
			result3="������ɢ����һ˿���˲�������Ϣ.\n";
			break;
		case 4:
			result3="ɢ����һ˿���˲�������Ϣ, ��Ȼ��ͨ�����Ѳ��ܺ�������ˡ�\n";
			break;
		case 5:
			result3="����ɢ����һ˿���ɵ�����������һ�ְ���ɢ���˳�����\n";
			break;
		case 6:
			result3="һ�ɰ���ֱ��������ֱ���񾪹���.\n";
			break;
		case 7:
			result3="�����ƺ������������������������һ�ɺ��˵�������\n";
			break;
		case 8:
			result3="������������˿��˲����ľ���ս����Ը�ٿ��ڶ��ۡ�\n";
			break;
		case 9:
			result3="�����ƺ������˲��٣�һ���º͵�����֮��͸�˳�����\n";
			break;
		case 10:
			result3="һ���º͵�����֮�����Ƶ�ɢ���˳���.\n";
			break;
		default:
			result3="һ��ׯ�ϣ��ºͣ���Ȼ�������ַ�����Ϣ���˲�����һ˿����֮��, ���Ѿ����ӹ��棬��Ϊ�������Ϲ����. \n";
		}

	result4="������С׭����һ��С�֣�"+me->query("name")+"����"+w_time+"\n";
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
	{	return notify_fail("��Ҫ����ʲô?\n");
	}
	else
	{
		armor=this_object();
	}

	if(armor->query("equipped") ) 
	return notify_fail("������������!\n");

	if( (int)me->query("max_neili") < 10 )
		return notify_fail("��������������޷�����������\n");

	if( (int)me->query("qi") < 150 )
		return notify_fail("������������޷�����������\n");

	if( (int)me->query("eff_qi") < 30 )
		return notify_fail("�����ڵ�����̫�����޷�����������\n");

	if( (int)me->query("eff_jing") < 10 )
		return notify_fail("�����ڵľ����޷����У����ܶ���������\n");

	if((int)me->query("jia/lv")>39)
		 return notify_fail("��������Ѿ��������ˣ������������ˣ�\n");
		 
if( ((int)me->query("potential") - (int)me->query("learned_points"))< 2 )
		return notify_fail("���Ǳ�ܲ������޷�����������\n");

	message_vision(HIR "$N��ָ�׼���һ������˿˿�Ĵ��˽�ȥ��\n" NOR, me);

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
		message_vision(CYN "�������һ����һ����������$N�ļ��У������ˣ�\n" NOR,me);
		message_vision(HIG "$N�ļ׵ĵȼ�����ˣ�\n" NOR, me);
		armor=this_object();
		if(armor->query("equipped") ) 
			armor->unequip();
		reload_object( armor );
		me->set("jia/value",0);
		return 1;
	}
	message_vision(RED "$N�ļ���������!\n" NOR, me);
	return 1;
}


int do_hui(string arg)
{	
	string w_name;
	object me,ob;
	me=this_player();
	
	w_name=me->query("jia/name");
	if( !arg||arg!="armor" )
		return notify_fail("��Ҫ�ݻ�ʲô?\n");
	message_vision(HIR "$N���һ����һ����ף�һ���������¡������¡һ������"
			+w_name+HIR"�ٵķ���!\n" NOR,me);
	
	me->delete("jia");
	destruct( this_object() );
	
	me->save();

	return 1;
}

