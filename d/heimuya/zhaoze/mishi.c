// Room: /d/heimuya/zhaoze/mishi.c
inherit ROOM;
int do_get(string arg);
void relay_circs(object me);
void create()
{
        set("short", "密室");
        set("long", @LONG
这里黑呼呼的，你什么都看不见。
LONG
);
        set("exits", ([ 
        "out" : __DIR__"shx",
]));
        setup();
}
void init()
{
    object me;
    me = this_player();
        set("long", @LONG
这里黑呼呼的，你什么都看不见。
LONG
);
     delete("item_desc"); 

    if (time()-query("time")>3600)
        set("yangpi",1);
    if (userp(me)){
        call_out("relay_circs",5,me);
        }
}
void relay_circs(object me)
{
//    if (environment(me)!=this_object()) return;             	

//     if ( !present("ming zhu",me) ) return;  	
     write("  你怀里的夜明珠忽然发出一阵豪光，你发现这密室四周空荡荡的,
但是却十分干燥，不知为何水进不来。在密室的中央有一石盒(box)。\n");
        set("long", @LONG
凭借夜明珠的豪光，你发现这密室四周空荡荡的,但是却十分干燥，不
知为何水进不来。在密室的中央有一石盒(box)。
LONG
);
    if ((int)query("yangpi")){
        set("item_desc", ([ "box" : "    石盒里好象有一卷羊皮。\n",  ])); 
        add_action("do_get", "get");
    }else
        set("item_desc", ([ "box" : "    一个空的石盒。\n",  ])); 
}
int do_get(string arg)
{
        object me,ob;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!(int)query("yangpi")) return 0;
        if( arg=="羊皮 from box" || arg=="羊皮 from 石盒") {
             ob=new(__DIR__"obj/yangpi");
            if (ob->move(me)){
             message_vision("$N从石盒中取出一卷羊皮。\n",me);
             set("item_desc", ([ "box" : "    一个空的石盒。\n",  ])); 
             return 1;    
           }   
      }
      return 0;              
}
void reset()
{
     object ob;
     ::reset();
     if (present("ling pai",this_object())) return;
     if (random(10)<4 ){
        ob=new(__DIR__"obj/lingpai");
        ob->move(this_object());
     }
}

