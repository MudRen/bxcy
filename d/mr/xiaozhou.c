inherit ROOM;
void create()
{
        set("short", "�ɴ�");
        set("long", @LONG
�������ӵĻ�����е�����һ��С���ϣ����ϵĴ������˵������
���ˡ���������͵���٢��ɽׯȥ��
LONG
        );

        setup();
}
void run(object ob)
{
        if (environment(ob) == this_object())
        ob->move(__DIR__"xiaozhou1");
        write("\n����Ѵ�ʻ����һƬһ���޼ʵĺɻ�����һ����ȥ, ������Ҷ, ��Ҷ, «έ, \n"
"����, ����һģһ��, ��֮��Ҷ, ��Ҷ��ˮ��Ư��, ��ʱһ�����, �㼴��\n"
"���ٶ�, ����˿̼ǵ��������, ��ʱ������ȫȻ��ͬ��\n\n");
}

void init()
{
       object ob = this_player();

    call_out("run", 3, ob);
}