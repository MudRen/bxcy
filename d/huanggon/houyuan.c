inherit ROOM;
void create()
{
    set("short", "��͵��Ժ");
    set("long", @LONG
��������͵��Ժ��Ժ������Щ��ˡ�ǽ����һ��ˮ��(well)��
վ��ˮ�������¿���ֻ������ף����������ǻ��������̦��һ��
��ꤵ���һ������������ϵ��һ��ľͰ��������һ�����ȣ�ͨ�����
�
LONG
    );
        set("outdoors", "huanggon");
    set("resource/water", 1);
    set("exits", ([
        "east" : "/d/huanggon/zoulang1",
"north" : "/d/hg/wumen",	
    ]));
    setup();
    replace_program(ROOM);
}