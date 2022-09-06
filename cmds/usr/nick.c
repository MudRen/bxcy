

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   int i;
   
   if( !arg ) return notify_fail("��Ҫ���Լ�ȡʲô�ºţ�\n");
   
   if( arg=="none" ) {
   me->delete("nickname");
   return 1;
   }

if(!wizardp(me)&&(i = strlen(arg)) > 50 )
     return notify_fail("��Ĵº�̫���ˣ���һ����һ��ġ�����һ��ġ�\n");

   while(i--) {
                  if( arg[i]<' ' ) {
                          return notify_fail("�Բ������ͷ�β����ÿ�����Ԫ��\n");
                  }
          }

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

   me->set("nickname", arg + NOR);
   write("Ok.\n");
   return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : nick <���, �º�>
      nick none   ȡ��
 
���ָ���������Ϊ�Լ�ȡһ�����������Ż�ͷ�Σ������ϣ���ڴº���
ʹ�� ANSI �Ŀ�����Ԫ�ı���ɫ�����������µĿ����ִ���

$BLK$ - ��ɫ       $NOR$ - �ָ�������ɫ
$RED$ - [31m��ɫ[0m       $HIR$ - [0;1;31m�[1m�[1m�[1m�[1m�[1m�[0m
$GRN$ - [32m��ɫ[0m       $HIG$ - [0;1;32m�[1m�[1m�[1m�[1m�[1m�[0m
$YEL$ - [33m����ɫ[0m     $HIY$ - [0;1;33m�[1m�[1m�[1m�[0m
$BLU$ - [34m����ɫ[0m     $HIB$ - [0;1;34m�[1m�[1m�[1m�[0m
$MAG$ - [35mǳ��ɫ[0m     $HIM$ - [0;1;35m�[1m�[1m�[1m�[1m�[1m�[0m
$CYN$ - [36m����ɫ[0m     $HIC$ - [0;1;36m�[1m�[1m�[1m�[1m�[1m�[0m
$WHT$ - [30mǳ��ɫ[0m     $HIW$ - [0;1;37m�[1m�[1m�[1m�[0m

 
����ϵͳ�Զ������ִ�β�˼�һ�� $NOR$��

HELP
        );
        return 1;
}
