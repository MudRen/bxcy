// expblade.c ��������
// Wenwu 2003.8.25
#include <weapon.h>	
inherit BLADE;   	
void create()	
{	
set_name("���Ƶ�", ({ "fengyun dao","blade","fengyun", "dao" }));	
set_weight(5000);	
if (clonep())	
set_default_object(__FILE__);	
else {	
set("unit", "��");              	
set("long", "����һ��������Ϊ�����ĵ���������ʿͨ������������ˢ���顣\n");                      	
set("value", 0);	
set("material", "steel");	
}	
init_blade(-500,2);                      	
setup();	
}	
