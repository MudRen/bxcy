
 
#include "ansi.h"

inherit "/inherit/misc/bbsboard";

void create()
{
        set_name(HIG"�������"NOR+"������", ({ "newsgroup" }) );
        set("location", "/d/wizard/snow_room");
        set("board_id", "jhfy_b");
        set("long", "����һ������λ�������۵�"+HIC+" BBS "+NOR+"�塣\n\n��ʦ������"+HIW"mkgroup"NOR+" �� "+HIW"rmgroup"NOR+"ȥ
������ɾ��һ��������,��ҿ�����\n"
+HIW"read board"NOR+"ָ���Ķ�\n" );
        setup();
        set("capacity", 500);
        replace_program("/inherit/misc/bbsboard");
}

