//LUCAS 2000-6-18
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
set_name( HIR "�ɽ���" NOR , ({ "yixi sword",}));	
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "������Ϲ��������֮һ"HIR"�ɽ�����"HIB"��˵�ɽ�һ��ʸ־���ʦ����Ը���ð������������һ�������񽣣�ȴ������޳��ݱ��һ�������������ľ���ħ����\n");
                set("value", 20000);
                set("material", "steel");
                set("weapon_prop/personality", 8);
                set("weapon_prop/unarmed", 100);
                set("wield_msg","$N����������һ��Ѫ��ӽ��ʳ��,"HIR"������������,Թ������,"HIW"һ��Ѫ���$n��Ȼ����" NOR);
set("unwield_msg", "$N��$n�����Ĳ�ؽ��� ��"GRN" ������أ�������̾�˿���...��" NOR);
        }
init_sword(1500,1);	
        setup();
}

int query_autoload() { return 1; }      	