// Room: /u/ibm/qq.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
set("short", HIC"��"HIM"�������"HIC"��"HIR"������");	
set("long",
HIW"         �κ�¥̨����"HIR" ========= "HIY"������Ļ�ʹ�\n"     	
HIB"           ȥ�괺��ȴ��ʱ"HIR" ========= "HIG"�仨�˶���\n"     
HIM"               ΢����˫��"HIR" ========= "CYN"�ǵ�СƼ����\n"   
GRN"             ������������"HIR" ========= "MAG"��������˵��˼\n" 
HIC"               ��ʱ������"HIR" ========= "YEL"���ղ��ƹ�\n"    	
);
	set("exits", ([ /* sizeof() == 1 */
"west" : "/d/city/zisharoom",	
]));

	setup();
        "/d/board/qq_b"->foo();
}
