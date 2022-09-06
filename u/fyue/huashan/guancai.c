// Room: /d/huashan/guancai.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
        set("short", "棺材");
        set("long", @LONG
这付棺材已经开始霉烂，棺材底已经被白蚁蛀出了许多孔洞，但是
奇怪的是里面有张符纸却完好无损，黑暗中发出幽幽的蓝色光芒。
LONG
);
        set("exits",([
         "out":__DIR__"daoguan",
        ]));
        set("objects",([
        "/clone/misc/magic_seal":1,
        ]));
        setup();
}
void init()
{
      if (userp(this_player())){
         delete("exits");
         call_out("close",1);
         remove_call_out("drop");
         call_out("drop",5,this_player(),1);
      }
}
void close()
{
       message("vision","突然不知是谁把棺材盖钉上了!\n",this_object());
}

void drop(object me,int i)
{
    object room;
    if (!me || environment(me)!=this_object())
           return;
    if (i<8){
       i++;
       message("vision","棺材咯吱咯吱直响......\n",this_object());
       remove_call_out("drop");
       call_out("drop",5,this_player(),i);
       return;
    }
    message_vision("霉烂的棺材板终于不堪支持$N的体重，应声而断，$N发现棺材底原来是个黑乎乎的大洞.....\n",me);
    if (!room=find_object(__DIR__"heidong"))
       room=load_object(__DIR__"heidong");
    me->move(room);
}
