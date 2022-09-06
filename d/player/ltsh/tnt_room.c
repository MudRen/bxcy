// Room: /u/aplio/ltsh/tnt_room.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "观星寒舍");
	set("long", @LONG
提起自然星体，不得不提江湖中最出名的星学大师：小市民。
他不但拥有高超的武功，那洞悉天机的天赋异能才让人不可思议。
这自然而然被帮主奉为上宾，观星寒舍固名是专为这位大师而设
的居舍。
　　　　　　古有诸葛今有我，
　　　　　　庸人自扰难开脱。
　　　　　　每星各透人命运，
　　　　　　愿尽所能析疑惑。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"lxg",
]));

	setup();
	replace_program(ROOM);
}
