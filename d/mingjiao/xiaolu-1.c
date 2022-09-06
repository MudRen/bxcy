// Room: xiaolu-1.c

inherit ROOM;

void create()
{
        set("short", "林间小路");
        set("long", @LONG
你走进一片松林，阳光照在松林中，一缕一缕的阳光，好
象有了弹性似的，反照下来，洒在人的身上，如细雨一般舒畅。
你仰着脸好象在饮着无私的和煦的阳光。阳光好金好亮，当山
风走过，全山的松林都摇首摆脑，发出“呵呵”的声音。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"banshanyao1",
  "northeast" : __DIR__"qian-ting",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        setup();
        replace_program(ROOM);
}

