#include <weapon.h>

inherit SWORD;
#include <ansi.h>

void create()
{
   set_name(HIC"���ǽ�"NOR, ({ "qixing sword", "jian", "sword" }) );
   set_weight(8000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 10000);
     set("material", "steel");
     set("long", "����һ�ѷ������ٽ𽣣����滭����������ǣ������Ի�����ǽ��������������˵��彣��\n");
     set("wield_msg", "һ�����������$N�����Ѷ��˰�$n��\n");
     set("unequip_msg", "$N�������е�$n��\n");
   }
   init_sword(400);
   setup();
}
int query_autoload() { return 1; }
