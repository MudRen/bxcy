inherit ROOM;


void create()
{
        set("short", "С����");
        set("long", @LONG
һҶƯ����С�ۣ�������ɢ����һ�ɵ��������㣬��ͷһ����������ҡҷ��
������ද�������죬����̫���ڴ�β�����س��Ŵ���
LONG
        );

        setup();
}
int do_check()
{
        object *obj;
        int     i;
        obj=all_inventory(this_object());
        if (!sizeof(obj))       return 1;
        for (i=0;i<sizeof(obj);i++)
                if (userp(obj[i]))      return 0;
        return 1;
}

