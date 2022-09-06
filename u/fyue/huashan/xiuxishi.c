// Room: xiuxishi.c
inherit ROOM;
void init();
void close_men();
int do_open(string);
int do_close(string);
string look_men();
void create()
{
        set("short", "华山小筑");
        set("long", @LONG
这是间整洁的厢房,因门(men)窗常闭着，光线很昏暗。房里别
无他物，只有中间放着一张收拾得舒舒服服的大床，看着就让人想
睡觉。
LONG
        );
        set("sleep_room", 1);
        set("no_fight", 1);
        set("item_desc",([
            "men"   :   (: look_men :),
        ]));
        setup();
}
void init()
{
    add_action("do_open", "open");
    add_action("do_close", "close");
}
string look_men()
{
    if (query("exits/west"))
        return ("门已经是开着了。\n");
    return ("门已经关上了。\n");
}
void close_men()
{
    object room;
    if(!( room = find_object(__DIR__"xiaolu2")) )
        room = load_object(__DIR__"xiaolu2");
    if(objectp(room))
    {
        delete("exits/west");
            message("vision", "门咿咿呀呀地自己合上了。\n", this_object());
        room->delete("exits/east");
        message("vision", "门咿咿呀呀地自己合上了。\n", room);
    }
}
int do_close(string arg)
{
    if (!query("exits/west"))
        return notify_fail("门已经是关着的了。\n");
    if (!arg || (arg != "men" && arg != "door"))
        return notify_fail("你要关什么？\n");
    message_vision("$N想把门关上。\n", this_player());
    remove_call_out("close_men");
    call_out("close_men", 2);
    return 1;
}
int do_open(string arg)
{
    object room;
    object me = this_player();
    if (query("exits/west"))
        return notify_fail("大门已经是开着了。\n");
    if (!arg || (arg != "men" && arg != "door" && arg != "west"))
        return notify_fail("你要开什么？\n");
    if(!( room = find_object(__DIR__"xiaolu2")) )
        room = load_object(__DIR__"xiaolu2");
    if(objectp(room))
    {
        set("exits/west", __DIR__"xiaolu2");
        message_vision("$N轻手轻脚地把门打开。\n", this_player());
        room->set("exits/east", __FILE__);
        
        if (me->query_temp("sleeped"))
        {
        message("vision", "吱地一声，"+me->query("name")+"精神焕发地从里面把门打开了。\n",
        room);
        } else 
        {
        message("vision", "梆地一声，"+me->query("name")+"从里面把门打开，一脸的不耐烦。\n",
             room);
        }   
        
        remove_call_out("close_men");
        call_out("close_men", 10);
    }
    return 1;
}
int valid_leave(object me, string dir)
{
    object room;
    if ( !::valid_leave(me, dir) ) 
        return 0;
    
    if(!(room = find_object(__FILE__)) )
        room = load_object(__FILE__);
    if(objectp(room))
    {
        room->add_temp("person_inside", -1);    
        if ((int)room->add_temp("person_inside", -1) <= 0)
            room->delete_temp("person_inside"); 
    }
    
    return 1;
}
