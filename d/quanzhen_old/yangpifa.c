// Room: /d/shaolin/duchuan.c
// Date: YZC 96/01/19
inherit ROOM;


void create()
{
        set("short", "��ƤС��");
        set("long", @LONG
һֻС��Ƥ���ӣ����Ҳ�����������ĸ��ˡ�һ����ʮ�����������
�ֳֳ���ݣ����ڳ����س��ŷ��ӡ�
LONG
        );

        setup();
}
int do_check()
{
	object *obj;
	int	i;
	obj=all_inventory(this_object());
	if (!sizeof(obj))	return 1;
	for (i=0;i<sizeof(obj);i++)
		if (userp(obj[i]))	return 0;
	return 1;
}
