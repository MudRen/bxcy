// salt.c
#include <ansi.h>

inherit COMBINED_ITEM;

int value() { return query_amount() * (int)query("base_value"); }

void create()
{
	set_name(HIW "盐" NOR, ({ "illicit salt","salt" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","人们生活中不可缺少的生活用品。看到了白花花的盐，你仿佛看到了白花花的银子！\n");
		set("unit", "些");
		set("base_unit", "斤");
		set("base_weight", 1000);
                set("base_value", 100);
	}
	set_amount(1);
	setup();
	call_out("lost",30);
}
int lost()
{
	if (environment())
	if (environment()->is_character()){
		add_amount(-1);
		tell_object(environment(),"你的"+this_object()->name()+"漏了!\n");
		new(base_name(this_object()))->move(environment(environment()));
        }else{
          if (query_amount()>2)
                add_amount(-query_amount()/2);
          else
                add_amount(-1);
         }
	call_out("lost",30);
	return 1;
}
void init()
{
	object	room;

	room=environment();
	while (room){
		if (room->is_character()){
			room->set_temp("illicit",1);
			return;
		}
		room=environment(room);
	}
}
int query_autoload() { return 1; }