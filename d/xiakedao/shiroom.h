int do_study(string arg)
{
	string *skill_name = ({
               "strike",          //�Կ��Ϻ�ӧ
               "sword",           //�⹳˪ѩ��
               "dodge",           //�����հ���
               "throwing",        //��������
               "pixie-jian",      //ʮ��ɱһ�� sword
               "qiankundanuoyi",//ǧ�ﲻ���� dodge
               "lingboweibu",     //���˷���ȥ dodge
               "qimen-wuxing",   //��������� dodge
               "unarmed",         //�й������� cuff or strike or unarmed
               "qimen-flee",      //�ѽ�ϥǰ�� sword
               "parry",           //������캥
               "blade",           //����Ȱ����
               "axe",              //������Ȼŵ force ��ʱ��count��
               "whip",            //������Ϊ�� cuff or strike or unarmed
               "staff",           //�ۻ����Ⱥ�   ³������
               "taoism",          //���������� cuff or strike or unarmed
               "hammer",          //���Իӽ� sword
               "buddhism",        //�������� force
               "hubo",            //ǧ���׳ʿ
               "xiaowuxiang",           //ب�մ����� force
               "checking",        //����������   ָ��
               "club",            //��������Ӣ   ��ü��
               "kuihua-xinfa",    //˭�������
               "taixuan-gong"     //����̫����
        });
        object me, where;
        int jing_cost, learn_pot, item, times, i, success=0;
        string skillname;

        me = this_player();
        if( !arg ) return notify_fail("��Ҫ����ʲôѽ��\n");
	if( sscanf(arg, "%s %d", arg, times)!=2)
		return notify_fail("ָ���ʽ��think wall <����>\n");
        if( ( arg != "wall" ) )
		return notify_fail("ָ���ʽ��think wall <����>\n");
	if (times < 1 || times > 5)
		return notify_fail("�������������һ�Σ��������Ρ�\n");
        if ((int)me->query("combat_exp")<500000)
                return notify_fail("��ľ���̫��, û������ʯ�����ݡ�\n");
        if ((int)me->query_skill("literate",1)<1)
                return notify_fail("�����˰�! ������ȥѧ���Ļ��ɡ�\n");
        jing_cost = 30 + random(me->query_int());
        if( me->query("jing") < jing_cost * times)
                return notify_fail("������̫���ˣ���������ô��Σ���Ϣһ��������ɡ�\n");
	where = environment(me);
	switch (file_name(where))
	{
		case "/d/xiakedao/shiroom01": item = 0; break;
		case "/d/xiakedao/shiroom02": item = 1; break;
		case "/d/xiakedao/shiroom03": item = 2; break;
		case "/d/xiakedao/shiroom04": item = 3; break;
		case "/d/xiakedao/shiroom05": item = 4; break;
		case "/d/xiakedao/shiroom06": item = 5; break;
		case "/d/xiakedao/shiroom07": item = 6; break;
		case "/d/xiakedao/shiroom08": item = 7; break;
		case "/d/xiakedao/shiroom09": item = 8; break;
		case "/d/xiakedao/shiroom10": item = 9; break;
		case "/d/xiakedao/shiroom11": item = 10; break;
		case "/d/xiakedao/shiroom12": item = 11; break;
		case "/d/xiakedao/shiroom13": item = 12; break;
		case "/d/xiakedao/shiroom14": item = 13; break;
		case "/d/xiakedao/shiroom15": item = 14; break;
		case "/d/xiakedao/shiroom16": item = 15; break;
		case "/d/xiakedao/shiroom17": item = 16; break;
		case "/d/xiakedao/shiroom18": item = 17; break;
		case "/d/xiakedao/shiroom19": item = 18; break;
		case "/d/xiakedao/shiroom20": item = 19; break;
		case "/d/xiakedao/shiroom21": item = 20; break;
		case "/d/xiakedao/shiroom22": item = 21; break;
		case "/d/xiakedao/shiroom23": item = 22; break;
		case "/d/xiakedao/shiroom24": item = 23; break;
		default: break;
	}

        message_vision("$N��������ʯ���ϵ�ͼ����ע�͡�\n",me);
	for (i = 1; i<=times; i++)
	{
		me->receive_damage("jing",jing_cost);
		if (me->query_skill(skill_name[item],1)<80)
		{
		  if(item != 23)
		  if(item != 19)
		  {write("������ʯ��ڤ˼������һ�ᣬ��������Ķ���������˵̫����ˡ�\n");
			return 1;}
		}
		 if (me->query_skill(skill_name[item],1)>=5900)
		{
			write("������ʯ��ڤ˼������һ�ᣬ��������Ķ���������˵̫ǳ���ˡ�\n");
			return 1;
		}
		if (item == 4)
		{
if (me->query_skill("pixie-jian", 1) >= 520)
return notify_fail("��ı�а�����Ѿ��޷�������ˡ�\n");
			if ((string)me->query("gender") != "����" )
			{
				write("���Ǳ����Ǳ�а����ͼ�ף������񹦣������Թ���\n");
				return 1;
			}
		}
		else
		{
			if( !SKILL_D(skill_name[item])->valid_learn(me) )
			return SKILL_D(skill_name[item])->valid_learn(me);
		}
		if((int)(me->query_skill(skill_name[item],1) * 
			me->query_skill(skill_name[item],1) * 
			60 ) >= me->query("combat_exp"))
		{
			write("�����ʯ��ڤ˼������һ�ᣬ�����ջ�\n");
			return 1;
		}
		learn_pot = random(me->query("int"));
		if (learn_pot > 0)
		{
			if(item == 22)
			{
			me->improve_skill(skill_name[item], random((int)me->query("ker"))+(10 + random((int)me->query_int() - 9))/200);
			me->add("qi",-random(me->query("int")));
			success=1;
		}
		
		else
		if(item == 4)
			{
			me->improve_skill(skill_name[item], random((int)me->query("ker"))+(10 + random((int)me->query_int() - 9))/20);
			me->add("qi",-random(me->query("int")));
			success=1;
		}
		else if(me->query("combat_exp") < 150000000)
		{
       
	   	  me->improve_skill(skill_name[item], random((int)me->query("ker"))+(10 + random((int)me->query_int() - 9))/10);
			me->add("qi",-random(me->query("int")));
			success=1;
		}
		else if(me->query("combat_exp") > 150000000)
		{
       
        me->improve_skill(skill_name[item], random((int)me->query("ker"))+(10 + random((int)me->query_int() - 9))/18);
			me->add("qi",-random(me->query("int")));
			success=1;
		}
		
//			write("�����ʯ��ڤ˼������һ�ᣬ�ƺ�"+CHINESE_D->chinese(skill_name[item])+"��Щ�ĵá�\n");
		}
//		else
// write("�����ʯ��ڤ˼������һ�ᣬ���ǳɼ�̫��ƺ�ûɶ�ĵá�\n");
	}
	if (success == 1)
		write("�����ʯ��ڤ˼������"+chinese_number(times)+"�أ��ƺ���"+CHINESE_D->chinese(skill_name[item])+"��Щ�ĵá�\n");
	else write("�����ʯ��ڤ˼������һ�ᣬ���ǳɼ�̫��ƺ�ûɶ�ĵá�\n");
	success=0;
	return 1;
}
