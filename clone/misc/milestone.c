inherit ITEM;

int do_read(string arg);
void create()
{
      

        set_name(RED YEL"��Ѫ�������а�"RED NOR, ({ "paihang bang","bang" }) );
        
        set("unit", "��");
        set("long", "����һ��������¼������������Ľ�񣬰����Ž�����
������꣬���µ����ţ�������ɡ����ϵ�����ȴ����
һ����һ����ʯ���Ͽ�¼�ţ�

             һ��"CYN"����ʮ��"YEL"����"NOR"
             ����"CYN"ʮ��"HIR"ɱ�˿�ħ"NOR"
             ����"CYN"ʮ��"HIC"���ָ���"NOR"
             �ģ�"CYN"ʮ��"RED"а������"NOR"
             �壺"CYN"ʮ��"HIR"��������"NOR"
             ��: "CYN"����"HIM"ʮ����Ů"NOR"
             �ߣ�"CYN"����ʮ��"GRN"��ǰ��"NOR"

�������(read ���)���������ء�\n");
        
        set("material","steel");
        set_weight(8888888);
        setup();
}

void init()
{
	add_action("do_read","read");
}

int do_read(string arg)
{
       string str;
	if(!arg||arg=="") 
	   return notify_fail("��Ҫ�Ķ���һ�����У�\n");
switch(arg)
	{
		case "һ": arg ="rich";break;
		case "��": arg = "pker";break;
		case "��": arg = "exp";break;
		case "��": arg = "shen";break;
		case "��": arg = "force";break;
		case "��": arg = "per";break;
		case "��": arg = "age";break;
		default : arg = "none";break;
	}
	str="/adm/daemons/toptend"->topten_query(arg);
	write(str+"\n");

	return 1;
}
