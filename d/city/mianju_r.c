// Room: /u/wyz/mianju1.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
        set("short", "夕阳泥吧");
        set("long", @LONG
这里是一家超大规模机房的大厅，这儿常门庭若市，好不热闹，柜台里的漂
亮小姐看见你进来，笑咪咪的迎了上来，使人还没进机房里面玩就有一种乐不思
孰的感觉，向房子里望望，只见人头挤挤，你已经按耐不住，冲了进去
LONG
);
        set("exits", ([
                "southeast" : "/d/city/guangchang",
//   "west" : "/d/city/mishi",       	
        ]));
           set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/guizi" : 1,
]));

    set("no_fight",1);
        setup();
        call_other("/d/board/mianju_b", "???");
}
void init()
{
        object me=this_player();
        add_action("kick_out","kickout");
        if (me->query("id")!="zjkknds")
        if (me->name()!=me->name(1)){
         message_vision("$N从半空中划了一道美妙的弧线，惨嚎着飞了出去 ！\n",me);
         me->move("/d/city/guangchang");
        }
        add_action("discmds",({"pretend","kill","hit","array"}));
}
int discmds(string arg)
{
    tell_object(this_player(),"商场里面可不能动粗耶！\n");
    return 1;
}

int kick_out(string str)
{
   object me=this_player();
   object ob;
   if (!str) return 0;
   if (me->query("id")!="zjkknds") return 0;
   if (!ob=present(str,this_object()))
        return 0;
   if (!living(ob) || wizardp(ob))      return 0;
   message_vision("$N飞起左脚把$n撩了起来，紧跟着右脚把$n踢了出去！\n",me,ob);
   ob->move("/d/city/guangchang");
   message("vison",ob->name()+"从半空中划了一道美妙的弧线，惨嚎着滚到你脚边！\n",environment(ob),({ob}));
   return 1;
}

