inherit ITEM;

void create()
{
        set_name("信件", ({"xin", "letter"}));
        set("long",
               "这是一封你师门托付你的信件。\n");
        set("unit", "封");
        set("weight", 5);
//	set("no_drop", 1);
	set("no_get", 1);

	setup();
}
