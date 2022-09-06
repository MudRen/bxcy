// swordbook.c

inherit ITEM;

void create()
{
	set_name( "��������", ({ "sword book", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ὣ�����ţ���������ų�ǳ�Ľ�����\n");
		set("value", 5000);
		set("material", "paper");
		set("skill", ([
			"name":	"sword",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 20, 	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	30,	// the maximum level you can learn
		]) );
	}
}
int query_autoload() { return 1; }