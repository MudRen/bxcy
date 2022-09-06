// Room: home.c

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
    ����ѩ������ѿ����С�ݣ���Ȼ�ط����󣬿��Ƿǳ����࣬��ȻŮ����ʱ��
��ɨ��ǽ������һ�����(book_shelf)����ܵ�һ��б����һ��������(guitar)��
���յ�ҹ�����Ӵ���Ʈ�����ŵ�����������һ��������Ů������Լ������<<˹
����̸�>>(Scarborough Fair)������ص����ڷ������ܵĲ�ƺ֮�ϡ�
LONG
	);

	set("no_die", 1);
	set("valid_startroom",1);

	set("exits", ([
              "west":__DIR__"melodies_room",
              "east":__DIR__"sunrise",
		"ts" : "/d/taishan/fengchan",
		"sl" : "/d/shaolin/dxbdian",
                "dm" : "/d/shaolin/damodong",
                "dx" : "/d/city2/daxiao",
		"td" : "/d/city2/dating",
		"bt" : "/d/baituo/dating",
		"wg" : "/d/wudang/sanqingdian",
		"xx" : "/d/xingxiu/xxh2",
                "xs" : "/d/xueshan/dadian",
                "lj" : "/d/lingjiu/dating",
                "xy" : "/d/xiaoyao/qingcaop",
                "ss" : "/d/shenlong/dating",
		"th" : "/d/taohua/dating",
		"hg" : "/d/city2/tian_anm",
		"gb" : "/d/city/gbxiaowu",
		"wz" : "/d/wizard/wizard_room",
		"ct" : "/d/city/guangchang",
		"qz" : "/d/quanzhou/zhongxin",
		"hs" : "/d/huashan/buwei1",
	]));
	setup();
	replace_program(ROOM);
}

