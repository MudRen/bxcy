
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
   �������������������������䲼�õļ�Ϊ��ª��
LONG
);
	set("exits", ([ /* sizeof() == 1 */
        "west" : __DIR__"nroom1",
]));
	set("objects", ([ /* sizeof() == 1 */
            __DIR__"npc/mu-ren" : 4,
         //   __DIR__"npc/tong-ren" : 4,
]));
	set("no_new_clean_up", 0);

	setup();
	replace_program(ROOM);
}
