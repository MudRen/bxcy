#include  <ansi.h>

inherit  ITEM;

string  *prefixs  =  ({
    "??",
    "С",
    "??",
    "??",
    "Բ",
    "????",
    "????",
    "????",
});

string  *names  =  ({
    "ľ",
    "??",
    "????",
    "?޽?",
});

string  *suffixs  =  ({
    "??",
    "??",
});

void  create()
{
    set_name(prefixs[random(sizeof(prefixs))]+names[random(sizeof(names))]+
                      suffixs[random(sizeof(suffixs))],  ({  "table"  }));
    set_weight(30000);
    set("long",  "????һ?????ӡ?\n"  );
    if(  clonep()  )
        set_default_object(__FILE__);
    else  {
        set("unit",  "??");
        set("material",  "stone");
        set("value",  2000);
        set("no_sell",  1);
    }
    setup();
}

void  init  ()
{
    object  me  =  this_object();
    object  where  =  environment(me);
    
    if  (where  &&  userp(where))
    {
        remove_call_out  ("destruct_me");
        call_out  ("destruct_me",900+random(900),me);
    }    
}

void  destruct_me  (object  me)
{
    destruct  (me);
}

int query_autoload() { return 1; }