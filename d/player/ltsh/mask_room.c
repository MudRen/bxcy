// Room: /u/aplio/ltsh/mask_room.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��Ȼ����");
	set("long", @LONG
�����ĺ���һ�����������λ�������׺��ѡ�����һֱ
�����ţ����̵�ʱ����λ������Ϊ�����������й�һ��ʮ��
���ʣ������ѵ�һ���ı��䡣����������λ����������ʶ��
��Ϊ�ֵܡ��������ѿ������飬������Ȼ���ڵ��������
����ǰ��̣�Ʒ�������������Եõ�һ���õط���
            ��������Ц���գ�
            ���ƺ쳾�������� 
            �����˵�����ң��
            �������������ڡ�
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lxg",
]));

	setup();
	replace_program(ROOM);
}
