inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("包不同",({"bao butong","bao","butong"}));
        set("title","金凤庄庄主");
        set("nickname","包三先生");
        set("long", 
              "他就是慕容复的结拜兄弟姑苏慕容金凤庄的庄主。\n");
        set("age", 25);
         set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 26);
        set("con", 26);
        set("dex", 26);
        
        set("max_qi", 2000);
        set("max_jing", 2000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 0);
        set("combat_exp", 500000);
        set("score", 35000);

        set_skill("sword",180);
        set_skill("blade",180);
        set_skill("dodge",180);
        set_skill("force", 180);
        set_skill("shenyuan-gong", 170);;
        set_skill("ding-dodge", 190);
        set_skill("parry", 180);
        set_skill("murong-daofa", 180);
        set_skill("literate", 180);

        map_skill("force", "shenyuan-gong");
        map_skill("dodge", "ding-dodge");
        map_skill("parry", "murong-daofa");
        map_skill("blade", "murong-daofa");   

            set("no_get",1);
        setup();
        
        carry_object(__DIR__"obj/cloth2")->wear();
        carry_object(__DIR__"obj/blade")->wield();   
        
        create_family("姑苏慕容",3,"弟子");
        
        set("inquiry", ([
            "name" : "非也，非也，我就是姑苏慕容金凤庄庄庄主包不同。\n",
            "here" : "这里是大名鼎鼎的燕子坞，难道你没有听说过？\n",
            "rumors" : "慕容公子的以彼之道，还施彼身天下闻名。\n",
            "阿珠" : "阿珠住在听香水榭，是慕容公子的贴身丫鬟，跟阿碧两个人一同侍奉公子。\n",
            "阿碧" : "阿碧姑娘住在琴韵小筑，所有要拜见慕容公子的人都要由她那里经过。\n",
            "王语嫣" : "王姑娘是慕容公子的表妹，不知道什么时候他们成亲。\n",
            "邓百川" : "邓百川是我大哥，是燕子坞青云庄的庄主。\n",
            "公孙乾" : "公孙乾是我二哥，是燕子坞赤霞庄的庄主。\n",
            "风波恶" : "风波恶是我四弟，是燕子坞玄霜庄的庄主，他就是喜欢跟别人打架。\n",
            "听香水榭" : "听香水榭是阿珠姑娘住的地方，离这里不远。\n",
            "琴韵小筑" : "琴韵小筑是阿碧姑娘住的地方，坐小舟有三九水路就到了。\n",
            "曼佗罗山庄" : "曼佗罗山庄是公子的姑妈住的地方，平时连我都不敢去。\n",
            "还施水阁" : "这是燕子坞的秘密之所在，我可不便对你说。\n",       
       ]));
}       
void attempt_apprentice(object ob)
{
        command("say 嗯，看你还是个学武的料，我就收下你吧！");
        command("recruit " + ob->query("id"));
                if( (string)ob->query("class") != "scholar")
                ob->set("class", "scholar");
        ob->set("title","姑苏慕容第四代弟子");
}
