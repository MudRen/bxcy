//room: /d/wizard/meeting.c
//workroom write by lee2000.2.20
#include <ansi.h>
#include <room.h>

int discmds();
inherit ROOM;

void create()
{
        set("short",HIY "�� ������ ��" NOR);
        set("long", 
""HIC"  ������Ǳ�Ѫ����֮���������ʦ�鿪��ĵط����кܶ���߶������ﾭ�����۶�������	
  ������ǰ"HIM"�� ��������"NOR""HIC"������ɫ���֣�����һ��ׯ�ϵ�"NOR"\n"
""HIR"�о����㲻֪�����ӿ��˽Ų���"NOR"
           "HIM"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
           ��         ��          ��           ��            ��
��         ��                               --"BLINK+HIY"�������"HIW"  "NOR+HIM" ��I��	
           @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"NOR"\n"
                                                                                                               

        );


         set("objects",([
 //  "/d/wizard/guanjia" : 1,
"/d/wizard/mishu" : 1,	
           ]));
         set("exits",([
        "west" : __DIR__"wizard_room",
          ]));
         set("no_sleep", 1);
         set("valid_startroom",1);
         set("no_fight",1);
         set("no_steal",1);
         setup();  
                          
}

void init()
{
    if(!wizardp(this_player())) {
        "/cmds/std/look"->look_room(this_player(),this_object());
// this_player()->set("startroom", __FILE__);
       add_action("discmds",({"es","quit","goto","home","summon","kickout","dest","snoop","sleep","kill","fight","hit","chat","chat*","rumor","rumor*","tell","reply","to","new","new*"}));
        }
}

int discmds()
{
        tell_object(this_player(),"�������ڿ��ᣬ��Ҫȥ����?\n");
        return 1;

}
