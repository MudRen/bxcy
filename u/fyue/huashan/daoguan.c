// Room: /d/huashan/daoguan.c
inherit ROOM;

void create()
{
        set("short", "纯阳道观");
        set("long", @LONG
几盏烛台发出幽暗的烛光，令整座道观显得逾加阴森恐怖，一座高大的神像
上挂满了蜘蛛网，神像上的金漆已经脱落了大半，露出里面的泥胚。神像前摆着
一张铺满灰尘的供桌，地下凌乱地散放着几个破旧蒲团。两旁横七竖八地摆放着
几具棺材。
LONG
);
        set("item_desc", ([ 
  "神像" : "你仔细地观察了一下神像，这尊满面络腮胡子的神像---一定是他“钟馗”。\n",
  "棺材" : "你蹑手蹑脚的围着棺材走了几圈，发现其中一具棺材的棺材板变形翘了起来。\n",
  "棺材板" : "棺材板上还插着几根七寸长钉，几丝幽幽的蓝光从棺材的缝隙中透了出来，好象可以撬(prize)开。\n",
]));
        setup();
}
void init()
{
   add_action("do_prize","prize");
}
int do_prize(string arg)
{
    object ob, weapon;
    string dir;
    if (stringp(query("exits/enter")) && query("do_prize")) return 0;
    if( !arg || arg !="棺材板" ) 
         return notify_fail("你要撬什么？\n" ) ;
    if (!objectp(weapon = this_player()->query_temp("weapon")))
        return notify_fail("你手中没东西怎撬？\n");
    if (weapon->query("skill_type")=="whip"
     || weapon->query("skill_type")=="hammer"
     || weapon->query("skill_type")=="throwing")
        return notify_fail("这种兵器怎么撬？\n");
        message_vision("$N抽出"+weapon->name()+"，插进棺材的缝隙，大喝一声，用力一撬。\n", this_player());
    if(this_player()->query_str()>200 && this_player()->query("neili")>200){
        message("vision","棺材板应声飞出丈外。\n", this_object());
        this_player()->add("neili",-200);
        set("exits/enter",__DIR__"guancai");
        set("do_prize",1);
    }else{
        message_vision("$N累得气喘吁吁，但棺材板丝毫不动。\n", this_player());
        this_player()->set("neili",0);
    }
    return 1;
}
int valid_leave(object me, string exit)
{
      if (exit=="enter"){
        delete("exits/enter");
        message_vision("$N战战兢兢地躺进棺材里。\n");
      } 
      return 1;
}

