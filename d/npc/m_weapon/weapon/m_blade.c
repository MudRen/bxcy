// m_blade.c
#include <ansi.h>
#include <weapon.h>
//inherit M_WEAPON;	
inherit S_WEAPON;	
int do_hui(object weapon);
int do_rename(string arg);
void init()
{
   if (!mapp(this_player()->query("weapon"))){
     this_object()->owner_is_killed();
     return;
   }
     if (this_player()!=environment()) return;
        add_action("do_duanlian","duanlian");
    add_action("do_hui","hui");
    add_action("do_rename","rename");
}
void create()
{   
    object me;
    string w_name,w_id,w_or;
    int w_lv;
    me = this_player();
//��������
    if (!me)   return;
    w_name=me->query("weapon/name");
    w_id = me->query("weapon/id");
    w_or = me->query("weapon/or");
    w_lv = me->query("weapon/lv");
    set_name(w_name, ({w_id,"blade"}));
    set("unit", "��");   
    set("no_get",1);
    set("no_drop",1);
    set("no_give",1);
set("no_put",1);
set("bianren",w_lv);         //  ������������2003��12��17��		
    set_desc(w_lv,w_or,w_name);
    switch(w_or)
        {
        case "ǧ����ľ" :
            set_weight(6000+w_lv*400);
            set("material", "iron");
            break;
        case "���׽�ĸ" :
            set_weight(8000+w_lv*400);
            set("material", "steel");
            break;
        case "��˿����" :
            set_weight(4000+w_lv*400);
            set("material", "bamboo");
            break;
        default :
        } 
    set("wield_msg", "$N������һ�����ͳ���һ��"+w_name+"\n");
    set("unwield_msg", "$N����"+w_name+"һ����գ�ۼ���Ȼ����Ӱ�١�\n");
    init_blade(w_lv * 10,2);
    setup();
}   
int do_duanlian(string arg)
{
    object me;
    object weapon;
    int w_zhi, w_level;
    string w_or;
    me=this_player();
    if( !arg || !id(arg) )
        return notify_fail("��Ҫ����ʲô?\n");
    if( (int)me->query("max_neili") < 1000 )
        return notify_fail("��������������޷�����������\n");
    if( (int)me->query("qi") < 150 )
        return notify_fail("������������޷�����������\n");
    if( (int)me->query("eff_qi") < 50 )
        return notify_fail("�����ڵ�����̫�����޷�����������\n");
    if( (int)me->query("eff_jing") < 50 )
        return notify_fail("�����ڵľ����޷����У����ܶ���������\n");
    if( ((int)me->query("potential") - (int)me->query("learned_points"))< 2 )
        return notify_fail("���Ǳ�ܲ������޷�����������\n");
    message_vision(HIR "$N��ָ������һ������˿˿�Ĵ��˽�ȥ��\n" NOR, me);
    me->add("max_neili",-10);
    me->set("neili", (int)me->query("max_neili"));
    me->add("qi",-150);
    me->add("eff_qi",-30);
    me->add("eff_jing",-30);
me->add("potential",-2);
    w_zhi = (int)me->query("weapon/value");
    w_zhi++;
    me->set("weapon/value", w_zhi);
    w_or = (string)me->query("weapon/or");
    w_level = (int)me->query("weapon/lv");
    if( w_zhi >= ((w_level + 1) * (w_level + 1)))
    {
        w_level++;
        me->set("weapon/lv", w_level);
        message_vision(CYN "��������һ����һ����������$N�ĵ��У������ˣ�\n" NOR,me);
        message_vision(HIG "$N�ĵ��ĵȼ�����ˣ�\n" NOR, me);
        weapon=this_object();
        if(weapon->query("equipped") ) 
            weapon->unequip();
        reload_object( weapon );
        me->set("weapon/value",0);
        return 1;
    }
    message_vision(RED "$N�ĵ���������!\n" NOR, me);
    return 1;
}
int do_hui(string weapon)
{   
    string w_name;
    object me;
    me=this_player();
    w_name=me->query("weapon/id");
    if( !weapon || !id(weapon) )
        return notify_fail("��Ҫ�ݻ�ʲô?\n");
    message_vision(HIR "����һ����һ���浶��һ���������¡������¡һ������"
            +this_object()->name()+HIR+"��Ϊ����!\n" NOR,me);
    me->delete("weapon");
    me->save();
    destruct( this_object() );
    return 1;
}
int do_rename(string arg)
{
    object me;
    me=this_player();
    if( !arg )
        return notify_fail("���ʲô������?\n");
if (this_object()->query("bianren") > me->query("weapon/lv"))    	
return notify_fail("��ֻ�ܸ��Լ���������!\n");		
if( strlen(arg) > 30 )          		
return notify_fail("��ı����������ֻ������ʮ����ַ���\n");     	
    arg = replace_string(arg, "$BLK$", BLK);
    arg = replace_string(arg, "$RED$", RED);
    arg = replace_string(arg, "$GRN$", GRN);
    arg = replace_string(arg, "$YEL$", YEL);
    arg = replace_string(arg, "$BLU$", BLU);
    arg = replace_string(arg, "$MAG$", MAG);
    arg = replace_string(arg, "$CYN$", CYN);
    arg = replace_string(arg, "$WHT$", WHT);
    arg = replace_string(arg, "$HIR$", HIR);
    arg = replace_string(arg, "$HIG$", HIG);
    arg = replace_string(arg, "$HIY$", HIY);
    arg = replace_string(arg, "$HIB$", HIB);
    arg = replace_string(arg, "$HIM$", HIM);
    arg = replace_string(arg, "$HIC$", HIC);
    arg = replace_string(arg, "$HIW$", HIW);
    arg = replace_string(arg, "$NOR$", NOR);
    me->set("weapon/name",arg+NOR);
    set("name",arg+NOR);
    write("ok!\n");
    this_object()->create();
    return 1;
}