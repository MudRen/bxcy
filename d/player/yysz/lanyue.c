
inherit ROOM;

void init();

void create()
{
        set("short", "悠闲居");
        set("long",@LONG
这是程公子的卧室，房中陈设普通，收拾得颇为整洁，屋角一架
茂兰盆景(penjing)长得很是旺盛。晚上月光从窗户射进来，满室银光，
是燕子坞的一大美景。
LONG );
        set("exits", ([
            "west": __DIR__"shuwu",
        ]));

        set("item_desc", ([
            "penjing" : "这盆景看来经过主人不少的心血去栽培啊，你不禁佩服程公子的精神。\n",
        ]));
        set("no_clean_up", 0);
        setup();
}

