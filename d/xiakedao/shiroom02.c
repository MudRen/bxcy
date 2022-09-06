// /d/xiakedao/shiroom02.c 侠客岛 石室2

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "石室");
        set("long", @LONG
进入第二间石室，只觉眼前一花，端的是剑气纵横。数人各持长
剑，正在捉对较量，兵刃撞击，铮铮不绝。地上遗弃着几柄长短不一
的断剑，墙上也有些兵器劈砍的斑痕。旁边有两位老者正在争论着什
麽。石壁(wall)上有若干字迹。
LONG );
        set("exits", ([
                "north" : __DIR__"shihole1",
        ]));
        set("item_desc", ([
                "wall" : @WALL
墙的正上方刻着「吴钩霜雪明」几个大字。大字的下方又密密麻麻地
刻满了数千小字，笔划各异，大小不同。第一行是：鲍照乐府：“锦
带配吴钩”。又有一行写的是：白居易诗云：“勿轻直折剑，犹胜曲
全钩”。
WALL
        ]));
        set("objects", ([
                __DIR__"master/zhang" : 1,
                __DIR__"master/feng"  : 1,
        ]));
/*
风清扬说道：非也，非也，这招应该剑意曲而剑势直

风清扬剑势忽缓而不疏，剑意有余而不尽，化恒山剑法为一剑，向张三丰慢慢推去！
但是张三丰身子一侧，用手中兵刃格开。

风清扬神声凝重，长剑上劈下切左右横扫，挟雷霆万钧之势逼往张三丰，「伏摩剑」剑意表
露无遗！
“哈哈哈……”张三丰一阵狂笑，轻轻一跃，轻描淡写地避开了风清扬的攻击，「豪气干云
」！
张三丰说道：这招好象应该这样，直中有曲，曲中有直

张三丰提起左腿转身垫步，右脚跟进，一招「黄峰入洞」，竹剑中宫直进，刺向风清扬的左
腿！
结果「噗」地一声刺进风清扬的左腿，使风清扬不由自主地退了几步！
( 风清扬似乎有些疲惫，但是仍然十分有活力。 )

张三丰向前连跳两步，一招「野马跳涧」，竹剑向前平刺风清扬的右脸！
却见风清扬踏前一步，剑式斜指张三丰的右脸，想要使张三丰闪身而退。
*/
        set("no_clean_up", 0);
        set("no_beg", 1);
        setup();
}
void init()
{
        add_action("do_study","think");
}
#include "/d/xiakedao/shiroom.h"
