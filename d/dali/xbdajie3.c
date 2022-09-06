// Room: /d/dali/xbdajie12
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月21日，北京时间：17时28分57秒。

inherit ROOM;

void create()
{
        set("short", "夕照路");
        set("long", @LONG
这是一条大理石铺成的大道，街面上几乎一尘不染，十分的干净，据
说每当夕阳西下的时候，这里就会由于大理石的反照而出现光芒四射的美
景，甚是壮观。来来往往的人匆匆的走着，都在忙着各自的事情，一副祥
和的气氛，微风吹动着路边的柳树，顿时也摇曳多姿起来，让人顿生一种
心神俱爽之意。大道向南延伸着，东边是一个大理的[1;32m北城门[2;37;0m，快赶路吧！
LONG
        );
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaofan" : 1,
]));

        set("outdoors", "dali");
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"beidajie3",
  "south" : __DIR__"xbdajie2",
]));

        setup();
}


