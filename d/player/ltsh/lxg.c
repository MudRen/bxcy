// Room: /u/aplio/ltsh/lxg.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "灵宵阁");
	set("long", @LONG
支撑整栋大殿，两条金漆镶龙大柱刻着：
　　　飞四　　　　　　　　　　风统　
　　　龙海　　　　　　　　　　起率
　　　在逍　　　　　　　　　　云江
　　　天遥　　　　　　　　　　涌湖
　　　龙浪　　　　　　　　　　枭翻
　　　腾起　　　　　　　　　　雄云
　　　震惊　　　　　　　　　　出与
　　　九风　　　　　　　　　　乱覆
　　　宵云　　　　　　　　　　世雨
居中一条红色地毯从石阶伸延到太师椅下。椅上一件白虎皮，似在炫耀无尽权势
风光。椅上端坐着一位剑眉星目，深不可测的就是亦正亦邪翻云总帮主。在帮主
右边傲然挺立着一位精光内敛的外家高手，便是让人谈虎色变的覆雨副帮主。而
左首边一座紫檀木雕托着就是震帮之宝：真武剑！
LONG
);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"tnt_room",
  "west" : __DIR__"taizi_room",
  "westdown" : __DIR__"tst",
  "east" : __DIR__"mask_room",
]));

	setup();
	replace_program(ROOM);
}
