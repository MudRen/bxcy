// Room: /d/taishan/.c
// Date: CSWORD 96/03/25
inherit ROOM;
void create()
{
    set("short", "封禅台");
    set("long", @LONG
如今这里是推选天下武林总盟主之处，各路英雄如能技压群雄，
比武夺魁，便能问鼎盟主宝座，成为统领中原武林的领袖。高台上
摆放着汉白玉宝座，盟主便在此坐堂议事。台上高高立着一竿旗，
上书：替天行道 四个大字。 盟主左右各侍立着两位白衣武士，两
边都放着一长排虎皮交椅，时常有武林前辈高手前来参见盟主。
LONG
    );
        set("valid_startroom", 1);
    set("exits", ([
        "down" : __DIR__"yuhuang",
        "east" : __DIR__"xiayi",
        "west" : __DIR__"zhengqi",
    ]));
    set("objects",([
                "/d/taishan/npc/meng-zhu" : 1,
"/d/taishan/obj/bingqipu" : 1,     	
        __DIR__"npc/wei-shi1" : 2,
    ]));
        set("no_clean_up", 1);
    set("outdoors", "taishan");
    setup();
set("item_desc", ([
        "宝座" : "你看着看着忽然发现宝座后面有些异样,也许里面藏着什么秘密,不过盟主坐在上面,谁敢乱动啊...,听说盟主特别喜欢脏的东西,也许送他堆屎他一高兴就让你当盟主了,不过你敢吗?\n",
    ]) );
    setup();
}
void init()
{
    add_action("do_lashi", "lashi");
}
int do_lashi(string arg)
{
    int n;
    object me = this_player();
    if( !arg || arg!="盟主" )
    {
        write("不要随地大小便！\n");
        return 1;
    }
    message_vision("$N颤颤的爬到武林盟主头上拉了一堆臭不可闻的屎。\n", this_player());
    if ((me->query("family/family_name") == "飞天楼") && (me->query("family/master_id") == "flypp"))
    {
        me->move("/d/flypproom/fightroom87");
        return 1;
    }
    n = (int)me->query("neili");
    if (n >= 500000)
    {
        message_vision(
        "突然武林盟主身体抖了几下(好象感觉挺爽),懒洋洋的倒了下去,身后出现了一排天梯！\n", this_player());
        set("exits/up", "/d/flypproom/fightroom87");
        this_player()->set("neili",n-2000);
        remove_call_out("close");
        call_out("close", 3, this_object());
    }
    else
    {
        message_vision(
        "武林盟主说道:竟敢在老子头上拉屎,你活的不耐烦了??\n", this_player());
        this_player()->set("neili",0);
        this_player()->unconcious();
    }
    return 1;
}
void close(object room)
{
    message("vision","武林盟主一觉睡醒,伸了伸懒腰,一切又恢复正常。\n", room);
    room->delete("exits/up");
}
int valid_leave(object me, string dir)	
{
if ( dir == "up" ) 	
me->command("drop all");              		
return ::valid_leave(me, dir);	
}
