// Room: /d/dali/duchang2.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月19日，北京时间：21时32分59秒。

inherit ROOM;

void create()
{
set("short", "赌坊大厅");
	set("long", @LONG
 一眼看过去，这大厅里真是金碧辉煌，堂皇富丽，连烛台都是纯银的，
在这种地方输了千儿八百两金子，没人会觉得冤枉。大厅里摆满了大大小小
的赌桌，只要能说出名堂的赌具，这里都有。有匾(sign)一块。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "

骰子的赌法：

ｂｅｔ　＜种类＞　＜数量＞ ＜货币名称＞

种类：　０，１，２，３到１８
０：　		赌小	（３－１０）	一赔一
１：  		赌大	（１１－１８）	一赔一
２：　		赌围骰	（三粒骰子同点）一赔三十六
３－１８        赌单点                  一赔四

例子：
ｂｅｔ　０　５０ ｓｉｌｖｅｒ
赌五十两在小上

",
]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"duchang1",
]));

        set("objects", ([
"/d/city/npc/dice_thrower" : 1,	
        ]));

	setup();
}
