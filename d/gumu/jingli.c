#include <ansi.h>
inherit NPC;
void create()
{
set_name("������", ({ "ding chunqiu", "ding" }));
set("nickname", HIR "�����Ϲ�" NOR);
set("long","�����������ɿ�ɽ��ʦ����������ʿ���ʹ���������Ϲֶ����\n");
set("gender", "����");
set("age", 60);
set("str", 60);
set("int", 60);
set("dex", 60);
set("con", 60);
set("max_qi", 400000);
set("max_jing", 400000);
set("max_neili", 1000000);
set("max_jingli", 1000000);
set("combat_exp", 103800);
setup();
}
