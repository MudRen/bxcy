//xln.c 小龙女
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_suo();
string ask_zhen();
 
void create()
{
        set_name("小龙女", ({ "xiao longnu", "xiao", "longnu" }));
        set("title","古墓侠侣");
        set("nickname",HIC"玉女素心"NOR);
        set("long", "她清丽异常，但也许是长居古墓之故，面色略白。\n");
        set("gender", "女性");
        set("age", 39);
//          set("attitude", "friendly");	
        set("per", 40);
        set("str", 24);
        set("dex", 23);
        set("con", 20);
        set("int", 24);
        set("shen", 20000);
        set_skill("parry", 480);
set_skill("force", 600);	
        set_skill("dodge", 480);
set_skill("sword", 600);	
        set_skill("throwing", 480);
        set_skill("whip", 500);
set_skill("meinu-quanfa", 600);	
set_skill("unarmed", 600);	
        set_skill("yunu-shenfa", 480);
        set_skill("yinsuo-jinling", 400); 
        set_skill("literate", 480);         
set_skill("yunu-jianfa", 600);	
set_skill("quanzhen-jianfa", 300);  	
set_skill("yunu-xinjing", 600);	
set_skill("qufeng",300);
        map_skill("force", "yunu-xinjing");
        map_skill("dodge", "yunu-shenfa");
        map_skill("unarmed", "meinu-quanfa");
        map_skill("sword", "yunu-jianfa");
        map_skill("whip", "yinsuo-jinling");
        prepare_skill("unarmed", "meinu-quanfa");
        set("jiali",100);
        create_family("古墓派",3,"女主人");
set("combat_exp", 24000000);	
set("max_qi", 50000);	
        set("max_jing", 1600);
set("neili", 150000);    	
set("max_neili", 15000);	
        set("eff_jingli",2500);
        
        set("inquiry", ([
            "杨过" : "过儿是我夫君，我知道他很爱我，可一直呆在这真怕他会闷。", 
          "李莫愁" : "她是我师姐，不过我已经派人去清理门户了。",            "钥匙" : "嗯....这我可记不清楚，好象是放在古墓里面了吧。",
            "银索" : (: ask_suo :),
          "玉蜂针" : (: ask_zhen :),
        ])); 
         set("zhen_count", 2);
        setup();

carry_object("/clone/npc/obj/golden_sword")->wield();           	
         carry_object("/d/gumu/obj/yinsuo")->wield();
         carry_object("/d/gumu/obj/buxue1")->wear();
        carry_object("/d/gumu/obj/qun1")->wear(); 
}

void attempt_apprentice(object ob)
{
     mapping fam = ob->query("family");
if (!fam || fam["family_name"] != "古墓派" || fam["generation"]!=5){
                command("say "+RANK_D->query_respect(ob)+"与本派素无来往，不知此话从何谈起？");
                return;
                }       
      if((int)ob->query_skill("yunu-xinjing", 1) < 120) {
                command("say 我古墓武功内功是基础。"); 
                command("say " + RANK_D->query_respect(ob)+"是否还应该先在内功上多下点功夫？");
                return;
                }  
      if((int)ob->query_skill("sword", 1) < 100) {
                command("say 你剑法这么差，我教的你不一定学得会。"); 
                command("say "+RANK_D->query_respect(ob)+"是否还应该在剑法上多下点功夫？");
                return;
                }
      if(ob->query_int() < 32) {
                command("say 我的武功都要极高的悟性才能学会。");
                command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性却是半点也马虎不得。");
                command("say 这位"+RANK_D->query_respect(ob)+"的悟性还大有潜力可挖，还是请回吧。");
                return;
                }
      if(ob->query("gender") != "女性") {
                command("say 我可只收女徒，你去找我夫君试试吧。");
                return;
                }
        command("say 嗯，看你还是个学武的料，我就收下你吧！");
        command("recruit " + ob->query("id"));
        ob->set("title","古墓派神雕侠侣传人");
        ob->set("class","sworder");
}

string ask_suo()
{
       object ob = this_player();
       mapping fam = ob->query("family");
       if (!fam || fam["family_name"] != "古墓派" || ob->query("family/master_name") != "小龙女")
        return RANK_D->query_respect(ob)+"，我已经多年未用银索了，也不知道放在何处了。";
       if (ob->query_skill("yinsuo-jinling", 1) < 100)
        return "这位"+ RANK_D->query_respect(ob) +"，银索灵活异常，你是否应该把武功练高些？";
       ob->set_temp("marks/银索", 1);
       command("nod " + ob->query("id"));
       return "不错，银索就放在此屋中，你自个找找吧。";       
} 

string ask_zhen()
{
                  mapping fam;
                  object ob;

                  if (!(fam = this_player()->query("family"))
                 || fam["family_name"] != "古墓派")
                                         return RANK_D->query_respect(this_player()) +
                                         "与本派素无来往，不知此话从何谈起？";
                  if (query("zhen_count") < 1)
                                         return "我已经将玉蜂针已给了派去清理门户的人，你好好练功，以后有机会再去吧。";
                  add("zhen_count", -1);
                  ob = new("/d/gumu/obj/yfzhen.c");
                  ob->move(this_player());
                  return "你如此自愿为师门清理门户，不枉我平时一番栽培，这枚玉蜂针你就拿去吧。";
}

