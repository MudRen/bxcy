// Room: /u/cass/hg/shenwumen.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "神武门");
	set("long", @LONG
由箭楼和正楼两部份组成。箭楼有两重飞檐，四层箭窗，首层平台围有
汉白玉石栏，琉璃瓦顶飞龙翘首，神态逼真。正楼有三重飞檐，两层楼阁。
朱红的梁柱上饰以金桦彩云，显得巍峨雄伟。在灿烂的阳光下更加金碧辉煌。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"qinandian",
  "north" : "/d/city2/hbridge",
]));

        set("objects", ([
                "/d/huanggon/npc/shiwei" : 1,
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
        ]));

	setup();
}
int valid_leave(object me, string dir)
{
    int i;
    object *inv,ob1,ob2;
    ob1=present("wu jiang", environment(me));
    ob2=present("guan bing", environment(me));
    if(dir=="south") {
     if( me->query("huanggong/canenter") ) {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop")&& (inv[i]->query("equipped")))
                if( objectp(ob1) && living(ob1) )
                    return notify_fail("武将上前挡住你，朗声说道：这位" +
                        RANK_D->query_respect(me) + "请放下兵刃。\n"
                        "不得持兵刃入宫。\n");
                else if(objectp(ob2) && living(ob2) )
                    return notify_fail("官兵上前挡住你，朗声说道：这位" +
                        RANK_D->query_respect(me) + "请放下兵刃。\n"
                        "不得持兵刃入宫。\n");
        return 1;
        }else{
        if (me->query("gender") == "女性") {
           if( objectp(ob1) && living(ob1) )
            return notify_fail("武将上前挡住你,朗声说道：皇宫重地，岂" 
            "容寻常烟花女子自由出入,\n" + RANK_D->query_respect(me) +"请回，免得"
                "自取其辱。\n");
        else  if( objectp(ob2) && living(ob2) )
            return notify_fail("官兵上前拦住你，朗声说道：皇宫重地，岂" 
            "容寻常烟花女子自由出入,\n" + RANK_D->query_respect(me) +"请回，免得"
            "自取其辱。\n");
        }
        if (me->query("gender") == "无性") {
           if( objectp(ob1) && living(ob1) )
            say("武将笑吟吟地说道：这位公公您辛苦了，快请进吧。\n");
        else   if( objectp(ob2) && living(ob2) )
            say("官兵笑吟吟地说道：这位公公您辛苦了，快请进吧。\n");
        }
        if (me->query("gender") == "男性") {
           if( objectp(ob1) && living(ob1) )
            return notify_fail("武将伸手拦住你朗声说道：皇宫重地，岂" 
            "容寻常乡村野夫自由出入.\n" + RANK_D->query_respect(me) +"请回，免得"
                "自取其辱。\n");
        else   if( objectp(ob2) && living(ob2) )
            return notify_fail("官兵伸手拦住你朗声说道：皇宫重地，岂" 
            "容寻常乡村野夫自由出入\n" + RANK_D->query_respect(me) +"请回，免得"
            "自取其辱。\n");
        }
        }
    }       
    return 1;
}

