
//modify by isle

inherit ROOM;

void create()
{
	set("short", "书馆");
	set("long", @LONG
这里是书馆的大厅，窗明几净，一尘不染。一位庄重严肃的老者坐在太师
椅上讲学。在他的两侧坐满了抄书的学生。一张古意盎然的书案放在先生
的前面，案上摆着几本翻开了的线装书籍。
LONG );
	
        set("no_fight", 1);
        set("no_sleep_room", 1);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"beimen",
	]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/xiansheng" : 1,
	]));

	setup();
	replace_program(ROOM);
}
