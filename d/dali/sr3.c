inherit ROOM;
void create()
{
        set("short", "?ײ?");
        set("long", @LONG
?ײ???????ʪ???????˱ǡ????ϲյĸ????????????Ǻϡ?һյ?????ĵ??????Ŵ?
????ҡ?ڶ?????֨֨?????ı??????????壬?ƺ?????ˮ???????????յױ??䣬?ƺ???
?Ըе???ˮ????????
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"sr1",
]));

        setup();
}