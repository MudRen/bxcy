// ��ͯ: /u/caac/npc/shutong.c  
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
int ask_me(object me);
void create()
{
        set_name("��ͯ",({ "shu tong","boy" }) );
        set("nickname","�������");
        set("title","���ǵ�С��ͯ");
         set("gender", "����" );
        set("age", 14);
        set("long",
"���ǽ��ǵ�С��ͯ���Ǹ�ϲ������ĺ��ӣ����������鱾�ﲻ������\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("vendor_goods", ([
                "�β�": "/u/caac/obj/tea",
                "����": "/obj/example/dumpling",
                "����": "/obj/example/chicken_leg",
                
        ]) );  

        setup();
}



