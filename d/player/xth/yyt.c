// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "演义堂");
	set("long", "这是一个方圆百丈的大广场，一个用白玉汉石砌成五丈高
的擂台耸立在广场中央，从上面不时传来吆喝声和惨叫声，擂
台的四个边角竖着四根十多丈高的旗杆，分别用金线绣着啸天
演义个大字.这里是给啸天会里面兄弟们了解恩怨的地方。\n");
       
	set("exits", ([
                "west" : __DIR__"jyt",
                "east" : __DIR__"clc2",

	]));
	setup();
	replace_program(ROOM);
}

