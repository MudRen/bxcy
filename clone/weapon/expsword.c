// expsword.c �㹥������
// Wenwu 2003.8.25
#include <weapon.h>	
inherit SWORD;	
void create()	
{	
set_name("���׽�", ({ "fenglei jian","sword","fenglei", "jian" }));
set_weight(5000);	
if (clonep())	
set_default_object(__FILE__);	
else {	
set("unit", "��");	
set("long", "����һ�ѹ�����Ϊ�����Ľ���������ʿͨ������������ˢ���顣\n");      	
set("value", 0);	
set("material", "steel");	
}	
init_sword(-500,2);             	
setup();	
}	
