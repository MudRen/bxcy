// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "演武堂");
	set("long", "这是一个方圆百丈的大广场，一个用白玉汉石砌成五丈高
的擂台耸立在广场中央，从上面不时传来吆喝声和惨叫声，擂
台的四个边角竖着四根十多丈高的旗杆，分别用金线绣着啸天
演武四个大字，广场的正西方用同样的石料砌了一个小台。台
上竖着一根大旗杆，一张大旗(flag)迎风招展。\n");
       
	set("exits", ([
                "east" : __DIR__"jyt",
                "west" : __DIR__"clc1",

	]));
	setup();
	replace_program(ROOM);
}

