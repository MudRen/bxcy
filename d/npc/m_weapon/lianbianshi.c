// Room: /d/npc/m_weapon/lianbianshi.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "造鞭潭");
    set("long", @LONG
这里是玄兵古洞的打造钢鞭的地方。处在荒芜人烟的戈壁滩上。居然能有这
样一泓漂亮的潭水，真是让人不得不赞叹大自然的鬼斧神工。潭边婷婷站者一位
妙龄的少女，手中把玩着一把看似极是锋利的匕首，呆呆的看着深邃的潭水出神。
LONG
    );
    set("no_clean_up", 0);
    set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shibian" : 1,
]));
    set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/xingxiu/luzhou",
]));
    setup();
    replace_program(ROOM);
}
