inherit ITEM;

int do_read(string arg);
void create()
{
      

        set_name(RED "※"YEL"江湖纪念碑"RED"※" NOR, ({ "jinian bei","bei" }) );
        
        set("unit", "本");
        set("long", "这是一块用来纪录江湖成名人物的石碑，伴随着江湖的
风风雨雨，岁月的流逝，石碑依旧。而上的名字却换了
一代又一代。石碑上刻录着：

             一："CYN"江湖十大"YEL"富豪"NOR"
             二："CYN"十大"HIR"杀人狂魔"NOR"
             三："CYN"十大"HIC"武林高手"NOR"
             四："CYN"十大"RED"邪道人物"NOR"
             五："CYN"十大"HIR"内力高手"NOR"
             六: "CYN"江湖"HIM"十大美女"NOR"
             七："CYN"江湖十大"GRN"老前辈"NOR"

你可以用(read 标号)来翻看记载。\n");
        
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
	   return notify_fail("你要阅读哪一项排行？\n");
switch(arg)
	{
		case "一": arg ="rich";break;
		case "二": arg = "pker";break;
		case "三": arg = "exp";break;
		case "四": arg = "shen";break;
		case "五": arg = "force";break;
		case "六": arg = "per";break;
		case "七": arg = "age";break;
		default : arg = "none";break;
	}
	str="/adm/daemons/toptend"->topten_query(arg);
	write(str+"\n");

	return 1;
}