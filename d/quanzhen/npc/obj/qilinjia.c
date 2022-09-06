
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name(HIR"麒麟甲"NOR, ({ "qilinjia" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("material", "cloth");
                set("for_create_cloth",1);
		set("base_armor",20);
                set("armor_prop/armor", 1200);
		set("long","一块麒麟的披甲。\n");
		set("max_enchant",3);
		set("value",200000);
        }
        setup();
}

void init()
{      if(this_player()!=environment())
	add_action("do_get","get");
}

int do_get(string arg)
{
	object me=this_player();
	object ob=this_object();
	string place;
	if(environment(ob)->query("short"))
	place = environment(ob)->query("short");
	else place = "一个不为人知的地方";
	if(arg=="qilinjia"){
	if(ob->move(me))
	message("channel:rumor",HIW"\n〖江湖传闻〗：听说"+me->name()+"在"+place+"弄到了一块"HIR"麒麟甲\n\n"NOR,users());
me->add("jing",-(me->query("max_jing")/3));
me->set("neili",0);
	return 1;
}
      return 0;
   }
int query_autoload() { return 1; }
