// smith.c
inherit NPC;
inherit F_DEALER;
void create()
{
        set_name("����", ({ "tie jiang", "smith" }));
	set("title", "�������ϰ�");
	set("shen_type", 1);
        set("gender", "����" );
        set("age", 33);
        set("long", "����������ǯ��סһ����ȵ�����Ž�¯�С�\n");
        set("combat_exp", 400);
	set("attitude", "friendly");
        set("vendor_goods",({
		"/d/city/obj/changjian",
		"/d/city2/obj/tudao",
		"/d/city/obj/dagger",
		"/d/xingxiu/obj/staff",
		"/d/xingxiu/obj/club",
		"/d/city/obj/gangdao",
                "/d/city/obj/gangaxe",
                "/d/obj/feidao",
		"/d/city/obj/whip",
                "/d/obj/feihuangshi",
                "/d/obj/tielianzi",
	   }));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
