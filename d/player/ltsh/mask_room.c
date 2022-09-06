// Room: /u/aplio/ltsh/mask_room.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "悠然静舍");
	set("long", @LONG
龙腾四海另一贵宾，亦是两位帮主至亲好友。江湖一直
流传着，阿颂当时与两位帮主各为其主。曾经有过一段十分
精彩，百年难得一见的比武。后来因与两位帮主惺惺相识，
结为兄弟。阿颂现已看破世情，向往悠然自在的生活，这里
亦就是阿颂，品尝幽茗，优游自得的一处好地方。
            名利各逐笑君痴，
            看破红尘渐隐世。 
            云游浪荡自逍遥，
            阿颂嘻哈乐融融。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lxg",
]));

	setup();
	replace_program(ROOM);
}
